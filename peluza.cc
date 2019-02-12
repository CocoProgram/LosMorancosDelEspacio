



//INICIALIZACION DEL ENEMIGO PELUZA
//LLamar antes de empezar el nivel que contenga este tipo de enemigo
void InicializarPelusa(TEnemy *pelusa, esat::SpriteHandle *sprite){
	
	
	
	*(sprite) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_azul.png");	
	(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_azul.png");
	
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_lila.png");
	(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_lila.png");
	
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_rojo.png");
	(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_rojo.png");
	
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_0_verde.png");
	(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_2_1_verde.png");
	
	for(int i=0;i<g_num_enemy;i++){
		
		AsignacionEnemy(pelusa, sprite, i);
		(*(pelusa+i)).points = 80;
		(*(pelusa+i)).speedx = 2;
	}
	
}

//Control y Animacion del enemigo tipo Pelusa
void MovimientoPelusa(TEnemy *pelusa){
	
	(*(pelusa)).posx += (*(pelusa)).speedx;
	
	if(CollisionEnemy((*(pelusa)))){
		
		(*(pelusa)).speedx *= (-1);
		(*(pelusa)).posx += (*(pelusa)).speedx;
	}
	
	(*(pelusa)).posy += (*(pelusa)).speedy;
	
	if(CollisionEnemy((*(pelusa)))){
		
		(*(pelusa)).speedy *= (-1);
		(*(pelusa)).posy += (*(pelusa)).speedy;
	}
	
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
		
		(*(pelusa)).posx = (kWindowX);		
		
	}
	
	if(fps_counter == 0 || fps_counter == 30){
		
		(*(pelusa)).phase_animation = !(*(pelusa)).phase_animation;		
		
	}	
	

	
}

//LLamar en el loop cuando se trabaja con este tipo de enemigos
void controlPelusa(){
		
	for(int i=0;i<g_num_enemy;i++){
		
		if(((*(str_enemy+i)).is_alive)){
			MovimientoPelusa((str_enemy+i));
		
			esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy+i)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		}else{
			
			if((*(str_enemy+i)).seg_counter == fps_counter && !(*((*(str_enemy+i)).my_explo)).visible){
				
				AsignacionEnemy(str_enemy, Block_sprite_Enemy, i);
				(*(str_enemy+i)).seg_counter = 0;
			}
			
			
		}
	}
		
}

