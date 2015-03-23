//============================================================================
// Name        : strToInt.cpp
// Author      : melalonso
// Version     :
// Copyright   : BADSA Corp. All rights reserved.
// Description : Methods for converting String number to integer value
//============================================================================

#include <iostream>
#include <sstream>
#include "../include/intToString.h"

using namespace std;

#define NOT_FOUND -1
#define MIL 1000
#define MILLON 1000000
#define BILLON 1000000000

// Method that searches for a word in the arrays
// of available words and return its value according to in what array
// it was found, otherwise it returns NOT_FOUND
long findWordValue(string w){
	for (int i =0;i<10;i++){
		if (w==units[i])         return i+1;
		else if (w==teens[i])    return 10+i+1;
		else if (w==tens[i])     return 10*(i+1);
		else if (w==twenties[i]) return 20+(i+1);
		else if (w==hundreds[i]) return 100*(i+1);
		else if (w=="y")         return 0;
	}
	return NOT_FOUND;
}

// Boolean method that returns true when the word
// that receives is a separator word, false otherwise.
bool isSeparator(string w){
	return w=="mil" || w=="millon" || w=="millones" ||
			w=="billon" || w=="billones";
}

// Method that returns value of a separator word like
// "millon", "billon" to multiply by previous value and
// add to the whole word value.
long getSeparatorValue(string w){
	if (w=="mil") return MIL;
	else if (w=="millon" || w=="millones") return MILLON;
	else if (w=="billon" || w=="billones") return BILLON;
	else return NOT_FOUND;
}

// Gets the number in string form
// and returns its integer value.
long strToInt(string str){
	int acc,flag=0;
	long total=0;
	stringstream ss(str);
	string w;
	while(ss >> w){
		acc = 0;
		while(!isSeparator(w)){
			acc += findWordValue(w);
			if (!(ss >> w)){
                flag=1;
                break;
            }
		}
		if (flag) total += acc;
		else total += (acc * getSeparatorValue(w));
	}
	return total;
}

/*
int main(){
	string numero = "cincuenta y cinco millones trescientos cuarenta y cinco mil trescientos dos";
	cout << strToInt(numero)<<endl;
}
*/



