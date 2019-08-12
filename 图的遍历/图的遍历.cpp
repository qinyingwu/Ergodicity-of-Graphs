// ͼ�ı���.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#define MAX_VERTEX_NUM 100 
#include<stdio.h> 
#include<malloc.h> 

struct EdgeNode 
{ int adjvex;//����ָ��Ķ����λ�� 
int weight;//�ߵ�Ȩֵ 
struct EdgeNode *next;//ָ����һ���ߵ�ָ�� 
}; 
struct Vnode//������Ľṹ 
{ int vertex;//������Ϣ 
EdgeNode *link;//ָ���һ�������ö���ı� 
} AdjList[MAX_VERTEX_NUM]; 
int Visited[MAX_VERTEX_NUM]={0}; 
int q[MAX_VERTEX_NUM]; 

void build_adjlist(Vnode ga[]) 
{ int n,e; 
printf("�����붥������������");scanf("%d%d",&n,&e); 
for (int i=1; i<=n ;i++) //��ʼ���ڽӱ� 
{ ga[i].vertex=i; ga[i].link=NULL;} 
int vi,vj; printf("�����붥��ԣ�\n"); 
for (int k=0;k<e;k++) 
{ scanf("%d%d",&vi,&vj); //���붥���<i,j> 
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
Visited[v0]=1; //��־v0�ѷ��� 
EdgeNode *p=g[v0].link; //��v0�ĵ�һ���ڽӵ� 
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
p=p->next;//��ĳһ������������ڽӵ㣬������ 
} 
if (f!=r)//v���� 
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
