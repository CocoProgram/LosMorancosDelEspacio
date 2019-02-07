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
  }

  if(g_right){

    player->speed_walk+=0.2;
  }

  if(!g_right && !g_left){

    if(player->speed_walk>0){
      player->speed_walk-=0.1;
    }else{
       player->speed_walk+=0.1;
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
