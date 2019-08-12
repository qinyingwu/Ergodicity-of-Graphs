// 图的遍历.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#define MAX_VERTEX_NUM 100 
#include<stdio.h> 
#include<malloc.h> 

struct EdgeNode 
{ int adjvex;//边所指向的顶点的位置 
int weight;//边的权值 
struct EdgeNode *next;//指向下一条边的指针 
}; 
struct Vnode//顶点结点的结构 
{ int vertex;//顶点信息 
EdgeNode *link;//指向第一条依附该顶点的边 
} AdjList[MAX_VERTEX_NUM]; 
int Visited[MAX_VERTEX_NUM]={0}; 
int q[MAX_VERTEX_NUM]; 

void build_adjlist(Vnode ga[]) 
{ int n,e; 
printf("请输入顶点数及边数：");scanf("%d%d",&n,&e); 
for (int i=1; i<=n ;i++) //初始化邻接表 
{ ga[i].vertex=i; ga[i].link=NULL;} 
int vi,vj; printf("请输入顶点对：\n"); 
for (int k=0;k<e;k++) 
{ scanf("%d%d",&vi,&vj); //读入顶点对<i,j> 
EdgeNode *p=(EdgeNode*)malloc(sizeof(EdgeNode)); 
p->adjvex=vj; 
p->next=ga[vi].link; 
ga[vi].link=p; 
EdgeNode *q=(EdgeNode*)malloc(sizeof(EdgeNode)); 
q->adjvex=vi; 
q->next=ga[vj].link; 
ga[vj].link=q;} 
} 

void dfs(Vnode g[],int v0) 
{ 
	printf("[%d]", v0); 
Visited[v0]=1; //标志v0已访问 
EdgeNode *p=g[v0].link; //找v0的第一个邻接点 
while (p!=NULL) 
{ if (Visited[p->adjvex]==0) 
dfs(g, p->adjvex); 
p=p->next; } 
} 

void bfs (Vnode g[],int v0) 
{
Visited[v0]=1; printf("[%d]", v0); 
int f=1,r=1,v; 
EdgeNode *p=g[v0].link; 
do 
{while (p!=NULL) 
{ v=p->adjvex; 
if (Visited[v]==0) 
{ q[r]=v; r++; printf("[%d]",v); Visited[v]=1;} 
p=p->next;//找某一个顶点的所有邻接点，并进队 
} 
if (f!=r)//v出队 
{ v=q[f]; f++; p=g[v].link;} 
}while ((p!=NULL)||(f!=r)); 
} 

void main() 
{ 
build_adjlist(AdjList); 
dfs(AdjList,1); 
//	bfs(AdjList,1); 
int b;
scanf("%d", &b);
}
