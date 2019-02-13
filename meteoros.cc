

//INICIALIZA ENEMIGO METEORO
//Llamar antes del bucle
void InicializarMeteoro(TEnemy *meteoro, esat::SpriteHandle *sprite) {
	
	//Azul derecha
	(*sprite)     = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_azul.png");
	(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_azul.png");
	//Azul izquierda
	(*(sprite+8)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_azul_inverse.png");
	(*(sprite+9)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_azul_inverse.png");
	//lila derecha
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_lila.png");
	(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_lila.png");
	//lila izquierda
	(*(sprite+10)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_lila_inverse.png");
	(*(sprite+11)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_lila_inverse.png");
	//rojo derecha
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_rojo.png");
	(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_rojo.png");
	//rojo izquierda
	(*(sprite+12)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_rojo_inverse.png");
	(*(sprite+13)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_rojo_inverse.png");
	//verde derecha
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_verde.png");
	(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_verde.png");
	//verde izquierda
	(*(sprite+14)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_0_verde_inverse.png");
	(*(sprite+15)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_verde_inverse.png");
	
	
	
	for(int i = 0 ; i < g_num_enemy ; i++){
		
		AsignacionEnemy(meteoro, sprite, i);		
		(*(meteoro+i)).points = 25;
		
		(*(meteoro+i)).speedx = (6*(rand()%2))-3;
		if((*(meteoro+i)).speedx == 0){
			(*(meteoro+i)).speedx = 2;
		}		
		(*(meteoro+i)).speedy = (0.25 * (1+rand()%4));
		
		if((*(meteoro+i)).speedx < 0){
			
			(*(meteoro+i)).enemy_sprites = ((*(meteoro+i)).enemy_sprites + 8);
			
		}
		
		if((*(meteoro+i)).speedy == 0){(*(meteoro+i)).speedy = 1;}		
		
	}
	
}


//MOVIMIENTO Y ANIMACION ENEMIGO METEORO

void MovimientoMeteoro(TEnemy *meteoro) {
	
	(*(meteoro)).posx += (*(meteoro)).speedx;
	
	if(CollisionEnemy((*(meteoro)))){
		
		EnemysCreateExplo(meteoro);
		(*(meteoro)).is_alive = false;
		(*(meteoro)).seg_counter = fps_counter;
	}
	
	(*(meteoro)).posy += (*(meteoro)).speedy;
	
	if(CollisionEnemy((*(meteoro)))){
		
		EnemysCreateExplo(meteoro);
		(*(meteoro)).is_alive = false;
		(*(meteoro)).seg_counter = fps_counter;
	}
	
	if((*(meteoro)).posy < 50){
		
		EnemysCreateExplo(meteoro);
		(*(meteoro)).is_alive = false;
		(*(meteoro)).seg_counter = fps_counter;
	}
	
	if((*(meteoro)).posy > (kWindowY-18)){
		
		EnemysCreateExplo(meteoro);
		(*(meteoro)).is_alive = false;
		(*(meteoro)).seg_counter = fps_counter;
	}
	
	if((*(meteoro)).posx > (kWindowX)){
		
		(*(meteoro)).posx = (-55);		
		
	}
	if((*(meteoro)).posx < (-55)){
		
		(*(meteoro)).posx = (kWindowX);		
		
	}
	
	if(fps_counter == 0 || fps_counter == 30){
		
		(*(meteoro)).phase_animation = !(*(meteoro)).phase_animation;		
		
	}	
	
	
}

void DibujarMeteoro(){
	
	for(int i=0;i<4;i++){
		
		if((*(str_enemy+i)).is_alive){
			MovimientoMeteoro((str_enemy+i));		
			esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy+i)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		}else{
			
			if((*(str_enemy+i)).seg_counter == fps_counter && !(*((*(str_enemy+i)).my_explo)).visible){
				
				AsignacionEnemy(str_enemy, Block_sprite_Enemy, i);
				
				(*(str_enemy+i)).speedx = (6*(rand()%2))-3;
				if((*(str_enemy+i)).speedx == 0){
					(*(str_enemy+i)).speedx = 2;
				}		
				(*(str_enemy+i)).speedy = (0.25 * (1+rand()%4));
		
				if((*(str_enemy+i)).speedx < 0){
			
					(*(str_enemy+i)).enemy_sprites = ((*(str_enemy+i)).enemy_sprites + 8);
			
				}
				
			}
			
			
		}
	}
	
	
	
	
}  