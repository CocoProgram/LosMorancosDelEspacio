

void GameOver(){

  esat::DrawSetFillColor(255,255,255,255);
  esat::DrawSetTextSize(100);
  esat::DrawText(200, 155, "GAME OVER");
  esat::DrawSetTextSize(40);

  esat::DrawText( 250, 275, "RECORD : ");
  esat::DrawText( 400, 275, g_write_hi);

  esat::DrawText( 225, 375, "YOUR SCORE : ");
  esat::DrawText( 425, 375, g_write_player1score);

  esat::DrawText( 150, 550, "PRESS ENTER TO GO TO THE MENU");

  if ( esat::IsSpecialKeyDown( esat::kSpecialKey_Enter)){
    phase = kGamePhase_Menu;
  }

}
