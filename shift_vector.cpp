//--yangyang--
//--2012/07/30--

/**
* this is program guiding to shift a n-dimension vector 
* thought: use reverse code as belows
* ab => ba
* supose reverse() is a function to reverse a vector
* reverse((reverse(a))(reverse(b))) = ba
* if you would like to shift "abcdefg" by 3 bits, do the followings
* reverse(0,i-1);
* reverse(i,n-1);
* reverse(0,n-1);
**/

#include <iostream>
using namespace std;

//reverse an array
void reverse(int *ary, int len){
	for(int i=0;i<len/2;i++){
		int t=ary[i];
		ary[i]=ary[len-i-1];
		ary[len-i-1]=t;
	}
}

//shift an array
void shiftAry(int *ary, int len, int k){
	reverse(&ary[0],k);
	reverse(&ary[k],len-k);
	reverse(ary,len);
}

void display_shift_vector(int *ary, int len){
	for(int i=0; i<len;i++)
		cout<<ary[i]<<"\t";
	cout<<endl;
}

/*
int main(){
	int ary[] = {1,2,3,4,5,6,7,8,9};
	shiftAry(ary, 9, 3);
	display_shift_vector(ary, 9);
	return 0;
}
*/