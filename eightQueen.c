#include <stdio.h>

#define ROWS 8
#define COLUMNS 8

int count=0;
char cmd=' ';

void arrayInit(int *a,int len,int initdata);
void locateQueen(int row,int board[],int col[],int mdia[],int vdia[]);
void showCheckBoard(int* board);

int main(int args,char* argv[]){
  int checkBoard[ROWS*COLUMNS];
  int column[COLUMNS];
  int mdiagonal[15];
  int vdiagonal[15];
  int row=1;
  
  arrayInit(checkBoard,ROWS*COLUMNS,'*');
  arrayInit(column,COLUMNS,1);
  arrayInit(mdiagonal,15,1);
  arrayInit(vdiagonal,15,1);
  
  locateQueen(row,checkBoard,column,mdiagonal,vdiagonal);
  	
  getchar();
  return 0;
}

void arrayInit(int *a,int len,int initdata){
  int i=0;
  while(i<len)
    a[i++]=initdata;
}

void locateQueen(int row,int board[],int col[],int mdia[],int vdia[]){
  int j=1;
  for(;j<=COLUMNS;j++)
    if( 1==col[j-1] && 1==mdia[row+j-2] && 1==vdia[row-j+7] ){
      board[(row-1)*COLUMNS+(j-1)]='@';
      col[j-1]=0;
      mdia[row+j-2]=0;
      vdia[row-j+7]=0;
      if(row<8)
        locateQueen(row+1, board , col , mdia , vdia);
      else
        showCheckBoard(board);      

	  //»ØËÝ
	  board[(row-1)*COLUMNS+(j-1)]='*';
      col[j-1]=1;
      mdia[row+j-2]=1;
      vdia[row-j+7]=1;
    }
}

void showCheckBoard(int* board){
  int i=0;
  count++;
  printf("this is solution %d:\n",count);
  for(i=0;i<64;i++){
    putchar(board[i]);
    if((i+1)%ROWS==0)
      putchar('\n');
    else
      putchar(' ');
  }
  if(cmd==' '){
	  printf("press blank to check out the next one,\npress 'r' to see all the rest:\n");
	  cmd=getchar();
          getchar();
	  putchar(cmd);
  }
}
