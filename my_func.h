typedef struct Schedule {
 	int info[30];	// 스케줄 내용 
 	char place[30];	// 스케줄 장소 
 	int type;		// 스케줄 유형 
 	int month;		// 스케줄 월 
 	int day;		// 스케줄 일 
 	struct Schedule *next;	// 다음 스케줄을 가리킬 포인터  
}Sch_list;	// 자료형 정의 

void Print_Schedules(void);
int Print_menu(int cnt);
void Search_month(int Month);
void Search_place(char *Place);
void Search_place(char *Type);
void Free_mem(void); 
