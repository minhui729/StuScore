
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
	���۵� ������ �̸��� ������� ��ġ�� ã�Ƽ� newNode�� �����Ͽ���.
	*/
	// ������� ��������
	if (h->head == NULL)
		h->head = newNode;
	else
	{
		newNode->link = h->head;
		h->head = newNode;
	}
	// ���� ����


	return newNode;
}

listNode* AddDirectNode(listHead* h, int s, char* n)
{
	listNode* newNode = (listNode*)malloc(sizeof(listNode));

	strcpy(newNode->name, n);
	newNode->score = s;
	newNode->link = NULL;

	/*
	�Էµ� ������ �̸��� ������� ��ġ�� ã�Ƽ� newNode�� �����Ͽ���.
	*/
	// ������� ��������
	if (h->head == NULL)
		h->head = newNode;
	else
	{
		newNode->link = h->head;
		h->head = newNode;
	}
	// ���� ����

	return newNode;
}

listNode* DeleteSelectNode(listHead* h, char* n)
{
	listNode* oldNode = NULL; //������ ����� ��ġ�� ����
	
	/*
	���ڿ� n�� ������� ������ ��带 ã�� �����ϰ�
	�� ������ ��带 oldNode�� ����	
	*/
	return oldNode;
}

listNode* DeleteLastNode(listHead* h)
{
	listNode* oldNode = NULL; //������ ����� ��ġ�� ����
	listNode* temp = h->head;

	if (temp == NULL)
	{
		printf("������ ��尡 �����ϴ�.\n");
		oldNode =  NULL;
	}
	else if( temp->link == NULL)
	{
		printf("��尡 ��� �����Ǿ����ϴ�.\n");
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
	listNode* tempNode = NULL; //������ ����� ��ġ�� ����


	return tempNode;
}
listNode* FindbyName(listHead* h, char* n)
{
	listNode* tempNode = NULL; //������ ����� ��ġ�� ����


	return tempNode;

}
listNode* FindbyScore(listHead* h, int s)
{
	listNode* tempNode = NULL; //������ ����� ��ġ�� ����


	return tempNode;
}
listNode* FindMiddleNode(listHead* h)
{
	listNode* tempNode = NULL; //������ ����� ��ġ�� ����


	return tempNode;
}
listNode* FindLastNode(listHead* h)
{
	listNode* tempNode = h->head;

	if (tempNode == NULL)
	{
		printf("����� �����Ͱ� �����ϴ�.\n");;
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

	if (h->head == NULL)		//��忡 �ϳ��� ���� ���
	{
		return -1;
	}
	else						// �� ���� ��쿡�� ave �� ��հ��� ����ϵ��� �϶�.
	{
	
	
	
	
	}



	return ave;
}
void PrintAllNode(listHead* h)
{
	int count = 1;
	listNode* temp;
	printf("%4s %12s: %5s\n", "����", "�̸�   ", "����");
	DRAWSINGLELINE;
	for (temp = h->head; temp != NULL; temp = temp->link)
		printf("%3d. %12s: %3d��\n", count++, temp->name, temp->score);
	
}

void PrintRangedNode(listHead* h, int min, int max)
{
	int count = 1;
	listNode* temp;
	printf("%4s %12s: %5s\n", "����", "�̸�   ", "����");
	DRAWSINGLELINE;
	/*
	 min �̻� max ������ ���� ��� ����ϴ� �κ� �߰�
	*/
	// �Ʒ� �κ� ��������. ����� ��ü ������� �Ǿ� ����
	for (temp = h->head; temp != NULL; temp = temp->link)
		printf("%3d. %12s: %3d��\n", count++, temp->name, temp->score);
}

void ReverseList(listHead* h)
{
	h->type = h->type == 0 ? 1 : 0;
	/*
	���⿡�� ����Ʈ�� ������Ű�� ������ �߰��Ǿ�� ��.
	*/
}


