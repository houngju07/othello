#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//#define N 6
/*int N;

void print_gamebard(int gameboard[N][N]){
	int i,j;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%i", gameboard[i][j]);
		}	printf("\n");
	}
	return 0;
}

int	init_othello(int N, int gameboard[N][N]){
	int i,j;		
	int center ;
	center = (N/2);
	
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				gameboard[i][j]=0;
			}
		}
	gameboard[center][center] = 1;
	gameboard[center+1][center+1] =1;
	gameboard[center+1][center] = 2;
	gameboard[center][center+1] = 2;
	
	return gameboard[N][N];
}
*/
/*int define_N(){
	int N;
	printf("input even num N: ");
	scanf("%i", &N);
			
	while((N%2)!= 0){
	printf("N is not even number\n");
	printf("input even num N: ");
	scanf("%i", &N);
		}
	return N;
}
*/

/*int print_Board(int N){
	int i; 
	int j;
	int game_Board[N][N];
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			game_Board[i][j] = 1;
			printf("%i", game_Board[i][j]);
		}	printf("\n");
	}
	return game_Board[N][N];
}
*/

/*int main(){
	
	print_Board();
	
	return 0;
}*/

/*int	isGameEnd(){
	if game end result 1
}

int	print_othello(){
}

int check_result(){
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
			for(i=0;i<N;i++){
				for(j=0;j<N;j++){
					gameboard[i][j]=' ';
					}
				}
				gameboard[N/2-1][N/2-1] = 'O';
				gameboard[N/2][N/2] = 'O';
				gameboard[N/2][N/2-1] = 'X';
				gameboard[N/2-1][N/2] = 'X';
	
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
