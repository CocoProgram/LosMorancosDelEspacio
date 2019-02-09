
void LoadShipPointers() { // Poner en el main de load pointers ( o no)
  str_nave = (TNave*) calloc (1, sizeof(TNave)); // Crearemos sólo un elemento a la vez.
  str_pieces = (TPieces*) calloc (3, sizeof(TPieces)); // Crearemos tres elementos a la vez

  ship_pieces_1 = (esat::SpriteHandle*) calloc (3,sizeof(esat::SpriteHandle));
  ship_pieces_2 = (esat::SpriteHandle*) calloc (3,sizeof(esat::SpriteHandle));
  ship_pieces_3 = (esat::SpriteHandle*) calloc (3,sizeof(esat::SpriteHandle));
  ship_pieces_4 = (esat::SpriteHandle*) calloc (3,sizeof(esat::SpriteHandle));

  ship_1 = (esat::SpriteHandle*) calloc (8,sizeof(esat::SpriteHandle));
  ship_2 = (esat::SpriteHandle*) calloc (8,sizeof(esat::SpriteHandle));
  ship_3 = (esat::SpriteHandle*) calloc (8,sizeof(esat::SpriteHandle));
  ship_4 = (esat::SpriteHandle*) calloc (8,sizeof(esat::SpriteHandle));
  combustion = (esat::SpriteHandle*) calloc (2,sizeof(esat::SpriteHandle));
}

// Poner en el main de liberar memoria
void FreeMemoryShip(){
  free(str_nave); // El free nave lo haremos cada vez que se complete una fase, el jugador muera, etc
  free(str_pieces); // El free pieces lo haremos cada vez que se complete una fase, el jugador muera, o cuando todas hayan sido colocadas.

  free(ship_pieces_1);
  free(ship_pieces_2);
  free(ship_pieces_3);
  free(ship_pieces_4);

  free(ship_1);
  free(ship_2);
  free(ship_3);
  free(ship_4);
  free(combustion);
}

// Cargar los sprites que utilizaremos
void LoadShipSprites() {

  *(ship_pieces_1) = esat::SpriteFromFile("./resources/Sprites/ship/1_Piece_0.png");
  *(ship_pieces_1 + 1) = esat::SpriteFromFile("./resources/Sprites/ship/1_Piece_1.png");
  *(ship_pieces_1 + 2) = esat::SpriteFromFile("./resources/Sprites/ship/1_Piece_2.png");

  *(ship_pieces_2) = esat::SpriteFromFile("./resources/Sprites/ship/2_Piece_0.png");
  *(ship_pieces_2 + 1) = esat::SpriteFromFile("./resources/Sprites/ship/2_Piece_1.png");
  *(ship_pieces_2 + 2) = esat::SpriteFromFile("./resources/Sprites/ship/2_Piece_2.png");

  *(ship_pieces_3) = esat::SpriteFromFile("./resources/Sprites/ship/3_Piece_0.png");
  *(ship_pieces_3 + 1) = esat::SpriteFromFile("./resources/Sprites/ship/3_Piece_1.png");
  *(ship_pieces_3 + 2) = esat::SpriteFromFile("./resources/Sprites/ship/3_Piece_2.png");

  *(ship_pieces_4) = esat::SpriteFromFile("./resources/Sprites/ship/4_Piece_0.png");
  *(ship_pieces_4 + 1) = esat::SpriteFromFile("./resources/Sprites/ship/4_Piece_1.png");
  *(ship_pieces_4 + 2) = esat::SpriteFromFile("./resources/Sprites/ship/4_Piece_2.png");

  *(ship_1) = esat::SpriteFromFile("./resources/Sprites/ship/1_Half.png");
  *(ship_1 + 1) = esat::SpriteFromFile("./resources/Sprites/ship/1_Full.png");
  *(ship_1 + 2) = esat::SpriteFromFile("./resources/Sprites/ship/1_Fueled_1.png");
  *(ship_1 + 3) = esat::SpriteFromFile("./resources/Sprites/ship/1_Fueled_2.png");
  *(ship_1 + 4) = esat::SpriteFromFile("./resources/Sprites/ship/1_Fueled_3.png");
  *(ship_1 + 5) = esat::SpriteFromFile("./resources/Sprites/ship/1_Fueled_4.png");
  *(ship_1 + 6) = esat::SpriteFromFile("./resources/Sprites/ship/1_Fueled_5.png");
  *(ship_1 + 7) = esat::SpriteFromFile("./resources/Sprites/ship/1_Fueled_6.png");

  *(ship_2) = esat::SpriteFromFile("./resources/Sprites/ship/2_Half.png");
  *(ship_2 + 1) = esat::SpriteFromFile("./resources/Sprites/ship/2_Full.png");
  *(ship_2 + 2) = esat::SpriteFromFile("./resources/Sprites/ship/2_Fueled_1.png");
  *(ship_2 + 3) = esat::SpriteFromFile("./resources/Sprites/ship/2_Fueled_2.png");
  *(ship_2 + 4) = esat::SpriteFromFile("./resources/Sprites/ship/2_Fueled_3.png");
  *(ship_2 + 5) = esat::SpriteFromFile("./resources/Sprites/ship/2_Fueled_4.png");
  *(ship_2 + 6) = esat::SpriteFromFile("./resources/Sprites/ship/2_Fueled_5.png");
  *(ship_2 + 7) = esat::SpriteFromFile("./resources/Sprites/ship/2_Fueled_6.png");

  *(ship_3) = esat::SpriteFromFile("./resources/Sprites/ship/3_Half.png");
  *(ship_3 + 1) = esat::SpriteFromFile("./resources/Sprites/ship/3_Full.png");
  *(ship_3 + 2) = esat::SpriteFromFile("./resources/Sprites/ship/3_Fueled_1.png");
  *(ship_3 + 3) = esat::SpriteFromFile("./resources/Sprites/ship/3_Fueled_2.png");
  *(ship_3 + 4) = esat::SpriteFromFile("./resources/Sprites/ship/3_Fueled_3.png");
  *(ship_3 + 5) = esat::SpriteFromFile("./resources/Sprites/ship/3_Fueled_4.png");
  *(ship_3 + 6) = esat::SpriteFromFile("./resources/Sprites/ship/3_Fueled_5.png");
  *(ship_3 + 7) = esat::SpriteFromFile("./resources/Sprites/ship/3_Fueled_6.png");

  *(ship_4) = esat::SpriteFromFile("./resources/Sprites/ship/4_Half.png");
  *(ship_4 + 1) = esat::SpriteFromFile("./resources/Sprites/ship/4_Full.png");
  *(ship_4 + 2) = esat::SpriteFromFile("./resources/Sprites/ship/4_Fueled_1.png");
  *(ship_4 + 3) = esat::SpriteFromFile("./resources/Sprites/ship/4_Fueled_2.png");
  *(ship_4 + 4) = esat::SpriteFromFile("./resources/Sprites/ship/4_Fueled_3.png");
  *(ship_4 + 5) = esat::SpriteFromFile("./resources/Sprites/ship/4_Fueled_4.png");
  *(ship_4 + 6) = esat::SpriteFromFile("./resources/Sprites/ship/4_Fueled_5.png");
  *(ship_4 + 7) = esat::SpriteFromFile("./resources/Sprites/ship/4_Fueled_6.png");

  *(combustion) = esat::SpriteFromFile("./resources/Sprites/ship/Fire_0.png");
  *(combustion + 1) = esat::SpriteFromFile("./resources/Sprites/ship/Fire_1.png");
}

// Esto sólo lo usaremos al EMPEZAR cada 6 niveles
void DrawShipPieces(int lvl) {
  if(lvl == 1)
  {
    if((*str_pieces).is_visible) { esat::DrawSprite((*ship_pieces_1), (*str_pieces).posx, (*str_pieces).posy); } // Para acceder al primero, que es LA BASE
    if((*(str_pieces + 1)).is_visible) // Para acceder al la PUNTA del cohete
    {
      if( (*(str_pieces + 1)).is_attached)
      {
        (*(str_pieces + 1)).posx = str_player.posx;
        (*(str_pieces + 1)).posy = str_player.posy;
        esat::DrawSprite((*(ship_pieces_1 + 1)), (*(str_pieces + 1)).posx, (*(str_pieces + 1)).posy);
      }
      else{
        esat::DrawSprite((*(ship_pieces_1 + 1)), (*(str_pieces + 1)).posx, (*(str_pieces + 1)).posy);
      }
    }

    if((*(str_pieces + 2)).is_visible) // Para acceder al la parte INTERMEDIA del cohete
    {
      if( (*(str_pieces + 2)).is_attached)
      {
        (*(str_pieces + 2)).posx = str_player.posx;
        (*(str_pieces + 2)).posy = str_player.posy;
        esat::DrawSprite((*(ship_pieces_1 + 2)), (*(str_pieces + 2)).posx, (*(str_pieces + 2)).posy);
      }
      else{
        esat::DrawSprite((*(ship_pieces_1 + 2)), (*(str_pieces + 2)).posx, (*(str_pieces + 2)).posy);
      }
    }
  }
  if(lvl == 7)
  {
    if((*str_pieces).is_visible) { esat::DrawSprite((*ship_pieces_2), (*str_pieces).posx, (*str_pieces).posy); }
    if((*(str_pieces + 1)).is_visible)
    {
      if( (*(str_pieces + 1)).is_attached)
      {
        (*(str_pieces + 1)).posx = str_player.posx;
        (*(str_pieces + 1)).posy = str_player.posy;
        esat::DrawSprite((*(ship_pieces_2 + 1)), (*(str_pieces + 1)).posx, (*(str_pieces + 1)).posy);
      }
      else{
        esat::DrawSprite((*(ship_pieces_2 + 1)), (*(str_pieces + 1)).posx, (*(str_pieces + 1)).posy);
      }
    }

    if((*(str_pieces + 2)).is_visible)
    {
      if( (*(str_pieces + 2)).is_attached)
      {
        (*(str_pieces + 2)).posx = str_player.posx;
        (*(str_pieces + 2)).posy = str_player.posy;
        esat::DrawSprite((*(ship_pieces_2 + 2)), (*(str_pieces + 2)).posx, (*(str_pieces + 2)).posy);
      }
      else{
        esat::DrawSprite((*(ship_pieces_2 + 2)), (*(str_pieces + 2)).posx, (*(str_pieces + 2)).posy);
      }
    }
  }
  if(lvl == 13)
  {
    if((*str_pieces).is_visible) { esat::DrawSprite((*ship_pieces_3), (*str_pieces).posx, (*str_pieces).posy); }
    if((*(str_pieces + 1)).is_visible)
    {
      if( (*(str_pieces + 1)).is_attached)
      {
        (*(str_pieces + 1)).posx = str_player.posx;
        (*(str_pieces + 1)).posy = str_player.posy;
        esat::DrawSprite((*(ship_pieces_3 + 1)), (*(str_pieces + 1)).posx, (*(str_pieces + 1)).posy);
      }
      else{
        esat::DrawSprite((*(ship_pieces_3 + 1)), (*(str_pieces + 1)).posx, (*(str_pieces + 1)).posy);
      }
    }

    if((*(str_pieces + 2)).is_visible) // Para acceder al la parte INTERMEDIA del cohete
    {
      if( (*(str_pieces + 2)).is_attached)
      {
        (*(str_pieces + 2)).posx = str_player.posx;
        (*(str_pieces + 2)).posy = str_player.posy;
        esat::DrawSprite((*(ship_pieces_3 + 2)), (*(str_pieces + 2)).posx, (*(str_pieces + 2)).posy);
      }
      else{
        esat::DrawSprite((*(ship_pieces_3 + 2)), (*(str_pieces + 2)).posx, (*(str_pieces + 2)).posy);
      }
    }
  }
  if(lvl == 19)
  {
    if((*str_pieces).is_visible) { esat::DrawSprite((*ship_pieces_4), (*str_pieces).posx, (*str_pieces).posy); }
    if((*(str_pieces + 1)).is_visible)
    {
      if( (*(str_pieces + 1)).is_attached)
      {
        (*(str_pieces + 1)).posx = str_player.posx;
        (*(str_pieces + 1)).posy = str_player.posy;
        esat::DrawSprite((*(ship_pieces_4 + 1)), (*(str_pieces + 1)).posx, (*(str_pieces + 1)).posy);
      }
      else{
        esat::DrawSprite((*(ship_pieces_4 + 1)), (*(str_pieces + 1)).posx, (*(str_pieces + 1)).posy);
      }
    }

    if((*(str_pieces + 2)).is_visible) // Para acceder al la parte INTERMEDIA del cohete
    {
      if( (*(str_pieces + 2)).is_attached)
      {
        (*(str_pieces + 2)).posx = str_player.posx;
        (*(str_pieces + 2)).posy = str_player.posy;
        esat::DrawSprite((*(ship_pieces_4 + 2)), (*(str_pieces + 2)).posx, (*(str_pieces + 2)).posy);
      }
      else{
        esat::DrawSprite((*(ship_pieces_4 + 2)), (*(str_pieces + 2)).posx, (*(str_pieces + 2)).posy);
      }
    }
  }
}

void DrawShip(TNave ship, int lvl){

  int fuel = ship.fuel_level; // Esto lo coge BIEN
  int parts = ship.ship_parts;

  // printf("PART: %d \n",parts );
  // printf("FUEL: %d \n",fuel );

  if(ship.ship_parts == 2)
  {
    // Cuando ship_parts sea de 2, aumentar la posy en 36
    if(lvl <= 6) { esat::DrawSprite((*ship_1), ship.posx, ship.posy-36); }
    if(lvl > 6 && lvl <= 12) { esat::DrawSprite((*ship_2), ship.posx, ship.posy-36); }
    if(lvl > 12 && lvl <= 18) { esat::DrawSprite((*ship_3), ship.posx, ship.posy-36); }
    if(lvl > 18 && lvl <= 24) { esat::DrawSprite((*ship_4), ship.posx, ship.posy-36); }
  }
  if(ship.ship_parts == 3)
  {
    switch (fuel) {
      case 0:
      if(lvl <= 6) { esat::DrawSprite((*(ship_1 + 1)), ship.posx, ship.posy-72); }
      if(lvl > 6 && lvl <= 12) { esat::DrawSprite((*(ship_2 + 1)), ship.posx, ship.posy-72); }
      if(lvl > 12 && lvl <= 18) { esat::DrawSprite((*(ship_3 + 1)), ship.posx, ship.posy-72); }
      if(lvl > 18 && lvl <= 24) { esat::DrawSprite((*(ship_4 + 1)), ship.posx, ship.posy-72); }
      break;
      case 1:
      if(lvl <= 6) { esat::DrawSprite((*(ship_1 + 2)), ship.posx, ship.posy-72); }
      if(lvl > 6 && lvl <= 12) { esat::DrawSprite((*(ship_2 + 2)), ship.posx, ship.posy-72); }
      if(lvl > 12 && lvl <= 18) { esat::DrawSprite((*(ship_3 + 2)), ship.posx, ship.posy-72); }
      if(lvl > 18 && lvl <= 24) { esat::DrawSprite((*(ship_4 + 2)), ship.posx, ship.posy-72); }
      break;
      case 2:
      if(lvl <= 6) { esat::DrawSprite((*(ship_1 + 3)), ship.posx, ship.posy-72); }
      if(lvl > 6 && lvl <= 12) { esat::DrawSprite((*(ship_2 + 3)), ship.posx, ship.posy-72); }
      if(lvl > 12 && lvl <= 18) { esat::DrawSprite((*(ship_3 + 3)), ship.posx, ship.posy-72); }
      if(lvl > 18 && lvl <= 24) { esat::DrawSprite((*(ship_4 + 3)), ship.posx, ship.posy); }
      break;
      case 3:
      if(lvl <= 6) { esat::DrawSprite((*(ship_1 + 4)), ship.posx, ship.posy-72); }
      if(lvl > 6 && lvl <= 12) { esat::DrawSprite((*(ship_2 + 4)), ship.posx, ship.posy-72); }
      if(lvl > 12 && lvl <= 18) { esat::DrawSprite((*(ship_3 + 4)), ship.posx, ship.posy-72); }
      if(lvl > 18 && lvl <= 24) { esat::DrawSprite((*(ship_4 + 4)), ship.posx, ship.posy-72); }
      break;
      case 4:
      if(lvl <= 6) { esat::DrawSprite((*(ship_1 + 5)), ship.posx, ship.posy-72); }
      if(lvl > 6 && lvl <= 12) { esat::DrawSprite((*(ship_2 + 5)), ship.posx, ship.posy-72); }
      if(lvl > 12 && lvl <= 18) { esat::DrawSprite((*(ship_3 + 5)), ship.posx, ship.posy-72); }
      if(lvl > 18 && lvl <= 24) { esat::DrawSprite((*(ship_4 + 5)), ship.posx, ship.posy-72); }
      break;
      case 5:
      if(lvl <= 6) { esat::DrawSprite((*(ship_1 + 6)), ship.posx, ship.posy-72); }
      if(lvl > 6 && lvl <= 12) { esat::DrawSprite((*(ship_2 + 6)), ship.posx, ship.posy-72); }
      if(lvl > 12 && lvl <= 18) { esat::DrawSprite((*(ship_3 + 6)), ship.posx, ship.posy-72); }
      if(lvl > 18 && lvl <= 24) { esat::DrawSprite((*(ship_4 + 6)), ship.posx, ship.posy-72); }
      break;
      case 6:
      if(lvl <= 6)
      {
        if(fps_counter >= 1 && fps_counter <=30)
        {
          esat::DrawSprite((*(ship_1 + 7)), ship.posx, ship.posy-72);
        }
        else{
          esat::DrawSprite((*(ship_1 + 1)), ship.posx, ship.posy-72);
        }
      }
      if(lvl > 6 && lvl <= 12)
      {
        if(fps_counter >= 1 && fps_counter <=30)
        {
          esat::DrawSprite((*(ship_2 + 7)), ship.posx, ship.posy-72);
        }
        else
        {
          esat::DrawSprite((*(ship_2 + 1)), ship.posx, ship.posy-72);
        }
      }
      if(lvl > 12 && lvl <= 18)
      {
        if(fps_counter >= 1 && fps_counter <=30)
        {
          esat::DrawSprite((*(ship_3 + 7)), ship.posx, ship.posy-72);
        }
        else
        {
          esat::DrawSprite((*(ship_3 + 1)), ship.posx, ship.posy-72);
        }
      }
      if(lvl > 18 && lvl <= 24)
      {
        if(fps_counter >= 1 && fps_counter <=30)
        {
          esat::DrawSprite((*(ship_4 + 7)), ship.posx, ship.posy-72);
        }
        else
        {
          esat::DrawSprite((*(ship_4 + 1)), ship.posx, ship.posy-72);
        }
      }
      break;
      default:printf("Error del fuel level.");break;
    }
  }
}

void RocketCreatePropulsion(){
  if( (*str_nave).posy < 450)
  {
    if(fps_counter >= 1 && fps_counter <=30)
    {
      esat::DrawSprite((*combustion), (*str_nave).posx-5, (*str_nave).posy+50);
    }
    else
    {
      esat::DrawSprite((*(combustion + 1)), (*str_nave).posx-5, (*str_nave).posy+50);
    }
  }
}

void PlayerInShip()
{
  if((*str_nave).fuel_level == 6)
  {
    if(str_player.posx > 490 && str_player.posx < 510 && str_player.posy > 392 && str_player.posy < 500)
    {
      str_player.show_player = false;
      str_player.vida +=1;
      if(str_player.vida > 5) {str_player.vida = 5;}
    }
    if(str_player.show_player == false) // ESTO NO
    {
      (*str_nave).posy-=1;
      RocketCreatePropulsion();
    }
  }
}

void LevelControl()
{
  if((*str_nave).posy < 50)
  {
    (*str_nave).fuel_level = 0;
    (*str_nave).posy += 2;
    // 1- Que desaparezcan todos los enemigos y bonus.
    // 2- Que la nave deje de parpadear y se quede en blanco
    // 2- Que descienda hasta posy 500 y se pare.
    // 3- Una vez haya descendido g_level + 1
    // 4- Inicializamos jugador, piezas, nave y enemigos
    // 5- Restamos una vida al jugador.
    // 6- Empieza el nuevo nivel.
  }
}

void CatchFuel(){
  if(str_player.can_grab)
  {
    if ( ( ( (str_player.posx <= ( fuel.pos.x + 36 ) )
    &&  ( str_player.posx >=  fuel.pos.x ) )
    ||  ( (str_player.posx + 31 ) <=  ( fuel.pos.x )
    &&  ( ( str_player.posx + 31 ) >=  fuel.pos.x ) ) )
    && ( (str_player.posy + 40 >= fuel.pos.y)
    && (str_player.posy + 40 <= fuel.pos.y + 36) ) )
    {
      fuel.is_attached = true;
    }
  }
}

void CatchPieces(TNave ship){
  // Aquí sería ver si le pasamos el jugador y la nave
  // Esto solo lo comprobariamos si estamos en los niveles 1,7,13,18
  if(ship.ship_parts != 3 && str_player.can_grab)
  {
    if(ship.ship_parts == 1)
    {
      if ( ( ( (str_player.posx <= ( (*(str_pieces + 2)).posx + 36 ) )
      &&  ( str_player.posx >=  (*(str_pieces + 2)).posx ) )
      ||  ( (str_player.posx + 31 ) <=  ( (*(str_pieces + 2)).posx + 36 )
      &&  ( ( str_player.posx + 31 ) >=  (*(str_pieces + 2)).posx ) ) )
      && ( (str_player.posy + 40 >= (*(str_pieces + 2)).posy)
      && (str_player.posy + 40 <= (*(str_pieces + 2)).posy + 36) ) ) {

        (*(str_pieces + 2)).is_attached = true;
    }
  }
    if(ship.ship_parts == 2)
    {
      if ( ( ( (str_player.posx <= ( (*(str_pieces + 1)).posx + 36 ) )
      &&  ( str_player.posx >=  (*(str_pieces + 1)).posx ) )
      ||  ( (str_player.posx + 31 ) <=  ( (*(str_pieces + 1)).posx + 36 )
      &&  ( ( str_player.posx + 31 ) >=  (*(str_pieces + 1)).posx ) ) )
      && ( (str_player.posy + 40 >= (*(str_pieces + 1)).posy)
      && (str_player.posy + 40 <= (*(str_pieces + 1)).posy + 36) ) ) {

        (*(str_pieces + 1)).is_attached = true;
    }
  }
}
}

void DropFuel(){
  if(fuel.is_attached && str_player.posx > 490 && str_player.posx < 510 )
  {
    fuel.pos.y = str_player.posy;
    str_player.can_grab = false;
    fuel.is_attached = false;
    fuel.just_dropped = true;
  }

  if(fuel.just_dropped)
  {
    fuel.pos.x = 500;
    fuel.pos.y += 2;

    if( fuel.pos.y > 486 && fuel.is_active)
    {
      fuel.is_active = false;
      fuel.just_dropped = false;
      str_player.can_grab = true;
      (*str_nave).fuel_level += 1;
    }
  }
}

void DropCargo(){
  if((*(str_pieces + 2)).is_attached && str_player.posx > 490 && str_player.posx < 510 )
  {
    str_player.can_grab = false;
    (*(str_pieces + 2)).is_attached = false;
    (*(str_pieces + 2)).just_dropped = true;
  }
  if((*(str_pieces + 1)).is_attached && str_player.posx > 490 && str_player.posx < 510 )
  {
    str_player.can_grab = false;
    (*(str_pieces + 1)).is_attached = false;
    (*(str_pieces + 1)).just_dropped = true;
  }

  if( (*(str_pieces + 2)).just_dropped)
  {
    (*(str_pieces + 2)).posx = 500;
    (*(str_pieces + 2)).posy += 2;

    if( (*(str_pieces + 2)).posy > 486 && (*(str_pieces + 2)).is_visible )
    {
      (*str_pieces).is_visible = false;
      (*(str_pieces + 2)).is_visible = false;
      (*str_nave).ship_parts = 2;
      str_player.can_grab = true;
    }
  }

  if( (*(str_pieces + 1)).just_dropped)
  {
    (*(str_pieces + 1)).posx = 500;
    (*(str_pieces + 1)).posy += 2;

    if( (*(str_pieces + 1)).posy > 450 && (*(str_pieces + 1)).is_visible  )
    {
      (*(str_pieces + 1)).is_visible = false;
      (*str_nave).ship_parts = 3;
      str_player.can_grab = true;
    }
  }
}

void InitializePieces()
{
    (*str_pieces).posx = 500;         (*str_pieces).posy = 519;           (*str_pieces).is_visible = true;
    (*(str_pieces + 1)).posx = 150;   (*(str_pieces + 1)).posy = 184;     (*(str_pieces + 1)).is_visible = true;
    (*(str_pieces + 2)).posx = 390;   (*(str_pieces + 2)).posy = 256;     (*(str_pieces + 2)).is_visible = true;
}

void InitializeShip()
{
  (*str_nave).posx=500;
  (*str_nave).posy=519;
  (*str_nave).fuel_level = 0;
  (*str_nave).ship_parts = 1;
}

void ShipSpritesRelease() {

  esat::SpriteRelease((*ship_pieces_1));
  esat::SpriteRelease((*(ship_pieces_1 + 1)));
  esat::SpriteRelease((*(ship_pieces_1 + 2)));

  esat::SpriteRelease((*ship_pieces_2));
  esat::SpriteRelease((*(ship_pieces_2 + 1)));
  esat::SpriteRelease((*(ship_pieces_2 + 2)));

  esat::SpriteRelease((*ship_pieces_3));
  esat::SpriteRelease((*(ship_pieces_3 + 1)));
  esat::SpriteRelease((*(ship_pieces_3 + 2)));

  esat::SpriteRelease((*ship_pieces_4));
  esat::SpriteRelease((*(ship_pieces_4 + 1)));
  esat::SpriteRelease((*(ship_pieces_4 + 2)));

  esat::SpriteRelease((*ship_1));
  esat::SpriteRelease((*(ship_1 + 1)));
  esat::SpriteRelease((*(ship_1 + 2)));
  esat::SpriteRelease((*(ship_1 + 3)));
  esat::SpriteRelease((*(ship_1 + 4)));
  esat::SpriteRelease((*(ship_1 + 5)));
  esat::SpriteRelease((*(ship_1 + 6)));
  esat::SpriteRelease((*(ship_1 + 7)));

  esat::SpriteRelease((*ship_2));
  esat::SpriteRelease((*(ship_2 + 1)));
  esat::SpriteRelease((*(ship_2 + 2)));
  esat::SpriteRelease((*(ship_2 + 3)));
  esat::SpriteRelease((*(ship_2 + 4)));
  esat::SpriteRelease((*(ship_2 + 5)));
  esat::SpriteRelease((*(ship_2 + 6)));
  esat::SpriteRelease((*(ship_2 + 7)));

  esat::SpriteRelease((*ship_3));
  esat::SpriteRelease((*(ship_3 + 1)));
  esat::SpriteRelease((*(ship_3 + 2)));
  esat::SpriteRelease((*(ship_3 + 3)));
  esat::SpriteRelease((*(ship_3 + 4)));
  esat::SpriteRelease((*(ship_3 + 5)));
  esat::SpriteRelease((*(ship_3 + 6)));
  esat::SpriteRelease((*(ship_3 + 7)));

  esat::SpriteRelease((*ship_4));
  esat::SpriteRelease((*(ship_4 + 1)));
  esat::SpriteRelease((*(ship_4 + 2)));
  esat::SpriteRelease((*(ship_4 + 3)));
  esat::SpriteRelease((*(ship_4 + 4)));
  esat::SpriteRelease((*(ship_4 + 5)));
  esat::SpriteRelease((*(ship_4 + 6)));
  esat::SpriteRelease((*(ship_4 + 7)));

  esat::SpriteRelease((*combustion));
  esat::SpriteRelease((*(combustion + 1)));
}
