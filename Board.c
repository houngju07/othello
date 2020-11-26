#define N 6
char gameboard[N][N];

void init_othello(){							//���� �ʱ�ȭ. �ʱ������ ������ define. 
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

void print_othello(){							//���� ��ġ �����ִ� �Լ�. ���� �� �������  
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

int get_input(int x){							//�Է� �޴� �Լ�  
	printf(": ");
	scanf("%i",&x);
	
	return x;
}

int isGameEnd(){								//���� ������ ��ĭ ���� ���ϰ� ����ϴ� �Լ�. 
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

void status(){									//���� ������ X�� ������ O�� ���� ���ϰ� ����ϴ� �Լ�. 
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

void check_result(){							//���� ������ X�� ������ O�� ������ ���Ͽ� ������ ����ڸ� ���ϰ� ����ϴ� �Լ�.(���� ����� ����ϴ� �Լ�) 
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

char get_player(int turn){						//���� ���� player�� �����ϴ� �Լ�.(� �� �ִ���) 
	char player;
	
	if((turn%2)==0)
		player='X';
	else
		player='O';
	
	return player;
}

char get_another_player(int turn){				//���� ���� player �ƴ� ���  �����ϴ� �Լ�.(��� �� ����) 
	char another_player;
	
	if((turn%2)==0)
		another_player='O';
	else
		another_player='X';
	
	return another_player;
}




int check_Empty(int x, int y){					//�ԷµǴ� x,y �� ���Ͽ� gameboard[x][y]�� �� ĭ���� Ȯ���ϴ� �Լ�  
	int Empty;
	
	if(gameboard[x][y]==' ')
		Empty=1;
	else
		Empty=0;
		
	return Empty;
	
}

int check_all(char player, char another_player){				//���Ӻ����� ��� ��ǥ�� ���� �Է��� �ɼ� �ִ� ��ǥ������ ���ϴ� �Լ�. 
																//�̶� �Է��� �ɼ� �ִ� ��ǥ ������ ������̸鼭, flip�Ǵ� ���� �ϳ��̻��� ��ǥ�̴�.
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
