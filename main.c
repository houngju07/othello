#include <stdio.h>
#include <stdlib.h>

#define N 6									//define N=6 for 6*6 game board(size of game board never change during game play, so that demine N as macro  
char gameboard[N][N];						//define game board

/* run this program using the console pauser or add your own getch, system("pause") or input loop */ 

int main(int argc, char *argv[]) {			//main function
	int x,y;								//게임 보드상에서 input 좌표
	char player;							//차례 player
	char another_player;					//차례아닌  player
	int whose_turn = 0;						//차례 바뀌는 것
	int End;								//gameboard 상에서 빈칸 갯수 
	int place;								//gameboard 상에서 input 놓을수 있는 좌표 갯수 
	int flip_sum;							//flip 되는 total 돌의 갯수 
	
	init_othello();							//게임 시작할때 게임 보드 상태 불러오는 함수 (가운데 4개의 각각 대각선으로 존재하는 초기 게임 형태). 게임 초기화  

	End = isGameEnd();						//isGameEnd()는 게임보드에 빈 공간 갯수를 출력하는 함수이다. 즉 End는 빈 공간 갯수.

	while(End!=0){							//앞서 End는 빈 공간 갯수. 따라서 빈공간 갯수 0되면 while 문 빠져나온다.(게임 끝나) 빈공간 갯수 0아닌 상황에서 게임 계속 돌아간다. 
		print_othello();					//print_othello()는 게임 보드판 출력하는 함수.(보드 판 보여줘).  배치상태 출력. 
		
		player = get_player(whose_turn);					//get_player()는 현재 player가 놓는 돌이  O 돌인지 X  돌인지 정의하는 함수. 누구 차례인지 정의하는 것이다. 
		another_player = get_another_player(whose_turn);	//현재 player 말고 다른 player 알려주는 함수. 
		
		printf("%c turn\n",player);							//지금 누구 차례인지 알려준다. 
		
		place = check_all(player,another_player);			// check_all() 함수는 게임보드의 모든 좌표에 대해 입력이 될수 있는 좌표갯수를 구하는 함수이다.
															// 이때 입력이 될수 있는 좌표 조건은 빈공간이면서, flip되는 돌이 하나이상인 좌표이다.
															// 따라서  check_all()의 출력 결과인 place는 input이 될수있는 gameboard상에서의 좌표 갯수이다. 
		
		
		if(place==0){													//input이 될수있는 gameboard상에서의 좌표 갯수인 place가 0이라는 것은 현재 player에 대해 배치 가능한 좌표 없다는 것이다. 
			printf("there is no place player %c can put",player);		//따라서 배치 할수 없다고 안내하고 
			whose_turn++;												//change turn
			continue;													//반복문을 빠져나가. 
		}
		
		//input
		printf("input col");				 
		x =	get_input(x);				//input을 입력받는 함수 get_input()을 이용해서  입력받음. x는 배열 gameboard[x][y]. 행렬의  열  
		printf("input row");
		y = get_input(y);				//input을 입력받는 함수 get_input()을 이용해서  입력받음. y는 배열 gameboard[x][y]. 행렬의  행  
		
		flip_sum=flip_num(x,y,another_player,player);		//flip_num()은 입력된 x,y에 대해 gameboard[x][y]가 입력되었을때 flip 되는 돌의 갯수 구하는 함수. 그래서 flip_sum은 flip 되는 돌의 갯수  
		 
		if((gameboard[x][y]==' ')&&(flip_sum!=0)){			//적절한 입력 x,y를 받으면 flip 진행. 이때 적절한 입력 x,y는 gameboard[x][y]가 빈곳이며, flip 되는 돌이 1개 이상 있는 x,y일때.  
			
			fliper(x, y, another_player, player);			//x,y 적절하면, flip 진행.  fliper()는 돌 뒤집고 + 8개의 각 방향별 뒤집어지는 알  갯수 출력  +총 뒤집은 알  갯수 출력 하는 함수 
			
			gameboard[x][y]=player;							//입력된 좌표의 player에 해당하는 돌 배치. 
			whose_turn++;									//change turn
		}

		else{												//적절하지 않은 입력 x,y를 받으면 flip 안하고 turn 안바꾸고  입력 x,y받는 동일 과정 다시해. 
			printf("Invalid input\n");						//적절하지 않은 값 넣었다구 알려주기. 
		}
			
	status();												//status()는  X알 O알 갯수 알려주는 함수. 
	End = isGameEnd();										//isGameEnd()는 게임보드에 빈 공간 갯수를 출력하는 함수
	}			
	
	printf("No more place... Game End\n");					//while 문 나옴 (End==0인 상황.   
	check_result();											//check_result() 는 X알이랑 O알 갯수 세어 비교하여 O알이 이겼는지 X알이 이겼는지 알려주는 함수. 
	
	return 0;
}

