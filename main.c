#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//#define N 6

/*int	isGameEnd(){
	if game end result 1
}

int gameboard[N][N];

void main(){
	
	init_othello();
	
	while (isGameEnd()==0){
		print_othello();
		if()
			continue;
		
		if()
			if(){
				printf("");
				printf("");
			}
		else
			printf("");
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
	if(X_num<O_num)
		printf("O player win\n");
	else if(X_num>O_num)
		printf("X player win\n");
	else
		printf("draw\n");
		
/*	//flip result
	int W, E, N, S, NW, NE, SW, SE;
	
		if()
		W=1;
		else;
		W=0;
		
		if()
		E=1;
		else;
		E=0;
		
		if()
		N=1;
		else;
		N=0;
		
		if()
		S=1;
		else;
		S=0;
		
		if()
		NW=1;
		else;
		NW=0;
		
		if()
		NE=1;
		else;
		NE=0;
		
		if()
		SW=1;
		else;
		SW=0;
		
		if()
		SE=1;
		else;
		SE=0;
		
	//invlid input
		if()
		
		
		else
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
