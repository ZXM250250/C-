

//��������һ����Ϸ��ͼ�Ļ���ģ��
//������Ϸ��ͼ
int printMap(void)
{
	int i = 0;
	int j = 0;

	//����
	system("cls");

	//������
	for (i = 0; i <= 26; i++)
	{
		//������
		for (j = 0; j <= 56; j = j + 2)
		{
			//��λ���
			gotoXY(j, i);
			if (0 == i || 26 == i || 0 == j || 56 == j)
			{
				setColor(5);
				printf("��");
			}
			else
			{
				setColor(3);
				printf("��");
			}
		}
	}

	return 0;
}
