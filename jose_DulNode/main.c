#include <stdio.h>
#include <stdlib.h>

typedef struct DulNode
{
    int data;
    struct DulNode *prior;  //ǰָ��prior��
    struct DulNode *next;
}DulNode;

DulNode *del_link1(DulNode *person, DulNode *t)
// n>0 ��������˳ʱ����Һ������m����λ�ã���ɾ��ģ���ͷŵ�ǰ�ڵ㣬ֱ�������˶���Ȧ������ǰһ���ڵ���Ϣ
{
    DulNode *s=t;
    t->prior->next=t->next;   //��t��ǰһ���ڵ��nextָ��ָ��t����һ���ڵ�
    t->next->prior=t->prior;  //��t����һ���ڵ��priorָ��ָ��t����һ���ڵ�
    s=s->next;
    free(t);
    return s;
}

DulNode *del_link2(DulNode *person,DulNode *t)
//  n<0 ������ʱ����Һ������m���˵�λ�ã�ɾ��ģ���ͷŵ�ǰ�ڵ㣬ֱ�������˳�Ȧ�����غ�һ���ڵ���Ϣ
{
    DulNode *s=t;
    t->prior->next=t->next;
    t->next->prior=t->prior;
    s=s->prior;
    free(t);
    return s;
}

void JoseduLink(DulNode *person, int n, int m)  //���Ҳ���ӡ��m���ڵ�
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
    printf("����������n:\n");
    scanf("%d",&n);
    printf("������m��ֵ:\n");
    scanf("%d",&m);
    printf("��Ȧ����:\n");
    person=(DulNode*)malloc(sizeof(DulNode));   //Ϊ��һ���ڵ�����ռ�
    person->data=1;       //data��¼��ǰ�˵�λ��
    person->next=person->prior=person;
    s=person;
    for(i=2;i<=n;i++)   //����n-1���ڵ�
    {
        r=s;
        s=(DulNode*)malloc(sizeof(DulNode));
        s->data=i;
        s->prior=r;   //���ν����ɵĽڵ����ѭ��������
        r->next->prior=s;
        s->next=r->next;
        r->next=s;
    }
    printf("\n");
    JoseduLink(person,n,m);
}
