

//INICIALIZACION DEL ENEMIGO BOLA
void InicializarBola(TEnemy *bola, esat::SpriteHandle *sprite){
	
	
	(*(sprite))   = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_azul.png");
	(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_azul.png");
	
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_lila.png");
	(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_lila.png");
	
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_rojo.png");
	(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_rojo.png");
	
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_0_verde.png");
	(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_3_1_verde.png");
	
	for(int i=0;i<4;i++){
		
		(*(bola+i)).enemy_sprites = sprite;
		(*(bola+i)).is_alive = true;
		(*(bola+i)).posx = (kWindowX*(rand()%2));
		(*(bola+i)).posy = 75 + (kWindowY / (1+rand()%5));
		(*(bola+i)).enemy_type = kEnemyTypes_2;
		(*(bola+i)).speedx = 2;
		(*(bola+i)).speedy = 2;
		(*(bola+i)).points = 30;
		(*(bola+i)).colour = i;
		(*(bola+i)).phase_animation = 0;
		(*(bola+i)).seg_counter = 0;
	}	
}



//Control y Animacion del enemigo tipo Bola
void MovimientoBola(TEnemy *Bola){
	
	
	(*(Bola)).posx += (*(Bola)).speedx;
	/*
	if(/*colicion terreno){
		
		(*(Bola)).speedx *= (-1);
		(*(Bola)).posx += (*(Bola)).speedx;
	}
	*/
	(*(Bola)).posy += (*(Bola)).speedy;
	/*
	if(/*colicion terreno){
		
		(*(Bola)).speedy *= (-1);
		(*(Bola)).posy += (*(Bola)).speedy;
	}
	*/
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

void controlBola(){
		
	for(int i=0;i<4;i++){
		
		MovimientoBola((str_enemy+i));
		
		esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		
	}
		
}