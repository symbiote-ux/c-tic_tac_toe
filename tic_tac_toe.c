#include<stdio.h>
#include<stdlib.h>

void display_board(char *);
void start_game(char *);
int has_won(char, char *);

int has_won(char name,char tiles[]) {
  if(((tiles[0] == tiles[1]) && (tiles[1] == tiles[2]) && (tiles[1] == name)) ||
     ((tiles[4] == tiles[5]) && (tiles[5] == tiles[6]) && (tiles[5] == name)) ||
     ((tiles[7] == tiles[8]) && (tiles[8] == tiles[9]) && (tiles[8] == name)) ||
     ((tiles[1] == tiles[4]) && (tiles[4] == tiles[7]) && (tiles[4] == name)) ||
     ((tiles[2] == tiles[5]) && (tiles[5] == tiles[8]) && (tiles[5] == name)) ||
     ((tiles[3] == tiles[6]) && (tiles[6] == tiles[9]) && (tiles[6] == name)) ||
     ((tiles[1] == tiles[5]) && (tiles[5] == tiles[9]) && (tiles[5] == name)) ||
     ((tiles[3] == tiles[5]) && (tiles[5] == tiles[7]) && (tiles[5] == name))) {
       return 1;
     }
     return 0;
};

void start_game(char tiles[]) {
  int turn = 1,move,i=1;
  while(i != 9) {
  if(turn) {
    printf("Human turn: Enter number between 1-9 \n");
    scanf("%d",&move);
    tiles[move -1] = 'H';
    display_board(tiles);
    if(has_won('H',tiles)) {
      printf("You Wins\n");
      exit(0);
    }
    turn =! turn;
  } 
  else {
  printf("Machine Turn:\n");
  move = rand() % 9 + 1;
  tiles[move] = 'M';
  display_board(tiles);
  if(has_won('M',tiles)) {
    printf("Machine Won\n");
    exit(0);
  }
  turn =!turn;
  }
  }
  i++;
}

void display_board(char tiles[]) {
  printf(" %c | %c | %c \n",tiles[0],tiles[1],tiles[2]);
  printf("-----------\n");
  printf(" %c | %c | %c \n",tiles[3],tiles[4],tiles[5]);
  printf("-----------\n");
  printf(" %c | %c | %c \n",tiles[6],tiles[7],tiles[8]);
}

int main() {
  int i;
  char tiles[9];
  for(i = 0; i < sizeof(tiles)/sizeof(char); i++){
    tiles[i] ='\0';
  }
  display_board(tiles);
  start_game(tiles);
  return 0;
}