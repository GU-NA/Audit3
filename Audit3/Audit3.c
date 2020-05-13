#include<stdlib.h>
#include<stdio.h>
#include<Windows.h>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf("Input the number of cities\n");
	int number_city;
	char** mass;
	scanf_s("%d", &number_city);
	number_city += 1;
	mass = (char**)malloc(sizeof(char*)*number_city);
	for (int i = 0; i < number_city; i++) 
		mass[i] = (char*)malloc(sizeof(char) * 26);
	printf("Input name of cities\n");
	for (int i = 0; i < number_city; i++) {
		int k = 0;
		char c = getc(stdin);
		while (1==1) {
			if (c == '\n') {
				mass[i][k] = '\0';
				break;
			}
			mass[i][k] = c;
			k++;
			c = getc(stdin);
		}
	}
	char** mass1;
	mass1 = (char**)malloc(sizeof(char*) * number_city);
	for (int i = 0; i < number_city; i++)
		mass1[i] = (char*)malloc(sizeof(char) * 2);
	for (int i = 0; i < number_city; i++) {
		mass1[i][0] = mass[i][0];
		int k = 0;
		while (1==1) {
			if (mass[i][k] == '\0') {
				mass1[i][1] = mass[i][k - 1];
				break;
			}
			k++;
		}

	}
	int proverka=0, proverka1 = 0;
	for (int i = 1; i < number_city-1; i++) {
		char c = mass1[i + 1][1];
		if ((c-32) != mass1[i][0]) {
			proverka++;
			}
	}
	for (int i = 1; i < number_city-1; i++) {
		char c = mass1[i][1];
		if ((c-32) != mass1[i+1][0]) {
			proverka1++;
		}
	}
	if ((proverka1 == 0) || (proverka == 0))
		printf("Suitable\n");
	else
		printf("Not suitable\n");
	for (int i = 0; i < number_city; i++)
		free(mass1[i]);
	free(mass1);
	for (int i = 0; i < number_city; i++)
		free(mass[i]);
	free(mass);
	return 0;
} 
/*#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<locale.h>
int main() {
	int n,sum=0;
	scanf_s("%d",&n);
	int* mass,mass_on_output[10000];
	mass = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf_s("%d",&mass[i]);
	for (int i = 0; i < 10000; i++)
		mass_on_output[i] = 0;
	for (int i = 0; i < n; i++) {
		int a = mass[i];
		mass_on_output[a] += 1;
	}
	for (int i = 0; i < 10000; i++)
		if (mass_on_output[i] > 0)
			printf("%d ", i);
	free(mass);
	system("pause");
	return(0);
}*/