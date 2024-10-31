
#include "student.h"

listHead* CreateNode()
{
	listHead* newLink = (listHead*)malloc(sizeof(listHead));
	newLink->head = NULL;
	newLink->type = 1;
	return newLink;
}

void  ClearNode(listHead* h)
{
	listNode* temp = h->head;
	listNode* old = temp;

	while (temp != NULL)
	{
		temp = temp->link;
		free(old);
		old = temp;
	}

}

listNode* AddRandomNode(listHead* h)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	for (int i = 0; i < 9; i++)
		newNode->name[i] = RANGEN(26) + 'a';
	newNode->name[9] = 0;
	newNode->score = RANGEN(101);
	newNode->link = NULL;
	
	/*
	제작된 점수와 이름을 기반으로 위치를 찾아서 newNode를 삽입하여라.
	*/
	// 여기부터 지워야함
	if (h->head == NULL)
		h->head = newNode;
	else
	{
		newNode->link = h->head;
		h->head = newNode;
	}
	// 여기 까지


	return newNode;
}

listNode* AddDirectNode(listHead* h, int s, char* n)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	strcpy(newNode->name, n);
	newNode->score = s;
	newNode->link = NULL;

	/*
	입력된 점수와 이름을 기반으로 위치를 찾아서 newNode를 삽입하여라.
	*/
	// 여기부터 지워야함
	if (h->head == NULL)
		h->head = newNode;
	else
	{
		newNode->link = h->head;
		h->head = newNode;
	}
	// 여기 까지

	return newNode;
}

listNode* DeleteSelectNode(listHead* h, char* n)
{
	listNode* oldNode = NULL; //삭제할 노드의 위치를 저장
	
	/*
	문자열 n을 기반으로 삭제할 노드를 찾아 삭제하고
	그 삭제할 노드를 oldNode에 저장	
	*/
	return oldNode;
}

listNode* DeleteLastNode(listHead* h)
{
	listNode* oldNode = NULL; //삭제할 노드의 위치를 저장
	listNode* temp = h->head;

	if (temp == NULL)
	{
		printf("삭제할 노드가 없습니다.\n");
		oldNode =  NULL;
	}
	else if( temp->link == NULL)
	{
		printf("노드가 모두 삭제되었습니다.\n");
		oldNode = temp;
		h->head = NULL;
	}
	else
	{
		oldNode = temp->link;
		while (oldNode->link != NULL)
		{
			temp = temp->link;
			oldNode = oldNode->link;
		}
		temp->link = NULL;
	}
	return oldNode;
}

listNode* ChangeNode(listHead* h, int s, char* n)
{
	listNode* tempNode = NULL; //삭제할 노드의 위치를 저장


	return tempNode;
}
listNode* FindbyName(listHead* h, char* n)
{
	listNode* tempNode = NULL; //삭제할 노드의 위치를 저장


	return tempNode;

}
listNode* FindbyScore(listHead* h, int s)
{
	listNode* tempNode = NULL; //삭제할 노드의 위치를 저장


	return tempNode;
}
listNode* FindMiddleNode(listHead* h)
{
	listNode* tempNode = NULL; //삭제할 노드의 위치를 저장


	return tempNode;
}
listNode* FindLastNode(listHead* h)
{
	listNode* tempNode = h->head;

	if (tempNode == NULL)
	{
		printf("저장된 데이터가 없습니다.\n");;
	}
	else
	{
		while (tempNode->link != NULL)
		{
			tempNode = tempNode->link;
		}
	}
	return tempNode;
}
double CalAverage(listHead* h)
{
	double ave = 0.0;

	if (h->head == NULL)		//노드에 하나도 없는 경우
	{
		return -1;
	}
	else						// 그 외의 경우에는 ave 에 평균값이 계산하도록 하라.
	{
	
	
	
	
	}



	return ave;
}
void PrintAllNode(listHead* h)
{
	int count = 1;
	listNode* temp;
	printf("%4s %12s: %5s\n", "순서", "이름   ", "점수");
	DRAWSINGLELINE;
	for (temp = h->head; temp != NULL; temp = temp->link)
		printf("%3d. %12s: %3d점\n", count++, temp->name, temp->score);
	
}

void PrintRangedNode(listHead* h, int min, int max)
{
	int count = 1;
	listNode* temp;
	printf("%4s %12s: %5s\n", "순서", "이름   ", "점수");
	DRAWSINGLELINE;
	/*
	 min 이상 max 이하의 값을 모두 출력하는 부분 추가
	*/
	// 아래 부분 지워야함. 현재는 전체 출력으로 되어 있음
	for (temp = h->head; temp != NULL; temp = temp->link)
		printf("%3d. %12s: %3d점\n", count++, temp->name, temp->score);
}

void ReverseList(listHead* h)
{
	h->type = h->type == 0 ? 1 : 0;
	/*
	여기에는 리스트를 반전시키는 내용이 추가되어야 함.
	*/
}


