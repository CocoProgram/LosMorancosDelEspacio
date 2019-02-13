//Llamar antes del comienzo de cada nivel
void InicializarEnemyLevel(){

	switch(g_level){

		case 1: InicializarMeteoro(str_enemy, Block_sprite_Enemy);break;
		case 2: InicializarPelusa(str_enemy, Block_sprite_Enemy); break;
		case 3: InicializarBola(str_enemy, Block_sprite_Enemy); break;
		case 4: InicializarAvion(str_enemy, Block_sprite_Enemy);break;
		case 5: InicializarOvni(str_enemy, Block_sprite_Enemy);break;
		case 6: InicializarCruz(str_enemy, Block_sprite_Enemy);break;
		case 7: InicializarAlcon(str_enemy, Block_sprite_Enemy);break;
		case 8: InicializarSapo(str_enemy, Block_sprite_Enemy);break;
		case 9: InicializarMeteoro(str_enemy, Block_sprite_Enemy);break;
		case 10: InicializarPelusa(str_enemy, Block_sprite_Enemy); break;
		case 11: InicializarBola(str_enemy, Block_sprite_Enemy); break;
		case 12: InicializarAvion(str_enemy, Block_sprite_Enemy);break;
		case 13: InicializarOvni(str_enemy, Block_sprite_Enemy);break;
		case 14: InicializarCruz(str_enemy, Block_sprite_Enemy);break;
		case 15: InicializarAlcon(str_enemy, Block_sprite_Enemy);break;
		case 16: InicializarSapo(str_enemy, Block_sprite_Enemy);break;
		default: printf("ERROR AL INICIAR ENEMIGOS-g_level = %d", g_level);
	}

}


//Llamar dentro del bucle del juego
void ControlEnemyLevel(){

	switch(g_level){

		case 1: DibujarMeteoro();break;
		case 2: controlPelusa(); break;
		case 3: controlBola(); break;
		case 4: controlAvion();break;
		case 5: controlOvni();break;
		case 6: controlCruces();break;
		case 7: DibujarAlcon();break;
		case 8: controlSapo();break;
		case 9: DibujarMeteoro();break;
		case 10: controlPelusa(); break;
		case 11: controlBola(); break;
		case 12: controlAvion();break;
		case 13: controlOvni();break;
		case 14: controlCruces();break;
		case 15: DibujarAlcon();break;
		case 16: controlSapo();break;
		default: printf("ERROR AL CONTROLAR ENEMIGOS-g_level = %d", g_level);
	}

}
