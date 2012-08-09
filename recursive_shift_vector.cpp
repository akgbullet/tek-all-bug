//--yangyang--
//--2012/08/02--

/**
* this is a functioin to shift an array by some bits;
* it is a recursive function
**/
#include <iostream>
using namespace std;

void displayAry_recursive_shift_vector(int *ary, int len){
	//return ;
	for(int i=0; i<len; i++)
		cout<<ary[i]<<'\t';
	cout<<endl;
}

void swapAryIndex(int *ary, int start, int end, int swaplen){
	if(start>=0 && start<end){
		for(int i=0;i<swaplen;i++){
			int t=ary[end+i];
			ary[end+i]=ary[start+i];
			ary[start+i]=t;
		}
	}
}

void recursive_shift(int *ary, int shift, int len){
	if(shift==0)
		return;
	int left=shift;
	int right=len-shift;
	if(left>=right){
		int mid=left-right;
		swapAryIndex(ary,0,left,right);
		//displayAry_recursive_shift_vector(ary,len);
		recursive_shift(&(ary[right]),mid,mid+right);
	}else{
		int mid=right-left;
		swapAryIndex(ary,0,left+mid,left);
		//displayAry_recursive_shift_vector(ary,len);
		recursive_shift(ary,left,left+mid);
	}
}

void loop_shift(int *ary, int len, int rotdist){
	int i,p;
	i=p=rotdist;
	int j=len-i;
	while(i!=j){
		if(i<j){
			swapAryIndex(ary,p-i,p+j-i,i);
			j-=i;
		}else{
			swapAryIndex(ary,p-i,p,j);
			i-=j;
		}
	}
	swapAryIndex(ary,p-i,p,i);
}

/*
int main(){
	int ary[] = {0,1,2,3,4,5,6,7,8,9,10};
	int len=11;
	int shift=5;
	//recursive_shift(ary,shift,len);
	loop_shift(ary,len,shift);
	displayAry_recursive_shift_vector(ary, len);
	return 0;
}
*/