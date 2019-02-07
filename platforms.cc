void PlatformsMemoryReserved(){
  str_mapa = (TMapa*) calloc (4, sizeof(TMapa));
}
void PlatformsFreeMemory(){
 free(str_mapa);
}


void PlaformsLoadSprites() {
   (*str_mapa).platform_sprites = esat::SpriteFromFile("./resources/Sprites/Suelo.png");
   (*(str_mapa + 1)).platform_sprites = esat::SpriteFromFile("./resources/Sprites/Plataforma_Media.png");
   (*(str_mapa + 2)).platform_sprites = esat::SpriteFromFile("./resources/Sprites/Plataforma_Pequenya.png");
   (*(str_mapa + 3)).platform_sprites = esat::SpriteFromFile("./resources/Sprites/Plataforma_Grande.png");
}

void PlatformsDraw(){
 esat::DrawSprite((*str_mapa).platform_sprites, (*str_mapa).posx, (*str_mapa).posy);
 esat::DrawSprite((*(str_mapa + 1)).platform_sprites, (*(str_mapa + 1)).posx , (*(str_mapa + 1)).posy );
 esat::DrawSprite((*(str_mapa + 2)).platform_sprites, (*(str_mapa + 2)).posx , (*(str_mapa + 2)).posy);
 esat::DrawSprite((*(str_mapa + 3)).platform_sprites, (*(str_mapa + 3)).posx , (*(str_mapa + 3)).posy );
}

void PlatformPositions(){

  (*str_mapa).posx = 0;           (*str_mapa).posy = 555;
  (*(str_mapa + 1)).posx = 98;   (*(str_mapa + 1)).posy = 219;
  (*(str_mapa + 2)).posx = 363;   (*(str_mapa + 2)).posy = 292;
  (*(str_mapa + 3)).posx = 580;   (*(str_mapa + 3)).posy = 147;
}
