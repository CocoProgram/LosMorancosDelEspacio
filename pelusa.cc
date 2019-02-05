#include <stdio.h>
#include <stdlib.h>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>

#include <conio.h>


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
	int points;
	char colour;
	//
	bool phase_animation;
	//
	//
	int seg_counter = 0;
	//
};
TEnemy *str_enemy;

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

//INICIALIZACION DEL ENEMIGO PELUZA
void InicializarPelusa(TEnemy *pelusa, esat::SpriteHandle *sprite){
	
	
	
	//printf("HOla\n");
	*(Block_sprite_Enemy) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_azul.png");
	printf("HOla\n");
	(*(Block_sprite_Enemy+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_azul.png");
	
	(*(Block_sprite_Enemy+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_lila.png");
	(*(Block_sprite_Enemy+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_lila.png");
	
	(*(Block_sprite_Enemy+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_rojo.png");
	(*(Block_sprite_Enemy+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_rojo.png");
	
	(*(Block_sprite_Enemy+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_verde.png");
	(*(Block_sprite_Enemy+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_verde.png");
	
	for(int i=0;i<4;i++){
		
		(*(pelusa+i)).enemy_sprites = (sprite+(2*i));
		(*(pelusa+i)).is_alive = true;
		(*(pelusa+i)).posx = (kWindowX*(rand()%2));
		(*(pelusa+i)).posy = 75 + (kWindowY * (rand()%6));
		(*(pelusa+i)).enemy_type = kEnemyTypes_1;
		(*(pelusa+i)).speedx = 2;
		(*(pelusa+i)).speedy = 2;
		(*(pelusa+i)).points = 80;
		(*(pelusa+i)).colour = i;
		(*(pelusa+i)).phase_animation = 0;
		(*(pelusa+i)).seg_counter = 0;
	}	
}

//INICIALIZACION DEL ENEMIGO BOLA
void InicializarBola(TEnemy *bola, esat::SpriteHandle *sprite){
	
	
	(*(sprite))   = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_azul.png");
	(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_azul.png");
	
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_lila.png");
	(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_lila.png");
	
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_rojo.png");
	(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_rojo.png");
	
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_verde.png");
	(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_verde.png");
	
	for(int i=0;i<4;i++){
		
		(*(bola+i)).enemy_sprites = sprite;
		(*(bola+i)).is_alive = true;
		(*(bola+i)).posx = (kWindowX*(rand()%2));
		(*(bola+i)).posy = 75 + (kWindowY * (rand()%6));
		(*(bola+i)).enemy_type = kEnemyTypes_2;
		(*(bola+i)).speedx = 2;
		(*(bola+i)).speedy = 2;
		(*(bola+i)).points = 30;
		(*(bola+i)).colour = i;
		(*(bola+i)).phase_animation = 0;
		(*(bola+i)).seg_counter = 0;
	}	
}

//Control y Animacion del enemigo tipo Pelusa
void MovimientoPelusa(TEnemy *pelusa){
	
	(*(pelusa)).posx += (*(pelusa)).speedx;
	/*
	if(/*colicion terreno){
		
		(*(pelusa)).speedx *= (-1);
		(*(pelusa)).posx += (*(pelusa)).speedx;
	}
	*/
	(*(pelusa)).posy += (*(pelusa)).speedy;
	/*
	if(/*colicion terreno){
		
		(*(pelusa)).speedy *= (-1);
		(*(pelusa)).posy += (*(pelusa)).speedy;
	}
	*/
	if((*(pelusa)).posy < 50){
		
		(*(pelusa)).speedy *= (-1);
		(*(pelusa)).posy += (*(pelusa)).speedy;
	}
	
	if((*(pelusa)).posy > (kWindowY-50)){
		
		(*(pelusa)).speedy *= (-1);
		(*(pelusa)).posy += (*(pelusa)).speedy;
	}
	
	if((*(pelusa)).posx >= (kWindowX+55)){
		
		(*(pelusa)).posx = (-55);		
		
	}
	if((*(pelusa)).posx <= (-55)){
		
		(*(pelusa)).posx = (kWindowX+55);		
		
	}
	
	if(fps_counter == 0 || fps_counter == 30){
		
		(*(pelusa)).phase_animation = !(*(pelusa)).phase_animation;		
		
	}	
	
}



//Control y Animacion del enemigo tipo Bola
void MovimientoBola(TEnemy *Bola){
	
	
	(*(Bola)).posx += (*(Bola)).speedx;
	/*
	if(/*colicion terreno){
		
		(*(Bola)).speedx *= (-1);
		(*(Bola)).posx += (*(Bola)).speedx;
	}
	*/
	(*(Bola)).posy += (*(Bola)).speedy;
	/*
	if(/*colicion terreno){
		
		(*(Bola)).speedy *= (-1);
		(*(Bola)).posy += (*(Bola)).speedy;
	}
	*/
	if((*(Bola)).posx >= (kWindowX+55)){
		
		(*(Bola)).posx = (-55);		
		
	}
	if((*(Bola)).posx <= (-55)){
		
		(*(Bola)).posx = (kWindowX+55);		
		
	}
	
	if(fps_counter == 0 || fps_counter == 30){
		
		(*(Bola)).phase_animation = !(*(Bola)).phase_animation;		
		
	}
	
	if(fps_counter == 59){
		(*(Bola)).seg_counter++;
	}
	
	if((*(Bola)).seg_counter == 3){
		
		(*(Bola)).speedy = ((-1)+rand()%3)/*multiplicar para dificultad*/;
		(*(Bola)).seg_counter = 0;
	}
	
	
}



void PreMemorySaved(){
	
	if((Block_sprite_Enemy = (esat::SpriteHandle *)calloc(8,sizeof(esat::SpriteHandle)))==NULL){
				printf("ERROR");
	}else{
		
	}
	
	if((str_enemy = (TEnemy *)calloc(4,sizeof(TEnemy)))==NULL){
				printf("ERROR");
	}else{
		
		InicializarPelusa(str_enemy, Block_sprite_Enemy);		
	}
	
	
	
}   //RESERVAR AQUÍ MEMORIA DE PUNTEROS AMORES
void FreeMemorySaved(){
	
	
	free(Block_sprite_Enemy);
	free(str_enemy);
}  //LIBERAR MEMORIA DE PUNTEROS AQUÍ JOSPDEPUTAS.

void LoadSprites() {

}   //CARGAR AQUÍ SPRITES CHICAS
void SpritesRelease() {
	
	
	
	
}  //LIBERAR AQUÍ LOS SPRITES OSTIA
void DrawingSprites(){
	
	for(int i=0;i<4;i++){
		
		MovimientoPelusa((str_enemy+i));
		
		esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		
	}
	// (*(str_enemy+i)).(*(
	
}  //VAMOH A DIBUJAR

void InitializeParametres(){



} //INICIAR TODAS LAS VARIABLES AQUÍ ANTES DEL BUCLE WHILE

















int esat::main(int argc, char **argv) {
	
  PreMemorySaved();
  
  InitializeParametres();
  LoadSprites();
	
	esat::WindowInit(kWindowX,kWindowY);
	WindowSetMouseVisibility(true);
	
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
