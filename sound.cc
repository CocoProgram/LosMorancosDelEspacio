void MemoriaAudio(){

  audio_disparo.load("./resources/sounds/Disparo.ogg");
  audio_nave.load("./resources/sounds/NaveParriba.ogg");
  audio_intro.load("./resources/sounds/intro.ogg");

}

void MenuBackgroundSound(){
  canal.play(audio_intro,1.0f); //ponedlo luego a 20, que esto solo era trolling.
}


void PlaySound(){
    if ( g_shoot == true) {
      audio_disparo.stop();
      canal.play(audio_disparo ,1.0f);
    }

  if (str_player.show_player == false) {
    canal.play(audio_nave, 1.0f);
  } else {
  (audio_nave).stop();
  }
}
