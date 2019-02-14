





//INICIALIZACION DEL ENEMIGO Avion
//Se llama dentro de controlEnemy.cc
void InicializarAvion(TEnemy *Avion, esat::SpriteHandle *sprite){
	
	
	(*(sprite))   = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_azul.png");
	(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_azul_inverse.png");
	
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_lila.png");
	(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_lila_inverse.png");
	
	(*(sprite+4)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_rojo.png");
	(*(sprite+5)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_rojo_inverse.png");	
	
	(*(sprite+6)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_verde.png");
	(*(sprite+7)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_verde_inverse.png");
		
	(*(sprite+8)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4.png");
	(*(sprite+9)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_4_inverse.png");
	
	for(int i=0;i<g_num_enemy;i++){
		
		AsignacionEnemy(Avion, sprite, i);
		(*(Avion+i)).points = 55;
		(*(Avion+i)).speedx = 0;
		(*(Avion+i)).speedy = (-2);
	}
	
}



//Control y Animacion del enemigo tipo Avion
void MovimientoAvion(TEnemy *Avion, TPlayer player){
	
	
		if((player.posy >= (*(Avion)).posy 
			&& player.posy <= ((*(Avion)).posy + 50)) 
			|| ((player.posy+54) >= (*(Avion)).posy 
			&& (player.posy+54) <= ((*(Avion)).posy+50))){
			
			if(player.posx > (*(Avion)).posx){
				
				(*(Avion)).speedx = 2;		
				(*(Avion)).phase_animation = 0;
			}else{
				
				(*(Avion)).speedx = (-2);
				(*(Avion)).phase_animation = 1;
			}
			
			if((kWindowX-player.posx)+(*(Avion)).posx < (player.posx - (*(Avion)).posx)){
				
				(*(Avion)).speedx = (-2);
				(*(Avion)).phase_animation = 1;
				
			}
			
			if((kWindowX-(*(Avion)).posx)+player.posx < ((*(Avion)).posx - player.posx)){
				
				(*(Avion)).speedx = (2);
				(*(Avion)).phase_animation = 0;
				
			}
			
			if(((player.posy+54)/2) > (((*(Avion)).posy+50)/2)){
				
				(*(Avion)).speedy = 2;
				
			}else{
				(*(Avion)).speedy = (-2);
				
			}
			(*(Avion)).enemy_sprites = ((*(Avion)).enemy_sprites + (8-((*(Avion)).colour*2)));
			(*(Avion)).colour = 4;
		}
			
		if((player.posx-(*(Avion)).posx) == (player.posy-(*(Avion)).posy)){
			
			if((player.posx-(*(Avion)).posx) > 0){
				(*(Avion)).speedx = 2;
				(*(Avion)).speedy = 2;
				(*(Avion)).phase_animation = 0;
			}else{
				
				(*(Avion)).speedx = (-2);
				(*(Avion)).speedy = (-2);
				(*(Avion)).phase_animation = 1;
				
			}
			(*(Avion)).enemy_sprites = ((*(Avion)).enemy_sprites + (8-((*(Avion)).colour*2)));
			(*(Avion)).colour = 4;
		}

		if((player.posx-(*(Avion)).posx) == ((player.posy-(*(Avion)).posy)*(-1))){
			
			(*(Avion)).speedx = 2;
			(*(Avion)).speedy = (-2);
			(*(Avion)).phase_animation = 0;
			(*(Avion)).enemy_sprites = ((*(Avion)).enemy_sprites + (8-((*(Avion)).colour*2)));
			(*(Avion)).colour = 4;
			
		}

		if(((player.posx-(*(Avion)).posx)*(-1)) == (player.posy-(*(Avion)).posy)){
			
			(*(Avion)).speedx = (-2);
			(*(Avion)).speedy = 2;
			(*(Avion)).phase_animation = 1;
			(*(Avion)).enemy_sprites = ((*(Avion)).enemy_sprites + (8-((*(Avion)).colour*2)));
			(*(Avion)).colour = 4;
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
		
		if(CollisionEnemy((*(Avion)))){
			
			EnemysCreateExplo(Avion);
			(*(Avion)).is_alive = false;
			(*(Avion)).seg_counter = fps_counter;
		}
		
		(*(Avion)).posy += (*(Avion)).speedy;
		
		if(CollisionEnemy((*(Avion)))){
			
			EnemysCreateExplo(Avion);
			(*(Avion)).is_alive = false;
			(*(Avion)).seg_counter = fps_counter;
		}
		
		if((*(Avion)).posx > (kWindowX)){
			
			(*(Avion)).posx = (-55);		
			
		}
		if((*(Avion)).posx < (-55)){
			
			(*(Avion)).posx = (kWindowX);		
			
		}
		
		if(((*(Avion)).posy +21) > (kWindowY-18)){
			
			(*(Avion)).is_alive = false;
			
		}
		if((*(Avion)).posy < 50){
			
			(*(Avion)).posy -= (*(Avion)).speedy;
			
		}
		
		
	}
	
	
	
}

//Se llama dentro de controlEnemy.cc
void controlAvion(){
		
	for(int i=0;i<g_num_enemy;i++){
		
		if(((*(str_enemy+i)).is_alive)){
			MovimientoAvion((str_enemy+i), str_player);
		
			esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites + (*(str_enemy+i)).phase_animation)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		}else{
			
			if((*(str_enemy+i)).seg_counter == fps_counter && !(*((*(str_enemy+i)).my_explo)).visible){
				
				AsignacionEnemy(str_enemy, Block_sprite_Enemy, i);
				//(*(str_enemy+i)).seg_counter = 0;
			}
			
			
		}
	}
		
}