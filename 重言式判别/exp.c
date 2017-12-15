#include<stdio.h>
#include<stdlib.h>

typedef struct exp{
    char data;
    int  weight;
}express;

express symbolrepresent[27];
express originalexpression[50];            

int trueforever=0;
int falseforever=0;
int originalexpressionlength =0;
int symbolrepresentlength=0;

//欢迎屏幕
void ShowWelcome()
{

    printf(" * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf(" *         重言式判别:           * ");
    printf(" * * * * * * * * * * * * * * * * * * * * * * * * ");
}

//表达式分析器 分析权值 把 | 权值设为1  &设为2  ~设为3  
//处理括号的思路是：遇见左括号 把里面权值提升4  遇见右括号 把权值减去4  这样可以处理多括号问题
int analyse(express *p)
{
    int weight=0;
    int length=0;
    printf("请输入表达式，并以回车符为结束: ");
    printf("注意:请自行检查输入表达式的正确性 ");
    while(scanf("%c",&(p->data))&&p->data!=10)
    {
        if(p->data>=97&&p->data<=122)
            p->data=p->data-32;        
        switch(p->data)
        {
        case '(':
            weight=weight+4;          //遇见左括号 把里面权值提升4 

            p->weight=0;                  //注意括号权值为0
            break;
        case ')':
            weight=weight-4;         //遇见右括号 把权值减去4  
            p->weight=0;
            break;
        case '|':
            p->weight=weight+1;
            break;
        case '&':
            p->weight=weight+2;
            break;
        case '~':
            p->weight=weight+3;
            break;
        default:
            p->weight=0;         //imply the data is char
            break;
        }
        p++;
        length++;
    }
    return length;
}

//查找表达式中权值最小的，作为子树的根节点
int findMin(express *originalexpression,int start,int end)
{
    int key=0;
    int current=start;
    int location=0;
    while(!originalexpression[current].weight)
    {key=originalexpression[current].weight;current++;}
    key=current>end?key:originalexpression[current].weight;
    location=current>end?0:current;
    while(current<=end)
    {
        if(originalexpression[current].weight&&originalexpression[current].weight<key)
        {
            location=current;
            key=originalexpression[current].weight;
        }
        current++;
    }
    return location;
}


//分析原表达式，提取所有变量 就是把所有变量罗列在一个数组内
int makeSymbolReprentArray(express *originalexpression)   
{
    int length=0;
    int hashmap[26]={0};
    while(originalexpression->data!=10)
    {
        if(originalexpression->data>=65&&originalexpression->data<=90)
        {
            if(!hashmap[(int)(originalexpression->data-65)])
            {
                hashmap[(int)(originalexpression->data-65)]=1;
                symbolrepresent[length].data=originalexpression->data;
                length++;
            }
        }
        originalexpression++;
    }
    return length;
}

//查找每个变量所代表值 0或1
int findSymbolRepresent(char symbol)
{
    int location=0;
    while(symbolrepresent[location].data!=symbol)
    {
        location++;
    }
    return symbolrepresent[location].weight;
}

//虚拟构建一个二叉树 注意并没有真正构建 不过可理解为建立一个树了 算法核心是一个类似中序遍历二叉树 
int virtualCreateTree(express *originalexpression,int start,int end)        //在以start和end的范围内建子树
{
    int key=0;
    if(start==end)                                                          //start==end 表明这个是叶子节点 那么里面是个变量 
        return findSymbolRepresent(originalexpression[start].data);           
    else if(start>end)
        return 1;                                                           //start>end  处理~的特殊情况
    else
    {
        key=findMin(originalexpression,start,end);                          //寻找最小权值  作为子树根节点    
        switch(originalexpression[key].data)
        {
        case '|':
            return(virtualCreateTree(originalexpression,start,key-1)||virtualCreateTree(originalexpression,key+1,end));
            break;
        case '&':
            return(virtualCreateTree(originalexpression,start,key-1)&&virtualCreateTree(originalexpression,key+1,end));
            break;
        case '~':     //注意~的处理 实际上我是用的(1&&!右子树) 
            return(virtualCreateTree(originalexpression,start,key-1)&&(!virtualCreateTree(originalexpression,key+1,end)));
        }
    }
    
}

//递归给所有变量赋值 注意递归思想用回溯二叉树理解
void recursion(express *symbolrepresent,int i,int length)
{
    if(i<length)
    {
        symbolrepresent[i].weight=1;                   //当前变量取1  
        recursion(symbolrepresent,i+1,length);         //递归调用下一个变量
        symbolrepresent[i].weight=0;                   //当前变量取0    
        recursion(symbolrepresent,i+1,length);         //递归调用下一个变量
    }
    else                                              //递归结束啦
    {
        if(!trueforever||!falseforever)               //注意这个处理 当表达式出现可真情况和可假情况 那么断定它是可满足式  没必要做下去了
        {
            switch(virtualCreateTree(originalexpression,0,originalexpressionlength-1))
            {
            case 1:
                trueforever++;
                break;
            case 0:
                falseforever++;
                break;
            default :
                break;
            }
        }
        else
            return ;
    }
}    

//结果处理  没啥说的
void resultReturn(int symbolrepresentlength)
{
    int i=0;
    if(trueforever&&falseforever)
    {
        printf("您输入的变量名序列为: ");
        while(i<symbolrepresentlength)
        {printf("%c ",symbolrepresent[i].data);i++;}
        printf(" ");
        printf("satisfactible ");
    }
    else if(!trueforever)
        printf("falseforever ");
    else
        printf("trueforever ");    
}

//用户自己设置值  也没啥说的
void userSetWeight()
{
    int i=0;
    printf("请依次为变量赋值,并以回车键结束: ");
    while(i<symbolrepresentlength)
    {
        printf("%c: ",symbolrepresent[i].data);
        scanf("%d",&symbolrepresent[i].weight);
        i++;
    }
    if(virtualCreateTree(originalexpression,0,originalexpressionlength-1))
        trueforever++;
    else
        falseforever++;
}

//主目录
void mainFunctionMenus()
{
    int menu=0;
    printf("请选择您的变量设值方式: ");
    printf("1.计算机自动穷举 ");
    printf("2.用户指定设置 ");
    scanf("%d",&menu);
    if(1==menu)
        recursion(symbolrepresent,0,symbolrepresentlength);
    else
        userSetWeight();
}


int main()
{
    ShowWelcome();
    originalexpressionlength        =    analyse(originalexpression);
    symbolrepresentlength           =    makeSymbolReprentArray(originalexpression);
    mainFunctionMenus();
    resultReturn(symbolrepresentlength);
    //printf("%d",analyse(exp));
    //printf(" %d",findMin(exp,0,analyse(exp);))
    return 0;
}