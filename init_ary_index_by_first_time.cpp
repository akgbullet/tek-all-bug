//--yangyang--
//--2012/07/28--

/**
* this function provide a method to initialize member of array
* when you first access this member
**/

#include <iostream>
#define N	10
#define PUDDING	1
int data[N];
int from[N];
int to[N];
int top;

using namespace std;

void display_init_ary_index_by_first_time(int *ary, int len){
	for(int i=0;i<len;i++)
		cout<<ary[i]<<"\t";
	cout<<endl;
}

void resetAry(int *ary, int len){
	for(int i=0;i<len;i++)
		ary[i]=0;
}

void init_by_first_time(int index){
	if(from[index]<top && to[from[index]]==index){
		cout<<"already init"<<endl;
	}else{
		from[index]=top;
		to[top]=index;
		top++;
		data[index]=PUDDING;
		cout<<"init index "<<index<<endl;
	}
}

void initAndTest(){
	//init data
	resetAry(data,N);
	resetAry(from,N);
	resetAry(to,N);
	top=0;
	
	init_by_first_time(3);
	init_by_first_time(3);
	init_by_first_time(5);
	init_by_first_time(7);
}

int main(){
	initAndTest();
	display_init_ary_index_by_first_time(data,N);
	display_init_ary_index_by_first_time(from,N);
	display_init_ary_index_by_first_time(to,N);
	cout<<top<<endl;
	return 0;
}