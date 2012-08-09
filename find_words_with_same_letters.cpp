//--yangyang--
//--2012/07/31--

/**
* this program is guiding you to find all words 
* consisting of same letters
* this program has a little problem, cannot check words
* with more than 2 same letters.
**/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;

#define N	100000000
#define BITSPERWORD	16
#define SHIFT		4
#define MASK		0xF
int data_find_words[N/BITSPERWORD+1];

int convertWord2Number(string s);
void setfirstbit(int k);
void setsecondbit(int k);
void clrfirstbit(int k);
void clrsecondbit(int k);
int testfirstbit(int k);
int testsecondbit(int k);

void generateRelatedNumber(char *wordsfile, char *outputfile){
	ifstream in(wordsfile);
	ofstream out(outputfile);
	string word;
	while(in>>word){
		//process word
		if(word.size()>0)
			out<<convertWord2Number(word)<<endl;
	}
	in.close();
	out.close();
}

void sortGenerateNumber(char *outputfile){
	for(int i=0;i<N/BITSPERWORD+1;i++)
		data_find_words[i]=0;
	ifstream in(outputfile);
	int k;
	while(in>>k){
		if(!testfirstbit(k))
			setfirstbit(k);
		else if(!testsecondbit(k))
			setsecondbit(k);
	}
	in.close();
}

void outputWords(char *wordsfile, char *outputfile){
	ifstream in(wordsfile);
	ofstream out(outputfile);
	string word;
	int key;
	while(in>>word){
		key=convertWord2Number(word);
		int t=testsecondbit(key);
		if(t)
			out<<word<<endl;
	}
	in.close();
	out.close();
}

/*
int main(){
	cout<<"begin"<<endl;
	time_t begin,end;
	begin=clock();
	generateRelatedNumber("words.txt", "generateNumber.txt");
	sortGenerateNumber("generateNumber.txt");
	outputWords("words.txt", "resule_find_words.txt");
	end=clock();
	cout<<"end"<<endl;
	cout<<"runtime:"<<end-begin<<endl;
	return 0;
}
*/

int convertWord2Number(string word){
	int size=word.size();
	int key=0;
	for(int i=0;i<size;i++){
		key+=(int)pow(2.0,word[i]-'a');
	}
	return key;
}

void setfirstbit(int k){
	data_find_words[k>>SHIFT] |= 1<<(2*(k&MASK));
}

void setsecondbit(int k){
	data_find_words[k>>SHIFT] |= 1<<(1+2*(k&MASK));
}

void clrfirstbit(int k){
	data_find_words[k>>SHIFT] &= ~(1<<(2*(k&MASK)));
}

void clrsecondbit(int k){
	data_find_words[k>>SHIFT] &= ~(1<<(1+2*(k&MASK)));
}

int testfirstbit(int k){
	return (data_find_words[k>>SHIFT] & (1<<(2*(k&MASK))));
}

int testsecondbit(int k){
	int rt=(data_find_words[k>>SHIFT] & (1<<(1+2*(k&MASK))));
	return rt;
}