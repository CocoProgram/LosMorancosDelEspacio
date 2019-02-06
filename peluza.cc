



//INICIALIZACION DEL ENEMIGO PELUZA
void InicializarPelusa(TEnemy *pelusa, esat::SpriteHandle *sprite){
	
	
	
	*(Block_sprite_Enemy) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_azul.png");	
	(*(Block_sprite_Enemy+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_azul.png");
	
	(*(Block_sprite_Enemy+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_lila.png");
	(*(Block_sprite_Enemy+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_lila.png");
	
	(*(Block_sprite_Enemy+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_rojo.png");
	(*(Block_sprite_Enemy+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_rojo.png");
	
	(*(Block_sprite_Enemy+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_verde.png");
	(*(Block_sprite_Enemy+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_verde.png");
	
	for(int i=0;i<4;i++){
		
		(*(pelusa+i)).enemy_sprites = (sprite+(2*i));
		(*(pelusa+i)).is_alive = true;
		(*(pelusa+i)).posx = (rand()%kWindowX);
		(*(pelusa+i)).posy = 75 + ((kWindowY-150) / (1+rand()%5));
		//(*(pelusa+i)).enemy_type = kEnemyTypes_1;
		(*(pelusa+i)).speedx = 2;
		(*(pelusa+i)).speedy = 2;
		(*(pelusa+i)).points = 80;
		(*(pelusa+i)).colour = i;
		(*(pelusa+i)).phase_animation = 0;
		(*(pelusa+i)).seg_counter = 0;
	}	
}

//Control y Animacion del enemigo tipo Pelusa
void MovimientoPelusa(TEnemy *pelusa){
	
	(*(pelusa)).posx += (*(pelusa)).speedx;
	/*
	if(/*colicion terreno){
		
		(*(pelusa)).speedx *= (-1);
		(*(pelusa)).posx += (*(pelusa)).speedx;
	}
	*/
	(*(pelusa)).posy += (*(pelusa)).speedy;
	/*
	if(/*colicion terreno){
		
		(*(pelusa)).speedy *= (-1);
		(*(pelusa)).posy += (*(pelusa)).speedy;
	}
	*/
	if((*(pelusa)).posy < 50){
		
		(*(pelusa)).speedy *= (-1);
		(*(pelusa)).posy += (*(pelusa)).speedy;
	}
	
	if((*(pelusa)).posy > (kWindowY-50)){
		
		(*(pelusa)).speedy *= (-1);
		(*(pelusa)).posy += (*(pelusa)).speedy;
	}
	
	if((*(pelusa)).posx > (kWindowX)){
		
		(*(pelusa)).posx = (-55);		
		
	}
	if((*(pelusa)).posx < (-55)){
		
		(*(pelusa)).posx = (kWindowX+55);		
		
	}
	
	if(fps_counter == 0 || fps_counter == 30){
		
		(*(pelusa)).phase_animation = !(*(pelusa)).phase_animation;		
		
	}	
	

	
}

void controlPelusa(){
		
	for(int i=0;i<4;i++){
		
		MovimientoPelusa((str_enemy+i));
		
		esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		
	}
		
}

