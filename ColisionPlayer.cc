int CollisionPlayer(TPlayer player, Tmapa mapa){
  //De abajo a arriba
  if(player.posy<mapa.posy+esat::SpriteHeight(mapa.platform_sprites)&&
  player.posy>mapa.posy&&
  player.posx+esat::SpriteWidth(player.player_sprites)>=mapa.posx&&
  player.posx<=mapa.posx+esat::SpriteWidth(mapa.platform_sprites)){
    return 1;
  }
  //De arriba a abajo
  else if(player.posy+esat::SpriteHeight(mapa.player_sprites)>mapa.posy&&
  player.posy+esat::SpriteHeight(mapa.player_sprites)<mapa.posy+esat::SpriteHeight(mapa.platform_sprites)&&
  player.posx+esat::SpriteWidth(player.player_sprites)>=mapa.posx&&
  player.posx+esat::SpriteWidth(player.player_sprites)<=mapa.posx+esat::SpriteWidth(mapa.platform_sprites)){
    return 2;
  }
  //De derecha a Izq
  /*else if(player.posy<mapa.posy+esat::SpriteHeight(mapa.platform_sprites)&&player.posy>mapa.posy&&player.posx>=mapa.posx&&
  player.posx+esat::SpriteWidth(player.player_sprites)<=mapa.posx+esat::SpriteWidth(mapa.platform_sprites)){
    return 3;
  }
  //De Izq a derecha
  else if(player.posy<mapa.posy+esat::SpriteHeight(mapa.platform_sprites)&&player.posy>mapa.posy&&player.posx>=mapa.posx&&
  player.posx+esat::SpriteWidth(player.player_sprites)<=mapa.posx+esat::SpriteWidth(mapa.platform_sprites)){
    return 4;
  }*/
  //No colisiona
  else{return 0;}
}
