

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
