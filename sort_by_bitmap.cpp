//--yangyang--
//--2012/07/25--

/*
* this file first generate 10,000,000 integers to a file,
* and then read these integers from the file and sort them 
* by bitmap, and finally output the result into another file.
*/

#include <iostream>
#include <fstream>
#include <string>

#define BITSPERWORD	32
#define SHIFT 5
#define MASK 0x1F
#define N 10000000
int bitary[1+N/BITSPERWORD];

using namespace std;
//the easiest way to generate N random number is to use the 
//first N number 
void generateRandom(){
	ofstream out("generate.txt");
	for(int i=N; i>=1; i--){
		out<<i<<endl;
	}
	out.close();
}

//set the bitmap
//it is a bit like memory management, first find the index in bitary
//then find the position in the index
void setBit(int k){
	bitary[k>>SHIFT] |= 1<<(k&MASK);
}

void clearBit(int k){
	bitary[k>>SHIFT] &= ~(1<<(k&MASK));
}

int testBit(int k){
	return bitary[k>>SHIFT] & (1<<(k&MASK));
}

void one_round() {
	for(int i=0; i<1+N/BITSPERWORD;i++)
		bitary[i]=0;
	ifstream in("generate.txt");
	int k=0;
	while(in>>k){
			setBit(k);
	}
	in.close();
	ofstream out("result.txt");
	for(int i=1;i<=N;i++){
		if(testBit(i))
			out<<i<<endl;
	}
	out.close();
}

//multi_round will read the file multi times
//each time read one number and check whether it is between the range
//if so, the number is to be processed this time
void multi_round(){
	int times=3;
	int gap=N/times;
	int left=0,right=0;
	ofstream out;
	out.open("multiResult.txt",ios::app);
	for(int i=0;i<times;i++){
		left=right;
		right+=gap;
		int k;
		ifstream in("generate.txt");
		while(in>>k){
			if(k>=left && k<right)
				setBit(k);
		}
		in.close();
		for(int t=left;t<right;t++){
			if(testBit(t))
				out<<t<<endl;
		}
	}
	//if right<=N, there will be another way to cover the left numbers
	//at most time, times should be divided by N exactly
	if(right<=N){
		left=right;
		right=N;
		int k;
		ifstream in("generate.txt");
		while(in>>k){
			if(k>=left && k<=right)
				setBit(k);
		}
		in.close();
		for(int t=left;t<=right;t++){
			if(testBit(t))
				out<<t<<endl;
		}
	}
	out.close();
}

//check the result 
//there is some problem here, can you find it?
bool checkFiles(){
	ifstream in1("result.txt");
	ifstream in2("multiResult.txt");
	int a,b;
	while(in1>>a && in2>>b){
		if(a!=b)
			return false;
	}
	if(in1>>a || in2>>b)
		return false;
	return true;
}

/*
int main(){
	//generateRandom();
	//one_round();
	//multi_round();
	cout << checkFiles();
	return 0;
}
*/