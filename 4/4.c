#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "4.h"
void main() {
	human *person1=NULL,*person2 = NULL;

	person1 = (human*)malloc(sizeof(human));
	if (person1 == NULL) {
		printf("오류, person1 메모리 할당\n");
	}

	person2 = (human*)malloc(sizeof(human));
	if (person2 == NULL) {
		printf("오류, person2 메모리 할당\n");
	}
	printf("Input person1's name,age ,salary : \n");
	fgets(person1->name,20,stdin);
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &person1->age);
	scanf("%d", &person1->salary);
	
	printf("Input person2's name,age ,salary : \n");
	
	getchar();
	fgets(person2->name,20,stdin);
	scanf("%d", &person2->age);
	scanf("%d", &person2->salary);

	if (humanEqual(person1, person2))
		printf("The two human beings are the same\n");
	else
		printf("The two human beings are not the same\n");

}
int humanEqual(human *person1, human *person2) {
	if (strcmp(person1->name, person2->name)) {
		return FALSE;
	}
	if (person1->age != person2->age) {
		return FALSE;
	}
	if (person1->salary != person2->salary) {
		return FALSE;
	}
	return TRUE;
}