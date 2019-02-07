
//INICIALIZACION DEL ENEMIGO Avion
//LLamar antes de empezar el nivel que contenga este tipo de enemigo
void InicializarAvion(TEnemy *Avion, esat::SpriteHandle *sprite){
	
	
	(*(sprite))   = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_azul.png");
	//(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_1_azul.png");
	
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_lila.png");
	//(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_1_lila.png");
	
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_rojo.png");
	//(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_1_rojo.png");	
	
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_verde.png");
	//(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_1_verde.png");
	
	(*(sprite+8)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_verde.png");
	//(*(sprite+9)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_1_verde.png");
	
	for(int i=0;i<4;i++){
		
		(*(Avion+i)).enemy_sprites = (sprite+(2*i));
		(*(Avion+i)).is_alive = true;
		(*(Avion+i)).posx = (kWindowX*(rand()%2));
		(*(Avion+i)).posy = 75 + ((kWindowY-150) / (1+rand()%5));
		//(*(Avion+i)).enemy_type = kEnemyTypes_2;
		(*(Avion+i)).speedx = 0;
		(*(Avion+i)).speedy = (-2);
		(*(Avion+i)).points = 30;
		(*(Avion+i)).colour = i;
		(*(Avion+i)).phase_animation = 0;
		(*(Avion+i)).seg_counter = 0;
	}	
}



//Control y Animacion del enemigo tipo Avion
void MovimientoAvion(TEnemy *Avion, TPlayer player){
	
	
		if((player.posy >= (*(Avion)).posy && player.posy <= ((*(Avion)).posy + 50)) || ((player.posy+54) >= (*(Avion)).posy && (player.posy+54) <= ((*(Avion)).posy+50))){
			
			if(player.posx > (*(Avion)).posx){
				
				(*(Avion)).speedx = 2;		
				
			}else{
				
				(*(Avion)).speedx = (-2);
				
			}
			
			if(((player.posy+54)/2) > (((*(Avion)).posy+50)/2)){
				
				(*(Avion)).speedy = 2;
				
			}else{
				(*(Avion)).speedy = (-2);
			}
			
		}
			
		if((player.posx-(*(Avion)).posx) == (player.posy-(*(Avion)).posy)){
			
			if((player.posx-(*(Avion)).posx) > 0){
				(*(Avion)).speedx = 2;
				(*(Avion)).speedy = 2;
			}else{
				
				(*(Avion)).speedx = (-2);
				(*(Avion)).speedy = (-2);
				
			}
		}

		if((player.posx-(*(Avion)).posx) == ((player.posy-(*(Avion)).posy)*(-1))){
			
			(*(Avion)).speedx = 2;
			(*(Avion)).speedy = (-2);
			
		}

		if(((player.posx-(*(Avion)).posx)*(-1)) == (player.posy-(*(Avion)).posy)){
			
			(*(Avion)).speedx = (-2);
			(*(Avion)).speedy = 2;
			
		}
	
	
	
	if((*(Avion)).speedx == 0){
		
				
		if(fps_counter == 59){
			(*(Avion)).seg_counter++;
		}
	
		if((*(Avion)).seg_counter == 1){
		
			(*(Avion)).speedy *= (-1);
			(*(Avion)).seg_counter = 0;
		}	
		(*(Avion)).posy += (*(Avion)).speedy;
	}else{
		
		
		(*(Avion)).posx += (*(Avion)).speedx;
		/*
		if(/*colicion terreno){
			
			destroy;
		}
		*/
		(*(Avion)).posy += (*(Avion)).speedy;
		/*
		if(/*colicion terreno){
			
			destroy
		}
		*/
		if((*(Avion)).posx > (kWindowX)){
			
			(*(Avion)).posx = (-55);		
			
		}
		if((*(Avion)).posx < (-55)){
			
			(*(Avion)).posx = (kWindowX);		
			
		}
		
		if((*(Avion)).posy > (kWindowY-50)){
			
			//destroy
			
		}
		if((*(Avion)).posy < 50){
			
			//destroy	
			
		}
		
		
	}
	
	
	
}

//LLamar en el loop cuando se trabaja con este tipo de enemigos
void controlAvion(){
		
	for(int i=0;i<4;i++){
		
		MovimientoAvion((str_enemy+i), str_player);
		
		esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		
	}
		
}