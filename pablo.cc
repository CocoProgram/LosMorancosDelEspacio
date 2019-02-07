

void MemoryForInterface(){
  g_write_player1score = (char*)malloc(6*sizeof(char));
  g_write_player2score = (char*)malloc(6*sizeof(char));
  g_write_hi = (char*)malloc(6*sizeof(char));
  g_write_player1lives = (char*)malloc(2*sizeof(char));

  g_white_box1 = (float*)malloc(10*sizeof(float));
  g_white_box2 = (float*)malloc(10*sizeof(float));
  g_white_box3 = (float*)malloc(10*sizeof(float));

  s_intro = (esat::SpriteHandle*)malloc(2*sizeof(esat::SpriteHandle));
}

void FreeMemoryForInterface(){
  free(g_write_hi);
  free(g_write_player1lives);
  free(g_write_player1score);
  free(g_write_player2score);

  free(s_intro);
}

void LoadInterfaceSprites(){
  //Player life
  s_vida = esat::SpriteFromFile("./resources/Sprites/player_lifes.png");

  // FUENTE
  esat::DrawSetTextFont("./resources/Fonts/zx_spectrum-7.ttf");
  esat::DrawSetTextSize(40);

  //intro
  *(s_intro) = esat::SpriteFromFile("./resources/Sprites/intro_jetpac1_2.0.png");
  *(s_intro + 1) = esat::SpriteFromFile("./resources/Sprites/intro_jetpac2_2.0.png");
}

void ReleaseSpritesForInterface(){
  esat::SpriteRelease( s_vida );

  //intro
  esat::SpriteRelease( *(s_intro) );
  esat::SpriteRelease( *(s_intro + 1) );
}

void InitInterfaceParametres(){
  //White Box 1:
  *(g_white_box1) = 195;					//x
  *(g_white_box1 + 1) = 230;			//y
  *(g_white_box1 + 2) = 530;			//x2
  *(g_white_box1 + 3) = 230;			//y
  *(g_white_box1 + 4) = 530;			//x2
  *(g_white_box1 + 5) = 255;			//y2
  *(g_white_box1 + 6) = 195;			//x
  *(g_white_box1 + 7) = 255;			//y2
  *(g_white_box1 + 8) = 195;			//x
  *(g_white_box1 + 9) = 230;			//y

  //White Box 2:
  *(g_white_box2) = 195;					//x
  *(g_white_box2 + 1) = 280;			//y
  *(g_white_box2 + 2) = 530;			//x2
  *(g_white_box2 + 3) = 280;			//y
  *(g_white_box2 + 4) = 530;			//x2
  *(g_white_box2 + 5) = 305;			//y2
  *(g_white_box2 + 6) = 195;			//x
  *(g_white_box2 + 7) = 305;			//y2
  *(g_white_box2 + 8) = 195;			//x
  *(g_white_box2 + 9) = 280;			//y

  //White Box 3:
  *(g_white_box3) = 195;					//x
  *(g_white_box3 + 1) = 330;			//y
  *(g_white_box3 + 2) = 440;			//x2
  *(g_white_box3 + 3) = 330;			//y
  *(g_white_box3 + 4) = 440;			//x2
  *(g_white_box3 + 5) = 355;			//y2
  *(g_white_box3 + 6) = 195;			//x
  *(g_white_box3 + 7) = 355;			//y2
  *(g_white_box3 + 8) = 195;			//x
  *(g_white_box3 + 9) = 330;			//y
}

void PrintScore () {

  esat::DrawSetFillColor(255,255,255);
	esat::DrawText(25,25,"1 UP");
  esat::DrawSetFillColor(96, 219, 219);
	esat::DrawText(375,25,"HI");
  esat::DrawSetFillColor(255,255,255);
	esat::DrawText(650,25,"2 UP");

	//PLAYER 1
  esat::DrawSetFillColor(170, 151, 57);
	if(str_player.score >= 0 && str_player.score <10){
		itoa(str_player.score, g_write_player1score, 10);
		esat::DrawText(20,50, "00000");
		esat::DrawText(100,50, g_write_player1score);
	}
	if(str_player.score >= 10 && str_player.score <100){
		itoa(str_player.score, g_write_player1score, 10);
		esat::DrawText(20,50, "0000");
		esat::DrawText(85,50, g_write_player1score);
	}
	if(str_player.score >= 100 && str_player.score <1000){
		itoa(str_player.score, g_write_player1score, 10);
		esat::DrawText(20,50, "000");
		esat::DrawText(70,50, g_write_player1score);
	}
	if(str_player.score >= 1000 && str_player.score <10000){
		itoa(str_player.score, g_write_player1score, 10);
		esat::DrawText(20,50, "00");
		esat::DrawText(55,50, g_write_player1score);
	}
	if(str_player.score >= 10000 && str_player.score <100000){
		itoa(str_player.score, g_write_player1score, 10);
		esat::DrawText(20,50, "0");
		esat::DrawText(40,50, g_write_player1score);
	}
	if(str_player.score >= 100000 ){
		itoa(str_player.score, g_write_player1score, 10);
		esat::DrawText(25,50, g_write_player1score);
	}
	//PLAYER 2
  /*
	if(score2 >= 0 && score2 <10){
		itoa(score2, g_write_player2score, 10);
		esat::DrawText(685,50, "00000");
		esat::DrawText(760,50, g_write_player2score);
	}
	if(score2 >= 10 && score2 <100){
		itoa(score2, g_write_player2score, 10);
		esat::DrawText(685,50, "0000");
		esat::DrawText(745,50, g_write_player2score);
	}
	if(score2 >= 100 && score2 <1000){
		itoa(score2, g_write_player2score, 10);
		esat::DrawText(685,50, "000");
		esat::DrawText(730,50, g_write_player2score);
	}
	if(score2 >= 1000 && score2 <10000){
		itoa(score2, write_player2score, 10);
		esat::DrawText(685,50, "00");
		esat::DrawText(715,50, write_player2score);
	}
	if(score2 >= 10000 && score2 <100000){
		itoa(score2, g_write_player2score, 10);
		esat::DrawText(685,50, "0");
		esat::DrawText(700,50, write_player2score);
	}
	if(score2 >= 100000 ){
		itoa(score2, g_write_player2score, 10);
		esat::DrawText(685,50, g_write_player2score);
	}
  */
	//HI-SCORE
	if( str_player.score > g_HiScore){
		g_HiScore = str_player.score;
	}
  /*
	if( score2 > hi_score){
		g_HiScore = score2;
	}
  */

	if(g_HiScore >= 0 && g_HiScore <10){
		itoa(g_HiScore, g_write_hi, 10);
		esat::DrawText(350,50, "00000");
		esat::DrawText(430,50, g_write_hi);
	}
	if(g_HiScore >= 10 && g_HiScore <100){
		itoa(g_HiScore, g_write_hi, 10);
		esat::DrawText(350,50, "0000");
		esat::DrawText(415,50, g_write_hi);
	}
	if(g_HiScore >= 100 && g_HiScore <1000){
		itoa(g_HiScore, g_write_hi, 10);
		esat::DrawText(350,50, "000");
		esat::DrawText(400,50, g_write_hi);
	}
	if(g_HiScore >= 1000 && g_HiScore <10000){
		itoa(g_HiScore, g_write_hi, 10);
		esat::DrawText(350,50, "00");
		esat::DrawText(385,50, g_write_hi);
	}
	if(g_HiScore >= 10000 && g_HiScore <100000){
		itoa(g_HiScore, g_write_hi, 10);
		esat::DrawText(350,50, "0");
		esat::DrawText(370,50, g_write_hi);
	}
	if(g_HiScore >= 100000 ){
		itoa(g_HiScore, g_write_hi, 10);
		esat::DrawText(350,50, g_write_hi);
	}

  //VIDAS
  esat::DrawSetFillColor(255,255,255);
  itoa(str_player.vida, g_write_player1lives, 10);
  esat::DrawText(200,25, g_write_player1lives);
  esat::DrawSprite(s_vida,225,5);

}

void PrintMenu(){
  if ( esat::IsKeyDown('1') ){
    mode = OnePlayer;
  }
  if ( esat::IsKeyDown('2') ){
    mode = TwoPlayers;
  }
  if ( esat::IsKeyDown('5') && mode != NoneSelected ){
    phase = kGamePhase_InGame;
  }

  esat::DrawSetFillColor(255,255,255);

  esat::DrawText(200,150, "JETPAC GAME SELECTION");
  if(mode == OnePlayer && seg_counter%2 == 0){
    esat::DrawSetFillColor(255,255,255);
    esat::DrawSolidPath(g_white_box1, 5, true);
    esat::DrawSetFillColor(0,0,0);
    esat::DrawText(200,250, "1      1 PLAYER GAME");
  }else{
    esat::DrawSetFillColor(255,255,255);
    esat::DrawText(200,250, "1      1 PLAYER GAME");
  }
  esat::DrawSetFillColor(255,255,255);
  if(mode == TwoPlayers && seg_counter%2 == 0){
    esat::DrawSetFillColor(255,255,255);
    esat::DrawSolidPath(g_white_box2, 5, true);
    esat::DrawSetFillColor(0,0,0);
    esat::DrawText(200,300, "2      2 PLAYER GAME");
  }else{
    esat::DrawSetFillColor(255,255,255);
    esat::DrawText(200,300, "2      2 PLAYER GAME");
  }
  esat::DrawSetFillColor(255,255,255);
  if ( g_keyboardSelected && seg_counter%2 == 0){
    esat::DrawSetFillColor(255,255,255);
    esat::DrawSolidPath(g_white_box3, 5, true);
    esat::DrawSetFillColor(0,0,0);
    esat::DrawText(200,350, "3      KEYBOARD");
  }else{
    esat::DrawSetFillColor(255,255,255);
    esat::DrawText(200,350, "3      KEYBOARD");
  }
  esat::DrawSetFillColor(255,255,255);
  esat::DrawText(200,400, "4      KEMPSTONE JOYSTICK");
  esat::DrawText(200,500, "5      START GAME");
  esat::DrawText(140,550, "© 1983 A.C.G ALL RIGHTS RESERVED");
}

void DrawLoadScreen(){
  int aux_rand = 0;
  for (int i=0;i< kWindowY; i++){
    if(seg_counter%1 == 0){aux_rand = rand()%3;}
    switch (aux_rand) {
      case 0:
        esat::DrawSetStrokeColor(255, 255, 0);
        break;
      case 1:
        esat::DrawSetStrokeColor(2, 24, 165);
        break;
      case 2:
        esat::DrawSetStrokeColor(103, 108, 113);
        break;
    }
    esat::DrawLine(0, i, kWindowX, i);
  }
}

void PrintIntro(){
  DrawLoadScreen();

  if ( seg_counter% 2 == 0 ){
    esat::DrawSprite( (*s_intro), 80, 50);
  }else{
  esat::DrawSprite( (*(s_intro + 1 )), 80, 50);
  }
  if( esat::IsSpecialKeyDown(esat::kSpecialKey_Space) ){
    phase = kGamePhase_Menu;
  }
}
