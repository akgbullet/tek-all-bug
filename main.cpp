#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int binarySearch(int *ary, int len, int key){
	int l=0; 
	int r=len-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(key<ary[mid]) r=mid-1;
		else if(key>ary[mid]) l=mid+1;
		else return mid;
	}
	return -1;
}

/*
int main(){
	int ary[] = {1,2,3,4,5,6,7,8,9,10};
	int len=10;
	cout<<binarySearch(ary,10,2)<<endl
		<<binarySearch(ary,10,10)<<endl
		<<binarySearch(ary,10,11)<<endl;
	return 0;
}
*/