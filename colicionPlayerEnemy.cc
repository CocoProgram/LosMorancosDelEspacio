
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
				printf("Player X= % 3f -- Player Y= % 3f -- Enemy X= % 3f -- Enemy Y= % 3f\n", Player.posx, Player.posy, tmp.posx, tmp.posy);
				return true;
			}
			
			if((Player.posx + esat::SpriteWidth((*(Player.player_sprites)))) > tmp.posx 
			&& (Player.posx + esat::SpriteWidth((*(Player.player_sprites)))) < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&&  Player.posy 											     > tmp.posy
			&&  Player.posy											         < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				printf("Player X= % 3f -- Player Y= % 3f -- Enemy X= % 3f -- Enemy Y= % 3f\n", Player.posx, Player.posy, tmp.posx, tmp.posy);
				return true;
			}
			
			if((Player.posx + esat::SpriteWidth((*(Player.player_sprites))))  > tmp.posx 
			&& (Player.posx + esat::SpriteWidth((*(Player.player_sprites))))  < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + esat::SpriteHeight((*(Player.player_sprites)))) > tmp.posy
			&& (Player.posy + esat::SpriteHeight((*(Player.player_sprites)))) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){
				printf("Player X= % 3f -- Player Y= % 3f -- Enemy X= % 3f -- Enemy Y= % 3f\n", Player.posx, Player.posy, tmp.posx, tmp.posy);
				return true;
			}
			
			if( Player.posx   											   > tmp.posx 
			&&  Player.posx  											   < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + esat::SpriteHeight((*(Player.player_sprites)))) > tmp.posy
			&& (Player.posy + esat::SpriteHeight((*(Player.player_sprites)))) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				printf("Player X= % 3f -- Player Y= % 3f -- Enemy X= % 3f -- Enemy Y= % 3f\n", Player.posx, Player.posy, tmp.posx, tmp.posy);
				return true;
			}
			
			if( (Player.posx + esat::SpriteWidth((*(Player.player_sprites))))     > tmp.posx 
			&&  (Player.posx + esat::SpriteWidth((*(Player.player_sprites))))     < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + (esat::SpriteHeight((*(Player.player_sprites)))/3)) > tmp.posy
			&& (Player.posy + (esat::SpriteHeight((*(Player.player_sprites)))/3)) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				//printf("Colicion_1");
				return true;
			}
			
			if(  (Player.posx + esat::SpriteWidth((*(Player.player_sprites))))        > tmp.posx 
			&&   (Player.posx + esat::SpriteWidth((*(Player.player_sprites))))        < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + (((esat::SpriteHeight((*(Player.player_sprites))))/3)*2)) > tmp.posy
			&& (Player.posy + (((esat::SpriteHeight((*(Player.player_sprites))))/3)*2)) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				//printf("Colicion_2");
				return true;
			}
			
			if(  Player.posx   											         > tmp.posx 
			&&   Player.posx  											         < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + ((esat::SpriteHeight((*(Player.player_sprites))))/3)) > tmp.posy
			&& (Player.posy + ((esat::SpriteHeight((*(Player.player_sprites))))/3)) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				//printf("Colicion_3");
				return true;
			}
			
			if(   Player.posx   					  					        	     > tmp.posx 
			&&    Player.posx  							         				     < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
			&& (Player.posy + (((esat::SpriteHeight((*(Player.player_sprites))))/3)*2)) > tmp.posy
			&& (Player.posy + (((esat::SpriteHeight((*(Player.player_sprites))))/3)*2)) < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))		
			){	
				//printf("Colicion_4");
				return true;
			}
			
		}
  }
  
  return false;
  
}
