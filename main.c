
int main()
{
    int choice;
    while(1)
    {
        choice = welcome();
        if (choice != 1 && choice != 2 && choice != 3);
        else break;
    }
    if (choice == 1)                      //��ʾ��ʼ��Ϸ
    {
        printMap();   //������Ϸ����ĵ�ͼ

        showScoreTips();   //������Ϸ���õķ�������ʾѡ��

        initSnake();   //��ʼ��̰����
    }
    else //tansfer(choice);
    return 0;
}
