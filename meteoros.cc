


//INICIALIZA ENEMIGO METEORO
//Llamar antes del bucle
void InicializarMeteoro(TEnemy *meteoro, esat::SpriteHandle *sprite) {
	
	(*sprite) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_azul.png");
	(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_azul_1.png");
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_azul.png");
	(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_azul_1.png");
	
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_lila.png");
	(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_lila_1.png");
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_lila.png");
	(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_lila_1.png");
	
	(*(sprite+8)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_rojo.png");
	(*(sprite+9)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_rojo_1.png");
	(*(sprite+10)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_rojo.png");
	(*(sprite+11)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_rojo_1.png");
	
	(*(sprite+12)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_verde.png");
	(*(sprite+13)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_verde_1.png");
	(*(sprite+14)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_verde.png");
	(*(sprite+15)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_verde_1.png");
	
	
	
	for(int i = 0 ; i < 4 ; i++){
		
		(*(meteoro+i)).enemy_sprites = sprite+(4*i);
		(*(meteoro+i)).is_alive = true;
		(*(meteoro+i)).posx = (kWindowX*(rand()%2));
		(*(meteoro+i)).posy = rand()%kWindowY;
		(*(meteoro+i)).enemy_type = kEnemyTypes_0;
		(*(meteoro+i)).speedx = 2;
		(*(meteoro+i)).speedy = 1;
		(*(meteoro+i)).points = 25;
		(*(meteoro+i)).colour = i;
		(*(meteoro+i)).phase_animation = 0;
		(*(meteoro+i)).seg_counter = 0;
		
	}
	
}


//MOVIMIENTO Y ANIMACION ENEMIGO METEORO

void MovimientoMeteoro(TEnemy *meteoro, esat::SpriteHandle *sprite) {
	
	if((*(meteoro)).direccionx == 0){
		
		(*(meteoro)).posx += (*(meteoro)).speedx;
		(*(meteoro)).phase_animation = 0;
		
	}else{
		
		(*(meteoro)).posx -= (*(meteoro)).speedx;
		(*(meteoro)).phase_animation = 1;
		
	}
	
	if((*(meteoro)).posx > kWindowX){
		
		(*(meteoro)).posx = 0;
		
	}
	
	if((*(meteoro)).posx < 0){
		
		(*(meteoro)).posx = kWindowX;
		
	}
	
	if((*(meteoro)).posy + 45 > kWindowY || CollisionEnemy((*(meteoro)))){
		
		(*(meteoro)).is_alive = false;
		(*(meteoro)).seg_counter++;
		
	}
	
	if((*(meteoro)).seg_counter == 50){
		
		(*(meteoro)).is_alive = true;
		(*(meteoro)).direccionx = rand()%2;
		(*(meteoro)).posx = (kWindowX*(rand()%2));
		(*(meteoro)).posy = rand()%kWindowY-30;
		
		(*(meteoro)).seg_counter = 0;
		
	}
	
	if((*(meteoro)).colour < 2){
		
		(*(meteoro)).posy += (*(meteoro)).speedy;
		
	}
	
	
	if(fps_counter == 0 || fps_counter == 30 ){
		
		(*(meteoro)).phase_animation = !(*(meteoro)).phase_animation;		
		
	}
	
	
}

//Llamar en la función de dibujado
void DibujarMeteoro(){
	
	for(int i=0;i<4;i++){
		
		/*MovimientoBola((str_enemy+i));*/
		/*esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));*/
		MovimientoMeteoro((str_enemy+i), (Block_sprite_Enemy+i));
		
		if((*(str_enemy+i)).is_alive){
			esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy+i)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		}
	}
	
	
	// (*(str_enemy+i)).(*(
	
}  //VAMOH A DIBUJAR



















