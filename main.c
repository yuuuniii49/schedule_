#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "my_func.c"	// 사용자 함수가 정의된 파일  
#include "my_func.h"	// 사용자 함수 선언된 파일  

int main()
{
 	Sch_list temp;	// 파일에서 읽어온 하나의 스케줄을 저장하기 위한 임시 구조체 변수 
 	int cnt = 0;	// 스케줄의 개수를 저장하기 위한 변수 
 	int option;		// 메뉴에서 사용자의 선택
 	int Month;		// 검색하고자 하는 월  
 	char Place[30];	// 검색하고자하는 장소  
 	char Type[30];	// 검색하고자 하는 유형  
 	
	FILE *fp = fopen("schedule.dat", "r");	// Schedule.dat 파일을 읽기모드로 열기  
	if (fp == NULL) {
		printf("파일을 열지 못했습니다.\n");
		exit(1);
	}

 	// 파일에서 스케줄 읽어오면서 linked-list 생성 
	while(1) {
  		if(fscanf(fp,"%s %s %d %d %d", &temp.info, temp.place, &temp.type, &temp.month, &temp.day) == EOF)
   			break;

  		Add(temp);	// 구조체 변수 temp를 Add함수로 전달 
  		cnt++;		// 읽어온 스케줄의 개수 증가  
 	}
	
	do {
		option = Print_menu(cnt);	// 메뉴를 출력하고 사용자의 입력을 받아옴 
		switch (option) {			// 사용자의 메뉴 선택을 조건으로 함  
			case 1 :	// 모든 스케줄 출력 
				Print_Schedules();
				break;
				
			case 2 :	// 월로 검색 
				printf("\n  Which month ? ");
				scanf("%d", &Month);
				Search_month(Month);	// 입력된 월정보를 Search_month 함수로 전달  
				break;
				
			case 3 :	// 장소로 검색 
				printf("\n  Which place ? ");
				scanf("%s", Place);
				Search_place(Place);	// 입력된 장소정보를 Search_place 함수로 전달 
				break;
				
			case 4 :	// 유형으로 검색 
				printf("\n  Which type ? ");
				scanf("%s", Type);
				Search_type(Type);		// 입력된 유형정보를 Search_type 함수로 전달 
				break;
				
			case 5 :	// 종료 
				Free_mem();	// 동적 할당한 메모리의 해제 
				break;
				
			default :	// 입력이 잘못된 경우  
				printf("\n  잘못된 입력입니다. 다시 입력하세요.");
		}
	}while(option != 5);	// 프로그램 종료 조건이 아니라면 반복  
 
 	fclose(fp);	// 파일 닫기  
 	return 0;
}

