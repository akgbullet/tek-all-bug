#include "display.h"

void insertsort(int *ary, int len){
	//loop invariant ary[0..i-1] is sorted
	for(int i=1;i<len;i++){
		int k=ary[i];
		int j;
		for(j=i-1;j>=0;j--){
			if(k>ary[j]) break;
			else ary[j+1]=ary[j];
		}
		ary[j+1]=k;
	}
}

/*
int main(void){
	int ary[] = {1,3,5,7,9,2,4,6,8,10};
	display(ary, 10);
	insertsort(ary,10);
	display(ary, 10);
	return 0;
}
*/