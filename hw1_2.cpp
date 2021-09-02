/*
 * 
 * Title: hw1_2.cpp
 * Abstract: . Write a C++ program (or Java program) called hw1_2.cpp (or hw1_2.java) that reads two groups of 
 * numbers in which each group has several integer numbers without duplicates. Your program should display the non-common numbers in both groups in the descending order.
 * Author: Karandeep Singh
 * ID: 2004
 * Date: 02/04/2021
 */

#include <iostream>
using namespace std;
int main(){
	int len;
	cin>>len;
	int list [len]; 
	for(int i = 0;i<len;i++){
		cin>>list[i];
	}
	
	int len2;
	cin>>len2;
	int list2 [len2];
	
	for(int i = 0; i<len2;i++){
		bool test2 = true;
		int tmp=0;
		cin>>tmp;
		for(int j = 0;j<len;j++){
			if(list[j]==tmp){
				list[j]= -10042;
				test2 = false;
			}
		}
		if(test2){
			list2[i]=tmp;
		}else{
			list2[i]=-10042;
		}
	}
	
	cout<<"Answer: ";
	bool test = true;
	int list3 [len2+len];
	
	for(int i =0;i<len2+len;i++){
		list3[i] = -10042;
	}
	
	for(int i =0;i<len+len2;i++){
		if(i<len){
			if(list[i]!=-10042){
				test = false;
				list3[i]=list[i];
			
			}
		}
		if(i<len2){
			if(list2[i]!=-10042){
				test = false;
				list3[i+len]=list2[i];
				
			}
		}
	}
	
	if(test){
		cout<<"NONE";
		return 0;
	}
	
	for(int i =0;i<len2+len;i++){
		for(int j =0;j<len2+len-1;j++){
			if(list3[j]<list3[j+1]){
				int tmp = list3[j];
				list3[j] = list3[j+1];
				list3[j+1] = tmp;
			}
		}
	}
	
	for(int i=0;i<len2+len;i++){
		if(list3[i]!=-10042){
			cout<<" "<<list3[i];
		}
	}	
	
}