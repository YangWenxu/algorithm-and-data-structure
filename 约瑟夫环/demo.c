//约瑟夫环上机代码

#include <stdio.h>
#include <stdlib.h>

typedef struct DulNode
{
    int data;
    struct DulNode *prior;  //前指针prior域
    struct DulNode *next;
}DulNode;

DulNode *del_link1(DulNode *person, DulNode *t)
// n>0 进行正向顺时针查找后，输出第m个人位置，并删除模块释放当前节点，直到所有人都出圈，返回前一个节点信息
{
    DulNode *s=t;
    t->prior->next=t->next;   //将t的前一个节点的next指针指向t的下一个节点
    t->next->prior=t->prior;  //将t的下一个节点的prior指针指向t的上一个节点
    s=s->next;
    free(t);
    return s;
}

DulNode *del_link2(DulNode *person,DulNode *t)
//  n<0 进行逆时针查找后，输出第m个人的位置，删除模块释放当前节点，直到所有人出圈，返回后一个节点信息
{
    DulNode *s=t;
    t->prior->next=t->next;
    t->next->prior=t->prior;
    s=s->prior;
    free(t);
    return s;
}

void JoseduLink(DulNode *person, int n, int m)  //查找并打印第m个节点
{
    int i;
    DulNode *t=person;
    if(m>0)
    {
        while(t->next!=t)
        {
            for(i=1;i<m;i++)
            {
                t=t->next;
            }
            printf("%d",t->data);
            t=del_link1(person,t);
        }
        printf("%d\n",t->data);
    }
    else
    {
        while(t->prior!=t)
        {
            for(i=1;i<-m;i++)
            {
                t=t->prior;
            }
            printf("%d",t->data);
            t=del_link2(person,t);
        }
        printf("%d\n",t->data);
    }
}

void main()
{
    DulNode *person, *s, *r;
    int i,m,n;
    printf("请输入人数n:\n");
    scanf("%d",&n);
    printf("请输入m的值:\n");
    scanf("%d",&m);
    printf("出圈序列:\n");
    person=(DulNode*)malloc(sizeof(DulNode));   //为第一个节点申请空间
    person->data=1;       //data记录当前人的位置
    person->next=person->prior=person;
    s=person;
    for(i=2;i<=n;i++)   //创建n-1个节点
    {
        r=s;
        s=(DulNode*)malloc(sizeof(DulNode));
        s->data=i;     //双向循环链表的操作
        s->prior=r;   //依次将生成的节点插入循环链表中
        r->next->prior=s;
        s->next=r->next;
        r->next=s;
    }
    printf("\n");
    JoseduLink(person,n,m);
}
