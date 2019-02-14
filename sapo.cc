
//INICIALIZACION DEL ENEMIGO sapo
//Se llama dentro de controlEnemy.cc
void InicializarSapo(TEnemy *sapo, esat::SpriteHandle *sprite){
	
	
	(*(sprite))   = esat::SpriteFromFile("./resources/Sprites/Enemigo_8_azul.png");
	//(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_azul_inverse.png");
	
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_8_lila.png");
	//(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_lila_inverse.png");
	
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_8_rojo.png");
	//(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_rojo_inverse.png");	
	
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_8_verde.png");
	//(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_verde_inverse.png");
		
		
	for(int i=0;i<g_num_enemy;i++){
		
		AsignacionEnemy(sapo, sprite, i);
		(*(sapo+i)).points = 50;
		(*(sapo+i)).phase_animation = false;
	}
	
}



//Control y Animacion del enemigo tipo sapo
void MovimientoSapo(TEnemy *sapo, TPlayer player){
	
	if((*(sapo)).phase_animation){
		
		if(fps_counter == 22 || fps_counter == 45 || fps_counter == 7){
			(*(sapo)).seg_counter++;
		}
		
		if((*(sapo)).seg_counter < 1){
			
			(*(sapo)).posx += (*(sapo)).speedx;
			(*(sapo)).posy += (*(sapo)).speedy;
			
		}else{
		
			if((player.posx-25) > (*(sapo)).posx){
					
					(*(sapo)).speedx = 2;		
					//(*(sapo)).phase_animation = 0;
			}else{
					
					(*(sapo)).speedx = (-2);
					//(*(sapo)).phase_animation = 1;
			}
			
			if(player.posy > (*(sapo)).posy){
				
				(*(sapo)).speedy = 2;			
			}else{
				
				(*(sapo)).speedy = (-2);	
				
			}
				
			
			if((kWindowX-player.posx)+(*(sapo)).posx < (player.posx - (*(sapo)).posx)){
					
					(*(sapo)).speedx = (-2);
					//(*(sapo)).phase_animation = 1;
					
			}
				
			if((kWindowX-(*(sapo)).posx)+player.posx < ((*(sapo)).posx - player.posx)){
					
					(*(sapo)).speedx = (2);
					//(*(sapo)).phase_animation = 0;
					
			}
			
					
			(*(sapo)).posx += (*(sapo)).speedx;
			
			if(CollisionEnemy((*(sapo)))){
				
				(*(sapo)).phase_animation = false;
				(*(sapo)).seg_counter = 0;
				(*(sapo)).speedx *= (-1);
				(*(sapo)).speedy = 0;
				(*(sapo)).posx += (*(sapo)).speedx;
				(*(sapo)).posy += (*(sapo)).speedy;
			}
			
			(*(sapo)).posy += (*(sapo)).speedy;
			
			if(CollisionEnemy((*(sapo)))){
				
				(*(sapo)).phase_animation = false;
				(*(sapo)).seg_counter = 0;
				(*(sapo)).speedy *= (-1);
				(*(sapo)).speedx = 0;
				(*(sapo)).posx += (*(sapo)).speedx;
				(*(sapo)).posy += (*(sapo)).speedy;
			}
			
			if((*(sapo)).posx > (kWindowX)){
				
				(*(sapo)).posx = (-55);		
				
			}
			if((*(sapo)).posx < (-55)){
				
				(*(sapo)).posx = (kWindowX);		
				
			}			
		}
	}else{		
		
		if(fps_counter == 20 || fps_counter == 40 || fps_counter == 60){
			(*(sapo)).seg_counter++;
		}
		
		if((*(sapo)).seg_counter < 1){
			
			(*(sapo)).posx += (*(sapo)).speedx;
			(*(sapo)).posy += (*(sapo)).speedy;
			
		}else if((*(sapo)).seg_counter < 10){
			
			if((player.posx+25) > (*(sapo)).posx){
					
					(*(sapo)).speedx = 2;		
					//(*(sapo)).phase_animation = 0;
			}else{
					
					(*(sapo)).speedx = (-2);
					//(*(sapo)).phase_animation = 1;
			}
			
			if((player.posy) > (*(sapo)).posy){
				
				(*(sapo)).speedy = 2;			
			}else{
				
				(*(sapo)).speedy = (-2);	
				
			}
				
			
			if((kWindowX-player.posx)+(*(sapo)).posx < (player.posx - (*(sapo)).posx)){
					
					(*(sapo)).speedx = (-2);
					//(*(sapo)).phase_animation = 1;
					
			}
				
			if((kWindowX-(*(sapo)).posx)+player.posx < ((*(sapo)).posx - player.posx)){
					
					(*(sapo)).speedx = (2);
					//(*(sapo)).phase_animation = 0;
					
			}
			
					
			(*(sapo)).posx += (*(sapo)).speedx;
			
			if(CollisionEnemy((*(sapo)))){
				
				(*(sapo)).phase_animation = true;
				(*(sapo)).seg_counter = 0;
				(*(sapo)).speedx *= (-1);
				(*(sapo)).speedy = 0;
				(*(sapo)).posx += (*(sapo)).speedx;
				(*(sapo)).posy += (*(sapo)).speedy;
			}
			
			(*(sapo)).posy += (*(sapo)).speedy;
			
			if(CollisionEnemy((*(sapo)))){
				
				(*(sapo)).phase_animation = true;
				(*(sapo)).seg_counter = 0;
				(*(sapo)).speedy *= (-1);
				(*(sapo)).speedx = 0;
				(*(sapo)).posx += (*(sapo)).speedx;
				(*(sapo)).posy += (*(sapo)).speedy;
			}
			
			if((*(sapo)).posx > (kWindowX)){
				
				(*(sapo)).posx = (-55);		
				
			}
			if((*(sapo)).posx < (-55)){
				
				(*(sapo)).posx = (kWindowX);		
				
			}
			
			
		}else{
			
			(*(sapo)).phase_animation = true;
			(*(sapo)).seg_counter = 0;
			
		}
		
		
	}
		
		
		
		
	
	
}

//Se llama dentro de controlEnemy.cc
void controlSapo(){
		
	for(int i=0;i<g_num_enemy;i++){
		
		if(((*(str_enemy+i)).is_alive)){
			MovimientoSapo((str_enemy+i), str_player);
		
			esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		}else{
			
			if((*(str_enemy+i)).seg_counter == fps_counter && !(*((*(str_enemy+i)).my_explo)).visible){
				
				AsignacionEnemy(str_enemy, Block_sprite_Enemy, i);
				//(*(str_enemy+i)).seg_counter = 0;
			}
			
			
		}
	}
		
}