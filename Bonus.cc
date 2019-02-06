esat::SpriteHandle *all_bonus_sprite;

void BonusSpriteMemory (){
  all_bonus_sprite = (esat::SpriteHandle*) calloc (8, sizeof(esat::SpriteHandle));
}
void BonusFreeMemory() {
  free(all_bonus_sprite);
}
void BonusSpriteRelease(){
  esat::SpriteRelease(str_bonus.bonus_sprite);
}
void BonusSpritesLoad(){
  (*all_bonus_sprite) = esat::SpriteFromFile("./resources/Sprites/Bonus_0_amarillo.png");
  (*(all_bonus_sprite + 1)) = esat::SpriteFromFile("./resources/Sprites/Bonus_0_verde.png");
  (*(all_bonus_sprite + 2)) = esat::SpriteFromFile("./resources/Sprites/Bonus_0_azul.png");
  (*(all_bonus_sprite + 3)) = esat::SpriteFromFile("./resources/Sprites/Bonus_0_rojo.png");
  (*(all_bonus_sprite + 4)) = esat::SpriteFromFile("./resources/Sprites/Bonus_1.png");
  (*(all_bonus_sprite + 5)) = esat::SpriteFromFile("./resources/Sprites/Bonus_2.png");
  (*(all_bonus_sprite + 6)) = esat::SpriteFromFile("./resources/Sprites/Bonus_3.png");
  (*(all_bonus_sprite + 7)) = esat::SpriteFromFile("./resources/Sprites/Bonus_4.png");
}
void BonusSpawn(float gravedad){
  int bonus_random_spawn = 0;
  gravedad = 3.0f;

    if(str_bonus.is_alive == false) {
      bonus_random_spawn = rand()%201;
        if(bonus_random_spawn <= 50){
          str_bonus.coll_bonus = false;
          str_bonus.type_bonus = kBonusType_0;
          str_bonus.bonus_sprite = (*all_bonus_sprite);
          str_bonus.posx = rand()%727*1.0f;
          str_bonus.is_alive = true;
          str_bonus.draw_bonus = true;
        }else if (bonus_random_spawn <= 70){
          str_bonus.coll_bonus = false;
          str_bonus.type_bonus = kBonusType_1;
          str_bonus.bonus_sprite = (*(all_bonus_sprite + 4));
          str_bonus.posx = rand()%727*1.0f;
          str_bonus.is_alive = true;
          str_bonus.draw_bonus = true;
        } else if( bonus_random_spawn <= 90) {
          str_bonus.coll_bonus = false;
          str_bonus.type_bonus = kBonusType_2;
          str_bonus.bonus_sprite = (*(all_bonus_sprite + 5));
          str_bonus.posx = rand()%727*1.0f;
          str_bonus.is_alive = true;
          str_bonus.draw_bonus = true;
        } else if(bonus_random_spawn <= 95){
          str_bonus.coll_bonus = false;
          str_bonus.type_bonus = kBonusType_3;
          str_bonus.bonus_sprite = (*(all_bonus_sprite + 6));
          str_bonus.posx = rand()%727*1.0f;
          str_bonus.is_alive = true;
          str_bonus.draw_bonus = true;
        } else if(bonus_random_spawn <= 100) {
          str_bonus.coll_bonus = false;
          str_bonus.type_bonus = kBonusType_4;
          str_bonus.bonus_sprite = (*(all_bonus_sprite + 7));
          str_bonus.posx = rand()%727*1.0f;
          str_bonus.is_alive = true;
          str_bonus.draw_bonus = true;
        }

    } else {
      if (str_bonus.coll_bonus == false){ str_bonus.posy += gravedad; }
      switch(str_bonus.type_bonus) {
        case kBonusType_0:
          switch (fps_counter){
            case 0: str_bonus.bonus_sprite = (*all_bonus_sprite);
            break;
            case 15: str_bonus.bonus_sprite = (*(all_bonus_sprite + 1));
            break;
            case 30: str_bonus.bonus_sprite = (*(all_bonus_sprite + 2));
            break;
            case 45: str_bonus.bonus_sprite = (*(all_bonus_sprite + 3));
            break;
          }
        break;
        case kBonusType_3:
          switch (fps_counter){
              case 0: str_bonus.draw_bonus = !str_bonus.draw_bonus;
            break;
            case 30:
              str_bonus.draw_bonus = !str_bonus.draw_bonus;
            break;
          }
        break;
        case kBonusType_4:
          switch (fps_counter){
              case 0: str_bonus.draw_bonus = !str_bonus.draw_bonus;
            break;
            case 30:
              str_bonus.draw_bonus = !str_bonus.draw_bonus;
            break;
          }
        break;
      }
      if (str_bonus.draw_bonus == true){
        esat::DrawSprite(str_bonus.bonus_sprite, str_bonus.posx,str_bonus.posy);
      }
    }
}
void BonusCollision(){
  if  ( (str_bonus.posy + esat::SpriteHeight(str_bonus.bonus_sprite) ) >= (*str_mapa).posy ) {
      str_bonus.coll_bonus = true;
  }
  else if ( (str_bonus.posy + esat::SpriteHeight(str_bonus.bonus_sprite)) >= (*(str_mapa + 1)).posy
  && ( ( ( ( str_bonus.posx + esat::SpriteWidth(str_bonus.bonus_sprite) ) <= ( (*(str_mapa + 1)).posx + esat::SpriteWidth( (*(str_mapa + 1)).platform_sprites) ) )
  && ( ( str_bonus.posx  ) >= (*(str_mapa + 1)).posx ) ) || ( ( ( str_bonus.posx + esat::SpriteWidth(str_bonus.bonus_sprite) ) <= ( (*(str_mapa + 1)).posx + esat::SpriteWidth( (*(str_mapa + 1)).platform_sprites) ) )
  && ( ( str_bonus.posx ) >= (*(str_mapa + 1)).posx ) ) )  ){
    str_bonus.coll_bonus = true;
  }
  else if ( (str_bonus.posy + esat::SpriteHeight(str_bonus.bonus_sprite)) >= (*(str_mapa + 2)).posy
  && ( ( ( ( str_bonus.posx + esat::SpriteWidth(str_bonus.bonus_sprite) ) <= ( (*(str_mapa + 2)).posx + esat::SpriteWidth( (*(str_mapa + 2)).platform_sprites) ) )
  && ( ( str_bonus.posx  ) >= (*(str_mapa + 2)).posx ) ) || ( ( ( str_bonus.posx + esat::SpriteWidth(str_bonus.bonus_sprite) ) <= ( (*(str_mapa + 2)).posx + esat::SpriteWidth( (*(str_mapa + 2)).platform_sprites) ) )
  && ( ( str_bonus.posx ) >= (*(str_mapa + 2)).posx ) ) )  ){
    str_bonus.coll_bonus = true;
  }
  else if ( (str_bonus.posy + esat::SpriteHeight(str_bonus.bonus_sprite)) >= (*(str_mapa + 3)).posy
  && ( ( ( ( str_bonus.posx + esat::SpriteWidth(str_bonus.bonus_sprite) ) <= ( (*(str_mapa + 3)).posx + esat::SpriteWidth( (*(str_mapa + 3)).platform_sprites) ) )
  && ( ( str_bonus.posx  ) >= (*(str_mapa + 3)).posx ) ) || ( ( ( str_bonus.posx + esat::SpriteWidth(str_bonus.bonus_sprite) ) <= ( (*(str_mapa + 3)).posx + esat::SpriteWidth( (*(str_mapa + 3)).platform_sprites) ) )
  && ( ( str_bonus.posx ) >= (*(str_mapa + 3)).posx ) ) )  ){
    str_bonus.coll_bonus = true;
  }
}
