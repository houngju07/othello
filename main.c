#include <stdio.h>
#include <stdlib.h>

#define N 6
char gameboard[N][N];

/* run this program using the console pauser or add your own getch, system("pause") or input loop */ 

int main(int argc, char *argv[]) {//한글로 주석달려도 반영되나..?! 
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
	
	printf("No more place... Game End\n");
	check_result();
	
	return 0;
}

