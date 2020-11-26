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
	printf("number of empty place :%i\n",GameEnd);
	
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

	flip=(W+E+S+North+SW+NW+SE+NE);
	
	return flip;
}

int print_flip_num(int x, int y, char another_player,char player){
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

void fliper(int x, int y, char another_player,char player){
	int n;
	int W,E,S,North,SW,NW,SE,NE;
	
	W=W_flip(x,y,player,another_player);
	E=E_flip(x,y,player,another_player);
	S=S_flip(x,y,player,another_player);
	North=North_flip(x,y,player,another_player);
	SW=SW_flip(x,y,player,another_player);
	NW=NW_flip(x,y,player,another_player);
	SE=SE_flip(x,y,player,another_player);
	NE=NE_flip(x,y,player,another_player);
	
	for(n=1;n<=North;n++){
	gameboard[x-n][y]=player;}
	
	for(n=1;n<=S;n++){
	gameboard[x+n][y]=player;}
		
	for(n=1;n<=W;n++){
	gameboard[x][y-n]=player;}
	
	for(n=1;n<=E;n++){
	gameboard[x][y+n]=player;}	
	
	for(n=1;n<=NW;n++){
	gameboard[x-n][y-n]=player;}
		
	for(n=1;n<=NE;n++){
	gameboard[x-n][y+n]=player;}
	
	for(n=1;n<=SW;n++){
	gameboard[x+n][y-n]=player;}
	
	for(n=1;n<=SE;n++){
	gameboard[x+n][y+n]=player;}		
	
	printf("W: %i,E: %i,S: %i,N: %i,SW: %i,NW: %i,SE: %i,NE: %i\n",W,E,S,North,SW,NW,SE,NE);

}


int main(int argc, char *argv[]) {
	int x,y;
	int turn;
	char player;
	char another_player;
	int whose_turn = 0;
	int End;
	int place;
	int flip_sum;
	
	init_othello();

	End = isGameEnd();

	while(End!=0){
		print_othello();
		
		player = get_player(whose_turn);
		another_player = get_another_player(whose_turn);
		
		printf("%c turn\n",player);
		
		place = check_all(player,another_player);
		
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
		
		flip_sum=flip_num(x,y,another_player,player);
		
		if((gameboard[x][y]==' ')&&(flip_sum!=0)){
			
			fliper(x, y, another_player, player);
			
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

