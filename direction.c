#define N 6
char gameboard[N][N];

//입력 좌표 x,y에 대하여 gameboard[x][y] 기준 뒤집힐 수 있는 돌 있는지  확 인  
 
int North_flip(int x, int y, char player, char another_player){			//입력되는 gameboard[x][y]에 대하여 North 방향으로 flip 되는 돌 갯수 구하는 함수. 
	int k;		//flip되는 돌의 갯수 									//매개 변수 k가 North 방향으로 flip 되는 돌 갯수. 함수 k(해당방향으로 flip 되는 돌갯수)를  return으로 출력해 
	
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

int S_flip(int x, int y, char player, char another_player){					//입력되는 gameboard[x][y]에 대하여 South 방향으로 flip 되는 돌 갯수 구하는 함수.  
	int k;																	//매개 변수 k가  South 방향으로 flip 되는 돌 갯수. 함수 k(해당방향으로 flip 되는 돌갯수)를  return으로 출력해 
		
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

int W_flip(int x, int y, char player, char another_player){						//입력되는 gameboard[x][y]에 대하여 West 방향으로 flip 되는 돌 갯수 구하는 함수. 
	int k;																		//매개 변수 k가  West 방향으로 flip 되는 돌 갯수. 함수 k(해당방향으로 flip 되는 돌갯수)를  return으로 출력해 
		
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

int E_flip(int x, int y, char player, char another_player){							//입력되는 gameboard[x][y]에 대하여 East 방향으로 flip 되는 돌 갯수 구하는 함수. 
	int k;																			//매개 변수 k가  East 방향으로 flip 되는 돌 갯수. 함수 k(해당방향으로 flip 되는 돌갯수)를  return으로 출력해 
		
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

int NW_flip(int x, int y, char player, char another_player){							//입력되는 gameboard[x][y]에 대하여 NW 방향으로 flip 되는 돌 갯수 구하는 함수. 
	int k;																				//매개 변수 k가  NW 방향으로 flip 되는 돌 갯수. 함수 k(해당방향으로 flip 되는 돌갯수)를  return으로 출력해 
		
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

int NE_flip(int x, int y, char player, char another_player){							//입력되는 gameboard[x][y]에 대하여 NE 방향으로 flip 되는 돌 갯수 구하는 함수. 
	int k;																				//매개 변수 k가  NE 방향으로 flip 되는 돌 갯수. 함수 k(해당방향으로 flip 되는 돌갯수)를  return으로 출력해 
		
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

int SW_flip(int x, int y, char player, char another_player){							//입력되는 gameboard[x][y]에 대하여 SW 방향으로 flip 되는 돌 갯수 구하는 함수. 
	int k;																				////매개 변수 k가  SW 방향으로 flip 되는 돌 갯수. 함수 k(해당방향으로 flip 되는 돌갯수)를  return으로 출력해 
	
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

int SE_flip(int x, int y, char player, char another_player){							//입력되는 gameboard[x][y]에 대하여 SE 방향으로 flip 되는 돌 갯수 구하는 함수. 
	int k;																				//매개 변수 k가  SE방향으로 flip 되는 돌 갯수. 함수 k(해당방향으로 flip 되는 돌갯수)를  return으로 출력해 
		
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


