#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define DRAWSINGLELINE printf("-----------------------------------------------------------------------------------\n")
#define DRAWDOUBLELINE printf("===================================================================================\n")
#define RANGEN(a)  ((int)rand() % a)
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct listNode {
	char name[10];			// 이름
	int score;				// 성적(0~100)
	struct listNode* link;
}listNode;


typedef struct {
	struct listNode* head;
	int type;	//1이면 내림 차순, 0이면 올림 차순 
}listHead;

listHead* CreateNode();
void ClearNode(listHead* h);
listNode* AddRandomNode(listHead* h);
listNode* AddDirectNode(listHead* h, int s, char* n);
listNode* DeleteSelectNode(listHead* h, char* n);
listNode* DeleteLastNode(listHead* h);
listNode* ChangeNode(listHead* h, int s, char* n);
listNode* FindbyName(listHead* h, char* n);
listNode* FindbyScore(listHead* h, int s);
listNode* FindMiddleNode(listHead* h);
listNode* FindLastNode(listHead* h);
double CalAverage(listHead* h);
void PrintAllNode(listHead* h);
void ReverseList(listHead* h);
void PrintRangedNode(listHead* h, int min, int max);

