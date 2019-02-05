bool CollisionEnemy(TEnemy enemy, Tmapa mapa){
  if(enemy.posx<mapa.posx+esat::SpriteWidth(mapa.platform_sprites)&&
    enemy.posx+esat::SpriteWidth(enemy.enemy_sprites)>mapa.posx&&
    enemy.posy<mapa.posy+esat::SpriteHeight(mapa.platform_sprites)&&
    enemy.posy+esat::SpriteHeight(enemy.enemy_sprites)>mapa.posy){
    return true;
  }
  else{
    return false;
  }
}
