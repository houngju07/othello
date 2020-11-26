#include <stdio.h>
#include <stdlib.h>

#define N 6									//define N=6 for 6*6 game board(size of game board never change during game play, so that demine N as macro  
char gameboard[N][N];						//define game board

/* run this program using the console pauser or add your own getch, system("pause") or input loop */ 

int main(int argc, char *argv[]) {			//main function
	int x,y;								//���� ����󿡼� input ��ǥ
	char player;							//���� player
	char another_player;					//���ʾƴ�  player
	int whose_turn = 0;						//���� �ٲ�� ��
	int End;								//gameboard �󿡼� ��ĭ ���� 
	int place;								//gameboard �󿡼� input ������ �ִ� ��ǥ ���� 
	int flip_sum;							//flip �Ǵ� total ���� ���� 
	
	init_othello();							//���� �����Ҷ� ���� ���� ���� �ҷ����� �Լ� (��� 4���� ���� �밢������ �����ϴ� �ʱ� ���� ����). ���� �ʱ�ȭ  

	End = isGameEnd();						//isGameEnd()�� ���Ӻ��忡 �� ���� ������ ����ϴ� �Լ��̴�. �� End�� �� ���� ����.

	while(End!=0){							//�ռ� End�� �� ���� ����. ���� ����� ���� 0�Ǹ� while �� �������´�.(���� ����) ����� ���� 0�ƴ� ��Ȳ���� ���� ��� ���ư���. 
		print_othello();					//print_othello()�� ���� ������ ����ϴ� �Լ�.(���� �� ������).  ��ġ���� ���. 
		
		player = get_player(whose_turn);					//get_player()�� ���� player�� ���� ����  O ������ X  ������ �����ϴ� �Լ�. ���� �������� �����ϴ� ���̴�. 
		another_player = get_another_player(whose_turn);	//���� player ���� �ٸ� player �˷��ִ� �Լ�. 
		
		printf("%c turn\n",player);							//���� ���� �������� �˷��ش�. 
		
		place = check_all(player,another_player);			// check_all() �Լ��� ���Ӻ����� ��� ��ǥ�� ���� �Է��� �ɼ� �ִ� ��ǥ������ ���ϴ� �Լ��̴�.
															// �̶� �Է��� �ɼ� �ִ� ��ǥ ������ ������̸鼭, flip�Ǵ� ���� �ϳ��̻��� ��ǥ�̴�.
															// ����  check_all()�� ��� ����� place�� input�� �ɼ��ִ� gameboard�󿡼��� ��ǥ �����̴�. 
		
		
		if(place==0){													//input�� �ɼ��ִ� gameboard�󿡼��� ��ǥ ������ place�� 0�̶�� ���� ���� player�� ���� ��ġ ������ ��ǥ ���ٴ� ���̴�. 
			printf("there is no place player %c can put",player);		//���� ��ġ �Ҽ� ���ٰ� �ȳ��ϰ� 
			whose_turn++;												//change turn
			continue;													//�ݺ����� ��������. 
		}
		
		//input
		printf("input col");				 
		x =	get_input(x);				//input�� �Է¹޴� �Լ� get_input()�� �̿��ؼ�  �Է¹���. x�� �迭 gameboard[x][y]. �����  ��  
		printf("input row");
		y = get_input(y);				//input�� �Է¹޴� �Լ� get_input()�� �̿��ؼ�  �Է¹���. y�� �迭 gameboard[x][y]. �����  ��  
		
		flip_sum=flip_num(x,y,another_player,player);		//flip_num()�� �Էµ� x,y�� ���� gameboard[x][y]�� �ԷµǾ����� flip �Ǵ� ���� ���� ���ϴ� �Լ�. �׷��� flip_sum�� flip �Ǵ� ���� ����  
		 
		if((gameboard[x][y]==' ')&&(flip_sum!=0)){			//������ �Է� x,y�� ������ flip ����. �̶� ������ �Է� x,y�� gameboard[x][y]�� ����̸�, flip �Ǵ� ���� 1�� �̻� �ִ� x,y�϶�.  
			
			fliper(x, y, another_player, player);			//x,y �����ϸ�, flip ����.  fliper()�� �� ������ + 8���� �� ���⺰ ���������� ��  ���� ���  +�� ������ ��  ���� ��� �ϴ� �Լ� 
			
			gameboard[x][y]=player;							//�Էµ� ��ǥ�� player�� �ش��ϴ� �� ��ġ. 
			whose_turn++;									//change turn
		}

		else{												//�������� ���� �Է� x,y�� ������ flip ���ϰ� turn �ȹٲٰ�  �Է� x,y�޴� ���� ���� �ٽ���. 
			printf("Invalid input\n");						//�������� ���� �� �־��ٱ� �˷��ֱ�. 
		}
			
	status();												//status()��  X�� O�� ���� �˷��ִ� �Լ�. 
	End = isGameEnd();										//isGameEnd()�� ���Ӻ��忡 �� ���� ������ ����ϴ� �Լ�
	}			
	
	printf("No more place... Game End\n");					//while �� ���� (End==0�� ��Ȳ.   
	check_result();											//check_result() �� X���̶� O�� ���� ���� ���Ͽ� O���� �̰���� X���� �̰���� �˷��ִ� �Լ�. 
	
	return 0;
}

