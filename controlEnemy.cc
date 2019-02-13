//Llamar antes del comienzo de cada nivel
void InicializarEnemyLevel(){

	switch(g_level){

		case 1: break;
		case 2: InicializarPelusa(str_enemy, Block_sprite_Enemy); break;
		case 3: InicializarBola(str_enemy, Block_sprite_Enemy); break;
		case 4: InicializarAvion(str_enemy, Block_sprite_Enemy);break;
		case 5: InicializarOvni(str_enemy, Block_sprite_Enemy);break;
		case 6: break;
		case 7: break;
		case 8: break;
		default: printf("ERROR AL INICIAR ENEMIGOS-g_level = %d", g_level);
	}

}


//Llamar dentro del bucle del juego
void ControlEnemyLevel(){
if(loadingLevel == false)
{
	switch(g_level){

		case 1: break;
		case 2: controlPelusa(); break;
		case 3: controlBola(); break;
		case 4: controlAvion();break;
		case 5: controlOvni();break;
		case 6: break;
		case 7: break;
		case 8: break;
		default: printf("ERROR AL INICIAR ENEMIGOS-g_level = %d", g_level);
	}
}

}

//Bola al llenar la mitad de la nave, enemy++
//cruz al completar la nave, enemy++
//Esto solo ocurre una vez
