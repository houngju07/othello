#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//#define N6

//int	init_othello(){
	
int main(){
	int i; 
	int j;
	int N;
	int game_Board[N][N];
	
			printf("input even num N: ");
			scanf("%i", &N);
			
		while((N%2)!= 0){
				printf("N is not even number\n");
				printf("input even num N: ");
				scanf("%i", &N);
			}
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			game_Board[i][j] = 1;
			printf("%i", game_Board[i][j]);
		}	printf("\n");
	}

	return 0;
	
	//return game_Board[i][j];
}

/*int main(){
	int N;
	int Borad;
	
	printf("N: ");
	scanf("%i", &N);
	
	printf("Board\n");
	printf("%c", init_othello);
}

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
