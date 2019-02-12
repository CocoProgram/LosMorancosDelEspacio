void MemoriaAudio(){
audio_disparo.load("./resources/sounds/Disparo.wav");
audio_nave.load("./resources/sounds/NaveParriba.wav");
audio_intro.load("./resources/sounds/NaveParriba.wav");

}



void MenuBackgroundSound(){
canal.play(audio_intro,100.0f);
  /*if(canal.play(audio_intro,100.0f)){
    printf("%f", getVolume(canal.play(audio_intro,100.0f)));
  }*/

}


void PlaySound(){
  if (g_shoot == true) {
    canal.play(audio_disparo);
  } else {
  (audio_disparo).stop();
}

  if (str_player.show_player == true) {
    canal.play(audio_nave);
  } else if(str_player.show_player == false){
  (audio_nave).stop();
  }
}
