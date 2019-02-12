
//INICIALIZACION DEL ENEMIGO OVNI
//LLamar antes de empezar el nivel que contenga este tipo de enemigo
void InicializarOvni(TEnemy *Ovni, esat::SpriteHandle *sprite){
	
	
	(*(sprite))   = esat::SpriteFromFile("./resources/Sprites/Enemigo_5_azul.png");
	//(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_azul_inverse.png");
	
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_5_lila.png");
	//(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_lila_inverse.png");
	
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_5_rojo.png");
	//(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_rojo_inverse.png");	
	
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_5_verde.png");
	//(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_verde_inverse.png");
		
		
	for(int i=0;i<g_num_enemy;i++){
		
		AsignacionEnemy(Ovni, sprite, i);
		(*(Ovni+i)).points = 30;
		(*(Ovni+i)).phase_animation = false;
	}
	
}



//Control y Animacion del enemigo tipo Ovni
void MovimientoOvni(TEnemy *Ovni, TPlayer player){
	
	if((*(Ovni)).phase_animation){
		
		if(fps_counter == 22 || fps_counter == 45 || fps_counter == 7){
			(*(Ovni)).seg_counter++;
		}
		
		if((*(Ovni)).seg_counter < 1){
			
			(*(Ovni)).posx += (*(Ovni)).speedx;
			(*(Ovni)).posy += (*(Ovni)).speedy;
			
		}else{
		
			if((player.posx-25) > (*(Ovni)).posx){
					
					(*(Ovni)).speedx = 2;		
					//(*(Ovni)).phase_animation = 0;
			}else{
					
					(*(Ovni)).speedx = (-2);
					//(*(Ovni)).phase_animation = 1;
			}
			
			if(player.posy > (*(Ovni)).posy){
				
				(*(Ovni)).speedy = 2;			
			}else{
				
				(*(Ovni)).speedy = (-2);	
				
			}
				
			
			if((kWindowX-player.posx)+(*(Ovni)).posx < (player.posx - (*(Ovni)).posx)){
					
					(*(Ovni)).speedx = (-2);
					//(*(Ovni)).phase_animation = 1;
					
			}
				
			if((kWindowX-(*(Ovni)).posx)+player.posx < ((*(Ovni)).posx - player.posx)){
					
					(*(Ovni)).speedx = (2);
					//(*(Ovni)).phase_animation = 0;
					
			}
			
					
			(*(Ovni)).posx += (*(Ovni)).speedx;
			
			if(CollisionEnemy((*(Ovni)))){
				
				(*(Ovni)).phase_animation = false;
				(*(Ovni)).seg_counter = 0;
				(*(Ovni)).speedx *= (-1);
				(*(Ovni)).speedy = 0;
				(*(Ovni)).posx += (*(Ovni)).speedx;
				(*(Ovni)).posy += (*(Ovni)).speedy;
			}
			
			(*(Ovni)).posy += (*(Ovni)).speedy;
			
			if(CollisionEnemy((*(Ovni)))){
				
				(*(Ovni)).phase_animation = false;
				(*(Ovni)).seg_counter = 0;
				(*(Ovni)).speedy *= (-1);
				(*(Ovni)).speedx = 0;
				(*(Ovni)).posx += (*(Ovni)).speedx;
				(*(Ovni)).posy += (*(Ovni)).speedy;
			}
			
			if((*(Ovni)).posx > (kWindowX)){
				
				(*(Ovni)).posx = (-55);		
				
			}
			if((*(Ovni)).posx < (-55)){
				
				(*(Ovni)).posx = (kWindowX);		
				
			}			
		}
	}else{		
		
		if(fps_counter == 20 || fps_counter == 40 || fps_counter == 60){
			(*(Ovni)).seg_counter++;
		}
		
		if((*(Ovni)).seg_counter < 1){
			
			(*(Ovni)).posx += (*(Ovni)).speedx;
			(*(Ovni)).posy += (*(Ovni)).speedy;
			
		}else if((*(Ovni)).seg_counter < 10){
			
			if((player.posx+25) > (*(Ovni)).posx){
					
					(*(Ovni)).speedx = 2;		
					//(*(Ovni)).phase_animation = 0;
			}else{
					
					(*(Ovni)).speedx = (-2);
					//(*(Ovni)).phase_animation = 1;
			}
			
			if((player.posy) > (*(Ovni)).posy){
				
				(*(Ovni)).speedy = 2;			
			}else{
				
				(*(Ovni)).speedy = (-2);	
				
			}
				
			
			if((kWindowX-player.posx)+(*(Ovni)).posx < (player.posx - (*(Ovni)).posx)){
					
					(*(Ovni)).speedx = (-2);
					//(*(Ovni)).phase_animation = 1;
					
			}
				
			if((kWindowX-(*(Ovni)).posx)+player.posx < ((*(Ovni)).posx - player.posx)){
					
					(*(Ovni)).speedx = (2);
					//(*(Ovni)).phase_animation = 0;
					
			}
			
					
			(*(Ovni)).posx += (*(Ovni)).speedx;
			
			if(CollisionEnemy((*(Ovni)))){
				
				(*(Ovni)).phase_animation = true;
				(*(Ovni)).seg_counter = 0;
				(*(Ovni)).speedx *= (-1);
				(*(Ovni)).speedy = 0;
				(*(Ovni)).posx += (*(Ovni)).speedx;
				(*(Ovni)).posy += (*(Ovni)).speedy;
			}
			
			(*(Ovni)).posy += (*(Ovni)).speedy;
			
			if(CollisionEnemy((*(Ovni)))){
				
				(*(Ovni)).phase_animation = true;
				(*(Ovni)).seg_counter = 0;
				(*(Ovni)).speedy *= (-1);
				(*(Ovni)).speedx = 0;
				(*(Ovni)).posx += (*(Ovni)).speedx;
				(*(Ovni)).posy += (*(Ovni)).speedy;
			}
			
			if((*(Ovni)).posx > (kWindowX)){
				
				(*(Ovni)).posx = (-55);		
				
			}
			if((*(Ovni)).posx < (-55)){
				
				(*(Ovni)).posx = (kWindowX);		
				
			}
			
			
		}else{
			
			(*(Ovni)).phase_animation = true;
			(*(Ovni)).seg_counter = 0;
			
		}
		
		
	}
		
		
		
		
	
	
}

//LLamar en el loop cuando se trabaja con este tipo de enemigos
void controlOvni(){
		
	for(int i=0;i<g_num_enemy;i++){
		
		if(((*(str_enemy+i)).is_alive)){
			MovimientoOvni((str_enemy+i), str_player);
		
			esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		}else{
			
			if((*(str_enemy+i)).seg_counter == fps_counter && !(*((*(str_enemy+i)).my_explo)).visible){
				
				AsignacionEnemy(str_enemy, Block_sprite_Enemy, i);
				(*(str_enemy+i)).seg_counter = 0;
			}
			
			
		}
	}
		
}