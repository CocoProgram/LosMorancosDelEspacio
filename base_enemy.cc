/*
esat::SpriteHandle *Block_sprite_Enemy;

struct TEnemy {
	float posx, posy;
	esat::SpriteHandle *enemy_sprites;
	//EnemyTypes enemy_type;
	bool is_alive;
	float speedx, speedy;
	int points;
	char colour;	
	bool phase_animation;	
	int seg_counter = 0;	
};
TEnemy *str_enemy;
*/

//LLamar dentro de PreMemorySaved
void ReservaMemoriaEnemy(){
	
	if((Block_sprite_Enemy = (esat::SpriteHandle *)calloc(16,sizeof(esat::SpriteHandle)))==NULL){
				printf("ERROR AL RESERVAR LOS SPRITES DE LOS ENEMIGOS");
	}
	
	if((str_enemy = (TEnemy *)calloc(g_num_enemy,sizeof(TEnemy)))==NULL){
				printf("ERROR AL RESERVAR LOS ENEMIGOS");
	}
		
}

//LLamar dentro de FreeMemorySaved
void LiberarEnemy(){
	
	
	free(Block_sprite_Enemy);
	free(str_enemy);
	
}

void MasReservaEnemy(){
	
	if((str_enemy = (TEnemy *)realloc(str_enemy,(g_num_enemy*sizeof(TEnemy))))==NULL){
				printf("ERROR AL RESERVAR LOS ENEMIGOS");
	}
	
}


void AsignacionEnemy(TEnemy *enemy, esat::SpriteHandle *sprite, int i){
		
		int ra = rand()%4;
		
		(*(enemy+i)).enemy_sprites = (sprite+(2*ra));
		(*(enemy+i)).is_alive = true;
		(*(enemy+i)).posx = ((kWindowX-25)*(rand()%2));
		
		(*(enemy+i)).posy = 75 + ((kWindowY-150) / (1+rand()%5));
		//(*(enemy+i)).enemy_type = kEnemyTypes_2;
		(*(enemy+i)).speedx = (-2+rand()%5);
		(*(enemy+i)).speedy = (-2+rand()%5);
		
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
	
  for(int i=0;i<=3;i++){
		
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



bool CollisionBullet(TShoot bullet) {
	//str_mapa
	TEnemy tmp;
	
  for(int i=0;i<g_num_enemy;i++){
		
		tmp = (*(str_enemy+i));
		
		if( bullet.posx > tmp.posx 
		&&  bullet.posx < (tmp.posx + (esat::SpriteWidth((*(tmp.enemy_sprites)))))
		&&  bullet.posy 					  > tmp.posy
		&&  bullet.posy 					  < (tmp.posy + (esat::SpriteHeight((*(tmp.enemy_sprites)))))
		&&  bullet.shot
		&&  !bullet.collision
		){	
			
			EnemysCreateExplo((str_enemy+i));
			(*(str_enemy+i)).is_alive = false;
			(*(str_enemy+i)).seg_counter = fps_counter;
			
			return true;
		}
		
		
		
		
  }
  
  return false;
  
}


















