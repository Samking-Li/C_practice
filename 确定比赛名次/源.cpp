/*
N支队伍，M场比赛，输入P1 P2表示“P1赢了P2”，根据比赛结果输出名次。当可能的排名不唯一时，优先输出编号小的队伍
例：
	输入：M=3
		  N=4
		  1 2
		  4 3
		  3 2
	
	输出：1432

算法思路：以有向图存储比赛数据，若P1赢了P2，则P2->P1，依此创建有向图。如范例所创建的有向图为'4'<-'3'<-'2'->'1'
之后在图中选取无出度的节点中最小的那个作为输出，并将其删去。依次循环直至图为空，此时得到所求输出。
*/

#include <stdio.h>
#include <stdlib.h>
#include "源.h"
#define MAX 100

//邻接表边表节点
typedef struct ArcNode {
	int adjvex;
	struct ArcNode *next;
}ArcNode;

//邻接表顶点表节点
typedef struct VNode {
	int data;
	ArcNode* next;
}VNode;

//邻接表
typedef struct ALGraph {
	VNode AdjList[MAX];
	int NodeNum;
}ALGraph;

//初始化图
void init_Grath(ALGraph &Graph, int N)
{
	int i;
	for (i = 0; i < MAX; i++)
	{
		Graph.AdjList[i].data = -1;
		Graph.AdjList[i].next = NULL;
	}
	Graph.NodeNum = N;
	for (i = 0; i < N; i++)
	{
		Graph.AdjList[i].data = i + 1;
	}
}

//添加边
void insert_Arc(ALGraph &Graph, int out, int in)
{
	ArcNode* node = (ArcNode*)malloc(sizeof(ArcNode));
	node->next = NULL;
	node->adjvex = in;
	if (Graph.AdjList[(out - 1)].next == NULL)
	{
		Graph.AdjList[(out - 1)].next = node;
	}
	else
	{
		ArcNode* p = Graph.AdjList[(out - 1)].next;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = node;
	}
}

//删除节点
void Del_VNode(ALGraph &Graph, int n)
{
	int i;
	ArcNode* p = NULL;
	ArcNode* q = NULL;
	/*if (Graph.AdjList[n].next != NULL)
	{
		q = Graph.AdjList[n].next;
		Graph.AdjList[n].next = NULL;
		while (q->next != NULL)
		{
			p = q->next;
			free(q);
			q = p;
		}
		free(q);
		p = NULL;
		q = NULL;
	}*/
	for (i = 0; i < MAX; i++)
	{
		if (Graph.AdjList[i].next!=NULL)
		{
			if(Graph.AdjList[i].next->adjvex == Graph.AdjList[n].data)
			{
				Graph.AdjList[i].next = Graph.AdjList[i].next->next;
			}
			else
			{
				p = Graph.AdjList[i].next;
				while (p->next != NULL)
				{
					if (p->next->adjvex == Graph.AdjList[n].data)
					{
						q = p->next;
						p->next = p->next->next;
						free(q);
						q = NULL;
					}
					else
					{
						p = p->next;
					}
				}
			}
			
		} 
		
	}
	Graph.AdjList[n].data = -1;
	Graph.NodeNum--;
}


void main()
{
	int M, N;
	int i, j;
	int P1, P2;
	ALGraph Graph;
	scanf_s("%d", &M);
	scanf_s("%d", &N);
	init_Grath(Graph, N);
	int comp[MAX][2];
	for (i = 0; i < M; i++)
	{
		scanf_s("%d %d", &P1,&P2);
		if (P1 > N || P2 > N)
		{
			printf("输入错误，不可大于%d", N);
			return;
		}
		insert_Arc(Graph, P2, P1);
	}


	while (Graph.NodeNum > 0)
	{
		for (i = 0; i < N; i++)
		{
			if (Graph.AdjList[i].next == NULL && Graph.AdjList[i].data != -1)
			{
				printf("%d", Graph.AdjList[i].data);
				Del_VNode(Graph, i);
			}
		}
	}

}