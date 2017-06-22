#include <stdio.h>

char c[7][7];
void title(void);//게임 시작화면
void set_sol(void);//솔리테어 판 
void tuto(void);//튜토리얼모드
void start_game(void);//게임 시작
void check_key(void);//입력 받은 키가 가능 한지 판단

void title(void) {
	int a;
	printf("Select Mode:(1.Tutorial,2.Game start)\n");
	scanf("%d", &a);
	if (a == 1) {
		system("clear");
		tuto();
	}
	if (a == 2) {
		system("clear");
		start_game();
	}
}

void check_key(void) {
	int x, y, a, b;
	printf("Select Number (x,y):");
	scanf("%d %d", &x, &y);
	printf("Move Number(1.up 2.right 3.down 4.left):");
	scanf("%d", &a);
	if (a == 1) {
		if( (c[x][y - 1] == 0 )||(c[x+1][y-1]!=0))
			printf("Fail.\n");
		else {
			c[x + 1][y - 1] = c[x - 1][y - 1];
			c[x][y - 1] = 0;
			c[x - 1][y - 1] = 0;
		}
	}
	else if (a == 2) {
		if( (c[x - 1][y] == 0) || (c[x-1][y+1]!=0))
			printf("Fail.\n");
		else {
			c[x - 1][y + 1] = c[x - 1][y - 1];
			c[x - 1][y] = 0;
			c[x - 1][y - 1] = 0;
		}
	}
	else if (a == 3) {
		if ((c[x - 2][y - 1] == 0) || (c[x-3][y-1]!=0))
			printf("Fail.\n");
		else {
			c[x - 3][y - 1] = c[x - 1][y - 1];
			c[x - 2][y - 1] = 0;
			c[x - 1][y - 1] = 0;
		}
	}
	else if (a == 4) {
		if ((c[x - 1][y - 2] == 0) || (c[x-1][y-2]!=0))
			printf("Fail.\n");
		else {
			c[x - 1][y - 3] = c[x - 1][y - 1];
			c[x - 1][y - 2] = 0;
			c[x - 1][y - 1] = 0;
		}
	};
}

void set_sol(void) {
	
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("| %c | %c | %c |\n",c[0][2],c[0][3],c[0][4]);
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("+---+---+---+\n");
	printf("         "); printf("| %c | %c | %c |\n",c[1][2],c[1][3],c[1][4]);
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
		printf("Select Number (x,y):");
		scanf("%d %d",&x,&y);
		printf("Move Number(1.up 2.right 3.down 4.left):");
		scanf("%d", &a);
		if (a == 1) {
			if ((c[x][y - 1] == 0) )
				printf("Fail.\n");
			else {
				c[x + 1][y - 1] = c[x - 1][y - 1];
				c[x][y - 1] = 0;
				c[x - 1][y - 1] = 0;
			}
		}
		else if (a == 2) {
			if (c[x-1][y] == 0)
				printf("Fail.\n");
			else {
				c[x - 1][y + 1] = c[x - 1][y - 1];
				c[x - 1][y] = 0;
				c[x - 1][y - 1] = 0;
			}
		}
		else if (a == 3) {
			if (c[x-2][y - 1] == 0)
				printf("Fail.\n");
			else {
				c[x - 3][y - 1] = c[x - 1][y - 1];
				c[x - 2][y - 1] = 0;
				c[x - 1][y - 1] = 0;
			}
		}
		else if (a == 4) {
			if (c[x-1][y - 2] == 0)
				printf("Fail.\n");
			else {
				c[x - 1][y - 3] = c[x - 1][y - 1];
				c[x - 1][y - 2] = 0;
				c[x - 1][y - 1] = 0;
			}
			fflush(stdin);
		};
		set_sol();
	}
	printf("clear\n");

}

void start_game(void) {
	c[0][2] = '3', c[0][3] = '4', c[0][4] = '5'; c[1][2] = '13', c[1][3] = '14', c[1][4] = '15';
	c[2][0] = '31', c[2][1] = '32', c[2][2] = '33', c[2][3] = '34', c[2][4] = '35', c[2][5] = '36', c[2][6] = '37';
	c[3][0] = '41', c[3][1] = '42', c[3][2] = '43', c[3][3] = 0, c[3][4] = '45', c[3][5] = '46', c[3][6] = '47';
	c[4][0] = '51', c[4][1] = '52', c[4][2] = '53', c[4][3] = '54', c[4][4] = '55', c[4][5] = '56', c[4][6] = '57';
	c[5][2] = '63', c[5][3] = '64', c[5][4] = '65'; c[6][2] = '73', c[6][3] = '74', c[6][4] = '75';
	set_sol();
	while (1) {
		check_key();
		set_sol();

	}
}


int main(void) {
	title();
	return 0;
}
