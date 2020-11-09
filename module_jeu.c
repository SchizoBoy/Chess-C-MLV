#include "assets.h"

void jeu(){
  int jeu = 1;
  Piece *board[8][8];
  Piece set_piece[32];
  Coord pos, target;
  int i, moves[9];
  MLV_create_window("jeu", "jeu", CASE*8, CASE*8);
  init_plateau(board, set_piece);
  actualise_plateau(board, pos, moves, 0);

  while(jeu == 1){
    pos = clic();
    if(est_piece(board, pos)){
      for(i = 0; i<9; i++){
        moves[i] = 0;
      }
      moves_legaux(board, pos, moves);
      actualise_plateau(board, pos, moves, 1);

      target = clic();
      if(est_legal(board, pos, target, moves)){
        board[target.y][target.x] = board[pos.y][pos.x];
        board[pos.y][pos.x] = NULL;
      }
      actualise_plateau(board, pos, moves, 0);
    }
    if(est_echec_et_mat(board, Noir)){
      printf("c'est tout bon\n");
      jeu = 0;
    }
  }
  exit(0);
}