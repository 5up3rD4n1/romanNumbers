/*
 * intToString.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: sd
 */

#include <stdio.h>
#include "../include/intToString.h"
char *units[9]={"uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve"};
char *teens[9]={"once","doce","trece","catorce","quince","dieciséis","diecisiete","dieciocho","diecinueve"};
char *twenties[9]={"ventiuno","ventidos","ventitres","venticuatro","veinticinco","veintiseis","veintisiete","ventiocho","ventinueve"};
char *tens[9]={"diez","veinte","treinta","cuarenta","cincuenta","sesenta","setenta","ochenta","noventa"};
char *hundreds[9]={"ciento","doscientos","trescientos","cuatrocientos","quinientos","seiscientos","setecientos","ochocientos","novecientos"};

void printNumber(int current,long int numbers[],int originalLength){
	int index = current-1;
	int num = numbers[index];
	//printf("%d , %d , %d \n",current,num,numbers[index]);
	if (num == 0) return;
	if (current == 10){
		if (num == 1){
			printf("un billon");
		}else{
			printf("%s billones ", units[num-1]);
		}
	}
	if (current == 9){
		if (numbers[index-1] == 0 && numbers[index-2] == 0){
			printf("%s millones ",hundreds[num-1]);
		}else{
			printf("%s ",hundreds[num-1]);
		}
	}

	if (current == 8){
		if (numbers[0] == 0){
			printf("%s millones ",tens[num-1]);
		}else if(num == 2){
			printf("%s millones ",twenties[numbers[index-1]-1]);
		}else if(num == 1){
			printf("%s ",teens[numbers[index-1]-1]);
		}else{
			printf("%s y ",tens[num-1]);
		}
	}

	if (current == 7){
		if (originalLength > 7){
			if (numbers[index+1] == 1 || numbers[index+1] == 2){
				return;
			}
		}
		if (num == 1){
			printf("un millon ");
		}else{
			printf("%s millones ",units[num-1]);
		}

	}

	if (current == 6){
		if (numbers[index-1] == 0 && numbers[index-2] == 0){
			printf("%s mil ",hundreds[num-1]);
		}else{
			printf("%s ",hundreds[num-1]);
		}
	}

	if (current == 5){
		if (numbers[0] == 0){
			printf("%s mil ",tens[num-1]);
		}else if(num == 2){
			printf("%s mil ",twenties[numbers[index-1]-1]);
		}else if(num == 1){
			printf("%s mil ",teens[numbers[index-1]-1]);
		}else{
			printf("%s y ",tens[num-1]);
		}
	}

	if (current == 4){
		if (originalLength > 4){
			if (numbers[index+1] == 1 || numbers[index+1] == 2){
				return;
			}
		}
		if(num == 1){
			printf("mil ");
		}else{
			printf("%s mil ",units[num-1]);
		}
	}

	if (current == 3){
		printf("%s ",hundreds[num-1]);

	}

	if (current == 2){
		if (numbers[0] == 0){
			printf("%s ",tens[num-1]);
		}else if(num == 2){
			printf("%s ",twenties[numbers[index-1]-1]);
		}else if(num == 1){
			printf("%s ",teens[numbers[index-1]-1]);
		}else{
			printf("%s y ",tens[num-1]);
		}
	}

	if (current == 1){
		if (originalLength>1) {
			if (numbers[1] == 1 || numbers[1] == 2) return;
		}
		printf("%s",units[num-1]);
	}
}


void intToString(long int num){
	long int numbers[10];
	for(int i = 0; i<10;i++)
		numbers[i]=0;
	int length = 0;
	long int numTemp = num;
	while (numTemp){
		numbers[length] = numTemp%10;
		numTemp /= 10;
		length++;
	}
	for(int i = 0; i<10;i++)
			printf("%d ",numbers[i]);
	printf(" \n");
	int originalLength = length;
	int current = length;

	while (current){
		printNumber(current, numbers,originalLength);
		current--;
	}
}



