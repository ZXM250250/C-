#include <stdio.h>
#include "tools.h"
#include <windows.h>
//��Ϸ��ʼ����
//�����ַ��� --��
int printSnake(void)
{
	//����
	system("cls");

	gotoXY(35, 1);
	setColor(6);
	printf("/^\\/^\\");      //���۾�

	gotoXY(34, 2);
	printf("|__|  O|");      //���۾�

	gotoXY(33, 2);
	setColor(2);
	printf("_");

	gotoXY(25, 3);
	setColor(12);
	printf("\\/");      	//����

	gotoXY(31, 3);
	setColor(2);
	printf("/");

	gotoXY(37, 3);
	setColor(6);
	printf(" \\_/");     	//���۾�

	gotoXY(41, 3);
	setColor(10);
	printf(" \\");

	gotoXY(26, 4);
	setColor(12);
	printf("\\____");   	//��ͷ

	gotoXY(32, 4);
	printf("_________/");

	gotoXY(31, 4);
	setColor(2);
	printf("|");

	gotoXY(43, 4);
	setColor(10);
	printf("\\");

	gotoXY(32, 5);
	setColor(2);
	printf("\\_______");    //����

	gotoXY(44, 5);
	setColor(10);
	printf("\\");

	gotoXY(39, 6);
	printf("|##**|                  \\");  //���涼�ǻ�����

	gotoXY(38, 7);
	printf("/####**/                   \\");

	gotoXY(37, 8);
	printf("/####*/                    \\*\\");

	gotoXY(35, 9);
	printf("/####**/                       \\*\\");

	gotoXY(34, 10);
	printf("/####*/                          \\**\\");

	gotoXY(33, 11);
	printf("/####*/             _----_         \\***\\");

	gotoXY(32, 12);
	printf("/####*/           _-~ *****~-_         |**|");

	gotoXY(31, 13);
	printf("(#####*(        _-~****_--_****~-_     _/**|");

	gotoXY(32, 14);
	printf("\\####*~-____-~****_-~    ~-_****~-_-~****/");

	gotoXY(33, 15);
	printf("~-_##**********_-~          ~-_*******_-~");

	gotoXY(35, 16);
	printf("~--______-~                ~-___-~");

	return 0;
}
//��ӡ�˵�
int printMenu(void)
{
    int choice;

	int i = 0;
	int j = 0;

	//�������
	//�����ı���ɫ 11
	setColor(11);
	//���ù��λ��(45, 18)
	gotoXY(45, 18);
	printf("̰����Plus");

	//���Ʊ߿�
	setColor(14);
	//������
	for (i = 19; i <= 27; i++)
	{
		//������
		for (j = 27; j <= 75; j++)
		{
			//������±߿�
			if (i == 20 || i == 26 || i == 19 || i == 27)
			{
			    if (j == 27 || j == 75)//��ӡ�Ľ�
                {
                    if(i == 20 || i == 26)
                    {
                        gotoXY(j, i);
                        printf("|");
                    }
                }
			    else if(i==20 || i == 26)//�����ڱ߿�
                {
                    gotoXY(j, i);
                    printf("-");
				}
				else if (i == 19)//����߿�
                {
                    gotoXY(j, i);
                    printf("_");
                }
                else if (i == 27)//����߿�
                {
                    gotoXY(j, i);
                    printf("^");
                }
			}
			else if (j == 27 || j == 75)
			{
				//������ұ߿�(��)
				gotoXY(j, i);
				printf("|");
			}
			else if (j==28 || j== 74 )
            {
                //������ұ߿�(��)
				gotoXY(j, i);
				printf("|");
            }
			else
			{
				//ע�⣺�ո��ַ�
				printf(" ");
			}
		}
	}

	//����˵�ѡ��
	//�����ı�������
	setColor(12);

	//��ʼ��Ϸ
	gotoXY(35, 22);
	printf("1. ��ʼ��Ϸ");

	//��Ϸ˵��
	gotoXY(55, 22);
	printf("2. ��Ϸ˵��");

	//�˳���Ϸ
	gotoXY(35, 24);
	printf("3. �˳���Ϸ");

	//�����ʾ��Ϣ
	gotoXY(55, 24);
	printf("��ѡ��[1 2 3]");
	gotoXY(49, 23);
	printf("[");
	gotoXY(51, 23);
	printf("]");
	gotoXY(50, 23);

	scanf("%d", &choice);

	//������з�  3 \n
	getchar();

	return choice;
}
int welcome()
{
    int choice;
    printSnake();
    choice = printMenu();
    return choice;
}
