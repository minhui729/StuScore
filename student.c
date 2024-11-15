
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

	for (int i = 0; i < 9; i++) {
		newNode->name[i] = RANGEN(26) + 'a';
		newNode->name[9] = 0;
		newNode->score = RANGEN(101);
		newNode->link = NULL;
	}

	return newNode;
}

listNode* AddDirectNode(listHead* h, int s, char* n)
{
	listNode* tempNode = h->head;
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->name, n);
    newNode->score = s;
    newNode->link = NULL;
 
    // 내림차순 정렬
    if (h->type == 1) {  
        // 헤드 노드 검사
        if (tempNode == NULL || tempNode->score < newNode->score ||
            (tempNode->score == newNode->score && strcmp(tempNode->name, newNode->name) > 0)) {
            newNode->link = tempNode;
           	h->head = newNode;
            return newNode;
        }
        
        // 헤드 다음부터 비교
        while (tempNode->link != NULL && tempNode->link->score > newNode->score) {
            tempNode = tempNode->link;
        }
        
        while (tempNode->link != NULL && tempNode->link->score == newNode->score && strcmp(tempNode->link->name, newNode->name) < 0) {
            tempNode = tempNode->link;
        }

        newNode->link = tempNode->link;
        tempNode->link = newNode;

    // 오름차순 정렬
    } else {  
        // 헤드 노드 검사
        if (tempNode == NULL || tempNode->score > newNode->score ||
            (tempNode->score == newNode->score && strcmp(tempNode->name, newNode->name) > 0)) {
            newNode->link = tempNode;
            h->head = newNode;
            return newNode;
        }

        // 헤드 다음부터 비교
        while (tempNode->link != NULL && tempNode->link->score < newNode->score) {
            tempNode = tempNode->link;
        }
        
        while (tempNode->link != NULL && tempNode->link->score == newNode->score && strcmp(tempNode->link->name, newNode->name) > 0) {
            tempNode = tempNode->link;
        }

        newNode->link = tempNode->link;
        tempNode->link = newNode;
    }

    return newNode;
}

listNode* DeleteSelectNode(listHead* h, char* n)
{
    listNode* tempNode = h->head;

    if (tempNode != NULL && strcmp(tempNode->name, n) == 0) {
        h->head = tempNode->link;
        return tempNode;
    }

    listNode* prevNode = tempNode;
    while (tempNode != NULL && tempNode->link != NULL) {
        if (strcmp(tempNode->link->name, n) == 0) {
            listNode* remove = tempNode->link;
            tempNode->link = tempNode->link->link;
            return remove;
        }
        tempNode = tempNode->link;
    }
    return NULL; 
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
	listNode* tempNode = h->head;
	listNode* change = NULL; 
	int isFound = 0;
	if (tempNode == NULL) return NULL;

	if (strcmp(tempNode->name, n) == 0) { // head change
		change = tempNode;
		h->head = tempNode->link;

		free(change);
		return AddDirectNode(h, s, n); 
	}

	while (tempNode->link != NULL) {
		if (strcmp(n, tempNode->link->name) == 0) {
			isFound = 1;
			break;
		}

		tempNode = tempNode->link;
	}
	
	if (isFound == 1) {
		change = tempNode->link;

		tempNode->link = tempNode->link->link;

		free(change);

		return AddDirectNode(h, s, n);
	} else {
		return NULL;
	}
}

listNode* FindbyName(listHead* h, char* n)
{
	listNode* tempNode = h->head;
	
	if (tempNode == NULL) return NULL;

	while (tempNode != NULL) {
		if (strcmp(tempNode->name, n) == 0) 
			return tempNode;

		tempNode = tempNode->link;
	}

	return NULL;
}

listNode* FindbyScore(listHead* h, int s)
{
	listNode* tempNode = h->head; 
	int isFound = 0;

	if (tempNode == NULL) return NULL;

	if (h->type == 1) {
		while (tempNode->link != NULL) {
			if (tempNode->score == s) {
				isFound = 1;
				break;
			}
			tempNode = tempNode->link;
		}

		if (isFound == 0) return NULL;

		while (tempNode->link != NULL && tempNode->link->score == s) {
			tempNode = tempNode->link;
		}

		return tempNode;
	} else {
		while (tempNode->link != NULL) {
			if (tempNode->score == s) {
				isFound = 1;
				break;
			}
			tempNode = tempNode->link;
		}

		if (isFound == 0) return NULL;

		while (tempNode->link != NULL && tempNode->link->score == s) {
			tempNode = tempNode->link;
		}

		return tempNode;		
	}
	
}

listNode* FindMiddleNode(listHead* h)
{
    listNode* slow = h->head; // 중간에 도착할 포인터 
    listNode* fast = h->head; // slow보다 2배 빨리 가는 포인터 

    if (slow == NULL) return NULL;

    while (fast != NULL && fast->link != NULL) {
        slow = slow->link;           
        fast = fast->link->link;     
    }

    return slow;
}

listNode* FindLastNode(listHead* h)
{
	listNode* tempNode = h->head;

	if (tempNode == NULL) {
		return NULL;
	}

	while (tempNode->link != NULL) tempNode = tempNode->link;

	return tempNode;
}

double CalAverage(listHead* h)
{
	listNode* temp = h->head;
	double ave = 0.0;
	int sum = 0, nStu = 0;

	if (h->head == NULL)		//노드에 하나도 없는 경우
	{
		return -1;
	}
	else						// 그 외의 경우에는 ave 에 평균값이 계산하도록 하라.
	{
		while (temp != NULL) {
			sum += temp->score;
			temp = temp->link;
			nStu++;
		}
	}

	ave = (double)sum / nStu;

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
	listNode* temp = h->head;
	printf("%4s %12s: %5s\n", "순서", "이름   ", "점수");
	DRAWSINGLELINE;

    if (h->type == 0) { 
        while (temp != NULL) {
            if (temp->score > max) 
                return;

            if (temp->score >= min) {
                printf("%4d %12s: %5d\n", count, temp->name, temp->score);
                count++;
            }
            temp = temp->link; 
        }
    } else { 
        while (temp != NULL) {
            if (temp->score < min) 
                return;

            if (temp->score <= max) {
                printf("%4d %12s: %5d\n", count, temp->name, temp->score);
                count++;
            }
            temp = temp->link; 
        }
    }
}

void ReverseList(listHead* h)
{
	h->type = h->type == 0 ? 1 : 0;
	listNode* r = NULL;
	listNode* q = NULL;
	listNode* p = h->head;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		
		q->link = r;
	}

	h->head = q;
}
