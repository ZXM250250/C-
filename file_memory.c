#include <stdio.h>


//��һ��ģ�� ���� ��Ϸ�и����ļ����ݵĴ洢����ģ��



//��ȡ�ļ�����߷�  ��߷ֱ�����sava.txt�ļ���
int readFile(void)
{
	int ret = -1;
	char buf[32];

	FILE *fp = NULL;

	//1. ��ֻ���ķ�ʽ���ļ�
	fp = fopen("save.txt", "r");
	if (NULL == fp)
	{
		printf("fopen failed...\n");
		return 0;
	}

	//2. ��ȡ�ļ�����
	memset(buf, 0, sizeof(buf));
	ret = fread(buf, sizeof(char), sizeof(buf), fp);
	if (ret <= 0)
	{
		printf("fread failed...\n");
		return 0;
	}


	//3. �ر��ļ�
	fclose(fp);

	//atoi --> ���ַ���������ת��Ϊ����  "123" --> 123
	return atoi(buf);
}




//����߷�д���ļ���
int writeFile(int score)
{
	FILE *fp = NULL;

	//���ļ�
	fp = fopen("save.txt", "w+");
	if (NULL == fp)
	{
		printf("���ļ�ʧ��\n");
		return -1;
	}

	//����߷�д���ļ���
	fprintf(fp, "%d", score);

	//�ر��ļ�
	fclose(fp);

	return 0;
}

