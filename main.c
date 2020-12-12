#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_func.c"	// ����� �Լ��� ���ǵ� ����  
#include "my_func.h"	// ����� �Լ� ����� ����  

int main()
{
 	Sch_list temp;	// ���Ͽ��� �о�� �ϳ��� �������� �����ϱ� ���� �ӽ� ����ü ���� 
 	int cnt = 0;	// �������� ������ �����ϱ� ���� ���� 
 	int option;		// �޴����� ������� ����
 	int Month;		// �˻��ϰ��� �ϴ� ��  
 	char Place[30];	// �˻��ϰ����ϴ� ���  
 	char Type[30];	// �˻��ϰ��� �ϴ� ����  
 	
	FILE *fp = fopen("schedule.dat", "r");	// Schedule.dat ������ �б���� ����  
	if (fp == NULL) {
		printf("������ ���� ���߽��ϴ�.\n");
		exit(1);
	}

 	// ���Ͽ��� ������ �о���鼭 linked-list ���� 
	while(1) {
  		if(fscanf(fp,"%s %s %d %d %d", &temp.info, temp.place, &temp.type, &temp.month, &temp.day) == EOF)
   			break;

  		Add(temp);	// ����ü ���� temp�� Add�Լ��� ���� 
  		cnt++;		// �о�� �������� ���� ����  
 	}
	
	do {
		option = Print_menu(cnt);	// �޴��� ����ϰ� ������� �Է��� �޾ƿ� 
		switch (option) {			// ������� �޴� ������ �������� ��  
			case 1 :	// ��� ������ ��� 
				Print_Schedules();
				break;
				
			case 2 :	// ���� �˻� 
				printf("\n  Which month ? ");
				scanf("%d", &Month);
				Search_month(Month);	// �Էµ� �������� Search_month �Լ��� ����  
				break;
				
			case 3 :	// ��ҷ� �˻� 
				printf("\n  Which place ? ");
				scanf("%s", Place);
				Search_place(Place);	// �Էµ� ��������� Search_place �Լ��� ���� 
				break;
				
			case 4 :	// �������� �˻� 
				printf("\n  Which type ? ");
				scanf("%s", Type);
				Search_type(Type);		// �Էµ� ���������� Search_type �Լ��� ���� 
				break;
				
			case 5 :	// ���� 
				Free_mem();	// ���� �Ҵ��� �޸��� ���� 
				break;
				
			default :	// �Է��� �߸��� ���  
				printf("\n  �߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.");
		}
	}while(option != 5);	// ���α׷� ���� ������ �ƴ϶�� �ݺ�  
 
 	fclose(fp);	// ���� �ݱ�  
 	return 0;
}

