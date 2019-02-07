#include <stdio.h>
#include <stdlib.h>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>

unsigned char fps = 60; //fps que trascurren en un segundo.
double current_time,last_time;
unsigned char fps_counter = 0; //cuenta los fps que trascurren en un segundo.
unsigned char seg_counter = 0;

const int kWindowX = 768, kWindowY = 576;

enum GamePhase { kGamePhase_Menu = 0,
                 kGamePhase_InGame,
                 kGamePhase_EndGame,
	       	 kGamePhase_Intro};
GamePhase phase = kGamePhase_Intro;

enum GameMode { OnePlayer, TwoPlayers, NoneSelected};
GameMode mode = NoneSelected;

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

enum BonusType {
  kBonusType_0 = 0,
  kBonusType_1,
  kBonusType_2,
  kBonusType_3,
  kBonusType_4
};

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
  int direction;
  int loop;
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
  esat:: SpriteHandle enemy_sprites;
  EnemyTypes enemy_type;
  bool is_alive;
  float speedx, speedy;
  int points;
  char colour;
  int phase_animation;
};
TEnemy str_enemy;

struct TBonus {
  float posx = 0, posy = 0;
  BonusType type_bonus;
  esat::SpriteHandle bonus_sprite;
  int points = 250;
  bool is_alive = false;
  bool draw_bonus = true;
  bool coll_bonus = false;
};
TBonus str_bonus;
#include "bonus.cc"

struct TNave {
  float posx, posy;
  esat::SpriteHandle nave_sprites; //puntero con numero de piezas
  int fuel_level;
  NaveType nave_type;
};
TNave *str_nave;

bool g_right, g_left, g_jetpac, g_shoot;
float g_gravity;

double g_HiScore = 0;
bool g_keyboardSelected = true; // bool de control para el menú
esat::SpriteHandle s_vida, *s_intro; // sprites para la intro y vida del jugador;

//Variables para hacer ITOA de Puntuaciones y Vidas:
char *g_write_player1score, *g_write_player2score, *g_write_hi, *g_write_player1lives;

//Punteros de floats para hacer: Draw Solid Path de las "cajas" blancas del menú:
float *g_white_box1, *g_white_box2, *g_white_box3;

void TimeInFps(){
  /* Contamos los fps que trascurren y cuando llegan al máximo,
  60, se resetea a 0, servirá para hacer transiciones entre animaciones.*/
 fps_counter == fps ? fps_counter = 0 : fps_counter++;
	if(fps_counter == fps) {seg_counter++;}
}

#include "pablo.cc"
#include "Player.cc"

void BoleanasTeclas(){ //EN ESTE VOID LLAMAMOS A LAS BOOLEANAS QUE INDICAN LA ACTIVACIÓN DE LAS TECLAS
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) != NULL ? g_left = true : g_left = false;
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) != NULL ? g_right = true : g_right = false;
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Up) != NULL ? g_jetpac = true : g_jetpac = false;
  esat::IsKeyPressed(esat::kSpecialKey_Space) != NULL ? g_shoot = true : g_shoot = false;
}

void PreMemorySaved(){
	MemoryForInterface();
	BonusSpriteMemory();
  PlatformsMemoryReserved();
  PlayerMemorySaved();
}
void FreeMemorySaved(){
	FreeMemoryForInterface();
	BonusFreeMemory();
  PlatformsFreeMemory();
  PlayerFreeMemory();
}

void InitializeParametres() {
  InitInterfaceParametres();
	PlatformPositions();
  PlayerInit();
}

void LoadSprites(){
	LoadInterfaceSprites();
	BonusSpritesLoad();
  PlaformsLoadSprites();
  PlayerLoadSprites();
}
void SpritesRelease() {
	ReleaseSpritesForInterface();
}  //LIBERAR AQUÍ LOS SPRITES OSTIA
void DrawingSprites(){
  BonusSpawn(g_gravity);
  PlatformsDraw();
  PlayerDraw();
}  //VAMOH A DIBUJAR

void Collisions () {
  if(str_bonus.coll_bonus == false) { BonusCollision(); }
}


int esat::main(int argc, char **argv) {
	esat::WindowInit(kWindowX,kWindowY);
  PreMemorySaved();
  LoadSprites();
  InitializeParametres();
  
	WindowSetMouseVisibility(true);

    while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

    	last_time = esat::Time();
    	esat::DrawBegin();
    	esat::DrawClear(0,0,0);
        TimeInFps();
	
	PrintScore();

	      switch ( phase ){
		case kGamePhase_Menu:
		  PrintMenu();
		  break;

		case kGamePhase_Intro:
		  PrintIntro();
		  break;

		case kGamePhase_InGame:
		  BoleanasTeclas();
      		  DrawingSprites();
     	          Collisions();
      PlayerFunctions();
		  break;

		case kGamePhase_EndGame:
		  break;
	      }    

    	esat::DrawEnd();

    	//Control fps
    	do{
    		current_time = esat::Time();
    	}while((current_time-last_time)<=1000.0/fps);
    	esat::WindowFrame();
  }
  SpritesRelease();
  FreeMemorySaved();


  esat::WindowDestroy();

  return 0;
}
