
//LLamar dentro de PreMemorySaved
void ReservaMemoriaEnemy(){
	
	if((Block_sprite_Enemy = (esat::SpriteHandle *)calloc(16,sizeof(esat::SpriteHandle)))==NULL){
				printf("ERROR AL RESERVAR LOS SPRITES DE LOS ENEMIGOS");
	}
	
	if((str_enemy = (TEnemy *)calloc(4,sizeof(TEnemy)))==NULL){
				printf("ERROR AL RESERVAR LOS ENEMIGOS");
	}
		
}

//LLamar dentro de FreeMemorySaved
void LiberarEnemy(){
	
	
	free(Block_sprite_Enemy);
	free(str_enemy);
	
}




void AsignacionEnemy(TEnemy *enemy, esat::SpriteHandle *sprite, int i){
		
		int ra = rand()%4;
		
		(*(enemy+i)).enemy_sprites = (sprite+(2*ra));
		(*(enemy+i)).is_alive = true;
		(*(enemy+i)).posx = ((kWindowX-25)*(rand()%2));
		
		(*(enemy+i)).posy = 75 + ((kWindowY-150) / (1+rand()%5));
		//(*(enemy+i)).enemy_type = kEnemyTypes_2;
		(*(enemy+i)).speedx = 0;
		(*(enemy+i)).speedy = (-2);
		(*(enemy+i)).points = 30;
		(*(enemy+i)).colour = ra;
		
		if((*(enemy+i)).posx > (kWindowX/2)){			
			(*(enemy+i)).phase_animation = 1;
		}else{		
			(*(enemy+i)).phase_animation = 0;
		}
		(*(enemy+i)).seg_counter = 0;
	
	
		for(int k=0;k<i;k++){
		
		if((*(enemy+i)).posx == (*(enemy+k)).posx && (*(enemy+i)).posy == (*(enemy+k)).posy){
			
			AsignacionEnemy(enemy, sprite, i);
			
		}		
		
	}
	
	
}



bool CollisionEnemy(TEnemy enemy) {
	//str_mapa
	TMapa tmp;
	
  for(int i=1;i<=3;i++){
		
		tmp = (*(str_mapa+i));
		
		if( enemy.posx > tmp.posx 
		&&  enemy.posx < (tmp.posx + (esat::SpriteWidth(tmp.platform_sprites)))
		&&  enemy.posy > tmp.posy
		&&  enemy.posy < (tmp.posy + (esat::SpriteHeight(tmp.platform_sprites)))		
		){
			return true;
		}
		
		if((enemy.posx + esat::SpriteWidth((*(enemy.enemy_sprites)))) > tmp.posx 
		&& (enemy.posx + esat::SpriteWidth((*(enemy.enemy_sprites)))) < (tmp.posx + (esat::SpriteWidth(tmp.platform_sprites)))
		&&  enemy.posy 											      > tmp.posy
		&&  enemy.posy											      < (tmp.posy + (esat::SpriteHeight(tmp.platform_sprites)))		
		){
			return true;
		}
		
		if((enemy.posx + esat::SpriteWidth((*(enemy.enemy_sprites))))  > tmp.posx 
		&& (enemy.posx + esat::SpriteWidth((*(enemy.enemy_sprites))))  < (tmp.posx + (esat::SpriteWidth(tmp.platform_sprites)))
		&& (enemy.posy + esat::SpriteHeight((*(enemy.enemy_sprites)))) > tmp.posy
		&& (enemy.posy + esat::SpriteHeight((*(enemy.enemy_sprites)))) < (tmp.posy + (esat::SpriteHeight(tmp.platform_sprites)))		
		){
			return true;
		}
		
		if( enemy.posx   											   > tmp.posx 
		&&  enemy.posx  											   < (tmp.posx + (esat::SpriteWidth(tmp.platform_sprites)))
		&& (enemy.posy + esat::SpriteHeight((*(enemy.enemy_sprites)))) > tmp.posy
		&& (enemy.posy + esat::SpriteHeight((*(enemy.enemy_sprites)))) < (tmp.posy + (esat::SpriteHeight(tmp.platform_sprites)))		
		){
			return true;
		}
		///
		if( (enemy.posx + esat::SpriteWidth((*(enemy.enemy_sprites))))     > tmp.posx 
		&&  (enemy.posx + esat::SpriteWidth((*(enemy.enemy_sprites))))     < (tmp.posx + (esat::SpriteWidth(tmp.platform_sprites)))
		&& (enemy.posy + (esat::SpriteHeight((*(enemy.enemy_sprites)))/3)) > tmp.posy
		&& (enemy.posy + (esat::SpriteHeight((*(enemy.enemy_sprites)))/3)) < (tmp.posy + (esat::SpriteHeight(tmp.platform_sprites)))		
		){	
			//printf("Colicion_1");
			return true;
		}
		
		if(  (enemy.posx + esat::SpriteWidth((*(enemy.enemy_sprites))))        > tmp.posx 
		&&   (enemy.posx + esat::SpriteWidth((*(enemy.enemy_sprites))))        < (tmp.posx + (esat::SpriteWidth(tmp.platform_sprites)))
		&& (enemy.posy + (((esat::SpriteHeight((*(enemy.enemy_sprites))))/3)*2)) > tmp.posy
		&& (enemy.posy + (((esat::SpriteHeight((*(enemy.enemy_sprites))))/3)*2)) < (tmp.posy + (esat::SpriteHeight(tmp.platform_sprites)))		
		){	
			//printf("Colicion_2");
			return true;
		}
		
		if(  enemy.posx   											         > tmp.posx 
		&&   enemy.posx  											         < (tmp.posx + (esat::SpriteWidth(tmp.platform_sprites)))
		&& (enemy.posy + ((esat::SpriteHeight((*(enemy.enemy_sprites))))/3)) > tmp.posy
		&& (enemy.posy + ((esat::SpriteHeight((*(enemy.enemy_sprites))))/3)) < (tmp.posy + (esat::SpriteHeight(tmp.platform_sprites)))		
		){	
			//printf("Colicion_3");
			return true;
		}
		
		if(   enemy.posx   					  					        	     > tmp.posx 
		&&    enemy.posx  							         				     < (tmp.posx + (esat::SpriteWidth(tmp.platform_sprites)))
		&& (enemy.posy + (((esat::SpriteHeight((*(enemy.enemy_sprites))))/3)*2)) > tmp.posy
		&& (enemy.posy + (((esat::SpriteHeight((*(enemy.enemy_sprites))))/3)*2)) < (tmp.posy + (esat::SpriteHeight(tmp.platform_sprites)))		
		){	
			//printf("Colicion_4");
			return true;
		}
		////
  }
  
  return false;
  
}


















