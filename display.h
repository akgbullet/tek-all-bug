#ifndef	_DISPLAY_H_
#define _DISPLAY_H_

#include <iostream>
#include <string>
using namespace std;

inline void display(int *ary, int len) {
	for(int i=0;i<len;i++)
		cout<<ary[i];
	cout<<endl;
}

#endif