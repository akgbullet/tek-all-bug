//--yangyang--
//--2012/08/04--

/**
* this program print character as the description of the schema file
**/

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

/*
* file format, suppose it is going to print 'I'
* 3 9 x
* 6 3 b 3 x 3 b
* 3 9 x
*/

void reset(int *ary, int len){
	for(int i=0;i<len;i++)
		ary[i]=0;
}

void banner(char *file){
	ifstream in(file);
	char c;
	int lines=0;
	int ary[10];
	reset(ary,10);
	while(in>>c){
		lines=c-'0';
		int i=0;
		while(in>>c){
			if(iscntrl(c)) break;
			if(isalnum(c)) ary[i++]=c;
		}
		for(int l=0;l<lines;l++){
			for(int k=0;k<i; k+=2)
				for(int t=0;t<ary[k];t++)
					cout<<ary[k+1];
		}
		reset(ary,10);
	}
}

/*
int main(void){
	banner("banner_format.txt");
	return 0;
}
*/