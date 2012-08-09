//--yangyang--
//--2012/07/30--

/**
* this program is guiding you to find a missing number in a file
* this file containing numbers ranging from 1 to 10000000
**/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
* file: path of the file containing random numbers
* from: smallest number in the range
* to:	biggest number in the range
*/
int binary_search_missing_number(char *file, int from, int to){
	while(from<to){
		//init the necessary data before starting
		int mid=(from+to)/2;
		int lessTotalCount=mid-from+1;
		int moreTotalCount=to-mid;
		int lessCount=0;
		int moreCount=0;
cout<<"from:\t"<<from<<"\tto:\t"<<to<<"\tmid:\t"<<mid;

		//because the limitaion of memory you should read the file once again each time
		ifstream in(file);
		int t;
		while(in>>t)
			//to be attention here, just notice that you narrow the range each time, so you should make sure t is between from and to
			if(t>=from && t<=mid) 
				lessCount++;
			else if(t>mid && t<=to)
				moreCount++;
		in.close();

		//to narrow the range
		if(lessCount<lessTotalCount)
			to=mid;
		else if(moreCount<moreTotalCount)
			from=mid+1;
		else
			return -1;
cout<<"\tlessCount:\t"<<lessCount
			<<"\tmoreCount\t"<<moreCount<<endl;
	}
	//at last from equals to, and they should be the missing number
	return to;
}

/*
int main(){
	cout<<"missing number is: "<<binary_search_missing_number("binary_search_test_file.txt",1,10000000);
	return 0;
}
*/