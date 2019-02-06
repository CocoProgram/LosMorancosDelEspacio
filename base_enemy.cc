void reserva_memoria_peluza(){
	
	if((Block_sprite_Enemy = (esat::SpriteHandle *)calloc(8,sizeof(esat::SpriteHandle)))==NULL){
				printf("ERROR AL RESERVAR LOS SPRITES DE LOS ENEMIGOS");
	}
	
	if((str_enemy = (TEnemy *)calloc(4,sizeof(TEnemy)))==NULL){
				printf("ERROR AL RESERVAR LOS ENEMIGOS");
	}
		
}

void liberarPeluza(){
	
	
	free(Block_sprite_Enemy);
	free(str_enemy);
	
}