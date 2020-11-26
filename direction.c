#define N 6
char gameboard[N][N];

//�Է� ��ǥ x,y�� ���Ͽ� gameboard[x][y] ���� ������ �� �ִ� �� �ִ���  Ȯ ��  
 
int North_flip(int x, int y, char player, char another_player){			//�ԷµǴ� gameboard[x][y]�� ���Ͽ� North �������� flip �Ǵ� �� ���� ���ϴ� �Լ�. 
	int k;		//flip�Ǵ� ���� ���� 									//�Ű� ���� k�� North �������� flip �Ǵ� �� ����. �Լ� k(�ش�������� flip �Ǵ� ������)��  return���� ����� 
	
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
	
	return k;		//
}

int S_flip(int x, int y, char player, char another_player){					//�ԷµǴ� gameboard[x][y]�� ���Ͽ� South �������� flip �Ǵ� �� ���� ���ϴ� �Լ�.  
	int k;																	//�Ű� ���� k��  South �������� flip �Ǵ� �� ����. �Լ� k(�ش�������� flip �Ǵ� ������)��  return���� ����� 
		
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

int W_flip(int x, int y, char player, char another_player){						//�ԷµǴ� gameboard[x][y]�� ���Ͽ� West �������� flip �Ǵ� �� ���� ���ϴ� �Լ�. 
	int k;																		//�Ű� ���� k��  West �������� flip �Ǵ� �� ����. �Լ� k(�ش�������� flip �Ǵ� ������)��  return���� ����� 
		
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

int E_flip(int x, int y, char player, char another_player){							//�ԷµǴ� gameboard[x][y]�� ���Ͽ� East �������� flip �Ǵ� �� ���� ���ϴ� �Լ�. 
	int k;																			//�Ű� ���� k��  East �������� flip �Ǵ� �� ����. �Լ� k(�ش�������� flip �Ǵ� ������)��  return���� ����� 
		
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

int NW_flip(int x, int y, char player, char another_player){							//�ԷµǴ� gameboard[x][y]�� ���Ͽ� NW �������� flip �Ǵ� �� ���� ���ϴ� �Լ�. 
	int k;																				//�Ű� ���� k��  NW �������� flip �Ǵ� �� ����. �Լ� k(�ش�������� flip �Ǵ� ������)��  return���� ����� 
		
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

int NE_flip(int x, int y, char player, char another_player){							//�ԷµǴ� gameboard[x][y]�� ���Ͽ� NE �������� flip �Ǵ� �� ���� ���ϴ� �Լ�. 
	int k;																				//�Ű� ���� k��  NE �������� flip �Ǵ� �� ����. �Լ� k(�ش�������� flip �Ǵ� ������)��  return���� ����� 
		
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

int SW_flip(int x, int y, char player, char another_player){							//�ԷµǴ� gameboard[x][y]�� ���Ͽ� SW �������� flip �Ǵ� �� ���� ���ϴ� �Լ�. 
	int k;																				////�Ű� ���� k��  SW �������� flip �Ǵ� �� ����. �Լ� k(�ش�������� flip �Ǵ� ������)��  return���� ����� 
	
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

int SE_flip(int x, int y, char player, char another_player){							//�ԷµǴ� gameboard[x][y]�� ���Ͽ� SE �������� flip �Ǵ� �� ���� ���ϴ� �Լ�. 
	int k;																				//�Ű� ���� k��  SE�������� flip �Ǵ� �� ����. �Լ� k(�ش�������� flip �Ǵ� ������)��  return���� ����� 
		
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


