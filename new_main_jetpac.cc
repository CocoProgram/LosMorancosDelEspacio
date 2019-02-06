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

bool g_right, g_left, g_jetpac, g_shoot;
float g_gravity;

void TimeInFps(){
  /* Contamos los fps que trascurren y cuando llegan al máximo,
  60, se resetea a 0, servirá para hacer transiciones entre animaciones.*/
 fps_counter == fps ? fps_counter = 0 : fps_counter++;
	if(fps_counter == fps) {seg_counter++;}
}

void BoleanasTeclas(){ //EN ESTE VOID LLAMAMOS A LAS BOOLEANAS QUE INDICAN LA ACTIVACIÓN DE LAS TECLAS
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Left) != NULL ? g_left = true : g_left = false;
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Right) != NULL ? g_right = true : g_right = false;
  esat::IsSpecialKeyPressed(esat::kSpecialKey_Space) != NULL ? g_jetpac = true : g_jetpac = false;
  esat::IsKeyPressed('D') != NULL ? g_shoot = true : g_shoot = false;
}

void PreMemorySaved(){

}
void FreeMemorySaved(){

}

void LoadSprites(){

}
void SpritesRelease() {

}  //LIBERAR AQUÍ LOS SPRITES OSTIA
void DrawingSprites(){

}  //VAMOH A DIBUJAR


int esat::main(int argc, char **argv) {
	esat::WindowInit(kWindowX,kWindowY);
  LoadSprites();
  
	WindowSetMouseVisibility(true);

    while(esat::WindowIsOpened() && !esat::IsSpecialKeyDown(esat::kSpecialKey_Escape)) {

    	last_time = esat::Time();
    	esat::DrawBegin();
    	esat::DrawClear(0,0,0);
      TimeInFps();

			BoleanasTeclas();
      DrawingSprites();

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
