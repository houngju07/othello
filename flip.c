#define N 6
char gameboard[N][N];

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
	printf("Total number of flip is %i\n",W+E+S+North+SW+NW+SE+NE);

}
