#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <esat/window.h>
#include <esat/draw.h>
#include <esat/input.h>
#include <esat/sprite.h>
#include <esat/time.h>
#include <esat_extra/soloud/soloud.h>
#include <esat_extra/soloud/soloud_wav.h>

unsigned char fps = 60; //fps que trascurren en un segundo.
double current_time,last_time;
unsigned char fps_counter = 0; //cuenta los fps que trascurren en un segundo.
unsigned char seg_counter = 0;

const int kWindowX = 768, kWindowY = 576;

//Declaración variables canal audio.
SoLoud::Soloud canal;
SoLoud::Wav audio_disparo, audio_nave, audio_intro;

esat::SpriteHandle *ship_1, *ship_2, *ship_3, *ship_4, *combustion, *ship_pieces_1, *ship_pieces_2, *ship_pieces_3, *ship_pieces_4; // Sprites para nave y combustion
esat::SpriteHandle *Block_sprite_Enemy;//Sprites de los enemigos.
int g_level=1; // De momento pongo esto para saber el nivel en el que estamos, para pasarle los parámetros.
bool newLevel = false; // Usaremos esto para INICIALIZAR enemigos, bonus y fuel
bool loadingLevel = false; // Usaremos esto a TRUE para hacer desaparecer enemigos, etc

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

enum BonusType { kBonusType_0 = 0,
                 kBonusType_1,
                 kBonusType_2,
                 kBonusType_3,
                 kBonusType_4 };

struct TMapa{
  int posx, posy;
  esat::SpriteHandle platform_sprites;
};
TMapa *str_mapa;

#include "platforms.cc"

struct TPlayer{
  float posx, posy;
  esat::SpriteHandle *player_sprites; //Pasar a puntero, son 16
  bool show_player = true, is_flying, is_alive = true;
  bool can_grab = true;
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

struct TPropulsion{
  float posx, posy;
  bool visible =false;
  esat::SpriteHandle *propulsion_sprites;
  int phase_animation;
};
TPropulsion str_propulsion, *str_explo_enemys;

struct TShoot {
 float posx;
 float posy;
 esat::SpriteHandle s_sub_shot;
 float length;
 float right_bullet;
 float distance;
 float speed;
 bool shot;
 bool direction;
 bool collision;
};
TShoot *str_shoot;

struct TEnemy {
  float posx, posy;
  esat:: SpriteHandle *enemy_sprites;
  TPropulsion *my_explo;
  bool is_alive;
  float speedx, speedy;
  int points;
  char colour;
  bool phase_animation;
  int seg_counter = 0;
};
TEnemy *str_enemy;
int g_num_enemy = 4;

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



struct TNave {
  float posx, posy;
  int fuel_level, ship_parts;
};
TNave *str_nave;

struct TPieces{
  float posx, posy;
  bool is_visible=false, is_attached=false;
  bool just_dropped=false;
};
TPieces *str_pieces;

bool g_right, g_left, g_jetpac, g_shoot;
float g_gravity;

struct Tfuel {
  esat::Vec2 pos;
  int f_counter = 6;
  float f_gravity = 2;
  bool is_active = false;
  bool map_colision = false;
  bool ship_colision = false;
  bool player_colision = false;
  bool is_attached = false;
  bool just_dropped = false;
}fuel;

#include "fuel.cc"

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

#include "Explo_Enemys.cc"
#include "pablo.cc"
#include "Player.cc"

#include "bonus.cc"

#include "base_enemy.cc"
#include "peluza.cc"
#include "bola.cc"
#include "avion.cc"
#include "ovni.cc"

#include "controlEnemy.cc" //Debe estar al final de los include de los enemy
#include "rocket.cc"

void BoleanasTeclas(){ //EN ESTE VOID LLAMAMOS A LAS BOOLEANAS QUE INDICAN LA ACTIVACIÓN DE LAS TECLAS
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) != NULL ? g_left = true : g_left = false;
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) != NULL ? g_right = true : g_right = false;
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Up) != NULL ? g_jetpac = true : g_jetpac = false;
  esat::IsKeyPressed(esat::kSpecialKey_Space) != NULL ? g_shoot = true : g_shoot = false;
}

#include "sound.cc"

void PreMemorySaved(){
  LoadShipPointers();
  MemoriaAudio();
  MemoryForInterface();
	BonusSpriteMemory();
  PlatformsMemoryReserved();
  PlayerMemorySaved();
  PropulsionMemorySaved();
  ReservaMemoriaEnemy();
}

void FreeMemorySaved(){
  FreeMemoryShip();

  FreeMemoryForInterface();
	BonusFreeMemory();
  PlatformsFreeMemory();
  PlayerFreeMemory();
  PropulsionFreeMemory();
  LiberarEnemy();
}

void InitializeParametres(){
    InitInterfaceParametres();
  	PlatformPositions();
    PlayerInit();
    PropulsionLoadSprites();
}

void LoadSprites(){
  LoadShipSprites();
  LoadFuelSprite();
  LoadInterfaceSprites();
	BonusSpritesLoad();
  PlaformsLoadSprites();
  PlayerLoadSprites();
}
void SpritesRelease() {
ShipSpritesRelease();
ReleaseFuelSprite();
ReleaseSpritesForInterface();
}

void DrawingSprites(){
  BonusSpawn(g_gravity);
  PlatformsDraw();
  PropulsionDraw();
  PlayerDraw();
}

void Collisions () {
  if(str_bonus.is_alive == true) { BonusCollision(); }
  if(str_player.is_alive == true) { CollisionPlayer(); }
}

int esat::main(int argc, char **argv) {

  canal.init();
	esat::WindowInit(kWindowX,kWindowY);
  WindowSetMouseVisibility(true);
  srand(time(NULL));
  PreMemorySaved();

  LoadSprites();
  InitializeParametres();

  // Esto hay que llamarlo también dentro de InGame en cada nivel que se haga. Por lo tanto esto de aquí abajo se modificará.
  InitializePieces();
  InitializeShip();
  InicializarEnemyLevel();

    while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

    	last_time = esat::Time();
    	esat::DrawBegin();
    	esat::DrawClear(0,0,0);
      TimeInFps();

	      switch (phase){
		case kGamePhase_Menu:
      (audio_intro).stop();
      PrintScore();
      PrintMenu();
		  break;

		case kGamePhase_Intro:
      PlaySound();
      PrintIntro();
		  break;

		case kGamePhase_InGame:
      PrintScore();
		  BoleanasTeclas();
      DrawingSprites();
      PlayerFunctions();
      Collisions();

      Fuel();

      DrawShipPieces(g_level);
      DrawShip(*str_nave,g_level); // Llamar siempre que esté en el juego.
      CatchPieces(*str_nave);
      CatchFuel();
      DropFuel();
      DropCargo();
      PlayerInShip();
      LevelControl();
      ControlEnemyLevel();

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
  canal.deinit();
  esat::WindowDestroy();

  return 0;
}
