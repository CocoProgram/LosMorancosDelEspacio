#include <stdio.h>
#include <stdlib.h>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>

#include <conio.h>
#include <time.h>

unsigned char fps = 60; //fps que trascurren en un segundo.
double current_time,last_time;
unsigned char fps_counter = 0; //cuenta los fps que trascurren en un segundo.

const int kWindowX = 768, kWindowY = 576;
esat::SpriteHandle *Block_sprite_Enemy;

enum GamePhase { kGamePhase_Menu = 0,
                 kGamePhase_InGame,
                 kGamePhase_EndGame };

enum EnemyTypes { kEnemyTypes_0 = 0,
                  kEnemyTypes_1,
                  kEnemyTypes_2,
                  kEnemyTypes_3,
                  kEnemyTypes_4,
                  kEnemyTypes_5,
                  kEnemyTypes_6,
                  kEnemyTypes_7 };

enum NaveType { kNaveType_0 = 0,
                kNaveType_1,
                kNaveType_2,
                kNaveType_3 };

enum BonusType { kBonusType_0 = 0,
                 kBonusType_1,
                 kBonusType_2,
                 kBonusType_3 };


bool g_right, g_left, g_jetpac, g_shoot;
float g_gravity;

struct TMapa{
  int posx, posy;
  esat::SpriteHandle platform_sprites;
};
TMapa *str_mapa;

#include "platforms.cc"

struct TPlayer{
  float posx, posy;
  esat::SpriteHandle *player_sprites; //Pasar a puntero, son 16
  bool is_flying, is_alive;
  bool shoot;
  char vida = 5;
  float jetpac;
  double score;
  int phase_animation;
  float speed_walk;
};
TPlayer str_player;

struct TShoot {
  float posx, posy;
  //Metodo de dibujado desconocido.
 float distance_max;
 bool collision;
};
TShoot *str_shoot;

struct TEnemy {
	float posx, posy;
	esat::SpriteHandle *enemy_sprites;
	EnemyTypes enemy_type;
	bool is_alive;
	float speedx, speedy;
	int direccionx;
	int direcciony;
	int points;
	char colour;
	bool phase_animation;
	int seg_counter = 0;
};
TEnemy *str_enemy;

#include "base_enemy.cc"

struct TBonus {
  float posx, posy;
  esat::SpriteHandle bonus_sprite;
  int points;
  BonusType bonus_type;
  bool is_alive;
};
TBonus str_bonus;

struct TNave {
  float posx, posy;
  esat::SpriteHandle nave_sprites; //puntero con numero de piezas
  int fuel_level;
  NaveType nave_type;
};
TNave *str_nave;

void TimeInFps(){
	/* Contamos los fps que trascurren y cuando llegan al máximo,
	60, se resetea a 0, servirá para hacer transiciones entre animaciones.*/
	//
	if(fps_counter == fps){fps_counter = 0;}else{fps_counter++;}
	//
}

void BoleanasTeclas(){ //EN ESTE VOID LLAMAMOS A LAS BOOLEANAS QUE INDICAN LA ACTIVACIÓN DE LAS TECLAS
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) != NULL ? g_left = true : g_left = false;
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) != NULL ? g_right = true : g_right = false;
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Space) != NULL ? g_jetpac = true : g_jetpac = false;
  esat::IsKeyPressed('D') != NULL ? g_shoot = true : g_shoot = false;
}


//INICIALIZA ENEMIGO METEORO

void InicializarMeteoro(TEnemy *meteoro, esat::SpriteHandle *sprite) {
	
	(*sprite) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_azul.png");
	(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_azul_1.png");
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_azul.png");
	(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_azul_1.png");
	
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_lila.png");
	(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_lila_1.png");
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_lila.png");
	(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_lila_1.png");
	
	(*(sprite+8)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_rojo.png");
	(*(sprite+9)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_rojo_1.png");
	(*(sprite+10)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_rojo.png");
	(*(sprite+11)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_rojo_1.png");
	
	(*(sprite+12)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_verde.png");
	(*(sprite+13)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_verde_1.png");
	(*(sprite+14)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_verde.png");
	(*(sprite+15)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_verde_1.png");
	
	
	
	for(int i = 0 ; i < 4 ; i++){
		
		(*(meteoro+i)).enemy_sprites = sprite+(4*i);
		(*(meteoro+i)).is_alive = true;
		(*(meteoro+i)).posx = (kWindowX*(rand()%2));
		(*(meteoro+i)).posy = rand()%kWindowY;
		(*(meteoro+i)).enemy_type = kEnemyTypes_0;
		(*(meteoro+i)).speedx = 2;
		(*(meteoro+i)).speedy = 1;
		(*(meteoro+i)).direccionx = rand()%2;
		(*(meteoro+i)).points = 25;
		(*(meteoro+i)).colour = i;
		(*(meteoro+i)).phase_animation = 0;
		(*(meteoro+i)).seg_counter = 0;
		
	}
	
}


//MOVIMIENTO Y ANIMACION ENEMIGO METEORO

void MovimientoMeteoro(TEnemy *meteoro, esat::SpriteHandle *sprite) {
	
	if((*(meteoro)).direccionx == 0){
		
		(*(meteoro)).posx += (*(meteoro)).speedx;
		(*(meteoro)).phase_animation = 0;
		
	}else{
		
		(*(meteoro)).posx -= (*(meteoro)).speedx;
		(*(meteoro)).phase_animation = 1;
		
	}
	
	if((*(meteoro)).posx > kWindowX){
		
		(*(meteoro)).posx = 0;
		
	}
	
	if((*(meteoro)).posx < 0){
		
		(*(meteoro)).posx = kWindowX;
		
	}
	
	if((*(meteoro)).posy + 45 > kWindowY || CollisionEnemy((*(meteoro)))){
		
		(*(meteoro)).is_alive = false;
		(*(meteoro)).seg_counter++;
		
	}
	
	if((*(meteoro)).seg_counter == 50){
		
		(*(meteoro)).is_alive = true;
		(*(meteoro)).direccionx = rand()%2;
		(*(meteoro)).posx = (kWindowX*(rand()%2));
		(*(meteoro)).posy = rand()%kWindowY-30;
		
		(*(meteoro)).seg_counter = 0;
		
	}
	
	if((*(meteoro)).colour < 2){
		
		(*(meteoro)).posy += (*(meteoro)).speedy;
		
	}
	
	
	if(fps_counter == 0 || fps_counter == 30 ){
		
		(*(meteoro)).phase_animation = !(*(meteoro)).phase_animation;		
		
	}
	
	
}





void PreMemorySaved(){
	
	if((Block_sprite_Enemy = (esat::SpriteHandle *)calloc(16,sizeof(esat::SpriteHandle)))==NULL){
				printf("ERROR");
	}else{
		
	}
	
	if((str_enemy = (TEnemy *)calloc(4,sizeof(TEnemy)))==NULL){
				printf("ERROR");
	}else{
		
		/*InicializarBola(str_enemy, Block_sprite_Enemy);*/
		InicializarMeteoro(str_enemy, Block_sprite_Enemy);
	}
	
	PlatformsMemoryReserved();
	
}   //RESERVAR AQUÍ MEMORIA DE PUNTEROS AMORES
void FreeMemorySaved(){
	
	
	LiberarEnemy();
	PlatformsFreeMemory();
}  //LIBERAR MEMORIA DE PUNTEROS AQUÍ JOSPDEPUTAS.

void LoadSprites() {
	PlaformsLoadSprites();
}   //CARGAR AQUÍ SPRITES CHICAS
void SpritesRelease() {
	
	
	
	
}  //LIBERAR AQUÍ LOS SPRITES OSTIA
void DrawingSprites(){
	
	for(int i=0;i<4;i++){
		
		/*MovimientoBola((str_enemy+i));*/
		/*esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));*/
		MovimientoMeteoro((str_enemy+i), (Block_sprite_Enemy+i));
		
		if((*(str_enemy+i)).is_alive){
			esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy+i)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		}
	}
	
	PlatformsDraw();
	// (*(str_enemy+i)).(*(
	
}  //VAMOH A DIBUJAR

void InitializeParametres(){



} //INICIAR TODAS LAS VARIABLES AQUÍ ANTES DEL BUCLE WHILE

















int esat::main(int argc, char **argv) {
	
  srand(time(NULL));
	
	esat::WindowInit(kWindowX,kWindowY);
	WindowSetMouseVisibility(true);
	
	PreMemorySaved();
  
	InitializeParametres();
	PlatformPositions();
	LoadSprites();
	
    while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

    	last_time = esat::Time();
    	esat::DrawBegin();
    	esat::DrawClear(0,0,0);
			TimeInFps();

			//BoleanasTeclas();
			DrawingSprites();
			
    	esat::DrawEnd();

    	//Control fps
    	do{
    		current_time = esat::Time();
    	}while((current_time-last_time)<=1000.0/fps);
    	esat::WindowFrame();
  }
  FreeMemorySaved();
  SpritesRelease();

  esat::WindowDestroy();

  return 0;
}