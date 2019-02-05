void Flying(Tplayer *player){

	if (player->isFlying) {
			player->posy+=player->jetpac;
			if (player->jetpac<=-8){
				player->jetpac=-8;
			}
			if (player->jetpac>=3){
				player->jetpac=3;
			}
	} else {
		player->jetpac=0;
	}

	if (g_jetpac){
		player->jetpac-=0.25;
	}else if (player->isFlying){
		player->jetpac+=0.25;
	}
}
