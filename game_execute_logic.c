
//����һ����Ϸ�߼�����ִ�е�ģ��


#include <stdio.h>
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
		//����ռ�
		new = malloc(sizeof(snake_t));
		if (NULL == new)
		{
			printf("malloc initSnake failed....\n");
			return -1;
		}
		memset(new, 0, sizeof(snake_t));

		//��ֵ
		new->x = 24 + i * 2;
		printf("�ߵĻ�������ִ������");
		new->y = 5;

		//ͷ�巨
		new->next = gethead();
		sethead(new);
	}


	//��������
	tmp = gethead();
	while (NULL != tmp)
	{
		//�����ߵ���ɫ 14 ��ɫ
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
