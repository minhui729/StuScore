#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "student.h"




void Menu()
{
	printf("0. ���� �߰�          ");			// �������� �����͸� �Ѹ� �߰��Ѵ�.
	printf("1. ���� �߰�          ");			// �̸��� ������ ���� �Է��Ͽ� �߰��Ѵ�.
	printf("2. ���� ����\n");			// �̸��� �Է¹޾� �̸��� ������� �����Ѵ�.
	printf("3. ���� ����          ");			// ������ ��带 �����Ѵ�.
	printf("4. ���� ����          ");			// �̸��� ������ �Է¹޾� �ش� �̸��� ������ �����Ѵ�.
	printf("5. �̸� �˻�\n");			// �̸��� �Է¹޾� �ش� �л��� ���� ������ ����Ѵ�.
	printf("6. ���� �˻�          ");			// ������ �Է¹޾� �ش� �л��� ���� ������ ����Ѵ�.(�� �� �������� ���, ���������� ���� �������� �ִ� �л��� ������ ����Ѵ�.)
	printf("7. �߰� ���          ");			// ���� �Էµ� �л����� �� ��, �߰� ����� �л�  ������ ����Ѵ�.(10���� ���� 5 or 6��, 9���̸� 5��) 
	printf("8. �õ� ���\n");			// �õ� �л��� ������ ����Ѵ�.(�������� ��� ���� ������ �л��� ����Ѵ�.) 
	printf("9. ��ü ���          ");			// ����� �л����� ��� ������ ����� ���� ����Ѵ�.
	printf("P. ��     ��          ");			// ��� �л��� ������ ����. �̸� : ���� ���·� ����Ѵ�.
	printf("S. ���� ����\n");			// head�� type ���� 0�̸� 1�� 1�̸� 0���� �ٲ۴�. + type �� �ٲ���� ������ ����Ǿ� �ִ� ���� ��� �������� �ٲ۴�.
	printf("R. ���� ���          ");			// �� ���� ������ �Է¹޾� �� ������ �л� ������ ��� ����Ѵ�.
	printf("Q. ��     ��\n");			// ���α׷��� �����Ѵ�.
}



void main()
{
	listHead* stuLL;
	stuLL = CreateNode();
	int flag = TRUE;
	srand(time(NULL));

	while (flag)
	{
		listNode* retNode;	//�Լ����� ���ϵǴ� ���� �޴� ����
		char in_Name[10];	//�̸��� �Է¹��� ����
		int in_Score;		//������ �Է¹��� ����
		int minv, maxv;		//���� ����� ���� ����
		int rank = 0;		//������ �Է¹��� ����
		double ave = 0.0;	//��հ��� �޴� ����
		Menu();
		DRAWDOUBLELINE;
		printf("��  ��  ��  �� -> ");
		char temp;
		scanf(" %c", &temp);
		DRAWDOUBLELINE;
		system("cls");
		switch (temp)
		{
		case '0':
			printf("���� �߰� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			retNode = AddRandomNode(stuLL);
			printf("%s �л��� %d���� ��ϵǾ����ϴ�.\n",retNode->name, retNode->score);
			break;
		case '1':
			printf("���� �߰� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			printf("�����Ͻ� �̸��� �Է��Ͻÿ� -> ");
			scanf("%s", in_Name);
			printf("�����Ͻ� ������ �Է��Ͻÿ� -> ");
			scanf("%d", &in_Score);
			DRAWSINGLELINE;
			retNode = AddDirectNode(stuLL, in_Score, in_Name);
			printf("%s �л��� %d���� ��ϵǾ����ϴ�.\n", retNode->name, retNode->score);
			break;
		case '2':
			printf("���� ���� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			printf("�����Ͻ� �̸��� �Է��Ͻÿ� -> ");
			scanf("%s", in_Name);
			DRAWSINGLELINE;
			retNode = DeleteSelectNode(stuLL, in_Name);
			if (retNode != NULL)
			{
				printf("%s �л��� %d���� �����Ǿ����ϴ�.\n", retNode->name, retNode->score);
				free(retNode);
			}
			break;
		case '3':
			printf("���� ���� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			retNode = DeleteLastNode(stuLL);
			if (retNode != NULL)
			{
				printf("%s �л��� %d���� �����Ǿ����ϴ�.\n", retNode->name, retNode->score);
				free(retNode);
			}
			break;
		case '4':
			printf("���� ���� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			printf("������ ������ ����� �̸��� �Է��Ͻÿ� -> ");
			scanf("%s", in_Name);
			printf("�����Ͻ� ������ �Է��Ͻÿ� -> "); 
			scanf("%d", &in_Score);
			DRAWSINGLELINE;
			retNode =  ChangeNode(stuLL, in_Score, in_Name);
			if (retNode != NULL)
			{
				printf("%s �л��� ������ %d ������ ���� �Ǿ����ϴ�.\n", retNode->name, retNode->score);
			}
			break;
		case '5':
			printf("�̸� �˻� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			printf("�˻��� �̸��� �Է��Ͻÿ� -> ");
			scanf("%s", in_Name);
			DRAWSINGLELINE;
			retNode = FindbyName(stuLL, in_Name);
			if (retNode != NULL)
			{
				printf("%s�л��� ������ %d�� �Դϴ�.\n", retNode->name, retNode->score);
			}
			break;
		case '6':
			printf("���� �˻� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			printf("�˻��� ������ �Է��Ͻÿ� -> ");
			scanf("%d", &in_Score);
			DRAWSINGLELINE;
			retNode = FindbyScore(stuLL, in_Score);
			if (retNode != NULL)
			{
				printf("%d���� ���� �л��� %s�Դϴ�..\n", retNode->score, retNode->name);
			}
			break;
		case '7':
			printf("�߰� ��� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			retNode = FindMiddleNode(stuLL);
			if (retNode != NULL)
			{
				printf("�߰� ����� �л��� %s�̰� ������ %d�Դϴ�..\n", retNode->name, retNode->score);
			}
			break;
		case '8':
			printf("�õ� ��� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			retNode = FindLastNode(stuLL);
			if (retNode != NULL)
			{
				printf("������ �л��� % s�̰� ������ %d�Դϴ�.\n", retNode->name, retNode->score);
			}
			break;
		case '9':
			printf("��ü ��� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			ave = CalAverage(stuLL);
			if (ave >= 0)
			{
				printf("��ü �л��� ����� %6.3lf�Դϴ�..\n", ave);
			}
			break;
		case 'p':case 'P':
			printf("��ü ��� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			PrintAllNode(stuLL);
			break;
		case 'r':case 'R':
			printf("���� ��� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			printf("����� ���� ������ �ּ� ���� �Է��Ͻÿ� -> ");
			scanf("%d", &minv);
			printf("����� ���� ������ �ִ� ���� �Է��Ͻÿ� -> ");
			scanf("%d", &maxv);
			DRAWSINGLELINE;
			printf("%3d~%3d ������ �л��� ������ �����ϴ�.\n");
			DRAWSINGLELINE;
			PrintRangedNode(stuLL, minv, maxv);
			break;
		case 's':case 'S':
			printf("���� ���� �޴��� ���õǾ����ϴ�.\n");
			DRAWSINGLELINE;
			ReverseList(stuLL);
			break;
		case 'q':case 'Q':
			printf("���α׷��� �����մϴ�.\n");
			ClearNode(stuLL);
			flag = FALSE; break;
		default:	printf("�ٽ� �Է��Ͻÿ�!!\n");	

		}
		DRAWDOUBLELINE;
	}
}
