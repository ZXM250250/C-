

//������һ����Ϣ�Ļ���ģ��  ������Ϸ�����е���ʾ ���� �Լ���Ϸ�����Ժ�Ľ���ҳ�����
//��ʾ��������ʾ��Ϣ
int showScoreTips(void)
{
	int highScore = 0;

	//���ļ��ж�ȡ��߷�

	highScore = readFile();
	//��ʾ��߷�
	setColor(3);
	gotoXY(64, 4);
	printf("�����߷ּ�¼���: %d", highScore);

	//��ʾ��ǰ�÷�
	setColor(14);
	gotoXY(64, 8);
	printf("�÷�: %d", getscore());

	//��ʾ��ܰ��ʾ
	setColor(12);
	gotoXY(72, 11);
	printf("�� ܰ �� ʾ");

	//�������±߿�
	setColor(10);
	gotoXY(60, 13);
	printf("==================================");

	gotoXY(60, 25);
	printf("==================================");

	//�����ʾ��Ϣ
	setColor(13);
	gotoXY(64, 14);
	printf("�� �Ե�ÿ��ʳ��÷�: %d", getadd());

	gotoXY(64, 16);
	printf("�� ����ײ��ǽ�ڣ�����ҧ���Լ�");

	gotoXY(64, 18);
	printf("�� F1����ǰ����F2����ǰ��");

	gotoXY(64, 20);
	printf("�� ʹ�ÿո���ͣ��Ϸ���߼�����Ϸ");

	gotoXY(64, 22);
	printf("�� ʹ�á�����������ǰ���ķ���");

	gotoXY(64, 24);
	printf("�� ����ESC�˳���Ϸ");

	return 0;
}



//������Ϸ
int endGame(void)
{
	int n = 0;
	int highScore = 0;

	while (1)
	{
		//��ʾ��Ϸʧ�ܽ���
		failGameUi();

		setColor(12);
		gotoXY(38, 9);

		//��ͬ��״̬ ��ʾ��ͬʧ����ʾ endStatus
		switch (getendStatus())
		{
			//ײ��ǽ��
		case 1:
			printf("��ײ��ǽ�ˣ���Ϸ����!!!");
			break;

			//ҧ���Լ�
		case 2:
			printf("��ҧ�������ˣ���Ϸ����!!!");
			break;

			//�û�����ESC
		case 3:
			printf("���Ѿ���������Ϸ����Ϸ����!!!");
			break;

		default:
			;
		}

		//��ʾ���ĵ÷�
		setColor(13);
		gotoXY(43, 12);
		printf("���ĵ÷�: %d", getscore());

		//��ʾ��߷�
		//���ļ��ж�ȡ��߷�
		highScore = readFile();

		if (getscore() > highScore)
		{
			setColor(10);
			gotoXY(38, 16);
			printf("��ϲ�㣬���Ѿ��Ƽ�¼�ˡ�");

			//����߷�д���ļ�
			writeFile(getscore());
		}
		else
		{
			setColor(10);
			gotoXY(38, 16);
			printf("����Ŷ�� ����߷ֻ���%d��", highScore - getscore());
		}

		//����û�ѡ�����Ϣ
		gotoXY(25, 23);
		setColor(12);
		printf("����һ�������룺1");

		gotoXY(52, 23);
		printf("ֱ���˳������룺2");

		gotoXY(46, 25);
		setColor(11);
		printf("��ѡ��: ");

		scanf("%d", &n);
		getchar();

		if (1 == n)
		{
			setscore( 0);
			setsleepTime (350);
			setadd(  1);

			//������
			destroySnake();

			break;
		}
		else if (2 == n)
		{
			exit(0);
		}
		else
		{
			gotoXY(30, 27);
			setColor(12);
			printf("���������������������룬���»س�������");
			getchar();
		}
	}
	return 0;
}



//��Ϸʧ�ܽ���߿�
void failGameUi(void)
{
	int i = 0;

	//����
	system("cls");

	//��ʾ��Ϸʧ����ʾ
	setColor(12);
	gotoXY(44, 3);
	printf("�� Ϸ ʧ ��!!!");

	//���ñ߿����ɫ
	setColor(11);
	gotoXY(17, 5);

	//�����ϱ߿�
	printf("+----------------------------------------------------------------+");

	//�����±߿�
	gotoXY(17, 20);
	printf("+----------------------------------------------------------------+");

	//�������ұ߿�
	for (i = 6; i < 20; i++)
	{
		gotoXY(17, i);
		printf("|");

		gotoXY(82, i);
		printf("|");
	}
}




