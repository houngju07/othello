#define N 6
char gameboard[N][N];

int flip_num(int x, int y, char another_player,char player){				//입력된 x,y에 대해 gameboard[x][y]가 입력되었을때 flip 되는 total 돌의 갯수 구하는 함수. 8방향에 대한 flip 갯수 더하면 돼   
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

void fliper(int x, int y, char another_player,char player){					//돌 flip 시키는 함수 + 8개의 각 방향별 뒤집어지는 알 갯수 출력  + 총 뒤집은 알  갯수 출력
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
	
	//각각의 8 방향에 대하여 돌 flip 시켜줌 
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
	
	//8개의 각 방향별 뒤집어지는 알 갯수 출력
	printf("W: %i,E: %i,S: %i,N: %i,SW: %i,NW: %i,SE: %i,NE: %i\n",W,E,S,North,SW,NW,SE,NE);
	
	//총 뒤집은 알  갯수 출력
	printf("Total number of flip is %i\n",W+E+S+North+SW+NW+SE+NE);

}
