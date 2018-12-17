#include<stdio.h>
#include<stdlib.h>
struct person {
	char num[15];
	char name[20];
	int score;
};
typedef struct person person;
void main() {
	person pe[10];
	person temp;
	FILE *fp1 = fopen("in1.txt", "r");
	FILE *fp2 = fopen("out1.txt", "w");
	char line[50];
	int i=0;
	if (fp1 == NULL) {
		printf("file is not open");
		exit(1);
	}
	fgets(line, 50, fp1);
	while (!feof(fp1)) {
		sscanf(line,"%s %s %d", pe[i].num, pe[i].name, &pe[i].score);
		i++;
		fgets(line, 50, fp1);
	}
	for (int n = 0; n < i; n++) {
		for (int m = n + 1; m < i; m++) {
			if (strcmp(pe[n].num, pe[m].num) >0) {
				temp = pe[n];
				pe[n] = pe[m];
				pe[m] = temp;
			}
		}
	}
	for (int n = 0; n < i; n++) {
		fprintf(fp2,"%s %s %d\n", pe[n].num, pe[n].name, pe[n].score);
	}
	fclose(fp1);
}