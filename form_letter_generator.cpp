//--yangyang--
//--2012/08/04--

/**
* this program guides you to format an ouput
**/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

/*
* form letter schema
* Welcome back, $1!
* We hope that you and all the members
* of the $0 family are constantly
* reminding your neighbors there 
* on $5 to shop with us.
* As usual, we wil ship your order to
*	$3 $1 #2. $0
*	$4 $5
*	$6, $7 $8
*/

/*
* Function: format output a schema like above description
* Paramter: file, input file with formattioin like above schema
*			ary, store some info with index 1-8
*/
void format_letter_generator( char *file, int *ary, int len){
	ifstream in(file);
	char c;
	while(in>>c){
		if(c!='$')
			cout<<c;
		else {
			in>>c;
			switch(c){
				case '$': cout<<'$';break;
				case '0':
				case '1':
				case '2': cout<<ary[c-'0'];break;
				default: return;
			}
		}
	}
}