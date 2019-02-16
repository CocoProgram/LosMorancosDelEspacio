//x = 500, centro de la nave
esat::SpriteHandle s_fuel;

void LoadFuelSprite(){
  s_fuel = esat::SpriteFromFile("./resources/Sprites/Fuel.png");
}

void ReleaseFuelSprite(){
  esat::SpriteRelease( s_fuel );
}

void InitFuelPosition(){
  if((*str_nave).ship_parts == 3 && (*str_nave).fuel_level < 6 && loadingLevel == false )
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
    if( fuel.is_active && fuel.f_counter > 0 && loadingLevel == false ){
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

void DropFuelToFloor(){
  if(fuel.is_attached && CollisionPlayerEnemy(str_player)==true )
  {
    fuel.pos.y = str_player.posy;
    str_player.can_grab = false;
    fuel.is_attached = false;
    fuel.just_dropped = false;
    fuel.enemy_colision = true;
    
  }else { fuel.enemy_colision = false; }

  if(fuel.enemy_colision)
  {
    FuelMovement();
    fuel.pos.x = str_player.posx;
    //fuel.pos.y += 2;

  }
}

void FuelFallAfterPlayerDies(){
  if( fuel.is_attached && CollisionPlayerEnemy(str_player)==true ){
    if((*str_nave).ship_parts == 3 && (*str_nave).fuel_level < 6 && loadingLevel == false )
    {
      fuel.pos.x = str_player.posx;
      fuel.pos.y = str_player.posy;
      fuel.map_colision = false;
      fuel.is_active = true;
      fuel.is_attached = false;
      fuel.just_dropped = false;
    }
  }
}

void Fuel(){

    if (!fuel.is_active && fuel.f_counter > 0){
      InitFuelPosition();
    }
    DropFuelToFloor();
    DrawFuel();
    FuelColisionWMap();
    FuelMovement();

    //atajo de teclado:
    if ( esat::IsKeyDown('F') ){
      fuel.is_active = false;
      fuel.f_counter--;
    }
}

