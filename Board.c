#define N 6
char gameboard[N][N];

void init_othello(){							//게임 초기화. 초기상태의 보드판 define. 
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

void print_othello(){							//보드 배치 보여주는 함수. 보드 판 출력해줌  
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

int get_input(int x){							//입력 받는 함수  
	printf(": ");
	scanf("%i",&x);
	
	return x;
}

int isGameEnd(){								//게임 보드의 빈칸 갯수 구하고 출력하는 함수. 
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

void status(){									//게임 보드의 X돌 갯수와 O돌 갯수 구하고 출력하는 함수. 
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
}

void check_result(){							//게임 보드의 X돌 갯수와 O돌 갯수를 비교하여 게임의 우승자를 구하고 출력하는 함수.(게임 결과를 출력하는 함수) 
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

char get_player(int turn){						//지금 게임 player를 결정하는 함수.(어떤 돌 넣는지) 
	char player;
	
	if((turn%2)==0)
		player='X';
	else
		player='O';
	
	return player;
}

char get_another_player(int turn){				//지금 게임 player 아닌 사람  결정하는 함수.(상대 돌 뭔지) 
	char another_player;
	
	if((turn%2)==0)
		another_player='O';
	else
		another_player='X';
	
	return another_player;
}




int check_Empty(int x, int y){					//입력되는 x,y 에 대하여 gameboard[x][y]가 빈 칸인지 확인하는 함수  
	int Empty;
	
	if(gameboard[x][y]==' ')
		Empty=1;
	else
		Empty=0;
		
	return Empty;
	
}

int check_all(char player, char another_player){				//게임보드의 모든 좌표에 대해 입력이 될수 있는 좌표갯수를 구하는 함수. 
																//이때 입력이 될수 있는 좌표 조건은 빈공간이면서, flip되는 돌이 하나이상인 좌표이다.
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
