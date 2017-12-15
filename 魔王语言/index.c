//魔王语言数据结构上机代码
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node
{
	char data;
	struct Node*next;
}Node, *NodePtr;

typedef struct Stak
{
	NodePtr top;   //栈顶指针
	NodePtr bot;   //在栈构造之前和销毁之后，top的值为NULL;
	int count;
}Stak;

void InitStak(Stak *ts)//创建空栈
{
	ts->top = (NodePtr)malloc(sizeof(Node));    //为栈顶指针申请节点空间
	if (NULL == ts->top)
		exit(-1);
	ts->bot = ts->top;
	ts->count = 0;  
	// ts->top->next = NULL;
}
void Push(Stak*S, char e) //插入元素e为新的栈顶元素
{
	NodePtr pnew = (NodePtr)malloc(sizeof(Node));
	pnew->data = e;
	pnew->next = S->top;
	S->top = pnew;
	S->count++;
}
char Pop(Stak*S)   //如果栈不空，则删除s的栈顶元素，用e返回其值，并返回ok
{
	NodePtr p;
	if (S->bot == S->top)
	{
		exit(1);
	}
	p = S->top;
	char e = p->data;
	S->top = S->top->next;
	free(p);  //释放栈顶P结点
	S->count--;
	return e;
}

void prin(Stak* S)
//打印输出栈
{
	NodePtr p;
	p = S->top;

	while (p != S->bot)
	{
		printf("%c\n", p->data);
		p = p->next;
	}
}

bool EmptyStack(Stak*S)  //如果栈是空栈，返回1
{
	if (S->count == 0)
		return 1;
	return 0;
}

typedef struct QNode
{
	char data;
	struct QNode *next;

}QNode, *QNodePtr;

typedef struct LinkQueue
{
	QNodePtr front;  //头指针，指向队列头元素
	QNodePtr rear;   //尾指针，指向队尾元素的下一个位置
}Queue; 

void InitQue(Queue *Q)   //构造一个空队列Q
{
	QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
	p->data = NULL;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
}

void EnQue(Queue *Q, char e)  //插入元素e为Q的新的队尾元素
{
	QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
}

char DeQue(Queue *Q)
//出队列  逻辑上的删除，并不是物理删除
{
	QNodePtr p;
	char c;
	if (Q->front == Q->rear)
	{//空时
		exit(1);
	}
	p = Q->front->next;
	c = Q->front->next->data;
	Q->front->next = p->next;
	if (p == Q->rear)
	{
		Q->rear = Q->front;
	}
	free(p);
    return c;
}

void pri(Queue *Q)  //从头到尾把front到rear打印出来
//打印队列
{
	QNodePtr p;
	p = Q->front;
	if (p != NULL)
	{
		while (p != Q->rear)
		{
			printf("%c", p->next->data);
			p = p->next;
		}
	}

}

bool EmptyQue(Queue *Q)
{
	if (Q->front == Q->rear)
		return 1;
	return 0;
}

void Reverse(char M[], Stak *S)  //保证括号对称出现
{
	int i;
	int len = strlen(M);
	int l = 0, r = 0;
	for (i = 0; i <len; i++)
	{
		Push(S, M[i]);
		if (M[i] == '(')
			l++;
		if (M[i] == ')')
			r++;
	}
	if (l != r)
		exit(1);
}

void EnA(Queue *Q)
//规则1
{
	EnQue(Q, 's');
	EnQue(Q, 'a');
	EnQue(Q, 'e');
}

void EnB(Queue *Q)
//规则2
{
	EnQue(Q, 't');
	EnA(Q);
	EnQue(Q, 'd');
	EnA(Q);
}

void  Fpri(Queue *Q)
//将小写字母与汉字建立对应关系
{
	char c;
	while (!EmptyQue(Q))
	{
		c = DeQue(Q);
		switch (c)
		{
		case 't':printf("天"); break;
		case 'd':printf("地"); break;
		case 's':printf("上"); break;
		case 'a':printf("一只"); break;
		case 'e':printf("鹅"); break;
		case 'z':printf("追"); break;
		case 'g':printf("赶"); break;
		case 'x':printf("下"); break;
		case 'n':printf("蛋"); break;
		case 'h':printf("恨"); break;
		default: printf("Error");
		}

	}
}

void zhaobuchu(Stak *Sbe, Stak *Saf, Queue *Q)
{
	char c;
	char d;
	int i = 0;
	while (Sbe->count != 0)
	{
		c = Pop(Sbe);
		if (c == ')')
			i = Saf->count;
		else if (c == '(')   //如果是开括号，则逐一出栈，将字母顺序入队列，直到闭括号出栈完毕
		{
			int j = Saf->count;
			while (j > i)    
			{
				d = Pop(Saf);
				EnQue(Q, d);
				j--;
			}
			char e = Q->front->next->data; // 头指针的下一个结点保证重复出现
			DeQue(Q);
			while (!EmptyQue(Q))
			//规则2   逐一出队列后再处理后入栈
			{
				char dl = DeQue(Q);
				Push(Saf, e);
				Push(Saf, dl);
			}
			Push(Saf, e);
		}
		else
			Push(Saf, c);//正常进去
	}

	while (Saf->count>0)
	{
		char en;
		en = Pop(Saf);
		if (en == 'A')
			EnA(Q);
		else if (en == 'B')
			EnB(Q);
		else
			EnQue(Q, en);
	}
	Fpri(Q);
}


int main()
{
	Stak ms, tm;
	InitStak(&ms);
	InitStak(&tm);
	Queue Qu1;
	InitQue(&Qu1);
	char M[] = "B(ehnxgz)B";
	Reverse(M, &ms);
	zhaobuchu(&ms, &tm, &Qu1);
	getchar();
	return 0;
}






