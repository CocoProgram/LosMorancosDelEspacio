void ExploEnemyMemorySaved(){
  str_explo_enemys = (TPropulsion*) calloc(5,sizeof(TPropulsion));

  for(int i=0;i<=4;i++){
    (str_explo_enemys+i)->propulsion_sprites = (esat::SpriteHandle*)calloc(4,sizeof(esat::SpriteHandle));
  }
}

void EnemysCreateExplo(TEnemy *enemy){
  bool check = false;
  for (int i=0;i<=4;i++){
    if ((str_explo_enemys+i)->visible==false&&check==false){
    (str_explo_enemys+i)->posx=(*(enemy)).posx;
    (str_explo_enemys+i)->posy=(*(enemy)).posy;
    (str_explo_enemys+i)->visible=true;
    check = true;
	(*(enemy)).my_explo = str_explo_enemys+i;
    }
  }
}

void ExploEnemyAnimations(){
  for (int i=0;i<=4;i++){
    if ((str_explo_enemys+i)->visible){
      if (fps_counter%5==0){
        if((str_explo_enemys+i)->phase_animation==3){
          (str_explo_enemys+i)->visible=false;
          (str_explo_enemys+i)->phase_animation=0;
        }else{(str_explo_enemys+i)->phase_animation++;}
      }
    }
  }
}

void ExploLoadSprites(){
  for(int i=0;i<=4;i++){
    (str_explo_enemys+i)->propulsion_sprites[0] = esat::SpriteFromFile("./resources/Sprites/Explosion_0.png");
    (str_explo_enemys+i)->propulsion_sprites[1] = esat::SpriteFromFile("./resources/Sprites/Explosion_1.png");
    (str_explo_enemys+i)->propulsion_sprites[2] = esat::SpriteFromFile("./resources/Sprites/Explosion_2.png");
    (str_explo_enemys+i)->propulsion_sprites[3] = esat::SpriteFromFile("./resources/Sprites/Explosion_3.png");

  }
}

void DrawExplos(){
  for (int i=0;i<=4;i++){
    if((str_explo_enemys+i)->visible){
      esat::DrawSprite((str_explo_enemys+i)->propulsion_sprites[(str_explo_enemys+i)->phase_animation],(str_explo_enemys+i)->posx,(str_explo_enemys+i)->posy);
    }
  }
}

void ExploEnemyMemoryFree(){
  for(int i=0;i<=4;i++){
    free((str_explo_enemys+i)->propulsion_sprites);
  }
  free(str_explo_enemys);

}
