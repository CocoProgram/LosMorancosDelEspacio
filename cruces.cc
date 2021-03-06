


//INICIALIZA ENEMIGO CRUZ
//Llamar en el fichero "controlEnemy.cc", dentro de la función InicializarEnemyLevel, en el nivel 6. 
void InicializarCruz(TEnemy *cruz, esat::SpriteHandle *sprite) {
	
	(*sprite) = esat::SpriteFromFile("./resources/Sprites/Enemigo_6_azul.png");
	(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_6_lila.png");
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_6_verde.png");
	(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_6_rojo.png");
	
	for(int i = 0 ; i < g_num_enemy ; i++){
		
		(*(cruz+i)).enemy_sprites = sprite+i;
		(*(cruz+i)).is_alive = true;
		(*(cruz+i)).posx = (kWindowX*(rand()%2));
		(*(cruz+i)).posy = rand()%kWindowY;
		if((*(cruz+i)).posy > 554){
			(*(cruz+i)).posy -= 30;
		}
		if(rand()%2 == 0){
			(*(cruz+i)).speedx = 2;
		}else{
			(*(cruz+i)).speedx = -2;
		}
		(*(cruz+i)).speedy = 2;
		(*(cruz+i)).points = 60;
		(*(cruz+i)).colour = i;
		(*(cruz+i)).phase_animation = 0;
		(*(cruz+i)).seg_counter = 0;
		
	}
	
}

void ReInicializarCruz(TEnemy *cruz, esat::SpriteHandle *sprite, int i) {
	
	(*sprite) = esat::SpriteFromFile("./resources/Sprites/Enemigo_6_azul.png");
	(*(sprite+1)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_6_lila.png");
	(*(sprite+2)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_6_verde.png");
	(*(sprite+3)) = esat::SpriteFromFile("./resources/Sprites/Enemigo_6_rojo.png");
	
	
		
	(*(cruz)).enemy_sprites = sprite+i;
	(*(cruz)).is_alive = true;
	(*(cruz)).posx = (kWindowX*(rand()%2));
	(*(cruz)).posy = rand()%kWindowY;
	if((*(cruz)).posy > 554){
		(*(cruz)).posy -= 30;
	}
	if(rand()%2 == 0){
		(*(cruz)).speedx = 2;
	}else{
		(*(cruz)).speedx = -2;
	}
	(*(cruz)).speedy = 2;
	(*(cruz)).points = 60;
	(*(cruz)).colour = i;
	(*(cruz)).phase_animation = 0;
	(*(cruz)).seg_counter = 0;
		
	
	
}

//MOVIMIENTO Y ANIMACION ENEMIGO CRUZ

void MovimientoCruz(TEnemy *cruz) {
	
	
	(*(cruz)).posx += (*(cruz)).speedx;
	(*(cruz)).posy += (*(cruz)).speedy;
	
	
	//Rebote en la posx
	if((*(cruz)).posx > kWindowX && (*(cruz)).speedx > 0){
		
		(*(cruz)).posx = 0-45;
		
	}
	
	if((*(cruz)).posx+45 < 0 && (*(cruz)).speedx < 0){
		
		(*(cruz)).posx = kWindowX;
		
	}
	//Rebote en la posy
	if((*(cruz)).posy+45 > 553 && (*(cruz)).speedy > 0){
		
		(*(cruz)).speedy = -1*rand()%3;
		if((*(cruz)).speedy == 0){
			(*(cruz)).speedy = -2;
		}
		
		
		
	}
	
	
	
	if((*(cruz)).posy < 50 && (*(cruz)).speedy < 0){
		(*(cruz)).speedy = 1*rand()%3;
		if((*(cruz)).speedy == 0){
			(*(cruz)).speedy = 2;
		}
	}
	
	
	
	
	//Direccion: Abajo Derecha
	if(CollisionEnemy((*(cruz))) && (*(cruz)).speedx == 2 && (*(cruz)).speedy > 0){
		//Zona izquierda
		if((*(cruz)).posx+45 > 98  && (*(cruz)).posx < 98  || 
		   (*(cruz)).posx+45 > 363 && (*(cruz)).posx < 363 || 
		   (*(cruz)).posx+45 > 580 && (*(cruz)).posx < 580){
			
			(*(cruz)).speedx = -2;
		}
		//Zona arriba
		if((*(cruz)).posy+45 > 219 && (*(cruz)).posy < 219 || 
		   (*(cruz)).posy+45 > 292 && (*(cruz)).posy < 292 || 
		   (*(cruz)).posy+45 > 147 && (*(cruz)).posy < 147){
			
			(*(cruz)).speedy = -1*rand()%3;
			if((*(cruz)).speedy == 0){
				(*(cruz)).speedy = -2;
			}
			
		}
		
	}
	
	//Direccion: Arriba Izquierda
	if(CollisionEnemy((*(cruz))) && (*(cruz)).speedx == -2 && (*(cruz)).speedy < 0){
		//Zona derecha
		if((*(cruz)).posx < 98+137  && (*(cruz)).posx+45  > 98+137 || 
		   (*(cruz)).posx < 363+90  && (*(cruz)).posx+45  > 363+90 || 
		   (*(cruz)).posx < 580+144 && (*(cruz)).posx+45 > 580+144){
			
			(*(cruz)).speedx = 2;
		}
		//Zona abajo
		if((*(cruz)).posy < 219+18 && (*(cruz)).posy+45 > 219+18 || 
		   (*(cruz)).posy < 292+18 && (*(cruz)).posy+45 > 292+18 || 
		   (*(cruz)).posy < 147+18 && (*(cruz)).posy+45 > 147+18){
			
			(*(cruz)).speedy = 1*rand()%3;
			if((*(cruz)).speedy == 0){
				(*(cruz)).speedy = 2;
			}
		}
	}
	
	//Direccion: Abajo Izquierda
	if(CollisionEnemy((*(cruz))) && (*(cruz)).speedx == -2 && (*(cruz)).speedy > 0){
		//Zona derecha
		if((*(cruz)).posx < 98+137  && (*(cruz)).posx+45 > 98+137  || 
		   (*(cruz)).posx < 363+90  && (*(cruz)).posx+45 > 363+90  || 
		   (*(cruz)).posx < 580+144 && (*(cruz)).posx+45 > 580+144){
			
			(*(cruz)).speedx = 2;
		}
		//Zona arriba
		if((*(cruz)).posy+45 > 219 && (*(cruz)).posy < 219 || 
		   (*(cruz)).posy+45 > 292 && (*(cruz)).posy < 292 || 
		   (*(cruz)).posy+45 > 147 && (*(cruz)).posy < 147){
			
			(*(cruz)).speedy = -1*rand()%3;
			if((*(cruz)).speedy == 0){
				(*(cruz)).speedy = -2;
			}
			
		}
		
	}
	
	//Direccion: Arriba Derecha
	if(CollisionEnemy((*(cruz))) && (*(cruz)).speedx == 2 && (*(cruz)).speedy < 0){
		//Zona izquierda
		if((*(cruz)).posx+45 > 98  && (*(cruz)).posx < 98  || 
		   (*(cruz)).posx+45 > 363 && (*(cruz)).posx < 363 || 
		   (*(cruz)).posx+45 > 580 && (*(cruz)).posx < 580){
			
			(*(cruz)).speedx = -2;
		}
		//Zona abajo
		if((*(cruz)).posy < 219+18 && (*(cruz)).posy+45 > 219+18 || 
		   (*(cruz)).posy < 292+18 && (*(cruz)).posy+45 > 292+18 || 
		   (*(cruz)).posy < 147+18 && (*(cruz)).posy+45 > 147+18){
		 
			(*(cruz)).speedy = 1*rand()%3;
			if((*(cruz)).speedy == 0){
				(*(cruz)).speedy = 2;
			}
			
		}
	}
	
	
	
	
}



//Llamar en el fichero "controlEnemy.cc", dentro de la función ControlEnemyLevel, en el nivel 6.
void controlCruces(){
	
	for(int i=0;i<g_num_enemy;i++){
		
		if((*(str_enemy+i)).is_alive){
			MovimientoCruz((str_enemy+i));
			esat::DrawSprite((*((*(str_enemy+i)).enemy_sprites)), ((*(str_enemy+i)).posx), ((*(str_enemy+i)).posy));
		}else{
		
			if((*(str_enemy+i)).seg_counter == fps_counter && !(*((*(str_enemy+i)).my_explo)).visible){
			
				ReInicializarCruz((str_enemy+i),Block_sprite_Enemy,i);
				
			}
		
		}
	}
	
	
	
	
}  //VAMOH A DIBUJAR



















