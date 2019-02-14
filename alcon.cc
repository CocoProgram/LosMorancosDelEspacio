
//INICIALIZA ENEMIGO alcon
//Llamar antes del bucle
void InicializarAlcon(TEnemy *alcon, esat::SpriteHandle *sprite) {
	
	//Azul derecha
	(*sprite)     = esat::SpriteFromFile("./resources/Sprites/Enemigo_7_azul.png");
	//(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_azul.png");
	//Azul izquierda
	(*(sprite+8)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_7_azul_inverse.png");
	//(*(sprite+9)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_azul_inverse.png");
	//lila derecha
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_7_lila.png");
	//(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_lila.png");
	//lila izquierda
	(*(sprite+10)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_7_lila_inverse.png");
	//(*(sprite+11)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_lila_inverse.png");
	//rojo derecha
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_7_rojo.png");
	//(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_rojo.png");
	//rojo izquierda
	(*(sprite+12)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_7_rojo_inverse.png");
	//(*(sprite+13)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_rojo_inverse.png");
	//verde derecha
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_7_verde.png");
	//(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_verde.png");
	//verde izquierda
	(*(sprite+14)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_7_verde_inverse.png");
	//(*(sprite+15)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_1_1_verde_inverse.png");
	
	
	
	for(int i = 0 ; i < g_num_enemy ; i++){
		
		AsignacionEnemy(alcon, sprite, i);		
		(*(alcon+i)).points = 25;
		
		(*(alcon+i)).speedx = (6*(rand()%2))-3;
			
		(*(alcon+i)).speedy = (0.25 * (1+rand()%4));
		
		if((*(alcon+i)).speedx < 0){
			
			(*(alcon+i)).enemy_sprites = ((*(alcon+i)).enemy_sprites + 8);
			
		}
		
		if((*(alcon+i)).speedy == 0){(*(alcon+i)).speedy = 1;}		
		(*(alcon+i)).phase_animation = false;
	}
	
}


//MOVIMIENTO Y ANIMACION ENEMIGO alcon

void MovimientoAlcon(TEnemy *alcon) {
	
	(*(alcon)).posx += (*(alcon)).speedx;
	
	if(CollisionEnemy((*(alcon)))){
		
		EnemysCreateExplo(alcon);
		(*(alcon)).is_alive = false;
		(*(alcon)).seg_counter = fps_counter;
	}
	
	(*(alcon)).posy += (*(alcon)).speedy;
	
	if(CollisionEnemy((*(alcon)))){
		
		EnemysCreateExplo(alcon);
		(*(alcon)).is_alive = false;
		(*(alcon)).seg_counter = fps_counter;
	}
	
	if((*(alcon)).posy < 50){
		
		EnemysCreateExplo(alcon);
		(*(alcon)).is_alive = false;
		(*(alcon)).seg_counter = fps_counter;
	}
	
	if((*(alcon)).posy > (kWindowY-18)){
		
		EnemysCreateExplo(alcon);
		(*(alcon)).is_alive = false;
		(*(alcon)).seg_counter = fps_counter;
	}
	
	if((*(alcon)).posx > (kWindowX)){
		
		(*(alcon)).posx = (-55);		
		
	}
	if((*(alcon)).posx < (-55)){
		
		(*(alcon)).posx = (kWindowX);		
		
	}
	
	if(fps_counter == 0 || fps_counter == 30){
		
		(*(alcon)).phase_animation = !(*(alcon)).phase_animation;		
		
	}	
	
	
}

void DibujarAlcon(){
	
	for(int i=0;i<g_num_enemy;i++){
		
		if((*(str_enemy+i)).is_alive){
			MovimientoAlcon((str_enemy+i));		
			esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		}else{
			
			if((*(str_enemy+i)).seg_counter == fps_counter && !(*((*(str_enemy+i)).my_explo)).visible){
				
				AsignacionEnemy(str_enemy, Block_sprite_Enemy, i);
				
				(*(str_enemy+i)).speedx = (6*(rand()%2))-3;
					
				(*(str_enemy+i)).speedy = (0.25 * (1+rand()%4));
		
				if((*(str_enemy+i)).speedx < 0){
			
					(*(str_enemy+i)).enemy_sprites = ((*(str_enemy+i)).enemy_sprites + 8);
			
				}
				
			}
			
			
		}
	}
	
	
	
	
}  