#include <windows.h>

#include <stdio.h>
//�ı����λ�ú���
void gotoXY(int x,int y)
{
    HANDLE handle;
    COORD coord;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(handle,coord);
}
//�ı��ն˵���ɫ����
void setColor(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

