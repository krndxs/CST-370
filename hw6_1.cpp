/*
 * Link to source code:  https://www.geeksforgeeks.org/iterative-depth-first-traversal/
 * Title: hw6_1.cpp
 * Write a C++ (or Java) program called hw6_1.cpp (or hw6_1.java) that reads a number of input values and the values themselves. Then, your program should put all negative numbers in front of all positive numbers. 
 * Author: Karandeep Singh
 * ID: 2004
 * Date: 3/12/2021
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int max;
    vector<int> values1;
    vector <int> values2;
    cin >> max;
    for(int i = 0; i < max; i++){
        int num;
        cin >> num;
        values1.push_back(num);
    }
    values2 = values1;
    int j, k;
    j = 0;
    k = max - 1;
    while(k > j){
        if(values1.at(k) > 0){
            k--;
        }
        if(values1.at(j) < 0){
            j++;
        }
        if(values1.at(k) < 0 && values1.at(j) > 0 && (k > j)){
            swap(values1.at(k), values1.at(j));
        }
    }
    for(int i = 0; i < max; i++){
        cout << values1.at(i) << " ";
    }
    cout << endl;
    j = 0;
    k = 0;
    while(j < max && k < max){
        if(values2.at(k) < 0){
            k++;
        }
        if(values2.at(j) > 0 || j <= k){
            j++;
        }
        if((j < max && k < max) && values2.at(k) > 0 && values2.at(j) < 0){
            swap(values2.at(k), values2.at(j));
        }
    }
    for(int i = 0; i < max; i++){
        cout << values2.at(i) << " ";
    }
}