#include "colicionplayerenemy.cc"

const int laser_quantity = 10;

void PlasmaLasers(TPlayer *player){

  bool  found=false;

  if(g_shoot){

    for(int i=0;i<laser_quantity;++i){
      if(!found && !(str_shoot+i)->shot){

        (str_shoot+i)->posy=player->posy+(esat::SpriteHeight(*((player->player_sprites)+player->phase_animation))/2)-2;
        (str_shoot+i)->speed=24;
        (str_shoot+i)->distance=0;
        (str_shoot+i)->direction=player->direction;
        (str_shoot+i)->length=0;
        (str_shoot+i)->collision=false;
        if(!(str_shoot+i)->direction){

          (str_shoot+i)->posx=player->posx;
        }else{

          (str_shoot+i)->posx=player->posx+31;
          (str_shoot+i)->right_bullet=288;
        }
        (str_shoot+i)->shot=true;
        found=true;
      }
    }

  }
}

void DrawLasers(int i){

  if((str_shoot+i)->shot){
     
     if(!(str_shoot+i)->direction){
      (str_shoot+i)->s_sub_shot = esat::SubSprite(*(s_shots+(str_shoot+i)->direction),0,0
    ,(str_shoot+i)->length,esat::SpriteHeight(*s_shots));
      esat::DrawSprite((str_shoot+i)->s_sub_shot,(str_shoot+i)->posx,(str_shoot+i)->posy);
    }else{
       (str_shoot+i)->s_sub_shot = esat::SubSprite(*(s_shots+(str_shoot+i)->direction),str_shoot->right_bullet,0
    ,(str_shoot+i)->length,esat::SpriteHeight(*s_shots));
       esat::DrawSprite((str_shoot+i)->s_sub_shot,(str_shoot+i)->posx-(str_shoot+i)->length,(str_shoot+i)->posy);
    }
  }
}

void LaserMovement(TPlayer *player){

  for(int i=0;i<laser_quantity;++i){

    if((str_shoot+i)->shot){

      if((str_shoot+i)->posx>0 && (str_shoot+i)->posx<kWindowX){
        (str_shoot+i)->distance+=(str_shoot+i)->speed;
      }

      if(!(str_shoot+i)->direction){

        if((str_shoot+i)->distance<kWindowX*0.75 && !(str_shoot+i)->collision){

          (str_shoot+i)->posx-=(str_shoot+i)->speed; 
        }

        if(((str_shoot+i)->distance>=kWindowX*0.75 || (str_shoot+i)->collision) && (str_shoot+i)->length>0){
          (str_shoot+i)->length-=(str_shoot+i)->speed;
        }

        if(((str_shoot+i)->distance>=kWindowX*0.75 || (str_shoot+i)->collision) && (str_shoot+i)->length<=0){
          (str_shoot+i)->shot=false;
        }

        if((str_shoot+i)->length<esat::SpriteWidth(*s_shots) && ((str_shoot+i)->distance<kWindowX*0.75 && !(str_shoot+i)->collision)){

          (str_shoot+i)->length+=(str_shoot+i)->speed; 
        }

        if((str_shoot+i)->length>esat::SpriteWidth(*s_shots)){

          (str_shoot+i)->length=esat::SpriteWidth(*s_shots);
        }
        
        if((str_shoot+i)->posx<-144){

          (str_shoot+i)->posx=kWindowX+144;
        }

      }else{

        if((str_shoot+i)->distance<kWindowX*0.75 && !(str_shoot+i)->collision){

          (str_shoot+i)->posx+=(str_shoot+i)->speed; 
        }

        if(((str_shoot+i)->distance>=kWindowX*0.75 || (str_shoot+i)->collision) && (str_shoot+i)->length>0){
          (str_shoot+i)->length-=(str_shoot+i)->speed;
          (str_shoot+i)->right_bullet+=(str_shoot+i)->speed;
        }

        if(((str_shoot+i)->distance>=kWindowX*0.75 || (str_shoot+i)->collision) && (str_shoot+i)->length<=0){
          (str_shoot+i)->shot=false;
        }

        if((str_shoot+i)->length<esat::SpriteWidth(*s_shots) && (str_shoot+i)->distance<kWindowX*0.75 && !(str_shoot+i)->collision){

          (str_shoot+i)->length+=(str_shoot+i)->speed;
          (str_shoot+i)->right_bullet-=(str_shoot+i)->speed;
        }

        if((str_shoot+i)->length>esat::SpriteWidth(*s_shots)){

          (str_shoot+i)->length=esat::SpriteWidth(*s_shots);
        }
        
        if((str_shoot+i)->posx>kWindowX+144){

        (str_shoot+i)->posx=-144;
        }
      }
    }

    if(CollisionBullet(*(str_shoot+i)) && str_shoot->shot && !str_shoot->collision){
      str_shoot->collision=true;
    }
    DrawLasers(i);
  }
}

void PlayerCreatePropulsion(){
    if(!(str_player.is_flying)&&g_jetpac&&str_propulsion.visible==false){
      str_propulsion.posx=str_player.posx-5;
      str_propulsion.posy=str_player.posy + 15;
      str_propulsion.visible=true;
    }
}

void PlayerFlying(TPlayer *player){

  if (player->is_flying) {
    player->posy+=player->jetpac;
      if (player->jetpac<=-5){
        player->jetpac=-5;
      }
      if (player->jetpac>=5){
        player->jetpac=5.0f;
      }
  }else{
    player->jetpac=0;
  }

  if (g_jetpac){

    player->jetpac-=0.25f;
    if(!player->is_flying){
      player->is_flying=true;
    }
  }else if (player->is_flying){
    player->jetpac+=0.25f;
  }
}

void PlayerMovementLimits(TPlayer *player){

if(player->posy<=65){
    player->posy=65.1f;
    player->jetpac=0.5f;
  }

  if(player->posx > kWindowX){
    player->posx=0-esat::SpriteWidth(*((str_player.player_sprites)+str_player.phase_animation));
  } else if(player->posx < (-esat::SpriteWidth(*((str_player.player_sprites)+str_player.phase_animation) ) ) ){
    player->posx=kWindowX;
  }
}

void PlayerFlyingMovement(TPlayer *player){

  if(g_left){

    player->speed_walk-=0.2f;
  }

  if(g_right){

    player->speed_walk+=0.2f;
  }

  if(!g_right && !g_left){

    if(player->speed_walk>0){
      player->speed_walk-=0.1f;
    }else{
       player->speed_walk+=0.1f;
    }
  }

  if(player->speed_walk>=5){

    player->speed_walk=5;
  }

  if(player->speed_walk<=-5){

    player->speed_walk=-5;
  }

  player->posx+=player->speed_walk;
}

void PlayerGroundMovement(TPlayer *player){

  if(g_left) { player->speed_walk=-3.0f; }
  if(g_right) { player->speed_walk=3.0f; }
  if(!g_right && !g_left) { player->speed_walk=0.0f; }

  player->posx+=player->speed_walk;
}

void PlayerAnimations(TPlayer *player){

  int stage=player->direction;

  if(g_left) { player->direction=0; }
  if(g_right){ player->direction=1; }
  if(!player->is_flying)
  {
    if(g_left || g_right)
    {
      if(fps_counter%3==0)
      {
        player->loop++;
      }
    }
  }
  else
  {
    stage+=2;
    if(fps_counter%3==0)
    {
      player->loop++;
    }
  }

  if(player->loop==4){ player->loop=0; }

  player->phase_animation=(stage*4)+player->loop;
}

void PropulsionAnimations(TPropulsion *propulsion){
  if (propulsion->visible){
    if (fps_counter%5==0){
      if(propulsion->phase_animation==3){
        propulsion->visible=false;
        propulsion->phase_animation=0;
      }else{propulsion->phase_animation++;}
    }
  }
}

void PlayerMemorySaved(){

  str_player.player_sprites = (esat::SpriteHandle*) calloc (16, sizeof(esat::SpriteHandle));

  str_shoot = (TShoot*) calloc (laser_quantity,sizeof(TShoot));

  s_shots = (esat::SpriteHandle*) calloc(2,sizeof(esat::SpriteHandle));
}

void PlayerFreeMemory(){

  free(str_player.player_sprites);

  free(str_shoot);

  free(s_shots);
}

void PlayerLoadSprites(){

  *(str_player.player_sprites) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_0.png");
  *((str_player.player_sprites)+1) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_1.png");
  *((str_player.player_sprites)+2) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_2.png");
  *((str_player.player_sprites)+3) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_3.png");
  *((str_player.player_sprites)+4) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_4.png");
  *((str_player.player_sprites)+5) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_5.png");
  *((str_player.player_sprites)+6) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_6.png");
  *((str_player.player_sprites)+7) = esat::SpriteFromFile("./resources/Sprites/Astronauta_walk_7.png");
  *((str_player.player_sprites)+8) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_0.png");
  *((str_player.player_sprites)+9) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_1.png");
  *((str_player.player_sprites)+10) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_2.png");
  *((str_player.player_sprites)+11) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_3.png");
  *((str_player.player_sprites)+12) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_4.png");
  *((str_player.player_sprites)+13) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_5.png");
  *((str_player.player_sprites)+14) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_6.png");
  *((str_player.player_sprites)+15) = esat::SpriteFromFile("./resources/Sprites/Astronauta_JetPac_7.png");

  *s_shots = esat::SpriteFromFile("./resources/Sprites/Disparo_I.png");
  *(s_shots+1) = esat::SpriteFromFile("./resources/Sprites/Disparo_D.png");
}

void PropulsionMemorySaved(){
  str_propulsion.propulsion_sprites = (esat::SpriteHandle*) calloc (4, sizeof(esat::SpriteHandle));
}

void PropulsionLoadSprites(){
  *(str_propulsion.propulsion_sprites) = esat::SpriteFromFile("./resources/Sprites/Explosion_0.png");
  *((str_propulsion.propulsion_sprites)+1) = esat::SpriteFromFile("./resources/Sprites/Explosion_1.png");
  *((str_propulsion.propulsion_sprites)+2) = esat::SpriteFromFile("./resources/Sprites/Explosion_2.png");
  *((str_propulsion.propulsion_sprites)+3) = esat::SpriteFromFile("./resources/Sprites/Explosion_3.png");

}

void PropulsionDraw(){
  if(str_propulsion.visible && str_player.show_player){
    esat::DrawSprite(*((str_propulsion.propulsion_sprites)+str_propulsion.phase_animation), str_propulsion.posx, str_propulsion.posy);
  }
}

void PropulsionFreeMemory(){

  free(str_propulsion.propulsion_sprites);
}

void PlayerDraw(){
  if(str_player.show_player)
  {
    esat::DrawSprite(*((str_player.player_sprites)+str_player.phase_animation), str_player.posx, str_player.posy);
  }
}

void PlayerInit(){

  str_player.posx=450;   str_player.posy=500;  str_player.phase_animation=0;
  str_player.speed_walk=0; str_player.loop=0;  str_player.direction=0;
  str_player.show_player = true; str_player.can_grab = true;

  for(int i=0;i<laser_quantity;++i) {
    (str_shoot+i)->shot=false;
  }
}

void PlayerFunctions(){

  if(str_player.show_player){
    PlayerCreatePropulsion();
    PlayerFlying(&str_player);
    if(str_player.is_flying){
      PlayerFlyingMovement(&str_player);
    }else{
      PlayerGroundMovement(&str_player);
    }
    PlayerMovementLimits(&str_player);
    PlayerAnimations(&str_player);
    PropulsionAnimations(&str_propulsion);
    PlasmaLasers(&str_player);
    LaserMovement(&str_player);
  }
}

void CollisionPlayer() {
  for(int i=0;i<=3;i++){
    if ( ( (str_player.posy + 50) > ( (*(str_mapa + i)).posy +18 ) )
    && ( (str_player.posy - 1) < ( (*(str_mapa + i)).posy) )
    && ( (str_player.posx + 31) > ( (*(str_mapa + i)).posx) )
    && ( (str_player.posx) < ( (*(str_mapa + i)).posx) ) ) {
      str_player.posx -= 0.1f;
      str_player.speed_walk = 0.0f;

    } else if ( ( (str_player.posy + 50) > ( (*(str_mapa + i)).posy +18 ) )
    && ( (str_player.posy - 1) < ( (*(str_mapa + i)).posy) )
    && ( (str_player.posx ) < ( (*(str_mapa + i)).posx + esat::SpriteWidth( (*(str_mapa + i)).platform_sprites) ) )
    && ( (str_player.posx + 31) > ( (*(str_mapa + i)).posx + esat::SpriteWidth( (*(str_mapa + i)).platform_sprites) ) ) ) {
        str_player.posx += 0.1f;
        str_player.speed_walk = 0.0f;

    } else if ( ( (str_player.posy + 50) >= (*(str_mapa + i)).posy )
    && ( str_player.posy < (*(str_mapa + i)).posy )
    && ( (str_player.posx + 31) > ( (*(str_mapa + i)).posx) )
    && ( str_player.posx  < ( (*(str_mapa + i)).posx + esat::SpriteWidth( (*(str_mapa + i)).platform_sprites) ) ) ){

      if (g_jetpac == false) {
        str_player.is_flying = false;
        str_player.jetpac = 0.0f;
      }

      str_player.posy = (*(str_mapa + i)).posy - 50;
    } else if ( ( (str_player.posy - 1) <= ( (*(str_mapa + i)).posy +18 ) )
    && ( (str_player.posy - 1) >= (*(str_mapa + i)).posy )
    && ( str_player.posx < ( (*(str_mapa + i)).posx + esat::SpriteWidth((*(str_mapa + i)).platform_sprites) ) )
    &&  ( (str_player.posx + 31) > (*(str_mapa + i)).posx) ) {
        str_player.posy += 0.1f;
        str_player.jetpac = 0.5f;

      }else if (i==0) { //JC MAGIC :)
        str_player.is_flying = true;
    }
  }
}
