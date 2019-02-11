
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
		
		
	for(int i=0;i<4;i++){
		
		AsignacionEnemy(Ovni, sprite, i);
		
	}
	
}



//Control y Animacion del enemigo tipo Ovni
void MovimientoOvni(TEnemy *Ovni, TPlayer player){
	
	if((*(Ovni)).phase_animation){
		if(player.posx > (*(Ovni)).posx){
				
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
			(*(Ovni)).speedx *= (-1);
			(*(Ovni)).speedy = 0;
			(*(Ovni)).posx += (*(Ovni)).speedx;
			//(*(Ovni)).posy += (*(Ovni)).speedy;
		}
		
		(*(Ovni)).posy += (*(Ovni)).speedy;
		
		if(CollisionEnemy((*(Ovni)))){
			
			(*(Ovni)).phase_animation = false;
			(*(Ovni)).speedy *= (-1);
			(*(Ovni)).speedx = 0;
			//(*(Ovni)).posx += (*(Ovni)).speedx;
			(*(Ovni)).posy += (*(Ovni)).speedy;
		}
		
		if((*(Ovni)).posx > (kWindowX)){
			
			(*(Ovni)).posx = (-55);		
			
		}
		if((*(Ovni)).posx < (-55)){
			
			(*(Ovni)).posx = (kWindowX);		
			
		}			
		
	}else{
		
		(*(Ovni)).posx += (*(Ovni)).speedx;
		(*(Ovni)).posy += (*(Ovni)).speedy;
		
		if(fps_counter == 20 || fps_counter == 40 || fps_counter == 60){
			(*(Ovni)).phase_animation = true;
		}
		
		
	}
		
		
		
		
	
	
}

//LLamar en el loop cuando se trabaja con este tipo de enemigos
void controlOvni(){
		
	for(int i=0;i<4;i++){
		
		MovimientoOvni((str_enemy+i), str_player);
		
		esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		
	}
		
}