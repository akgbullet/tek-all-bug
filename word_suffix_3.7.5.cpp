//--yangyang--
//--2012/08/04--

/**
* this program guides you to process some suffix problem about words
**/

#include <iostream>
#include <stdlib.h>
using namespace std;

int compare(int a, int b){
	return a-b;
}

void findSuffix(char *word){
	const int suffixLen = 10;
	char suffix[][suffixLen]=
	{"et-ic",
	"al-is-tic",
	"s-tic",
	"p-tic",
	"-lyt-ic",
	"ot-ic",
	"an-tic",
	"n-tic",
	"c-tic",
	"c-tic",
	"at-ic",
	"h-nic",
	"n-ic",
	"m-ic",
	"l-lic",
	"b-lic",
	"-clic",
	"l-ic",
	"h-ic",
	"f-ic",
	"d-ic",
	"-bic",
	"a-ic",
	"-mac",
	"i-ac"
	};
}