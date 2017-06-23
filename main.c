#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
typedef struct numbers Number;

int c[7][7];
void title(Number*);//게임 시작화면
void set_sol(void);//솔리테어 판 
void tuto(Number*);//튜토리얼모드
void start_game(Number*);//게임 시작
void check_key(Number*);//입력 받은 키가 가능 한지 판단
void up(Number*,int, int);
void down(Number*,int, int);
void right(Number*,int, int);
void left(Number*,int, int);
int gameover(Number*);

struct numbers{
	int numberOfmove;
	int numberOfelements;
};

int gameover(Number* this){
	if (this->numberOfelements==1)
		return 1;
	else
		return 0;
}
Number* newNumber(int x, int y){
	Number *num;

	num=(Number*)malloc(sizeof(Number));
	num->numberOfmove=x;
	num->numberOfelements=y;
};

void up(Number *this,int x, int y) {
	if ((c[x - 2][y - 1] == 0) || (c[x - 3][y - 1] != 0)){
		this->numberOfmove++;
		printf("move number:%d\n",this->numberOfmove);
		printf("Fail.\n");
	}	
	else {
		c[x - 3][y - 1] = c[x - 1][y - 1];
		c[x - 2][y - 1] = 0;
		c[x - 1][y - 1] = 0;
		this->numberOfmove++;
		this->numberOfelements--;
		printf("move number:%d, leave numbers:%d\n",this->numberOfmove,this->numberOfelements);
	};
};
void down(Number *this,int x, int y) {
	if ((c[x][y - 1] == 0) || (c[x + 1][y - 1] != 0)){
                this->numberOfmove++;
                printf("move number:%d\n",this->numberOfmove);
                printf("Fail.\n");
        }
	else {
		c[x + 1][y - 1] = c[x - 1][y - 1];
		c[x][y - 1] = 0;
		c[x - 1][y - 1] = 0;
		this->numberOfmove++;
                this->numberOfelements--;
                printf("move number:%d,leave number:%d\n",this->numberOfmove,this->numberOfelements);

	}
};
void right(Number *this,int x, int y) {
	if ((c[x - 1][y] == 0) || (c[x - 1][y + 1] != 0)){
                this->numberOfmove++;
                printf("move number:%d\n",this->numberOfmove);
                printf("Fail.\n");
        }
	else {
		c[x - 1][y + 1] = c[x - 1][y - 1];
		c[x - 1][y] = 0;
		c[x - 1][y - 1] = 0;
		this->numberOfmove++;
                this->numberOfelements--;
                printf("move number:%d,leave number:%d\n",this->numberOfmove,this->numberOfelements);

	}
};
void left(Number *this,int x, int y) {
	if ((c[x - 1][y - 2] == 0) || (c[x - 1][y - 3] != 0)){
                this->numberOfmove++;
                printf("move number:%d\n",this->numberOfmove);
                printf("Fail.\n");
        }
	else {
		c[x - 1][y - 3] = c[x - 1][y - 1];
		c[x - 1][y - 2] = 0;
		c[x - 1][y - 1] = 0;
		this->numberOfmove++;
                this->numberOfelements--;
                printf("move number:%d,leave numbers:%d\n",this->numberOfmove,this->numberOfelements);

	}
};


void title(Number* this) {
	int a;
	printf("Select Mode:(1.Tutorial,2.Game start)\n");
	scanf("%d", &a);
	if (a == 1) {
		system("clear");
		tuto(this);
	}
	if (a == 2) {
		system("clear");
		start_game(this);
	}
}

void check_key(Number* this) {
	int x, y, a, b;
	void(*func[])(Number*,int,int) = {down, right,up,left};
	while(1){
	printf("Select Number (x,y):");
	scanf("%d %d", &y, &x);
	if (c[x-1][y-1]==0)
		printf("fail\n");
	else
		break;
	}
	printf("Move Number(1.down 2.right 3.up 4.left):");
	scanf("%d", &a);
	func[a-1](this,x,y);
	fflush(stdin);
	
}

void set_sol(void) {
	
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("| %d | %d | %d |\n",c[0][2],c[0][3],c[0][4]);
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("| %d | %d | %d |\n",c[1][2],c[1][3],c[1][4]);
	printf("         "); printf("+---+---+---+\n");
	printf("+---+---+");                 printf("+---+---+---+"); printf("+---+---+\n");
	printf("| %d | %d |",c[2][0],c[2][1]); printf("| %d | %d | %d |",c[2][2],c[2][3],c[2][4]); printf("| %d | %d |\n",c[2][5],c[2][6]);
	printf("+---+---+");                 printf("+---+---+---+"); printf("+---+---+\n");
	printf("+---+---+");                 printf("+---+---+---+"); printf("+---+---+\n");
	printf("| %d | %d |",c[3][0],c[3][1]); printf("| %d | %d | %d |",c[3][2],c[3][3],c[3][4]); printf("| %d | %d |\n",c[3][5],c[3][6]);
	printf("+---+---+");                 printf("+---+---+---+"); printf("+---+---+\n");
	printf("+---+---+");                 printf("+---+---+---+"); printf("+---+---+\n");
	printf("| %d | %d |",c[4][0],c[4][1]); printf("| %d | %d | %d |",c[4][2],c[4][3],c[4][4]); printf("| %d | %d |\n",c[4][5],c[4][6]);
	printf("+---+---+");                 printf("+---+---+---+"); printf("+---+---+\n");
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("| %d | %d | %d |\n",c[5][2],c[5][3],c[5][4]);
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("| %d | %d | %d |\n",c[6][2],c[6][3],c[6][4]);
	printf("         "); printf("+---+---+---+\n");

	return;
}

void tuto(Number* this) {
	c[3][2] = 3; c[3][3] = 4 ;
	set_sol();
	while (1) {
		check_key(this);
		set_sol();
		if (this->numberOfelements ==32)
			break;
	}
	printf("clear\n");

}

void start_game(Number* this) {
	FILE *fp=fopen("data","rb");
/*	c[0][2] = 3, c[0][3] = 4, c[0][4] = 5; c[1][2] = 3, c[1][3] = 4, c[1][4] = 5;
	c[2][0] = 1, c[2][1] = 2, c[2][2] = 3, c[2][3] = 4, c[2][4] = 5, c[2][5] = 6, c[2][6] = 7;
	c[3][0] = 1, c[3][1] = 2, c[3][2] = 3, c[3][3] = 0, c[3][4] = 5, c[3][5] = 6, c[3][6] = 7;
	c[4][0] = 1, c[4][1] = 2, c[4][2] = 3, c[4][3] = 4, c[4][4] = 5, c[4][5] = 6, c[4][6] = 7;
	c[5][2] = 3, c[5][3] = 4, c[5][4] = 5; c[6][2] = 3, c[6][3] = 4, c[6][4] = 5;
	fwrite(c,sizeof(*c),49,fp);
	fclose(fp);
	fp=fopen("data","rb");*/
	size_t ret_code =fread(c,sizeof(*c),49,fp);
	set_sol();
	int k=0;
	while (1) {
		check_key(this);
		set_sol();
		if (this->numberOfelements==1)
			break; 
	}
	fclose(fp);
}


int main(void) {
	Number * this=newNumber(0,33);
	title(this);
	return 0;
	free(this);
}
