


int main()
{
    int choice;
    while(1)
    {
        while(1)
        {
            choice = welcome();
            if (choice != 1 && choice != 2 && choice != 3);
            else break;
        }
        if (choice == 1)
        {
            printMap();   //������Ϸ����ĵ�ͼ

        showScoreTips();   //������Ϸ���õķ�������ʾѡ��

        initSnake();   //��ʼ��̰����

        randFood();       //��ʼ�������ʳ��

        //ͨ������������ߵ��ƶ�
			moveKeyControl();


        scanf("sdaj1");
        }
        else
            transfer(choice);
    }

    return 0;
}
