/*
 * 
 * Title: hw1_1.cpp
 * Abstract: Write a C++ program (or Java program) called hw1_1.cpp (or hw1_1.java) that reads input numbers from a user and displays the number that occurs most frequently among all the input numbers.
 * Author: Karandeep Singh
 * ID: 2004
 * Date: 02/04/2021
 */
#include <iostream>
using namespace std;
int main(){
   
   int length;
   int pos[10000] = {0};
   int posneg[10000] = {0};
   cin>>length;
   int temp = 0;
   int freq = 0;
   int number =0;
   
   for(int i =0;i<length;i++){
   		cin >> temp;
   		if(temp > 0){
   			pos[temp]++;
   			
   			if(freq<pos[temp]||(temp>number && freq == number)){
   				freq = pos[temp];
   				number = temp;
   			}
   		}else{
   		   cout << endl;
   			posneg[temp]++;
   			if(freq<posneg[temp]||(temp>number && freq == number)){
   				freq = posneg[temp];
   				number = temp;
   			}
   		}
   }
   
   cout<<"Number:" << number << endl;
   cout<<"Frequency:" << freq;
   
  }