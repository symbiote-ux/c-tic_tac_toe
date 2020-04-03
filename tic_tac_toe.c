#include<stdio.h>
#include<stdlib.h>

void display_board(char *);
void start_game(char *);

void start_game(char tiles[]) {
  int turn = 1,move;
  if(turn) {
    printf("Human turn: Enter number between 1-9 \n");
    scanf("%d",&move);
    tiles[move -1] = 'H';
    turn = !turn;
    display_board(tiles);
  } 
  else {
  printf("Machine Turn:\n");
  move = rand() % 9 + 1;
  tiles[move] = 'M';
  display_board(tiles);
  }
}

void display_board(char tiles[]) {
  printf(" %c | %c | %c \n",tiles[0],tiles[1],tiles[2]);
  printf("-----------\n");
  printf(" %c | %c | %c \n",tiles[3],tiles[4],tiles[5]);
  printf("-----------\n");
  printf(" %c | %c | %c \n",tiles[6],tiles[7],tiles[8]);
}

int main() {
  char tiles[9];
  for(int i = 0; i < sizeof(tiles)/sizeof(char); i++){
    tiles[i] ='\0';
  }
  display_board(tiles);
  start_game(tiles);
  return 0;
}