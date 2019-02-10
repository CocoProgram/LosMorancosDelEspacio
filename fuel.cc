//x = 500, centro de la nave

esat::SpriteHandle s_fuel;

void LoadFuelSprite(){
  s_fuel = esat::SpriteFromFile("./resources/Sprites/Fuel.png");
}

void ReleaseFuelSprite(){
  esat::SpriteRelease( s_fuel );
}

void InitFuelPosition(){
  if((*str_nave).ship_parts == 3 && (*str_nave).fuel_level < 6 )
  {
    do{
      fuel.pos.x = rand()%(kWindowX - esat::SpriteWidth(s_fuel));
      fuel.pos.y = 0 - esat::SpriteHeight(s_fuel) ;
      // fuel.f_gravity = rand() % 4 + 1;
    }while( (fuel.pos.x + esat::SpriteWidth(s_fuel)) > (500 - 36) && fuel.pos.x < (500 + 36) );
    fuel.map_colision = false;
    fuel.is_active = true;
    fuel.is_attached = false;
    fuel.just_dropped = false;
  }
}

void DrawFuel(){
    if( fuel.is_active && fuel.f_counter > 0){
      if(fuel.is_attached)
      {
        esat::DrawSprite(s_fuel, str_player.posx, str_player.posy);
      }
      else
      {
        esat::DrawSprite(s_fuel, fuel.pos.x, fuel.pos.y);
      }
    }
}

void FuelColisionWMap(){

  for ( int i=0; i<4; i++){

    if ( ( fuel.pos.x > (*(str_mapa + i)).posx && fuel.pos.x < (*(str_mapa + i)).posx + esat::SpriteWidth( (*(str_mapa + i)).platform_sprites) &&
         (fuel.pos.y + esat::SpriteHeight( s_fuel )) >= ((*(str_mapa +i)).posy -1) &&
         (fuel.pos.y + esat::SpriteHeight( s_fuel )) <= ((*(str_mapa +i)).posy +1) ) ||
         ( (fuel.pos.x + esat::SpriteWidth(s_fuel)) > (*(str_mapa + i)).posx &&
         (fuel.pos.x + esat::SpriteWidth(s_fuel)) < (*(str_mapa + i)).posx + esat::SpriteWidth( (*(str_mapa + i)).platform_sprites) &&
         (fuel.pos.y + esat::SpriteHeight( s_fuel )) >= ((*(str_mapa +i)).posy - 1) &&
         (fuel.pos.y + esat::SpriteHeight( s_fuel )) <= ((*(str_mapa +i)).posy + 1)) )
    {
      fuel.map_colision = true;
    }
  }
}

void FuelMovement(){
  if(fuel.is_active && !fuel.map_colision ){
    fuel.pos.y = fuel.pos.y + fuel.f_gravity;
  }
}
/*
void FuelColisionsWPlayer(){
  //izquierda:
  if ( (str_player.posy > fuel.pos.y && (str_player.posy + esat::SpriteHeight( *(str_player.player_sprites) ) ) &&
       (str_player.posx + esat::SpriteWidth(*(str_player.player_sprites) ) )  >= fuel.pos.x &&
       (str_player.posx + esat::SpriteWidth(*(str_player.player_sprites) ) )  <= (fuel.pos.x + 1 ) )|| (
       ((str_player.posy + esat::SpriteHeight( *(str_player.player_sprites) )) > fuel.pos.y &&
       (str_player.posy + esat::SpriteHeight( *(str_player.player_sprites) )) > (fuel.pos.y + esat::SpriteHeight(s_fuel)) &&
       (str_player.posx + esat::SpriteWidth( *(str_player.player_sprites) ) )  >= fuel.pos.x) &&
        (str_player.posx + esat::SpriteWidth( *(str_player.player_sprites) ) ) <= (fuel.pos.x +1)) )
  {
    fuel.player_colision = true;
  }
  if ( fuel.player_colision ){
    fuel.map_colision = false;
    fuel.pos.x = str_player.posx;
    fuel.pos.y = str_player.posy;
    while (fuel.ship_colision) {
      fuel.player_colision = false;
    }
  }
}
void FuelDown(){
  if (fuel.map_colision) {
    fuel.pos.y = fuel.pos.y + fuel.f_gravity;
  }
}
void FuelColisionWShip(){
  if ( fuel.pos.x + (esat::SpriteWidth(s_fuel)/2) >= (500 -2) && fuel.pos.x + (esat::SpriteWidth(s_fuel)/2) <= (500 +2)  ) {
    fuel.player_colision = false;
    FuelDown();
  }
}
*/

void Fuel(){

    if (!fuel.is_active && fuel.f_counter > 0){
      InitFuelPosition();
    }
    DrawFuel();
    FuelColisionWMap();
    FuelMovement();

    //atajo de teclado:
    if ( esat::IsKeyDown('F') ){
      fuel.is_active = false;
      fuel.f_counter--;
    }
}
