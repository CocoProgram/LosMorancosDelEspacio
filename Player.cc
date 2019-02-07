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

  if(((player->posy + 49) >= (*str_mapa).posy) && g_jetpac == false){
    player->is_flying=false;
    player->posy=((*str_mapa).posy - 49);
    player->jetpac = 0.0f;
  }else if(player->posy<=0){
    player->posy=0.1f;
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

    player->speed_walk=-3.0f;
  }

  if(g_right){

    player->speed_walk=3.0f;
  }

  if(!g_right && !g_left){

    player->speed_walk=0.0f;
  }

  player->posx+=player->speed_walk;
}

void PlayerAnimations(TPlayer *player){

  int stage=player->direction;

  if(g_left){

    player->direction=0;
  }

  if(g_right){

    player->direction=1;
  }

  if(!player->is_flying){

    if(g_left || g_right){

      if(fps_counter%5==0){
        player->loop++;
      }
    }
  }else{

    stage+=2;

    if(fps_counter%5==0){
      player->loop++;
    }
  }

  if(player->loop==4){

    player->loop=0;
  }

  player->phase_animation=(stage*4)+player->loop;
}

void PlayerMemorySaved(){

  str_player.player_sprites = (esat::SpriteHandle*) calloc (16, sizeof(esat::SpriteHandle));
}

void PlayerFreeMemory(){

  free(str_player.player_sprites);
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
}

void PlayerDraw(){

  esat::DrawSprite(*((str_player.player_sprites)+str_player.phase_animation), str_player.posx, str_player.posy);
}

void PlayerInit(){

  str_player.posx=500;   str_player.posy=500;  str_player.phase_animation=0;
  str_player.speed_walk=0; str_player.loop=0;  str_player.direction=0;
}

void PlayerFunctions(){

  PlayerFlying(&str_player);
  if(str_player.is_flying){
    PlayerFlyingMovement(&str_player);
  }else{
    PlayerGroundMovement(&str_player);
  }
  PlayerMovementLimits(&str_player);
  PlayerAnimations(&str_player);
}

void CollisionPlayer() {
  if ( ( (str_player.posy + 50) > ( (*(str_mapa + 3)).posy +18 ) )
  && ( (str_player.posy - 1) < ( (*(str_mapa + 3)).posy) )
  && ( (str_player.posx + 31) > ( (*(str_mapa + 3)).posx) )
  && ( (str_player.posx) < ( (*(str_mapa + 3)).posx) ) ) {
    str_player.posx -= 0.1f;
    str_player.speed_walk = 0.0f;
    printf (" coll 1 \n ");
  } else if ( ( (str_player.posy + 50) > ( (*(str_mapa + 3)).posy +18 ) )
  && ( (str_player.posy - 1) < ( (*(str_mapa + 3)).posy) )
  && ( (str_player.posx ) < ( (*(str_mapa + 3)).posx + esat::SpriteWidth( (*(str_mapa + 3)).platform_sprites) ) )
  && ( (str_player.posx + 31) > ( (*(str_mapa + 3)).posx + esat::SpriteWidth( (*(str_mapa + 3)).platform_sprites) ) ) ) {
      str_player.posx += 0.1f;
      str_player.speed_walk = 0.0f;
      printf (" coll 2 \n ");
  } else if ( ( (str_player.posy + 50) >= (*(str_mapa + 3)).posy )
  && ( str_player.posy < (*(str_mapa + 3)).posy )
  && ( (str_player.posx + 31) > ( (*(str_mapa + 3)).posx) )
  && ( str_player.posx  < ( (*(str_mapa + 3)).posx + esat::SpriteWidth( (*(str_mapa + 3)).platform_sprites) ) ) ){
    if (g_jetpac == false) {
      str_player.is_flying = false;
      str_player.jetpac = 0.0f;
    }

    str_player.posy = (*(str_mapa + 3)).posy - 50;
  } else if ( ( (str_player.posy - 1) <= ( (*(str_mapa + 3)).posy +18 ) )
  && ( (str_player.posy - 1) >= (*(str_mapa + 3)).posy )
  && ( str_player.posx < ( (*(str_mapa + 3)).posx + esat::SpriteWidth((*(str_mapa + 3)).platform_sprites) ) )
  &&  ( (str_player.posx + 31) > (*(str_mapa + 3)).posx) ) {
      str_player.posy += 0.1f;
      str_player.jetpac = 0.5f;

    } else {
    str_player.is_flying = true;
  }
}

