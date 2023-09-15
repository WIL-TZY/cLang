#include <stdio.h>

int main() {
	int i;
	for (i = 0; i < 10; i++) {
		switch (i) {
			case 0: printf("0 "); // ---> Se não adicionar o break ele printa o 2 e o 3 juntos e depois printa o 3 de novo
			/*
			start:
				printf("["); 
				break;
			*/
			case 1: printf("1 "); break;
			case 2: printf("2 "); break; 
			case 3: printf("3 "); break;
			case 4: printf("4 "); break;
			case 5: printf("5 "); break;
			case 6: printf("6 "); break;
			case 7: printf("7 "); break;
			case 8: printf("8 "); break;
			case 9: printf("9 "); break;
			case 10: printf("10"); // ---> Como esse é o último case, o break não faz tanta falta mas é uma boa prática colocá-lo
		}
	}
	return 0;
}