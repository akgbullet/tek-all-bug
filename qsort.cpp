#include "display.h"

void swap(int *ary, int a, int b){
	int t=ary[a];
	ary[a]=ary[b];
	ary[b]=t;
}

void qsort (int *ary, int l, int u){
	if(l>=u)
		return;
	int m=l;
	int t=ary[l];
	for(int i=l+1;i<=u;i++){
		if(ary[i]<t){
			swap(ary,++m,i);
		}
	}
	swap(ary,l,m);
	qsort(ary,l,m-1);
	qsort(ary,m+1,u);
}

/*
int main(){
	int ary[] = {1,3,5,7,9,2,4,6,8,10};
	display(ary, 10);
	qsort(ary,0,9);
	display(ary,10);
	return 0;
}
*/