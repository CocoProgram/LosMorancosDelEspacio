void MemoriaAudio(){
audio_disparo.load("./resources/sounds/Disparo.ogg");
audio_nave.load("./resources/sounds/NaveParriba.ogg");
audio_intro.load("./resources/sounds/intro.ogg");

}



void MenuBackgroundSound(){
canal.play(audio_intro,1000.0f);


}


void PlaySound(){
 /* if (g_shoot == true) {
    canal.play(audio_disparo);
  } else {
  (audio_disparo).stop();
}*/

  if (str_player.show_player == false) {
    canal.play(audio_nave);
  } else {
  (audio_nave).stop();
  }
}
