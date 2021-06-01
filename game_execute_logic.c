
//����һ����Ϸ�߼�����ִ�е�ģ��

//����  ��������
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
//����ڵ���������  Ҳ��������
typedef struct _snake_t {
    //������
    int x;
    int y;

    struct _snake_t *next;//ָ����
}snake_t;

//��ʼ���������ͷ
int initSnake(void)
{
	int i = 0;

	snake_t *new = NULL;
	snake_t *tmp = NULL;


	//ѭ�������ĸ��ڵ�
	for (i = 0; i < 4; i++)
	{
		//����ռ� ��ֹ�ڴ治��
		new = malloc(sizeof(snake_t));
		if (NULL == new)
		{
			printf("malloc initSnake failed....\n");
			return -1;
		}
		memset(new, 0, sizeof(snake_t));

		//��ֵ
		new->x = 24 + i * 2;
		new->y = 5;

		//ͷ�巨
		new->next = gethead();
		sethead(new);
	}


	//��������
	tmp = gethead();
	while (NULL != tmp)
	{
		//�����ߵ���ɫ 14 ��ɫ  �ﵽ
		setColor(14);
		//��λ���
		gotoXY(tmp->x, tmp->y);

		//��һ���ڵ�������ǵ���ͷ�ڵ�
		if (gethead() == tmp)
		{
			printf("��");
		}
		else
		{
			printf("��");
		}

		tmp = tmp->next;
	}


	return 0;
}






//���ʳ��
int randFood(void)
{
	snake_t *tmp = NULL;

	//�����ʳ�ﲻ�ܹ�������ǽ����
	//�����ʳ�ﲻ�ܹ�������������
	//�����ʳ��x����һ����ż��

	//����ռ�
	setfoodNode(malloc(sizeof(snake_t)));
	snake_t *foodNode =getfoodNode();
	if (NULL == foodNode)
	{
		gotoXY(1, 28);
		printf("malloc failed...\n");
		return -1;
	}
	memset(foodNode, 0, sizeof(snake_t));

	while (1)
	{
		while (1)
		{
			//��֤X������ż�� ͬʱ��Ӧ�ó�����ǽ��(2, 54)
			foodNode->x = rand() % 53 + 3;

			if (0 == foodNode->x % 2)
			{
				break;
			}
		}

		//y�����ǣ�1,25��
		foodNode->y = rand() % 25 + 1;  //(0,24) --> (1, 25)

		//�ж�ʳ�ﲻ�ܹ���������
		tmp = gethead();

		while (NULL != tmp)
		{
			if ((foodNode->x == tmp->x) && (foodNode->y == tmp->y))
			{
				break;
			}

			tmp = tmp->next;
		}

		//ʳ��û�����ߵ�����
		if (NULL == tmp)
		{
			gotoXY(foodNode->x, foodNode->y);
			setColor(12);
			printf("��");
			break;
		}
		else
		{
			continue;
		}

	}

	return 0;
}




//ͨ������������ߵ��ƶ�
int moveKeyControl(void)
{
	//Ĭ�Ϸ����������
	setdirection (RIGHT);

	while (1)
	{
		//��ʾ�Ҳ��С��ʾ
		showScoreTips();

		//����
		if (GetAsyncKeyState(VK_UP) && getdirection() != DOWN)
		{
			setdirection(UP);
		}

		//����
		if (GetAsyncKeyState(VK_DOWN) && getdirection() != UP)
		{
			setdirection(DOWN);
		}


		//����
		if (GetAsyncKeyState(VK_LEFT) && getdirection() != RIGHT)
		{
			setdirection(LEFT);
		}

		//����
		if (GetAsyncKeyState(VK_RIGHT) && getdirection() != LEFT)
		{
			setdirection (RIGHT);
		}

		//���¿ո���ͣ��Ϸ���߼�����Ϸ
		if (GetAsyncKeyState(VK_SPACE))
		{
			while (1)
			{
				Sleep(300);
				if (GetAsyncKeyState(VK_SPACE))
				{
					break;
				}
			}
		}



		//����F8����
		if (GetAsyncKeyState(VK_F8))
		{
			//����˯��ʱ��  ����˯�ߵ�ʱ�䲻��С��50ms
			speedUp();
		}



		//����F9����
		if (GetAsyncKeyState(VK_F9))
		{
			//����˯�ߵ�ʱ��
			speedDown();
		}



		//����ESC�� ������Ϸ
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			//��ʾ�û�����ESC��������Ϸ
			setendStatus (3);

			endGame();

			//exit(1);
			break;
		}


		Sleep(getsleepTime());

		moveSnake();

		//�ж��Ƿ�ײ��ǽ��
		if (isHitWall())
		{
			setendStatus (1);
			endGame();
			break;
		}

		//�ж��Ƿ�ҧ���Լ�
		if (isBitSelf())
		{

			setendStatus (2);
			endGame();
			break;
		}
	}

	return 0;
}



//�����ߵ��ƶ�
int speedUp(void)
{
	//�����ٶ� ˯��ʱ��50ms
	if (getsleepTime() > 50)
	{
		setsleepTime (getsleepTime() - 20);
		setadd(getadd ()+ 2);
	}

	return 0;
}


//�����ߵ��ƶ�  ����˯�ߵ�ʱ��
int speedDown(void)
{
	if (getsleepTime() < 350)
	{
	    setsleepTime (getsleepTime() +20);
		//�������ӵķ���
         setadd ( getadd ()- 2);


	}

	if (getadd ()<= 0)
	{
		setadd(  1);
	}

	return 0;
}





//�����ߵ��ƶ�    ��û��д�� ����������
int moveSnake(void)
{
	snake_t *new = NULL;
	snake_t *tmp = NULL;
	snake_t *save = NULL;
    snake_t *head = gethead();


	//�����µĽڵ�
	new = malloc(sizeof(snake_t));
	if (NULL == new)
	{
		printf("malloc failed...\n");
		return -1;
	}
	memset(new, 0, sizeof(snake_t));

	//����
	if (UP == getdirection())
	{
		new->x = head->x;
		new->y = head->y - 1;
	}

	//����
	if (DOWN == getdirection())
	{
		new->x = head->x;
		new->y = head->y + 1;
	}

	//����
	if (LEFT == getdirection())
	{
		new->x = head->x - 2;
		new->y = head->y;
	}

	//����
	if (RIGHT == getdirection())
	{
		new->x = head->x + 2;
		new->y = head->y;
	}

	//ͷ�巨
	new->next = head;
	sethead(new);

	tmp = gethead();
	setColor(14);


	snake_t *foodNode = getfoodNode();
	//�ж��Ƿ�Ϊʳ��
	if ((new->x == foodNode->x) && (foodNode->y == new->y))
	{
		//ѭ��������
		while (NULL != tmp)
		{
			gotoXY(tmp->x, tmp->y);
			if (gethead() == tmp)
			{
				printf("��");
			}
			else
			{
				printf("��");
			}

			tmp = tmp->next;
		}

		//�Ե�һ��ʳ�� ���ӷ���
		setscore( getscore() + getadd());

		//���ʳ��
		randFood();
	}
	else
	{
		while (NULL != tmp->next)
		{
			gotoXY(tmp->x, tmp->y);
			if (gethead() == tmp)
			{
				printf("��");
			}
			else
			{
				printf("��");
			}

			save = tmp;
			tmp = tmp->next;
		}

		//�����һ���ڵ��ͷ�
		gotoXY(tmp->x, tmp->y);
		setColor(3);
		printf("��");

		save->next = NULL;
		free(tmp);
	}

	return 0;
}




//�ж��Ƿ�ײ��ǽ��
int isHitWall(void)
{
    snake_t *head = gethead();
	//��ʾײ��ǽ��
	if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)
	{
		return 1;
	}

	//��ʾû��ײ��ǽ��
	return 0;
}

//�ж��Ƿ�ҧ���Լ�
int isBitSelf(void)
{
    snake_t *head = gethead();
	snake_t *tmp = NULL;

	//�ӵڶ����ڵ㿪ʼ��
	tmp = head->next;

	while (NULL != tmp)
	{
		if ((head->x == tmp->x) && (head->y == tmp->y))
		{
			return 1;
		}

		//ָ����һ���ڵ�
		tmp = tmp->next;
	}

	return 0;
}





//������
int destroySnake(void)
{
	snake_t *tmp = NULL;
	snake_t *save = NULL;


	tmp = gethead();
	while (NULL != tmp)
	{
		save = tmp->next;
		free(tmp);

		tmp = save;
	}

	sethead(NULL);

	return 0;
}
