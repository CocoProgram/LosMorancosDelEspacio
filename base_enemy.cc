/*
esat::SpriteHandle *Block_sprite_Enemy;

struct TEnemy {
	float posx, posy;
	esat::SpriteHandle *enemy_sprites;
	//EnemyTypes enemy_type;
	bool is_alive;
	float speedx, speedy;
	int points;
	char colour;	
	int phase_animation;	
	int seg_counter = 0;	
};
TEnemy *str_enemy;
*/

//LLamar dentro de PreMemorySaved
void ReservaMemoriaEnemy(){
	
	if((Block_sprite_Enemy = (esat::SpriteHandle *)calloc(16,sizeof(esat::SpriteHandle)))==NULL){
				printf("ERROR AL RESERVAR LOS SPRITES DE LOS ENEMIGOS");
	}
	
	if((str_enemy = (TEnemy *)calloc(4,sizeof(TEnemy)))==NULL){
				printf("ERROR AL RESERVAR LOS ENEMIGOS");
	}
		
}

//LLamar dentro de FreeMemorySaved
void LiberarEnemy(){
	
	
	free(Block_sprite_Enemy);
	free(str_enemy);
	
}