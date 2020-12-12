#include <stdlib.h>
#include <stdio.h>

#include "my_func.h"

Sch_list *head = NULL;	// �������� ���� ���� ó�� ����ü ����

// ������ ���� �迭 ����  
char TYPE[7][20] = { "drama", "movie", "advertisement",	"entertainment", "meeting",	"fitness", "privacy" };

// �� ������ ���� �迭 ���� 
char MONTH[13][4] = { "", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };

// �� ������ ����ü�� ���� 
void Add(Sch_list node)
{
	Sch_list *add = (Sch_list*)malloc(sizeof(Sch_list));	// ���� �޸� �Ҵ�
 
 	*add = node;		// ���޹��� ������ ����ü�� �޸� �Ҵ��Ѻ����� ����
 	add->next = head;	// ��ü�� �Ǿտ� ����
 	head = add;			// ���� ������ ��ü�� �Ǿ����� ����  
}

 
// ��ü �������� ����ϴ� �Լ� 
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
  		loop = loop->next;	// ���� ����ü�� loop�� �Ҵ�  
  		n++;
 	}
}

// �޴��� ����ϴ� �Լ�
// �޴��� ������ �Ű������� ���� 
int Print_menu(int cnt) {
	int option;	// ������� ���ù�ȣ 
	 
	printf("\n\nReading the data files...\n");
	printf("Reading dong! %d schedules are read.\n\n", cnt);
	
	// �޴��� ��� 
	printf("  1. Print all the schedules\n");
	printf("  2. Search for schedules in the month\n");
	printf("  3. Search for schedules in the place\n");
	printf("  4. Search for specific type scheduls\n");
	printf("  5. Exit\n\n");
	printf("  Select an option : ");
	scanf("%d", &option);
	
	return option;
}

// ���� �˻��ϴ� �Լ�  
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
		loop = loop->next;	// ���� ����ü�� loop�� �Ҵ� 
 	}
 	if (n==1) printf("�˻� ����� �����ϴ�.\n\n");
}

// ��ҷ� �˻��ϴ� �Լ�  
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
		loop = loop->next;	// ���� ����ü�� loop�� �Ҵ� 
 	}
 	if (n==1) printf("�˻� ����� �����ϴ�.\n\n");
}

// �������� �˻��ϴ� �Լ�  
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
		loop = loop->next;	// ���� ����ü�� loop�� �Ҵ� 
 	}
 	if (n==1) printf("�˻� ����� �����ϴ�.\n\n");
}

// ���� �޸� ��ȯ�� ���� �Լ�  
void Free_mem(void)
{
	Sch_list *loop = head;
	Sch_list *temp;		// ������ ���� ����ü ������  
	
	while(head != NULL) {
			temp = loop;		// temp�� lopp�� �Ҵ�ް�, 
			loop = temp->next;	// loop�� temp�� ���� ����ü�� �ް�, 
			free(temp);			// temp ��ȯ  
 	}	
}


