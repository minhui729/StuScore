#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "student.h"




void Menu()
{
	printf("0. 랜덤 추가          ");			// 랜덤으로 데이터를 한명 추가한다.
	printf("1. 직접 추가          ");			// 이름과 성적을 직접 입력하여 추가한다.
	printf("2. 선택 삭제\n");			// 이름을 입력받아 이름을 기반으로 삭제한다.
	printf("3. 말단 삭제          ");			// 마지막 노드를 삭제한다.
	printf("4. 점수 변경          ");			// 이름과 성적을 입력받아 해당 이름의 성적을 변경한다.
	printf("5. 이름 검색\n");			// 이름을 입력받아 해당 학생의 순서 정보를 출력한다.
	printf("6. 성적 검색          ");			// 성적을 입력받아 해당 학생의 순서 정보를 출력한다.(이 때 동점자의 경우, 사전상으로 제일 마지막에 있는 학생의 정보를 출력한다.)
	printf("7. 중간 출력          ");			// 현재 입력된 학생들의 수 중, 중간 등수의 학생  정보를 출력한다.(10명일 경우는 5 or 6등, 9명이면 5등) 
	printf("8. 꼴등 출력\n");			// 꼴등 학생의 점수를 출력한다.(동점자의 경우 가장 마지막 학생을 출력한다.) 
	printf("9. 전체 평균          ");			// 저장된 학생들의 모든 성적의 평균을 구해 출력한다.
	printf("P. 출     력          ");			// 모든 학생의 정보를 순서. 이름 : 성적 형태로 출력한다.
	printf("S. 반전 저장\n");			// head의 type 값을 0이면 1로 1이면 0으로 바꾼다. + type 이 바뀌었기 때문에 저장되어 있는 값을 모두 역순으로 바꾼다.
	printf("R. 범위 출력          ");			// 두 개의 점수를 입력받아 그 사이의 학생 정보를 모두 출력한다.
	printf("Q. 종     료\n");			// 프로그램을 종료한다.
}



void main()
{
	listHead* stuLL;
	stuLL = CreateNode();
	int flag = TRUE;
	srand(time(NULL));

	while (flag)
	{
		listNode* retNode;	//함수에서 리턴되는 값을 받는 변수
		char in_Name[10];	//이름을 입력받을 변수
		int in_Score;		//성적을 입력받을 변수
		int minv, maxv;		//범위 출력을 위한 변수
		int rank = 0;		//순서를 입력받을 변수
		double ave = 0.0;	//평균값을 받는 변수
		Menu();
		DRAWDOUBLELINE;
		printf("메  뉴  선  택 -> ");
		char temp;
		scanf(" %c", &temp);
		DRAWDOUBLELINE;
		system("cls");
		switch (temp)
		{
		case '0':
			printf("랜덤 추가 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			retNode = AddRandomNode(stuLL);
			printf("%s 학생의 %d점이 등록되었습니다.\n",retNode->name, retNode->score);
			break;
		case '1':
			printf("직접 추가 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			printf("저장하실 이름을 입력하시오 -> ");
			scanf("%s", in_Name);
			printf("저장하실 점수를 입력하시오 -> ");
			scanf("%d", &in_Score);
			DRAWSINGLELINE;
			retNode = AddDirectNode(stuLL, in_Score, in_Name);
			printf("%s 학생의 %d점이 등록되었습니다.\n", retNode->name, retNode->score);
			break;
		case '2':
			printf("선택 삭제 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			printf("삭제하실 이름을 입력하시오 -> ");
			scanf("%s", in_Name);
			DRAWSINGLELINE;
			retNode = DeleteSelectNode(stuLL, in_Name);
			if (retNode != NULL)
			{
				printf("%s 학생의 %d점이 삭제되었습니다.\n", retNode->name, retNode->score);
				free(retNode);
			}
			break;
		case '3':
			printf("말단 삭제 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			retNode = DeleteLastNode(stuLL);
			if (retNode != NULL)
			{
				printf("%s 학생의 %d점이 삭제되었습니다.\n", retNode->name, retNode->score);
				free(retNode);
			}
			break;
		case '4':
			printf("점수 변경 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			printf("점수를 변경할 사람의 이름을 입력하시오 -> ");
			scanf("%s", in_Name);
			printf("변경하실 점수를 입력하시오 -> "); 
			scanf("%d", &in_Score);
			DRAWSINGLELINE;
			retNode =  ChangeNode(stuLL, in_Score, in_Name);
			if (retNode != NULL)
			{
				printf("%s 학생의 점수가 %d 점수로 변경 되었습니다.\n", retNode->name, retNode->score);
			}
			break;
		case '5':
			printf("이름 검색 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			printf("검색할 이름을 입력하시오 -> ");
			scanf("%s", in_Name);
			DRAWSINGLELINE;
			retNode = FindbyName(stuLL, in_Name);
			if (retNode != NULL)
			{
				printf("%s학생의 점수는 %d점 입니다.\n", retNode->name, retNode->score);
			}
			break;
		case '6':
			printf("성적 검색 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			printf("검색할 성적을 입력하시오 -> ");
			scanf("%d", &in_Score);
			DRAWSINGLELINE;
			retNode = FindbyScore(stuLL, in_Score);
			if (retNode != NULL)
			{
				printf("%d점을 갖는 학생은 %s입니다..\n", retNode->score, retNode->name);
			}
			break;
		case '7':
			printf("중간 출력 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			retNode = FindMiddleNode(stuLL);
			if (retNode != NULL)
			{
				printf("중간 등수의 학생은 %s이고 점수는 %d입니다..\n", retNode->name, retNode->score);
			}
			break;
		case '8':
			printf("꼴등 출력 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			retNode = FindLastNode(stuLL);
			if (retNode != NULL)
			{
				printf("마지막 학생은 % s이고 점수는 %d입니다.\n", retNode->name, retNode->score);
			}
			break;
		case '9':
			printf("전체 평균 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			ave = CalAverage(stuLL);
			if (ave >= 0)
			{
				printf("전체 학생의 평균은 %6.3lf입니다..\n", ave);
			}
			break;
		case 'p':case 'P':
			printf("전체 출력 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			PrintAllNode(stuLL);
			break;
		case 'r':case 'R':
			printf("범위 출력 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			printf("출력할 점수 범위의 최소 값을 입력하시오 -> ");
			scanf("%d", &minv);
			printf("출력할 점수 범위의 최대 값을 입력하시오 -> ");
			scanf("%d", &maxv);
			DRAWSINGLELINE;
			printf("%3d~%3d 구간의 학생은 다음과 같습니다.\n");
			DRAWSINGLELINE;
			PrintRangedNode(stuLL, minv, maxv);
			break;
		case 's':case 'S':
			printf("반전 저장 메뉴가 선택되었습니다.\n");
			DRAWSINGLELINE;
			ReverseList(stuLL);
			break;
		case 'q':case 'Q':
			printf("프로그램을 종료합니다.\n");
			ClearNode(stuLL);
			flag = FALSE; break;
		default:	printf("다시 입력하시오!!\n");	

		}
		DRAWDOUBLELINE;
	}
}
