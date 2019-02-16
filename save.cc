//GUARDAR DATOS DE PARTIDA:
FILE *save_score;


void SaveHiScore(){

    save_score = fopen("save_score.dat", "wb");
    fwrite( &g_HiScore, sizeof(double), 1, save_score);
    fclose(save_score);

}

void CargarHiScore(){
  if ( (save_score = fopen("save_score.dat", "rb")) == NULL ) {

    save_score = fopen("save_score.dat", "wb");
    fclose(save_score);

  }else{

    fopen("save_score.dat", "rb");
    fread( &g_HiScore, sizeof(double), 1, save_score);
    fclose(save_score);
  }
}
