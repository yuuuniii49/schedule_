#include <stdlib.h>
#include <stdio.h>

#include "my_func.h"

Sch_list *head = NULL;	// 스케줄을 넣을 가장 처음 구조체 변수

// 스케줄 유형 배열 선언  
char TYPE[7][20] = { "drama", "movie", "advertisement",	"entertainment", "meeting",	"fitness", "privacy" };

// 월 정보에 대한 배열 선언 
char MONTH[13][4] = { "", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };

// 각 스케줄 구조체의 연결 
void Add(Sch_list node)
{
	Sch_list *add = (Sch_list*)malloc(sizeof(Sch_list));	// 동적 메모리 할당
 
 	*add = node;		// 전달받은 스케줄 구조체를 메모리 할당한변수에 저장
 	add->next = head;	// 객체를 맨앞에 연결
 	head = add;			// 새로 연결한 객체를 맨앞으로 만듦  
}

 
// 전체 스케줄을 출력하는 함수 
void Print_Schedules()
{
	Sch_list *loop = head;
	int n = 1;

	printf("----------------------------------\n");
	while(loop != NULL) {
		printf("# %d\n", n);
		printf("  Schedule Name : %s(%s)\n", loop->info, TYPE[loop->type]);
		printf("  When : %s, %d\n", MONTH[loop->month], loop->day);
		printf("  Where : %s\n", loop->place);
		printf("----------------------------------\n");
  		loop = loop->next;	// 다음 구조체를 loop에 할당  
  		n++;
 	}
}

// 메뉴를 출력하는 함수
// 메뉴의 개수를 매개변수로 받음 
int Print_menu(int cnt) {
	int option;	// 사용자의 선택번호 
	 
	printf("\n\nReading the data files...\n");
	printf("Reading dong! %d schedules are read.\n\n", cnt);
	
	// 메뉴의 출력 
	printf("  1. Print all the schedules\n");
	printf("  2. Search for schedules in the month\n");
	printf("  3. Search for schedules in the place\n");
	printf("  4. Search for specific type scheduls\n");
	printf("  5. Exit\n\n");
	printf("  Select an option : ");
	scanf("%d", &option);
	
	return option;
}

// 월로 검색하는 함수  
void Search_month(int Month) {
	Sch_list *loop = head;
	int n = 1;

	printf("\n\n----------------------------------\n");
	while(loop != NULL) {
		if (loop->month == Month) {
			printf("# %d\n", n);
			printf("  Schedule Name : %s(%s)\n", loop->info, TYPE[loop->type]);
			printf("  When : %s, %d\n", MONTH[loop->month], loop->day);
			printf("  Where : %s\n", loop->place);
			printf("----------------------------------\n");	
			n++;
		}		
		loop = loop->next;	// 다음 구조체를 loop에 할당 
 	}
 	if (n==1) printf("검색 결과가 없습니다.\n\n");
}

// 장소로 검색하는 함수  
void Search_place(char *Place) {
	Sch_list *loop = head;
	int n = 1;

	printf("\n\n----------------------------------\n");
	while(loop != NULL) {
		if (strcmp(loop->place, Place) == 0 ) {
			printf("# %d\n", n);
			printf("  Schedule Name : %s(%s)\n", loop->info, TYPE[loop->type]);
			printf("  When : %s, %d\n", MONTH[loop->month], loop->day);
			printf("  Where : %s\n", loop->place);
			printf("----------------------------------\n");	
			n++;
		}		
		loop = loop->next;	// 다음 구조체를 loop에 할당 
 	}
 	if (n==1) printf("검색 결과가 없습니다.\n\n");
}

// 유형으로 검색하는 함수  
void Search_type(char *Type) {
	Sch_list *loop = head;
	int n = 1;

	printf("\n\n----------------------------------\n");
	while(loop != NULL) {
		if (strcmp(TYPE[loop->type], Type) == 0 ) {
			printf("# %d\n", n);
			printf("  Schedule Name : %s(%s)\n", loop->info, TYPE[loop->type]);
			printf("  When : %s, %d\n", MONTH[loop->month], loop->day);
			printf("  Where : %s\n", loop->place);
			printf("----------------------------------\n");	
			n++;
		}		
		loop = loop->next;	// 다음 구조체를 loop에 할당 
 	}
 	if (n==1) printf("검색 결과가 없습니다.\n\n");
}

// 동적 메모리 반환을 위한 함수  
void Free_mem(void)
{
	Sch_list *loop = head;
	Sch_list *temp;		// 삭제를 위한 구조체 포인터  
	
	while(head != NULL) {
			temp = loop;		// temp는 lopp를 할당받고, 
			loop = temp->next;	// loop는 temp의 다음 구조체를 받고, 
			free(temp);			// temp 반환  
 	}	
}


