//--yangyang--

/**
* this is a guidance to process integer by bit
**/

#include <iostream>
using namespace std;

#define BITSPERWORD	32
#define SHIFT	5
#define MASK	0x1F
#define N	1000
//ary to store bit map
int ary[1+N/BITSPERWORD];

//set the bit representing integer k
void set(int k) {ary[k>>SHIFT] |= (1<<(k&MASK));}

//clear the bit representing integer k
void clr(int k) {ary[k>>SHIFT] &= ~(1<<(k&MASK));}

//test whether bit represening integer k is setted or cleared
int test(int k) {return (ary[k>>SHIFT] & (1<<(k&MASK)));}

//test these functions
void display(int a[], int len){
	for(int i=0; i<len; i++){
		cout<<hex<<a[i]<<"\t";
	}
	cout<<endl;
}
int main(){
	int count=1+N/BITSPERWORD;
	for(int i=0; i<count; i++){
		ary[i]=0;
	}
	for(int i=0;i<50;i++){
		set(i);
	}
	display(ary,count);
	for(int i=0; i<50; i++){
		if(test(i)) clr(i);
	}
	display(ary,count);
	return 0;
}

//--2012/7/24--