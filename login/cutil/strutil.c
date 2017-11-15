#include "util.h"

#include <assert.h>
#include <string.h>


int charsum(char * str,int sz){
	int sum=0;
	for(int i=0;i<sz;i++){
	    sum+=(int)str[i];
	}
	return sum;
}

bool strncmp2(char * str1,char * str2,int len){
	for(int i=0;i<len;i++){
		if(str1[i]!=str2[i]){
			return false;
		}
	}
	return true;
}
int find(char ** arr,char str[],int sz){
	for(int i=0;i<sz;i++){
		//std::cout<<arr[i]<<"!="<<str<<std::endl;
		//std::cout<<charsum(arr[i],2)<<"!="<<charsum(str,2)<<std::endl;
		if(strcmp(arr[i],str)){
			//std::cout<<"eq"<<std::endl;
			return i;
		}
	}
	return -1;
}

bool remove(char ** arr,int index,int sz){//returns true if delted item succeed
	if(index>=sz){
		return false;
	}
	for(int i=index;i<sz;i++){
		arr[i]=arr[i+1];
	}
	return true;
}


