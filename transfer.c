#include<stdio.h>
#include<windows.h>
//����˵��������˳���Ϸ�Ľ���
void complain()
{
    int i = 0;
	int j = 0;

	//����
	system("cls");

	//�������
	setColor(13);
	gotoXY(44, 3);
	printf("��Ϸ˵��");

	//�����������ұ߿�
	//������
	for (i = 6; i <= 22; i++)
	{
		//������
		for (j = 20; j <= 75; j++)
		{
			//���±߿� =
			if (i == 6 || i == 22)
			{
				gotoXY(j, i);
				printf("=");
			}
			else if (j == 20 || j == 75)
			{
				gotoXY(j, i);
				printf("|");
			}
			else
			{

			}
		}
	}

	//����˵�ѡ��
	setColor(3);
	gotoXY(30, 8);
	printf("�� 1. ����ײ��ǽ������ҧ���Լ�");

	setColor(5);
	gotoXY(30, 11);
	printf("�� 2. F1����ǰ����F2����ǰ��");

	setColor(11);
	gotoXY(30, 14);
	printf("�� 3. ʹ�ÿո���ͣ��Ϸ���߼�����Ϸ");

	setColor(13);
	gotoXY(30, 17);
	printf("�� 4. ʹ�÷��������ǰ���ķ���");

	setColor(14);
	gotoXY(30, 20);
	printf("�� 5. ����ESC���˳���Ϸ");

	//�����ʾ��Ϣ
	setColor(12);
	gotoXY(20, 24);
	printf("������������������棬");

}
void transfer(int c)
{
    if (c == 3)
    {
        exit(0);
    }
    else if (c == 2)
    {
        complain();
        system("pause");
    }
}
