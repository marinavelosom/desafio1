/*
	* Aluna: Marina Melo Veloso
	* Disciplina: Logica para Computacao
	* Desafio 1
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	printf("Alfabeto aceito: \n\n");
	printf("S�mbolos proposicionais -> (a, b, c .... p, q, r, s, p1, q1, r1, s1, p2...) \n");
	printf("S�mbolos de verdade -> (v, f)\n");
	printf("S�mbolos de pontuac�o -> {()} par�nteses  \n");
	printf("Nega��o -> (~) \n");
	printf("E conectivos proposicionais, sendo eles:  \n");
	printf("{^} significando conju��o \n");
	printf("{|} significando disjun��o\n");
	printf("{>} significando implica��o \n");
	printf("{<>} significando bicondicional \n\n");
	
	
	char entrada(char *dig, char x, int j);
	int verificacao(char *n, char x, int m);
	
	char dig[1000];
	char *digitado = dig;
	char c;
	int i;
	
	entrada(digitado, c, i);
	verificacao(digitado, c, i);
	return 0;
}

char entrada(char *dig, char x, int j){
	
	char digitado[1000];
	char *pont = digitado;
	char c, n;
	int i = 0;
	
	do{
		c = getch();
		if (isalnum(c) != 0 ||c == 32 || c == 40 || c == 41 || c == 126 || c == 94 || c== 124 || c== 60 || c == 62){
			digitado[i] = c;
			i++;
			printf("%c", c);
		}
		if(c == 8 && i !=0){ 
			digitado[i] = '\0';
			i--;
			printf("\b \b");
		}
	}while (c != 13);
	digitado[i] = '\0';
	return  digitado[i];
}
	

int verificacao(char *n, char x, int m){
	
	//char entrada(char *dig, char x, int j);
	
	char digitado[1000];
	char *pont = digitado;
	char c;
	int i;
	
	for (i = 0; i < digitado[i]; i++){
		if (digitado[i] == 126){ 
			if (digitado[i + 1] == 94 || digitado[i + 1] == 124 || digitado[i + 1] == 60 || digitado[i + 1] == 62){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nNega��o n�o pode ser seguido de um conetivo.\n");
				exit(1); 
			}
			if(digitado[i + 1] == 41){
				printf("\nN�o � uma f�rmula l�gica proposicional.\n");
				exit(1); 
			}
			if(isalpha(digitado[i - 1]) != 1){
				printf("\nN�o � uma f�rmula l�gica proposicional.\n");
				exit(1); 
			}
		}
		if (isalpha(digitado[i]) != 0){ 
			if (isalpha(digitado[i + 1]) != 0){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nS�mbolo proposicional n�o pode ser seguido de outro S.P..\n", 163, 198, 144, 161);
				exit(1); 
			}
			if (digitado[i + 1 ] == 32 && isalpha(digitado[i + 2]) != 0){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nS�mbolo proposicional n�o pode ser seguido de outro S.P..\n", 163, 198, 144, 161);
				exit(1); 
			}
		}
		if (isdigit(digitado[i]) != 0){ 
			if(isalpha(digitado[i + 1]) != 0){
				printf("\nN�mero n�o � s�mbolo proposicional, digite somente depois de uma letra.\n", 163, 198, 144, 161);
				exit(1); 
			}
			if (digitado[i + 1 ] == 32 && isalpha(digitado[i + 2]) != 0){
				printf("\nN�mero n�o � s�mbolo proposicional, digite somente depois de uma letra.\n", 163, 198, 144, 161);
				exit(1); 
			}
			if(isalpha(digitado[i - 1]) != 1){
				printf("\nN�mero n�o � s�mbolo proposicional, digite somente depois de uma letra.\n", 163, 198, 144, 161);
				exit(1); 
			}
			
		}
		if (digitado[i] == 94){ 
			if(digitado[i + 1] == 94 || digitado[i + 1] == 124 ||  digitado[i + 1] == 60 ||  digitado[i + 1] == 62){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nConetivo n�o pode ser seguido de outro conectivo.\n");
				exit(1); 
			}
			if (digitado[i + 1 ] == 32 && digitado[i + 2] == 94 || digitado[i + 2] == 124 ||  digitado[i + 2] == 60 ||  digitado[i + 2] == 62 ){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nConetivo n�o pode ser seguido de outro conectivo.\n");
				exit(1); 
			}
			
		}
		if (digitado[i] == 124){
			if(digitado[i + 1] == 94 || digitado[i + 1] == 124 ||  digitado[i + 1] == 60 ||  digitado[i + 1] == 62){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nConetivo n�o pode ser seguido de outro conectivo.\n");
				exit(1); 
			}
			if (digitado[i + 1 ] == 32 && digitado[i + 2] == 94 || digitado[i + 2] == 124 ||  digitado[i + 2] == 60 ||  digitado[i + 2] == 62 ){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nConetivo n�o pode ser seguido de outro conectivo.\n");
				exit(1); 
			}
		
		}
		if (digitado[i] == 60){
			if(digitado[i + 1] == 94 ||  digitado[i + 1] ==  124 || digitado[i + 1] == 60){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nConetivo n�o pode ser seguido de outro conectivo.\n");
				exit(1); 
			}
			if (digitado[i + 1 ] == 32 && digitado[i + 2] == 94 || digitado[i + 2] == 124 ||  digitado[i + 2] == 60){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nConetivo n�o pode ser seguido de outro conectivo.\n");
				exit(1); 
			}
			
		}
		if (digitado[i] == 62){
			if(digitado[i + 1] == 94 ||  digitado[i + 1] == 124 ||  digitado[i + 1] == 60 || digitado[i + 1] == 62){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nConetivo n�o pode ser seguido de outro conectivo.\n");
				exit(1); 
			}
			if (digitado[i + 1 ] == 32 && digitado[i + 2] == 94 || digitado[i + 2] == 124 ||  digitado[i + 2] == 60 ||  digitado[i + 2] == 62 ){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nConetivo n�o pode ser seguido de outro conectivo.\n");
				exit(1); 
			}
			
		}
		if(digitado[i] == 94 || digitado[i] == 124 || digitado[i] == 60){
			if(isalpha(digitado[i - 1]) == 0 && digitado[i - 1] != 41){
				printf("\nN�o � uma f�rmula l�gica proposicional.\n");
				exit(1); 
			}
		}
	
		if(digitado[i] == 62){
			if(isalpha(digitado[i - 2]) == 0 && digitado[i - 2] != 41){
				printf("\nN�o � uma f�rmula l�gica proposicional.\nConectivo deve ficar entre S.P..\n");
				exit(1); 
			}
		}
		if(digitado[i] == 40){
			if(digitado[i + 1] == 41){
				printf("\nN�o � uma f�rmula l�gica proposicional.");
				exit(1);
			}
		}
		if (digitado[i] == 60){
			if(digitado[i + 1] != 62){
				printf("\n(<) n�o � um s�mbolo aceito pelo alfabeto");
				exit(1);
			}
		}
	}
	printf("\n� uma f�rmula l�gica proposicional.\n");
	
	return 0;
}








	



	










