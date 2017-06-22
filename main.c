#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char c[7][7];
void title(void);//게임 시작화면
void set_sol(void);//솔리테어 판 
void tuto(void);//튜토리얼모드
void start_game(void);//게임 시작
void reset(void);//게임 초기화
void check_key(void);//키를 입력받음

void title(void) {
	int a;
	printf("모드를 입력하세요:(1.튜토리얼,2.시작)\n");
	scanf("%d", &a);
	if (a == 1) {
		system("cls");
		tuto();
	}
	if (a == 2) {
		system("cls");
		set_sol();
	}
}

void set_sol(void) {
	
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("| %c | %c | %c |\n",c[0][3],c[0][4],c[0][5]);
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("| %c | %c | %c |\n",c[1][3],c[1][4],c[1][5]);
	printf("         "); printf("+---+---+---+\n");
	printf("+---+---+"); printf("+---+---+---+"); printf("+---+---+\n");
	printf("| %c | %c |",c[2][0],c[2][1]); printf("| %c | %c | %c |",c[2][2],c[2][3],c[2][4]); printf("| %c | %c |\n",c[2][5],c[2][6]);
	printf("+---+---+"); printf("+---+---+---+"); printf("+---+---+\n");
	printf("+---+---+"); printf("+---+---+---+"); printf("+---+---+\n");
	printf("| %c | %c |",c[3][0],c[3][1]); printf("| %c | %c | %c |",c[3][2],c[3][3],c[3][4]); printf("| %c | %c |\n",c[3][5],c[3][6]);
	printf("+---+---+"); printf("+---+---+---+"); printf("+---+---+\n");
	printf("+---+---+"); printf("+---+---+---+"); printf("+---+---+\n");
	printf("| %c | %c |",c[4][0],c[4][1]); printf("| %c | %c | %c |",c[4][2],c[4][3],c[4][4]); printf("| %c | %c |\n",c[4][5],c[4][6]);
	printf("+---+---+"); printf("+---+---+---+"); printf("+---+---+\n");
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("| %c | %c | %c |\n",c[5][2],c[5][3],c[5][4]);
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("| %c | %c | %c |\n",c[6][2],c[6][3],c[6][4]);
	printf("         "); printf("+---+---+---+\n");

	return;
}

void tuto(void) {
	c[3][2] = '43', c[3][3] = '44' ;
	set_sol();
	while (c[3][3]!=0) {
		int x,y,a,b;
		printf("움직이고 싶은 위치를 입력하시오(x,y):");
		scanf("%d %d",&x,&y);
		printf("움직이고 싶은 방향을 입력하시오(1.up 2.right 3.down 4.left):");
		scanf("%d", &a);
		if (a == 1) {
			c[x + 1][y - 1] = c[x - 1][y - 1];
			c[x][y - 1] = 0;
			c[x - 1][y - 1] = 0;
		}
		else if (a == 2) {
			c[x - 1][y + 1] = c[x - 1][y - 1];
			c[x - 1][y] = 0;
			c[x - 1][y - 1] = 0;
		}
		else if (a == 3) {
			c[x - 3][y - 1] = c[x - 1][y - 1];
			c[x - 2][y - 1] = 0;
			c[x - 1][y - 1] = 0;
		}
		else if (a == 4) {
			c[x - 1][y - 3] = c[x - 1][y - 1];
			c[x - 1][y - 2] = 0;
			c[x - 1][y - 1] = 0;
		};
		set_sol();
	}
	printf("clear\n");

}

int main(void) {
	title();
	return 0;
}