#include<stdlib.h>     
#include<conio.h>     
#include<string.h>     
#define INFINITY      32767           
#define MAX_VERTEX_NUM      30     
#define MAX 30     
#define TRUE 1     
#define FALSE 0     
typedef struct    
{    
    int adj;//路径长度     
}ArCell,ArcNode[30][30];    
typedef struct//，图中顶点表示主要景点，存放景点的编号、名称、简介等信息，     
{    
    char name[30];    
    int num;    
    char info[100];//简介     
}VexNode;    
typedef struct    
{    
    VexNode vertex[MAX_VERTEX_NUM];    
    ArcNode arcs;    
    int vexnum,arcnum;    
}AdjMatrix;    
    
////返回V在G中的位置     
int LocateVex(AdjMatrix G,char* v)    
{          
    int m=-1,i;    
    for(i=0;i<G.vexnum;i++)    
    if(strcmp(v,G.vertex[i].name)==0)    
    {    
        m=i;    
        break;    
    }    
    return m;    
}    
    
///创建完整的网     
AdjMatrix CreateDN()    
{    
    AdjMatrix G;    
    int i,j;    
    G.vexnum=25;    
    G.arcnum=31;    
    for(i=0;i<G.vexnum;i++)    
        G.vertex[i].num=i;    
    for(i=0;i<G.vexnum;i++)    
        for(j=0;j<G.vexnum;j++)    
           G.arcs[i][j].adj=INFINITY;    
        //所有带权边     
    G.arcs[0][3].adj=400;    
    G.arcs[0][4].adj=150;    
    G.arcs[1][2].adj=150;    
    G.arcs[1][6].adj=500;    
    G.arcs[2][3].adj=50;    
    G.arcs[3][5].adj=100;    
    G.arcs[4][5].adj=200;    
    G.arcs[4][6].adj=100;    
    G.arcs[6][7].adj=50;    
    G.arcs[6][11].adj=80;    
    G.arcs[7][8].adj=5;    
    G.arcs[7][15].adj=5;    
    G.arcs[8][9].adj=5;    
    G.arcs[9][10].adj=35;    
    G.arcs[9][14].adj=20;    
    G.arcs[10][11].adj=20;    
    G.arcs[10][12].adj=5;    
    G.arcs[10][14].adj=30;    
    G.arcs[11][12].adj=5;    
    G.arcs[12][13].adj=10;    
    G.arcs[15][16].adj=20;    
    G.arcs[15][17].adj=10;    
    G.arcs[16][19].adj=100;    
    G.arcs[16][18].adj=250;    
    G.arcs[18][20].adj=20;    
    G.arcs[19][21].adj=50;    
    G.arcs[20][22].adj=30;    
    G.arcs[22][23].adj=100;    
    G.arcs[19][24].adj=400;    
    G.arcs[21][24].adj=400;    
    G.arcs[22][24].adj=450;    
          //所有景点信息     
    strcpy(G.vertex[0].name,"北门");    
    strcpy(G.vertex[0].info,"北门是华农校门，连接着南湖大道。!");    
    strcpy(G.vertex[1].name,"西大门");    
    strcpy(G.vertex[1].info,"西大门是华农的主校门，门前是梧桐路,步行街!");    
    strcpy(G.vertex[2].name,"华农附小");    
    strcpy(G.vertex[2].info,"华农附属小学，祖国花朵的希望!");    
    strcpy(G.vertex[3].name,"校医院");    
    strcpy(G.vertex[3].info,"校医院有着比较先进的设备，并且学生，教职工看病十分便宜!");    
    strcpy(G.vertex[4].name,"继续教育学院");    
    strcpy(G.vertex[4].info,"继续教育学院是华农专为有志的成人大学生设立的专门院!");    
    strcpy(G.vertex[5].name,"南湖派出所");    
    strcpy(G.vertex[5].info,"校园法制机构,请拨打87281110，24小时为华农人服务!");    
    strcpy(G.vertex[6].name,"主楼");    
    strcpy(G.vertex[6].info,"主楼是华农的标志性建筑，座落在华农北边，远看很有气质!");    
    strcpy(G.vertex[7].name,"逸夫楼");    
    strcpy(G.vertex[7].info,"逸夫楼座落在主楼旁，是理学院的标志!");    
    strcpy(G.vertex[8].name,"求是楼");    
    strcpy(G.vertex[8].info,"求是楼紧靠逸夫楼，在这里你可以看见很多留学生!");    
    strcpy(G.vertex[9].name,"求真楼");    
    strcpy(G.vertex[9].info,"求真楼又叫研究生楼，通常里面都是考研的人!");    
    strcpy(G.vertex[10].name,"求实楼");    
    strcpy(G.vertex[10].info,"求实楼是主教学楼，各个年级的很多课程都在这里上!");    
    strcpy(G.vertex[11].name,"图书馆");    
    strcpy(G.vertex[11].info,"图书馆是华中地区仅有的三个B级成员馆之一，馆藏丰富!");    
    strcpy(G.vertex[12].name,"人文楼");    
    strcpy(G.vertex[12].info,"人文楼也是一主要教学，多媒体集一身的主教学楼!");    
    strcpy(G.vertex[13].name,"外语系");    
    strcpy(G.vertex[13].info,"云集众多美女的外语系是各个大学的亮点，本校深刻体现了这一点!");    
    strcpy(G.vertex[14].name,"工程技术学院");    
    strcpy(G.vertex[14].info,"拥有50年历史的工程院，有其强悍的实力,座落在狮山广场的喷泉边!");    
    strcpy(G.vertex[15].name,"一运");    
    strcpy(G.vertex[15].info,"一运有篮球场足球场还有健身器材等!");    
    strcpy(G.vertex[16].name,"愽园");    
    strcpy(G.vertex[16].info,"愽园是学生住宿区之一，旁边即是愽园食堂，以北方面食，饼为主!");    
    strcpy(G.vertex[17].name,"学生大食堂");    
    strcpy(G.vertex[17].info,"食堂够大!");    
    strcpy(G.vertex[18].name,"体育馆");    
    strcpy(G.vertex[18].info,"体育馆美观大方旁边建有  游泳池，同时也是新生报到点!");    
    strcpy(G.vertex[19].name,"橘园");    
    strcpy(G.vertex[19].info,"橘园也是学生住宿区之一!");    
    strcpy(G.vertex[20].name,"荟园食堂");    
    strcpy(G.vertex[20].info,"荟园食堂是最多学生的选择!");    
    strcpy(G.vertex[21].name,"二运");    
    strcpy(G.vertex[21].info,"二运除了具有足球场，跑道，还有网球、排球场，通常运动会在此召开!");    
    strcpy(G.vertex[22].name,"荟园");    
    strcpy(G.vertex[22].info,"荟园也是学生住宿区之一!");    
    strcpy(G.vertex[23].name,"后勤集团");    
    strcpy(G.vertex[23].info,"后勤集团,华农的后备力量,很出色!");    
    strcpy(G.vertex[24].name,"南湖");    
    strcpy(G.vertex[24].info,"南湖毫无疑问是华农的特色之一，而是情侣约会的好场所!");    
    for(i=0;i<G.vexnum;i++)    
        for(j=0;j<G.vexnum;j++)    
            G.arcs[j][i].adj=G.arcs[i][j].adj;    
     return G;    
}    
    
// 迪杰斯特拉算法来计算出起点到各个顶点之间的最短路径,v0为起点     
void ShortestPath_DIJ(AdjMatrix G)    
{    
    int v,w,i,min,c=0,x,ex=1,v0 ;    
    int last[MAX], D[MAX], p[MAX][MAX];    
    while(ex)    
    {    
        printf("请输入一个起始景点编号:");    
        scanf("%d",&v0);    
        if(v0<0||v0>G.vexnum)    
        {    
             printf("景点编号不存在!请重新输入景点编号:");    
             scanf("%d",&v0);    
        }    
    if(v0>=0&&v0<G.vexnum)    
    ex=0;    
    }    
    for(v=0;v<G.vexnum;v++)    
    {    
        last[v]=FALSE;    
        D[v]=G.arcs[v0][v].adj;    
        for(w=0;w<G.vexnum;w++)    
           p[v][w]=FALSE;    
        if(D[v]<INFINITY)    
        {    
            p[v][v0]=TRUE;    
            p[v][v]=TRUE;    
        }    
    }    
    D[v0]=FALSE;    
    last[v0]=TRUE;    
    for(i=1;i<G.vexnum;i++)    
    {    
        min=INFINITY;    
        for(w=0;w<G.vexnum;w++)    
           if(!last[w])    
              if(D[w]<min)    
              {    
                  v=w;    
                  min=D[w];    
              }    
        last[v]=1;    
        for(w=0;w<G.vexnum;w++)    
            if(!last[w]&&(min+G.arcs[v][w].adj<D[w]))    
            {    
               D[w]=min+G.arcs[v][w].adj;    
               for(x=0;x<G.vexnum;x++)     
                    p[w][x]=p[v][x];    
               p[w][w]=TRUE;    
            }    
    
        
    }    
    for(v=0;v<G.vexnum;v++)    
    {    
        if(v0!=v)printf("%s",G.vertex[v0].name);    
        for(w=0;w<G.vexnum;w++)    
        {    
            if(p[v][w]&&w!=v0)printf("-->%s",G.vertex[w].name);    
            c++;    
        }    
        if(c>G.vexnum-1&&v0!=v)    
              printf("       最短总路线长%dm\n\n",D[v]);    
    }    
}    
typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];    
typedef int DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    
void ShortestPath_Floyd(AdjMatrix G,PathMatrix *P,DistancMatrix *D)    
{ /* 用Floyd算法求有向网G中各对顶点v和w之间的最短路径P[v][w]及其 */    
  /* 带权长度D[v][w]。若P[v][w][u]为TRUE,则u是从v到w当前求得最短 */    
  /* 路径上的顶点。算法7.16 */    
  int u,v,w,i,k,j,ex=1;    
  for(v=0;v<G.vexnum;v++) /* 各对结点之间初始已知路径及距离 */    
    for(w=0;w<G.vexnum;w++)    
    {    
      (*D)[v][w]=G.arcs[v][w].adj;    
      for(u=0;u<G.vexnum;u++)    
        (*P)[v][w][u]=FALSE;    
      if((*D)[v][w]<INFINITY) /* 从v到w有直接路径 */    
      {    
        (*P)[v][w][v]=TRUE;    
        (*P)[v][w][w]=TRUE;    
      }    
    }    
  for(u=0;u<G.vexnum;u++)    
    for(v=0;v<G.vexnum;v++)    
      for(w=0;w<G.vexnum;w++)    
        if((*D)[v][u]+(*D)[u][w]<(*D)[v][w]) /* 从v经u到w的一条路径更短 */    
        {    
          (*D)[v][w]=(*D)[v][u]+(*D)[u][w];    
          for(i=0;i<G.vexnum;i++)    
            (*P)[v][w][i]=(*P)[v][u][i]||(*P)[u][w][i];    
        }    
    while(ex)    
    {    
        printf("请输入出发点和目的地的编号(以空格分开):\n\n");    
        scanf("%d%d",&k,&j);    
        if(k<0||k>G.vexnum||j<0||j>G.vexnum)    
        {    
            printf("景点编号不存在!请重新输入出发点和目的地的编号:\n\n");    
            scanf("%d%d",&k,&j);    
        }    
        if(k>=0&&k<G.vexnum&&j>=0&&j<G.vexnum)    
        ex=0;    
    }    
    printf("%s",G.vertex[k].name);    
    for(u=0;u<G.vexnum;u++)    
        if((*P)[k][j][u]&&k!=u&&j!=u)    
           printf("-->%s",G.vertex[u].name);    
    printf("--->%s",G.vertex[j].name);    
    printf("      最短总路线长%dm\n",(*D)[k][j]);    
}    
///////////////////////////////////////////////////////////////
//显示所有的景点信息     
void ShowAll(AdjMatrix  G)    
{    
    int v;    
    printf("        _________________________________________________________________________________________\n\n");    
    printf("       | 编号   |景点名称        | 简介                                                   |\n\n");    
    for(v=0;v<G.vexnum;v++)    
    printf("       |  %-3d  | %-15s| %-65s|\n",G.vertex[v].num,G.vertex[v].name,G.vertex[v].info);             
    printf("       |_________________________________________________________________________________________|\n\n");    
}    
/////////////////////////////////////////////////////////////////     
//查询函数，查询你了解的景点     
void Find(AdjMatrix G)    
{    
    int k,ex=1;    
    while(ex)    
    {    
       printf("请输入要查询的景点标号:\n\n");    
       scanf("%d",&k);    
       if(k<0||k>G.vexnum)    
       {    
           printf("您真幽默!请重新输入景点标号:\n\n");    
           scanf("%d",&k);    
           if(k<0||k>G.vexnum)    
           {    
               printf("您太会开玩笑了!请重新输入景点标号:\n\n");    
               scanf("%d",&k);    
               if(k<0||k>G.vexnum)    
               {    
                   printf("您不要玩我了!请重新输入景点标号:\n\n");    
                   scanf("%d",&k);    
               }    
           }    
       }    
      if(k>=0&&k<G.vexnum)    
         ex=0;    
    }    
    printf("\n\n景点编号:%d \n",G.vertex[k].num);    
    printf("\n\n景点名称:%s \n",G.vertex[k].name);    
    printf("\n\n景点简介:%s \n\n\n",G.vertex[k].info);    
}    
void Display()    
{     
    printf("\n                            XXXX校园导游\n\n");    
    printf("                                        ------XX XXXXXXXX\n");    
    printf("                  _____________________________________________ \n\n");    
    printf("                  |            1.浏览校园全部景点              |\n\n");    
    printf("                  |            2.查询任意景点信息              |\n\n");    
    printf("                  |            3.查看全部游览最短路线          |\n\n");    
    printf("                  |            4.查询任意两点的最短路线        |\n\n");    
    printf("                  |            5.退出导游系统                  |\n\n");    
    printf("                  |____________________________________________|\n\n\n\n");    
    printf("选择功能如下:\n\n");    
}    
void main()    
{    
    system("color D");    //设置淡紫色     
    system("mode con: cols=128 lines=60"); //设置显示宽、高     
    AdjMatrix g;    
    int i;    
    PathMatrix a;    
    DistancMatrix b;    
    g=CreateDN();       
    Display();    
    while(1)    
    {    
        scanf("%d",&i);    
        if(i==1)    
        {    
            system("cls"); //清屏     
            Display();    
            ShowAll(g);   //显示全景     
            printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");    
            continue ;    
        }    
        if(i==2)    
        {    
            system("cls");    
            Display();    
            Find(g);    
            printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");    
            continue;    
        }    
        if(i==3)    
        {
            system("cls");    
            Display();    
            ShortestPath_DIJ(g);      
            printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");    
            continue;    
        }    
        if(i==4)    
        {    
            system("cls");    
            Display();    
            ShortestPath_Floyd(g,&a,&b);    
            printf("\n\n您可以继续使用本系统的其他服务，输入5退出系统!\n\n");    
            continue;    
        }    
        if(i==5)    
        {    
             exit(0);    
        }    
    }    
}   
