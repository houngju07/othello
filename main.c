#include <stdio.h>
#include <stdlib.h>

#define N 6
char gameboard[N][N];

/* run this program using the console pauser or add your own getch, system("pause") or input loop */ 

void init_othello(){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			gameboard[i][j]=' ';
	}
	gameboard[N/2-1][N/2-1]='O';
	gameboard[N/2][N/2]='O';
	gameboard[N/2-1][N/2]='X';
	gameboard[N/2][N/2-1]='X';	
}

void print_othello(){
	int i,j;
	
	printf("  0 1 2 3 4 5\n");
	printf(" ------------\n");
	for(i=0;i<N;i++){
		printf("%i|",i);
		for(j=0;j<N;j++)
			printf("%c|", gameboard[i][j]);
		printf("\n");
			printf(" ------------\n");
	}		
}

int get_input(int x){	
	printf(": ");
	scanf("%i",&x);
	
	return x;
}

int isGameEnd(){
	int i,j;
	int GameEnd=0;
	for(i=0;i<N;i++){	
		for(j=0;j<N;j++){
			if(gameboard[i][j]==' ')
				GameEnd++;
			else ;
		}
	}
	printf("%i\n",GameEnd);
	
	return GameEnd;
}

int status(){	
	int i,j;
	int blank_num;
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
	
	blank_num=(36-X_num-O_num);
	
	return blank_num;
}

void check_result(){	
	int i,j;
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
	
	if(X_num<O_num)
		printf("O player win\n");
	else if(X_num>O_num)
		printf("X player win\n");
	else
		printf("draw\n");
}

char get_player(int turn){
	char player;
	
	if((turn%2)==0)
		player='X';
	else
		player='O';
	
	return player;
}

char get_another_player(int turn){
	char another_player;
	
	if((turn%2)==0)
		another_player='O';
	else
		another_player='X';
	
	return another_player;
}


int North_flip(int x, int y, char player, char another_player){
	int k;
	int n;
	
	if(gameboard[x-1][y]==another_player){
		if(gameboard[x-2][y]==another_player){
			if(gameboard[x-3][y]==another_player){
				if(gameboard[x-4][y]==another_player){
					if(gameboard[x-5][y]==another_player)
						k=0;
					else if(gameboard[x-5][y]==player)
						k=4;
					else
						k=0;
				}
				else if(gameboard[x-4][y]==player)
					k=3;
				else
					k=0;
				}	
			else if(gameboard[x-3][y]==player)
				k=2;
			else
				k=0;
		}		
		else if(gameboard[x-2][y]==player)
			k=1;
		else
			k=0;
	}
	else 
		k=0;
	
	for(n=1;n<=k;n++){
		gameboard[x-n][y]=player;}

	return k;
}

int S_flip(int x, int y, char player, char another_player){
	int k;
	int n;
		
	if(gameboard[x+1][y]==another_player){
		if(gameboard[x+2][y]==another_player){
			if(gameboard[x+3][y]==another_player){
				if(gameboard[x+4][y]==another_player){
					if(gameboard[x+5][y]==another_player)
						k=0;
					else if(gameboard[x+5][y]==player)
						k=4;
					else
						k=0;
				}
				else if(gameboard[x+4][y]==player)
					k=3;
				else
					k=0;
				}	
			else if(gameboard[x+3][y]==player)
				k=2;
			else
				k=0;
		}		
		else if(gameboard[x+2][y]==player)
			k=1;
		else
			k=0;
	}
	else 
		k=0;
		
	for(n=1;n<=k;n++){
		gameboard[x+n][y]=player;}


	return k;
}

int W_flip(int x, int y, char player, char another_player){
	int k;
	int n;
		
	if(gameboard[x][y-1]==another_player){
		if(gameboard[x][y-2]==another_player){
			if(gameboard[x][y-3]==another_player){
				if(gameboard[x][y-4]==another_player){
					if(gameboard[x][y-5]==another_player)
						k=0;
					else if(gameboard[x][y-5]==player)
						k=4;
					else
						k=0;
				}
				else if(gameboard[x][y-4]==player)
					k=3;
				else
					k=0;
				}	
			else if(gameboard[x][y-3]==player)
				k=2;
			else
				k=0;
		}		
		else if(gameboard[x][y-2]==player)
			k=1;
		else
			k=0;
	}
	else 
		k=0;
		

	for(n=1;n<=k;n++){
		gameboard[x][y-n]=player;}

	return k;
}

int E_flip(int x, int y, char player, char another_player){
	int k;
	int n;
		
	if(gameboard[x][y+1]==another_player){
		if(gameboard[x][y+2]==another_player){
			if(gameboard[x][y+3]==another_player){
				if(gameboard[x][y+4]==another_player){
					if(gameboard[x][y+5]==another_player)
						k=0;
					else if(gameboard[x][y+5]==player)
						k=4;
					else
						k=0;
				}
				else if(gameboard[x][y+4]==player)
					k=3;
				else
					k=0;
				}	
			else if(gameboard[x][y+3]==player)
				k=2;
			else
				k=0;
		}		
		else if(gameboard[x][y+2]==player)
			k=1;
		else
			k=0;
	}
	else 
		k=0;
		
	for(n=1;n<=k;n++){
		gameboard[x][y+n]=player;}	

	return k;
}

int NW_flip(int x, int y, char player, char another_player){
	int k;
	int n;
		
	if(gameboard[x-1][y-1]==another_player){
		if(gameboard[x-2][y-2]==another_player){
			if(gameboard[x-3][y-3]==another_player){
				if(gameboard[x-4][y-4]==another_player){
					if(gameboard[x-5][y-5]==another_player)
						k=0;
					else if(gameboard[x-5][y-5]==player)
						k=4;
					else
						k=0;
				}
				else if(gameboard[x-4][y-4]==player)
					k=3;
				else
					k=0;
				}	
			else if(gameboard[x-3][y-3]==player)
				k=2;
			else
				k=0;
		}		
		else if(gameboard[x-2][y-2]==player)
			k=1;
		else
			k=0;
	}
	else 
		k=0;

	for(n=1;n<=k;n++){
		gameboard[x-n][y-n]=player;}

	return k;
}

int NE_flip(int x, int y, char player, char another_player){
	int k;
	int n;
		
	if(gameboard[x-1][y+1]==another_player){
		if(gameboard[x-2][y+2]==another_player){
			if(gameboard[x-3][y+3]==another_player){
				if(gameboard[x-4][y+4]==another_player){
					if(gameboard[x-5][y+5]==another_player)
						k=0;
					else if(gameboard[x-5][y+5]==player)
						k=4;
					else
						k=0;
				}
				else if(gameboard[x-4][y+4]==player)
					k=3;
				else
					k=0;
				}	
			else if(gameboard[x-3][y+3]==player)
				k=2;
			else
				k=0;
		}		
		else if(gameboard[x-2][y+2]==player)
			k=1;
		else
			k=0;
	}
	else 
		k=0;
		
	for(n=1;n<=k;n++){
		gameboard[x-n][y+n]=player;}

	return k;
}

int SW_flip(int x, int y, char player, char another_player){
	int k;
	int n;
	
	if(gameboard[x+1][y-1]==another_player){
		if(gameboard[x+2][y-2]==another_player){
			if(gameboard[x+3][y-3]==another_player){
				if(gameboard[x+4][y-4]==another_player){
					if(gameboard[x+5][y-5]==another_player)
						k=0;
					else if(gameboard[x+5][y-5]==player)
						k=4;
					else
						k=0;
				}
				else if(gameboard[x+4][y-4]==player)
					k=3;
				else
					k=0;
				}	
			else if(gameboard[x+3][y-3]==player)
				k=2;
			else
				k=0;
		}		
		else if(gameboard[x+2][y-2]==player)
			k=1;
		else
			k=0;
	}
	else 
		k=0;
		
	for(n=1;n<=k;n++){
		gameboard[x+n][y-n]=player;}		

	return k;
}

int SE_flip(int x, int y, char player, char another_player){
	int k;
	int n;
		
	if(gameboard[x+1][y+1]==another_player){
		if(gameboard[x+2][y+2]==another_player){
			if(gameboard[x+3][y+3]==another_player){
				if(gameboard[x+4][y+4]==another_player){
					if(gameboard[x+5][y+5]==another_player)
						k=0;
					else if(gameboard[x+5][y+5]==player)
						k=4;
					else
						k=0;
				}
				else if(gameboard[x+4][y+4]==player)
					k=3;
				else
					k=0;
				}	
			else if(gameboard[x+3][y+3]==player)
				k=2;
			else
				k=0;
		}		
		else if(gameboard[x+2][y+2]==player)
			k=1;
		else
			k=0;
	}
	else 
		k=0;
		
	for(n=1;n<=k;n++){
		gameboard[x+n][y+n]=player;}		

	return k;
}

int flip_num(int x, int y, char another_player,char player){
	int flip;
	int W,E,S,North,SW,NW,SE,NE;
	
	W=W_flip(x,y,player,another_player);
	E=E_flip(x,y,player,another_player);
	S=S_flip(x,y,player,another_player);
	North=North_flip(x,y,player,another_player);
	SW=SW_flip(x,y,player,another_player);
	NW=NW_flip(x,y,player,another_player);
	SE=SE_flip(x,y,player,another_player);
	NE=NE_flip(x,y,player,another_player);

	printf("%i,%i,%i,%i,%i,%i,%i,%i\n",W,E,S,North,SW,NW,SE,NE);
	flip=(W+E+S+North+SW+NW+SE+NE);
	
	return flip;
}

int check_Empty(int x, int y){
	int Empty;
	
	if(gameboard[x][y]==' ')
		Empty=1;
	else
		Empty=0;
		
	return Empty;
	
}

int check_all(char player, char another_player){
	int PlaceCanPut=0;
	int i,j;
	int Empty;
	int flip;

	for(i=0;i<N;i++){
	for(j=0;j<N;j++){
		Empty = check_Empty(i,j);
		flip = flip_num(i,j,player,another_player);
		
		PlaceCanPut=(Empty&&flip) ;
		PlaceCanPut++;
			}
	}
	
	return PlaceCanPut;
}


int main(int argc, char *argv[]) {
	int x,y;
	int turn;
	char player;
	char another_player;
	int whose_turn = 0;
	int End;
	int place;
	
	init_othello();

	End = isGameEnd();
	place = check_all();
		
	while(End!=0){
		print_othello();
		
		player = get_player(whose_turn);
		another_player = get_another_player(whose_turn);
		
		printf("%c turn\n",player);
		
		if(place==0){	//if no place... change turn and contine
			printf("there is no place player %c can put",player);
			whose_turn++;	//change turn
			continue;
		}
		
		//input
		printf("input col");
		x =	get_input(x);
		printf("input row");
		y = get_input(y);
		
		if((gameborad[x][y]==' ')&&()){
			
			gameboard[x][y]=player;
			
			whose_turn++;//change turn
		}

		else{
			printf("invalid input\n");
		}
			
	status();	
	End = isGameEnd();
	}			
	
	printf("No more place\n");
	check_result();
	
	return 0;
}

/*
//	gameboard[x][y]='X';
//	gameboard[i][j]=gameboard[x][y];

	//int flip_point;
	flip_point=0;
	W=0;
	E=0;
	S=0;
	North=0;
	SW=0;
	NW=0;
	SE=0;
	NE=0;
	int k;
		for(k=0;k<x;k++){
			if(gameboard[x-k][y]=='Y')
				W++;
			else if(gameboard[x-k][y]=='X')
				break;
			else
				W=0; 
				break;
		for(k=0;k<x;k++)
			if(gameboard[x+k][y]=='Y')
				E++;
			else if(gameboard[x+E+1][y]=='X')
				break;
			else
				E=0;
				break;					
		for(k=0;k<x;k++)
			if(gameboard[x][y-k]=='Y')
				S++;
			else if(gameboard[x][y-S-1]=='X')
				break;
			else
				S=0;
				break;
		for(k=0;k<x;k++)
			if(gameboard[x][y+k]=='Y')
				North++;
			else if(gameboard[x][y+S+1]=='X')
				break;
			else
				North=0;
		for(k=0;k<x;k++)
			if(gameboard[x-k][y-k]=='Y')
				SW++;
			else if(gameboard[x-SW-1][y-SW-1]=='X')
				break;
			else
				SW=0;
				break;
			
		for(k=0;k<x;k++)
			if(gameboard[x-k][y+k]=='Y')
				NW++;
			else if(gameboard[x-NW-1][y+NW+1]=='X')
				break;
			else
				NW=0;
				break;
			
		for(k=0;k<x;k++)
			if(gameboard[x+k][y-k]=='Y')
				SE++;
			else if(gameboard[x+SE+1][y-SE-1]=='X')
				break;
			else
				SE=0;
				break;	
			
		for(k=0;k<x;k++)
			if(gameboard[x+k][y+k]=='Y')
				NE++;
			else if(gameboard[x+NE+1][y+NE+1]=='X')	
				break;
			else
				NE=0;
				break;				
		}
	
		if((gameboard[x][y]=='A')&&(flip_point!=0)){
				gameboard[x][y]='X';
				gameboard[i][j]=gameboard[x][y];
				printf("flip_point : %i",flip_point);
				printf("%i,%i,%i,%i,%i,%i,%i,%i\n",W,E,S,North,SW,NW,SE,NE);
	//flip
	flip=0;
	W=0;
	E=0;
	S=0;
	North=0;
	SW=0;
	NW=0;
	SE=0;
	NE=0;

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(gameboard[i][j]=='X'){
			if(gameboard[i-1][j]=='O')
				W++;
			else
				;
			if(gameboard[i+1][j]=='O')
				E++;
			else
				;
			if(gameboard[i][j-1]=='O')
				S++;
			else
				;
			if(gameboard[i+1][j+1]=='O')
				North++;
			else
				;
			if(gameboard[i-1][j-1]=='O')
				SW++;
			else
				;
			if(gameboard[i+1][j+1]=='O')
				NE++;
			else
				;
			if(gameboard[i+1][j-1]=='O')
				SE++;
			else
				;
			if(gameboard[i-1][j+1]=='O')
				NW++;
			else
				;
			}
			else;
		}
	}	
		flip=(W+E+S+North+SW+NW+SE+NE);
		printf("%i,%i,%i,%i,%i,%i,%i,%i\n",W,E,S,North,SW,NW,SE,NE);
		printf("%i\n",flip);
		
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


