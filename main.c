#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char c[7][7];
void title(void);//���� ����ȭ��
void set_sol(void);//�ָ��׾� �� 
void tuto(void);//Ʃ�丮����
void start_game(void);//���� ����
void reset(void);//���� �ʱ�ȭ
void check_key(void);//Ű�� �Է¹���

void title(void) {
	int a;
	printf("��带 �Է��ϼ���:(1.Ʃ�丮��,2.����)\n");
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
		printf("�����̰� ���� ��ġ�� �Է��Ͻÿ�(x,y):");
		scanf("%d %d",&x,&y);
		printf("�����̰� ���� ������ �Է��Ͻÿ�(1.up 2.right 3.down 4.left):");
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