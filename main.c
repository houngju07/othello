#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char *argv[]) {
	int N=6;
	char gameboard[N][N];
	int i,j;
	int x,y;
	int isGameEnd;
	
	//init othello
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			gameboard[i][j]=' ';
	}
	gameboard[N/2-1][N/2-1]='O';
	gameboard[N/2][N/2]='O';
	gameboard[N/2-1][N/2]='X';
	gameboard[N/2][N/2-1]='X';	
	
	//print_othello
	printf("  0 1 2 3 4 5\n");
	printf(" ------------\n");
	
	for(i=0;i<N;i++){
		printf("%i|",i);
		for(j=0;j<N;j++)
			printf("%c|", gameboard[i][j]);
		printf("\n");
	}		
	printf(" -----------\n");
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			if(gameboard[i][j]!=' '){
				isGameEnd++;
			}
			else 
				isGameEnd==0;}
	
printf("%i\n",	isGameEnd);
		
	//input
		printf("input row: ");
		scanf("%i",&x);
		printf("input col: ");
		scanf("%i",&y);
	
		gameboard[x][y]='X';
		gameboard[i][j]=gameboard[x][y];

			
	


	return 0;
}

/*
void init_othello(int N, char gameboard[N][N]){
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
}

int	flip_result(int N,char gameboard[N][N]);
int check_flip_result(int N,char gameboard[N][N]);


int Blank(int N, char gameboard[N][N]){
	int Blank=0;
	int i,j;
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(gameboard[i][j]==' ')
				Blank++;
			}
	}
	printf("Blank %i\n", Blank);

	return Blank;
}

void print_othello(int N, char gameboard[N][N]){
	int i,j;
	printf("  0 1 2 3 4 5\n");
	printf("  -----------\n");
	for(i=0;i<N;i++){
		printf("%i|",i);
		for(j=0;j<N;j++){
			printf("%c|", gameboard[i][j]);
		}	
		printf("\n");
		printf("  -----------\n");
	}
}


int status(int N,int gameboard[N][N]){	
	int i; 
	int j;
	int X_num=0;
	int O_num=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(gameboard[i][j]=='X')
				X_num++;
			else if(gameboard[i][j]=='O')
				O_num++;
			}
	}
	printf("number of X: %i,number of O: %i\n", X_num, O_num);
}


void check_result(int N,int gameboard[N][N]){
	int i; 
	int j;
	int X_num=0;
	int O_num=0;
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(gameboard[i][j]=='X')
				X_num++;
			else if(gameboard[i][j]=='O')
				O_num++;
			}
	}
	printf("No more place\n");
	if(X_num<O_num)
		printf("O player win\n");
	else if(X_num>O_num)
		printf("X player win\n");
	else
		printf("draw\n");
}

void main(){
	int N=6;
	char gameboard[N][N];
	int isGameEnd;
	int x,y;
	int a,b;
	int check;
	int flip;
	


//init_othello
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

//	init_othello(N,gameboard[N][N]);//reset the board
//	isGameEnd=Blank(N,gameboard[N][N]);
	
//	print_othello(N,gameboard[N][N]);
	
	
	check_flip_result(N,gameboard[N][N]);
	flip_result(N,gameboard[x][y]);
	
	while (isGameEnd!=0){
		print_othello(N,gameboard[N][N]);
		
		if((check==0)&&(flip!=0))
		
			continue;
			
		printf("input row: ");
		scanf("%i", &x);
		printf("input colmn: ");
		scanf("%i", &y);
		gameboard[x][y] = 'X';
			
		if(check_flip_result==0)
			if(flip_result!=0){
				printf("");
				printf("");
			}
		else
			printf("invalid input");
	}
	
	check_result(N,gameboard[N][N]);
	return 0;
}

/*
int	flip_result(int x, int y,int N,int gameboard[x][y]){
	int W,E,S,North,SW,NW,SE,NE =0;
	int flip_result;
	int k;
	
	if(gameboard[x][y]==' '){	
		for(k=0;k<x;k++)
			if(gameboard[x-k][y]=='Y')
				W++;
			else;
			if(gameboard[x-W-1][y]=='X');
			else
				W=0;
		
		for(k=0;k<x;k++)
			if(gameboard[x+k][y]=='Y')
				E++;
			else;
			if(gameboard[x+E+1][y]=='X');
			else
				E=0;
							
		for(k=0;k<x;k++)
			if(gameboard[x][y-k]=='Y')
				S++;
			else;
			if(gameboard[x][y-S-1]=='X');
			else
				S=0;
			
		for(k=0;k<x;k++)
			if(gameboard[x][y+k]=='Y')
				North++;
			else;
			if(gameboard[x][y+S+1]=='X');
			else
				North=0;
			
		for(k=0;k<x;k++)
			if(gameboard[x-k][y-k]=='Y')
				SW++;
			else;
			if(gameboard[x-SW-1][y-SW-1]=='X');
			else
				SW=0;
			
		for(k=0;k<x;k++)
			if(gameboard[x-k][y+k]=='Y')
				NW++;
			else;
			if(gameboard[x-NW-1][y+NW+1]=='X');
			else
				NW=0;
			
		for(k=0;k<x;k++)
			if(gameboard[x+k][y-k]=='Y')
				SE++;
			else;
			if(gameboard[x+SE+1][y-SE-1]=='X');
			else
				SE=0;
			
		for(k=0;k<x;k++)
			if(gameboard[x+k][y+k]=='Y')
				NE++;
			else;
			if(gameboard[x+NE+1][y+NE+1]=='X');
			else
				NE=0;
				
		printf("W:%i, E:%i, S:%i N:%i, SW:%i, NW:%i, SE:%i, NE:%i\n" W,E,S,North,SW,NW,SE,NE);
		
		flip_result=(W+E+S+North+SW+NW+SE+NE);
	}	
	else
	flip_result=0;
	
	return flip_result;
}

int check_flip_result(int N,int gameboard[N][N]){
	int i,j;
	int check_flip_result=0;
	
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(flip_result(int N,int gameboard[N][N])!=0)
					check_flip_result++;
				else
					check_flip_result=0;
				}
		}
		
	return check_flip_result;
}

/*
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

	//return Blank;
		
	//flip result
	int W,E,S,North,SW,NW,SE,NE =0;
	int k;
		for(k=0;k<x;k++)
			if(gameboard[x-k][y]=='Y')
				W++;
			else;
			if(gameboard[x-W-1][y]=='X');
			else
				W=0;
		
		for(k=0;k<x;k++)
			if(gameboard[x+k][y]=='Y')
				E++;
			else;
			if(gameboard[x+E+1][y]=='X');
			else
				E=0;
							
		for(k=0;k<x;k++)
			if(gameboard[x][y-k]=='Y')
				S++;
			else;
			if(gameboard[x][y-S-1]=='X');
			else
				S=0;
			
		for(k=0;k<x;k++)
			if(gameboard[x][y+k]=='Y')
				North++;
			else;
			if(gameboard[x][y+S+1]=='X');
			else
				North=0;
			
		for(k=0;k<x;k++)
			if(gameboard[x-k][y-k]=='Y')
				SW++;
			else;
			if(gameboard[x-SW-1][y-SW-1]=='X');
			else
				SW=0;
			
		for(k=0;k<x;k++)
			if(gameboard[x-k][y+k]=='Y')
				NW++;
			else;
			if(gameboard[x-NW-1][y+NW+1]=='X');
			else
				NW=0;
			
		for(k=0;k<x;k++)
			if(gameboard[x+k][y-k]=='Y')
				SE++;
			else;
			if(gameboard[x+SE+1][y-SE-1]=='X');
			else
				SE=0;
			
		for(k=0;k<x;k++)
			if(gameboard[x+k][y+k]=='Y')
				NE++;
			else;
			if(gameboard[x+NE+1][y+NE+1]=='X');
			else
				NE=0;				
		
		
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


