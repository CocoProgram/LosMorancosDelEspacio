
bool CollisionPlayerEnemy(TPlayer Player) {
	//str_mapa
	TEnemy tmp;
	
  for(int i=0;i<g_num_enemy;i++){
		
		tmp = (*(str_enemy+i));
		if(tmp.is_alive){
			
			if( Player.posx  > tmp.posx 
			&&  Player.posx  < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&&  Player.posy  > tmp.posy
			&&  Player.posy  < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				return true;
			}
			
			if((Player.posx + esat::SpriteWidth((*(Player.player_sprites)))) > tmp.posx 
			&& (Player.posx + esat::SpriteWidth((*(Player.player_sprites)))) < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&&  Player.posy 											     > tmp.posy
			&&  Player.posy											         < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				return true;
			}
			
			if((Player.posx + esat::SpriteWidth((*(Player.player_sprites))))  > tmp.posx 
			&& (Player.posx + esat::SpriteWidth((*(Player.player_sprites))))  < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + esat::SpriteHeight((*(Player.player_sprites)))) > tmp.posy
			&& (Player.posy + esat::SpriteHeight((*(Player.player_sprites)))) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){
				return true;
			}
			
			if( Player.posx   											   > tmp.posx 
			&&  Player.posx  											   < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + esat::SpriteHeight((*(Player.player_sprites)))) > tmp.posy
			&& (Player.posy + esat::SpriteHeight((*(Player.player_sprites)))) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				return true;
			}
			
			if( (Player.posx + esat::SpriteWidth((*(Player.player_sprites))))     > tmp.posx 
			&&  (Player.posx + esat::SpriteWidth((*(Player.player_sprites))))     < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + (esat::SpriteHeight((*(Player.player_sprites)))/3)) > tmp.posy
			&& (Player.posy + (esat::SpriteHeight((*(Player.player_sprites)))/3)) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				return true;
			}
			
			if(  (Player.posx + esat::SpriteWidth((*(Player.player_sprites))))        > tmp.posx 
			&&   (Player.posx + esat::SpriteWidth((*(Player.player_sprites))))        < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + (((esat::SpriteHeight((*(Player.player_sprites))))/3)*2)) > tmp.posy
			&& (Player.posy + (((esat::SpriteHeight((*(Player.player_sprites))))/3)*2)) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				return true;
			}
			
			if(  Player.posx   											         > tmp.posx 
			&&   Player.posx  											         < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + ((esat::SpriteHeight((*(Player.player_sprites))))/3)) > tmp.posy
			&& (Player.posy + ((esat::SpriteHeight((*(Player.player_sprites))))/3)) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				return true;
			}
			
			if(   Player.posx   					  					        	     > tmp.posx 
			&&    Player.posx  							         				     < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + (((esat::SpriteHeight((*(Player.player_sprites))))/3)*2)) > tmp.posy
			&& (Player.posy + (((esat::SpriteHeight((*(Player.player_sprites))))/3)*2)) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				return true;
			}
			
		}
  }
  
  return false;
  
}
