#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*

int init_othello(){}
int isGameEnd(){}
int print_othello(){}
void check_result(){}

void main(){
	
	init_othello();//reset the board
	
	while (isGameEnd()==0){
		print_othello();
		if(flip_result!=0)
			continue;
		//input
		if()
			if(){
				printf("");
				printf("");
			}
		else
			printf("invalid input");
	}
	check_result();
}*/

int main(){
	int N=6;
	char gameboard[N][N];
	int x,y;
	
	//init_othello()
		int i,j;
		int center;
		center = N/2;
			for(i=0;i<N;i++){
				for(j=0;j<N;j++){
					gameboard[i][j]=' ';
					}
				}
				gameboard[center-1][center-1] = 'O';
				gameboard[center][center] = 'O';
				gameboard[center][center-1] = 'X';
				gameboard[center-1][center] = 'X';
	
	//print_othello
	int a,b;
	printf("  0 1 2 3 4 5\n");
	printf("  -----------\n");
	for(a=0;a<N;a++){
		printf("%i|",a);
		for(b=0;b<N;b++){
			printf("%c|", gameboard[a][b]);
		}	
		printf("\n");
		printf("  -----------\n");
	}

	//X turn
	printf("X turn\n");
	printf("input row: ");
	scanf("%i", &x);
	printf("input colmn: ");
	scanf("%i", &y);
	gameboard[x][y] = 'X';
	
	//Status
	int c; 
	int d;
	int X_num=0;
	int O_num=0;
	
	for(c=0;c<N;c++){
		for(d=0;d<N;d++){
			if(gameboard[c][d]=='X')
				X_num++;
			else if(gameboard[c][d]=='O')
				O_num++;
			}
	}
	printf("number of X: %i,number of O: %i\n", X_num, O_num);
	
	//check_result
	printf("No more place\n");
	if(X_num<O_num)
		printf("O player win\n");
	else if(X_num>O_num)
		printf("X player win\n");
	else
		printf("draw\n");
		
	//isGameEnd
	int Blank=0;
	int e,f;
		for(e=0;e<N;e++){
			for(f=0;f<N;f++){
			if(gameboard[e][f]==' ')
						Blank++;
				}
	}
	printf("Blank %i\n", Blank);
	//return Blank;
		
	//flip result
	int W,E,S,North,SW,NW,SE,NE =0;
	int k;
		for(k=0;k<x;k++)
			if(gameboard[x-k][y]=='Y')
				W++;
			else;
		for(k=0;k<x;k++)
			if(gameboard[x+k][y]=='Y')
				E++;
			else;
		for(k=0;k<x;k++)
			if(gameboard[x][y-k]=='Y')
				S++;
			else;
		for(k=0;k<x;k++)
			if(gameboard[x][y+k]=='Y')
				North++;
			else;
		for(k=0;k<x;k++)
			if(gameboard[x-k][y-k]=='Y')
				SW++;
			else;
		for(k=0;k<x;k++)
			if(gameboard[x-k][y+k]=='Y')
				NW++;
			else;
		for(k=0;k<x;k++)
			if(gameboard[x+k][y-k]=='Y')
				SE++;
			else;
		for(k=0;k<x;k++)
			if(gameboard[x+k][y+k]=='Y')
				NE++;
			else;			
		
//		
		printf("ivalid input(no flip happens)");
		
	//choose input player1
//	printf("input x: ");
//	scanf("%i", &x);
//	printf("input y: ");
//	scanf("%i", &y);
//	gameboard[x-1][y-1] = 1;
	
/*	//choose input player2
	printf("input x: ");
	scanf("%i", &x);
	printf("input y: ");
	scanf("%i", &y);
	gameboard[x-1][y-1] = 2;
	
	//player1
	printf("player1 turn\n");
	//player2
	printf("player2 turn\n");
	
	//reverse stone player1
/*	int reverse_stone;
		if(gameboard[x-1][y-1]==0)
		
			if
		}((gameboard[x-2][y-2]==0) && (gameboard[x-1][y-1]!=0)
			gameboard[x-1][y-1] = 1;
		else
		
		switch(gameboard[x-1][y-1]){
			case 0:
				
			
			case 1:
		}
	
	//game
//	while (isGameEnd()==0){

/*		if((gameboard[x][y]==0) & )
			continue;
		
		if()
			if(){
				printf("");
				printf("");
			}
		else
			printf("wrong position");
	}
	check_result();
*/

	return 0;
}
