/*
N֧���飬M������������P1 P2��ʾ��P1Ӯ��P2�������ݱ������������Ρ������ܵ�������Ψһʱ������������С�Ķ���
����
	���룺M=3
		  N=4
		  1 2
		  4 3
		  3 2
	
	�����1432

�㷨˼·��������ͼ�洢�������ݣ���P1Ӯ��P2����P2->P1�����˴�������ͼ���緶��������������ͼΪ'4'<-'3'<-'2'->'1'
֮����ͼ��ѡȡ�޳��ȵĽڵ�����С���Ǹ���Ϊ�����������ɾȥ������ѭ��ֱ��ͼΪ�գ���ʱ�õ����������
*/

#include <stdio.h>
#include <stdlib.h>
#include "Դ.h"
#define MAX 100

//�ڽӱ�߱�ڵ�
typedef struct ArcNode {
	int adjvex;
	struct ArcNode *next;
}ArcNode;

//�ڽӱ����ڵ�
typedef struct VNode {
	int data;
	ArcNode* next;
}VNode;

//�ڽӱ�
typedef struct ALGraph {
	VNode AdjList[MAX];
	int NodeNum;
}ALGraph;

//��ʼ��ͼ
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

//��ӱ�
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

//ɾ���ڵ�
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
			printf("������󣬲��ɴ���%d", N);
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