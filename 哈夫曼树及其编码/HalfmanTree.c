#include <stdio.h>
#include <stdlib.h>

struct HTnode {
	char ch;
	int weight,parent,lchild,rchild;
};

struct HuffmanTree {
	HTnode *ht; //静态树表基地址指针；
	int htsize; //树节点个数
};

void InitHuffmanTree (HuffmanTree &HT, int n)
{
	//n个节点的哈夫曼树共有2n-1个节点
    HT.ht = new HTnode[2*n-1];
    HT.htsize = 2*n-1;  //创建哈夫曼树
};

void DestoryHuffmanTree(HuffmanTree &HT)
{
     delete[] HT.ht;
     HT.htsize = 0;	
};

void MinVal(HuffmanTree &HT, int i)
{
	int j,k,min=max;
	for(j=0;j<i;j++)
	{
		if()
		{
			min=HT.ht[j].weight;
			k=j;
		}
		HT.ht[k].parent = max;
		return k;
	}
}

void Select(HuffmanTree &HT,int i, int &s1, int &s2)
{
	int s;
	s1 = MinVal(HT,i);
	s2 = MinVal(HT,i);
	if(s1>s2)  //s1是最小的两个值中序号小的那个
	{
		s=s1;
		s1=s2;
		s2=s;
	}
}

//根据字符表和相应权值，建立哈夫曼树
void Create(HuffmanTree &HT,int n, char ch[], int weight[])
{
   int i,s1,s2;
   if(n>1)
   {
      for(i=0;i<n;i++)
      {
      	HT.ht[i].ch = ch[i];
      }
      for(;i<HT.HTsize;i++)
      {
          
      }
   }
   printf("哈夫曼树构建完毕！\n");
};

void Display(HuffmanTree &HT)
{
	//显示哈夫曼树
	int i;
	printf("所建哈夫曼树的静态链表表示如下：\n");
	for(i=0;i<HT.size;i++)
	{
		printf();
	}
}


struct HCnode {
	char ch;
	char *pstring;
}

struct HUffmanCoder {
	HCnode *hc;
	int hcsize; //树叶节点的个数
};

void InitHuffmanCoder(HuffmanCoder &HC, int n)
{
	HC.hc = new HCnode[n];
	HC.hcsize = n;
};

void DestoryHuffmanCoder(HuffmanCoder &HC)
{
	int i;
	for(i = 0;i<HC.hcsize;i++)
		delete[]HC.hc[i].pstring;
	delete[] HC.hc;	
};

void tips() //操作选择界面
{
     printf("--------------------------------------\n");
     printf("--          请选择你的操作        ----\n");
     printf("--------------------------------------\n");
     printf("----------  I.哈夫曼树的初始化--------\n");
     printf("----------  E.编码  ------------------\n");
     printf("----------  D.译码  ------------------\n");
     printf("----------  P.印代码文件  ------------\n");
     printf("----------  T.印哈夫曼树  ------------\n");
     printf("----------  Q.安全退出   -------------\n");
     printf("--------------------------------------\n");
}

int main()
{
	char choice;
	while(1)
	{
		tips();
		scanf("%c", &choice);
		// switch(choice)
		// {
  //           case 'I': Init();
  //              break;
  //           case 'E': Encoding();
  //              break;
  //           case 'D': Decoding();
  //              break;
  //           case 'P': Print();
  //              break;
  //           case 'T': Printing();
  //              break;
  //           case 'Q': exit(1);

  //           default : printf("Input error !\n");
		// }
		//getchar();
	}
	return 0;
	// int i,n;
	// printf("*******哈夫曼树及其哈夫曼编码********\n");
	// printf("请输入树叶节点的个数\n");
	// scanf("%d", &n);
	// char ch[256];
	// int weight[256];

	// for(i=0;i<n;i++)
	// {
	// 	printf("请输入第i+1个字符及其权值");
	// 	scanf("%s %s",&ch[i],&weight[i]);
	// };
};