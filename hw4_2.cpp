/*
 * 
 * Title: hw4_2.cpp
 * Abstract: . Write a C++ program (or Java program) called hw4_2.cpp (or hw4_2.java) that reads a set of events and displays the maximum number of events that take place concurrently.
 * Author: Karandeep Singh
 * ID: 2004
 * Date: 02/21/2021
 */

#include <iostream>
using namespace std;
int main(){
  int count;
  int start,stop;
  int times [24]={0};

  cin>>count;
  
  for(int i =0;i<count;i++){
    cin >> start >> stop;
    for(int j = start; j < stop; j++){
      times[j]++;
    }
   }
   
  int max_events = 0;
  for(int i = 0;i < 24; i++){
    if(times[i] > max_events){
      max_events = times[i];
    }
  }
  
  cout<<"Max events: "<< max_events << endl;
  
}