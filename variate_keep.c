





//������һ�� ������Ϸ�� ȫ�ֱ����ı���ģ��  Ҳ������Ϣģ��    �Լ� �����ļ��洢���ܵ�ģ��   ���ڲ�֪��codeblocks��ôȥ���ø���ģ�鹲��ı���
//�����������java ��Զ����˼��  ���÷������ر�����ֵ  ���ֻ�ܵ��÷���  �����ܷ��ʵ����� �൱�� pravite ����  Ҳ����һ��javabean�������



#include <stdio.h>
//����  ��������
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4





//����ڵ���������  Ҳ��������
typedef struct _snake_t {
    //������
    int x;
    int y;

    struct _snake_t *next;//ָ����
}snake_t;


//�÷�
int score = 100;



//�Ե�ÿһ��ʳ��ĵ÷�
int add = 1;

//�ߵ��ƶ�����
int direction = RIGHT;

//˯��ʱ��
int sleepTime = 350;

//�����ı�־
int endStatus = 0;

//�����ͷָ��
snake_t *head = NULL;

//ʳ��Ľڵ�ָ��
snake_t *foodNode = NULL;


int getadd(){
return add;
}


int getscore(){
    return score;
}

void setscore(int num){
    score=num;
}

int getdirection(){
    return direction;
}

void setdirection(int num){
    direction =num;
}

struct _snake_t *gethead(){
return head;
};


void sethead(struct _snake_t *h){
head = h;
}

