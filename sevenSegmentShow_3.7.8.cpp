//--yangyang--
//--2012/08/04--

/**
* this program using an array to help display seven segment show
**/

#include <iostream>
using namespace std;

void sevenSegmentShow(int k){
	short ary[10] = {0x7c,0x50,0x37,0x57,0x5a,
					0x4f,0x6f,0x54,0x7f,0x5e};
	short rt[5];
	int t=k%10;
	int index=0;
	while(t>0){
		rt[index++]=ary[t];
		k/=10;
		t=k%10;
	}
	for(int i=index-1;i>=0;i--)
		cout<<hex<<rt[i]<<endl;
}

/*
int main(){
	sevenSegmentShow(56);
	cout<<"*******"<<endl;
	sevenSegmentShow(1234);
	cout<<"*******"<<endl;
	return 0;
}
*/