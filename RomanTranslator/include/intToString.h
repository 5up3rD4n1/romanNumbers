/*
 * intToString.h
 *
 *  Created on: Mar 25, 2015
 *      Author: sd
 */


#include <iostream>
#include <sstream>
#include <string>

#ifndef INTTOSTRING_H_
#define INTTOSTRING_H_


extern char *units[9];
extern char *teens[9];
extern char *twenties[9];
extern char *tens[9];
extern char *hundreds[9];

void intToString(long int num);
long strToInt(std::string s);

#endif /* INTTOSTRING_H_ */
