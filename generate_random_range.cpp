//--yangyang--
//--2012/07/28--

/**
* this function is to generate specific random numbers
**/

#include <iostream>
#include <time.h>

using namespace std;
void display(int *ary, int len);

//generate k numbers between left and right
//the first k numbers in ary is what we want
void generate_random(int k,int left, int right){
	int max=right-left;
	int *ary = new int[max+1];
	srand(time(NULL));
	for(int i=0; i<max+1; i++)
		ary[i]=i;
//	display(ary,max+1);
	for(int i=0;i<k;i++){
		int ind=rand()%(max-i)+i;
		int t=ary[ind];
		ary[ind]=ary[i];
		ary[i]=t;
		cout<<ary[i]<<"\t";
	}
	cout<<endl;
//	display(ary,max+1);
	delete[] ary;
}

void display(int *ary, int len){
	for(int i=0;i<len;i++){
		cout<<ary[i]<<"\t";
	}
	cout<<endl;
}

int main(){
	generate_random(5,0,20);
	return 0;
}