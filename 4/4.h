#ifndef _COMMON_DEF_
#define _COMMON_DEF_
#define TRUE 1
#define FALSE 0
#endif

#ifndef _HUMAN_DEF_
#define _HUMAN_DEF_
typedef struct human {
	char name[20];
	int age;
	int salary;
}human;
#endif

int humanEqual(human *person1, human *person2);

