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
 fps_counter == fps ? fps_counter = 0 : fps_counter++;
	if(fps_counter == fps) {seg_counter++;}
}

void PlayerFlying(TPlayer *player){

  if (player->is_flying) {
    player->posy+=player->jetpac;
      if (player->jetpac<=-5){
        player->jetpac=-5;
      }
      if (player->jetpac>=5){
        player->jetpac=5;
      }
  }else{

    player->jetpac=0;
  }

  if (g_jetpac){
    player->jetpac-=0.25;

    if(!player->is_flying){

      player->posy-=0.25;
      player->is_flying=true;
    }
  }else if (player->is_flying){
    player->jetpac+=0.25;
  }
}

void PlayerMovementLimits(TPlayer *player){

  if(player->posy+esat::SpriteHeight(*((str_player.player_sprites)+str_player.phase_animation))
    >=(*str_mapa).posy){

    player->is_flying=false;
    player->posy=(*str_mapa).posy-esat::SpriteHeight(*((str_player.player_sprites)+str_player.phase_animation));
  }

  if(player->posy<=0){

    player->posy=0.1;
    player->jetpac=0.5;
  }

  if(player->posx>kWindowX){

    player->posx=0-esat::SpriteWidth(*((str_player.player_sprites)+str_player.phase_animation));
  }

  if(player->posx<0-esat::SpriteWidth(*((str_player.player_sprites)+str_player.phase_animation))){

    player->posx=kWindowX;
  }
}

void PlayerFlyingMovement(TPlayer *player){

  if(g_left){

    player->speed_walk-=0.2;
  }else{

    if(player->speed_walk<0){
      player->speed_walk+=0.2;
    }
  }

  if(g_right){

    player->speed_walk+=0.2;
  }else{

    if(player->speed_walk>0){
      player->speed_walk-=0.2;
    }
  }

  if(player->speed_walk>=4){

    player->speed_walk=4;
  }

  if(player->speed_walk<=-4){

    player->speed_walk=-4;
  }

  player->posx+=player->speed_walk;
}

void PlayerGroundMovement(TPlayer *player){

  if(g_left){

    player->speed_walk=-3;
  }

  if(g_right){

    player->speed_walk=3;
  }

  if(!g_right && !g_left){

    player->speed_walk=0;
  }

  player->posx+=player->speed_walk;
}

int CollisionPlayer(TPlayer player, TMapa mapa){
  //De abajo a arriba
  if(player.posy<mapa.posy+esat::SpriteHeight(mapa.platform_sprites)&&
  player.posy>mapa.posy&&
  player.posx+esat::SpriteWidth(*(player.player_sprites+0))>=mapa.posx&&
  player.posx<=mapa.posx+esat::SpriteWidth(mapa.platform_sprites)){
    return 1;
  }
  //De arriba a abajo
  else if(player.posy+esat::SpriteHeight(*(player.player_sprites+0))>mapa.posy&&
  player.posy+esat::SpriteHeight(*(player.player_sprites+0))<mapa.posy+esat::SpriteHeight(mapa.platform_sprites)&&
  player.posx+esat::SpriteWidth((*(player.player_sprites+0)))>=mapa.posx&&
  player.posx<=mapa.posx+esat::SpriteWidth(mapa.platform_sprites)){
    return 2;
  }//De derecha a Izq
  else if(player.posx<mapa.posx+esat::SpriteWidth(mapa.platform_sprites)&&
  player.posx+esat::SpriteWidth((*(player.player_sprites+0)))>mapa.posx+esat::SpriteWidth(mapa.platform_sprites)&&
  player.posy+esat::SpriteHeight((*(player.player_sprites+0)))>mapa.posy&&
  player.posy<mapa.posx+esat::SpriteWidth(mapa.platform_sprites)){
    return 3;
  }
  //De Izq a derecha
  else if(player.posx+esat::SpriteWidth(*(player.player_sprites+0))>mapa.posx&&
  player.posx<mapa.posx&&
  player.posy+esat::SpriteHeight((*(player.player_sprites+0)))>mapa.posy&&
  player.posy<mapa.posx+esat::SpriteWidth(mapa.platform_sprites)){
    return 4;
  }
  //No Colisiona
  else{return 0;}
}

void PreMemorySaved(){
  str_mapa = (TMapa*) calloc (4, sizeof(TMapa));
  str_player.player_sprites = (esat::SpriteHandle*) calloc (8, sizeof(esat::SpriteHandle));
}   //RESERVAR AQUÍ MEMORIA DE PUNTEROS AMORES
void FreeMemorySaved(){
 free(str_mapa);
}  //LIBERAR MEMORIA DE PUNTEROS AQUÍ JOSPDEPUTAS.

void BoleanasTeclas(){ //EN ESTE VOID LLAMAMOS A LAS BOOLEANAS QUE INDICAN LA ACTIVACIÓN DE LAS TECLAS
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) != NULL ? g_left = true : g_left = false;
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) != NULL ? g_right = true : g_right = false;
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Space) != NULL ? g_jetpac = true : g_jetpac = false;
  esat::IsKeyPressed('D') != NULL ? g_shoot = true : g_shoot = false;
}

void LoadSprites() {
  /* M A P A */
  (*str_mapa).platform_sprites = esat::SpriteFromFile("./resources/Sprites/Suelo.png");
  (*(str_mapa + 1)).platform_sprites = esat::SpriteFromFile("./resources/Sprites/Plataforma_Media.png");
  (*(str_mapa + 2)).platform_sprites = esat::SpriteFromFile("./resources/Sprites/Plataforma_Pequenya.png");
  (*(str_mapa + 3)).platform_sprites = esat::SpriteFromFile("./resources/Sprites/Plataforma_Grande.png");

  /*PLAYER*/
  *(str_player.player_sprites) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_0.png");
  *((str_player.player_sprites)+1) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_1.png");
  *((str_player.player_sprites)+2) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_2.png");
  *((str_player.player_sprites)+3) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_3.png");
  *((str_player.player_sprites)+4) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_0.png");
  *((str_player.player_sprites)+5) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_1.png");
  *((str_player.player_sprites)+6) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_2.png");
  *((str_player.player_sprites)+7) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_3.png");
}   //CARGAR AQUÍ SPRITES CHICAS
void SpritesRelease() {
 /* M A P A */
 esat::SpriteRelease((*str_mapa).platform_sprites);
 esat::SpriteRelease((*(str_mapa + 1)).platform_sprites);
 esat::SpriteRelease((*(str_mapa + 2)).platform_sprites);
 esat::SpriteRelease((*(str_mapa + 3)).platform_sprites);

 /*PLAYER*/
 esat::SpriteRelease(*(str_player.player_sprites));
 esat::SpriteRelease(*((str_player.player_sprites)+1));
 esat::SpriteRelease(*((str_player.player_sprites)+2));
 esat::SpriteRelease(*((str_player.player_sprites)+3));
 esat::SpriteRelease(*((str_player.player_sprites)+4));
 esat::SpriteRelease(*((str_player.player_sprites)+5));
 esat::SpriteRelease(*((str_player.player_sprites)+6));
 esat::SpriteRelease(*((str_player.player_sprites)+7));
}  //LIBERAR AQUÍ LOS SPRITES OSTIA
void DrawingSprites(){
  /* M A P A */
 esat::DrawSprite((*str_mapa).platform_sprites, (*str_mapa).posx, (*str_mapa).posy);
 esat::DrawSprite((*(str_mapa + 1)).platform_sprites, (*(str_mapa + 1)).posx , (*(str_mapa + 1)).posy );
 esat::DrawSprite((*(str_mapa + 2)).platform_sprites, (*(str_mapa + 2)).posx , (*(str_mapa + 2)).posy);
 esat::DrawSprite((*(str_mapa + 3)).platform_sprites, (*(str_mapa + 3)).posx , (*(str_mapa + 3)).posy );

  /*PLAYER*/

 esat::DrawSprite(*((str_player.player_sprites)+str_player.phase_animation), str_player.posx, str_player.posy);
}  //VAMOH A DIBUJAR

void PlayerFunctions(){

  PlayerFlying(&str_player);
  if(str_player.is_flying){
    PlayerFlyingMovement(&str_player);
  }else{
    PlayerGroundMovement(&str_player);
  }
  PlayerMovementLimits(&str_player);
}

void CollisionFunctions(){
  for(int i=0;i<=3;i++){
    CollisionPlayer(str_player,*(str_mapa+i));
  }
}

void InitializeParametres(){
 /* M A P A */
 (*str_mapa).posx = 0;           (*str_mapa).posy = 555;
 (*(str_mapa + 1)).posx = 98;   (*(str_mapa + 1)).posy = 219;
 (*(str_mapa + 2)).posx = 363;   (*(str_mapa + 2)).posy = 292;
 (*(str_mapa + 3)).posx = 580;   (*(str_mapa + 3)).posy = 147;

 /*PLAYER*/
 str_player.posx=500;   str_player.posy=500;  str_player.phase_animation=0;
 str_player.speed_walk=0;

} //INICIAR TODAS LAS VARIABLES AQUÍ ANTES DEL BUCLE WHILE



int esat::main(int argc, char **argv) {
	esat::WindowInit(kWindowX,kWindowY);

  PreMemorySaved();
  InitializeParametres();
  LoadSprites();

	WindowSetMouseVisibility(true);

    while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

    	last_time = esat::Time();
    	esat::DrawBegin();
    	esat::DrawClear(0,0,0);
      TimeInFps();

			BoleanasTeclas();
      PlayerFunctions();
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
