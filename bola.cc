

//INICIALIZACION DEL ENEMIGO BOLA
//LLamar antes de empezar el nivel que contenga este tipo de enemigo
void InicializarBola(TEnemy *bola, esat::SpriteHandle *sprite){
	
	
	(*(sprite))   = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_azul.png");
	(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_azul.png");
	
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_lila.png");
	(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_lila.png");
	
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_rojo.png");
	(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_rojo.png");
	
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_verde.png");
	(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_verde.png");
	
	for(int i=0;i<g_num_enemy;i++){
		
		AsignacionEnemy(bola, sprite, i);
		(*(bola+i)).points = 30;
		(*(bola+i)).speedx = 2;
	}	
}



//Control y Animacion del enemigo tipo Bola
void MovimientoBola(TEnemy *Bola){
	
	
	(*(Bola)).posx += (*(Bola)).speedx;
	
	if(CollisionEnemy((*(Bola)))){
		
		(*(Bola)).speedx *= (-1);
		(*(Bola)).posx += (*(Bola)).speedx;
	}
	
	(*(Bola)).posy += (*(Bola)).speedy;
	
	if(CollisionEnemy((*(Bola)))){
		
		(*(Bola)).speedy *= (-1);
		(*(Bola)).posy += (*(Bola)).speedy;
	}
	
	if((*(Bola)).posx > (kWindowX)){
		
		(*(Bola)).posx = (-55);		
		
	}
	if((*(Bola)).posx < (-55)){
		
		(*(Bola)).posx = (kWindowX);		
		
	}
	
	if((*(Bola)).posy > (kWindowY-50)){
		
		(*(Bola)).speedy *= (-1);
		(*(Bola)).posy += (*(Bola)).speedy;	
		
	}
	if((*(Bola)).posy < 50){
		
		(*(Bola)).speedy *= (-1);
		(*(Bola)).posy += (*(Bola)).speedy;		
		
	}
	
	if(fps_counter == 0 || fps_counter == 30){
		
		(*(Bola)).phase_animation = !(*(Bola)).phase_animation;		
		
	}
	
	if(fps_counter == 59){
		(*(Bola)).seg_counter++;
	}
	
	if((*(Bola)).seg_counter == 3){
		
		(*(Bola)).speedy = ((-1)+rand()%3)/*multiplicar para dificultad*/;
		(*(Bola)).seg_counter = 0;
	}
	
	
}

//LLamar en el loop cuando se trabaja con este tipo de enemigos
void controlBola(){
		
	for(int i=0;i<g_num_enemy;i++){
		
		if(((*(str_enemy+i)).is_alive)){
			MovimientoBola((str_enemy+i));
		
			esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy+i)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		}else{
			
			if((*(str_enemy+i)).seg_counter == fps_counter && !(*((*(str_enemy+i)).my_explo)).visible){
				
				AsignacionEnemy(str_enemy, Block_sprite_Enemy, i);
				(*(str_enemy+i)).seg_counter = 0;
			}
			
			
		}
	}
		
}