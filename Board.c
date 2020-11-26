#define N 6
char gameboard[N][N];

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
