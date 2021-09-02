/*
 * Link to source code:  https://replit.com/@YBYUN/sumdivNconqcpp
 * Title: hw7_1.cpp
 * ) Write a C++ (or Java) program named hw7_1.cpp (or hw7_1.java) which displays the biggest number in an array with n integer numbers using a divide-and-conquer technique.
 * Author: Karandeep Singh
 * ID: 2004
 * Date: 3/26/2021
 */
#include <iostream>
int max(int i, int i1);
using namespace std;
int sum_div_N_conq(int A[ ], int start, int end) {
    if (end - start > 1) {
        int sum1 = sum_div_N_conq(A, start, (start + end) / 2);
        int sum2 = sum_div_N_conq(A, (start + end) / 2 + 1, end);
        return (max(sum1, sum2));
    } else {
        return max(A[start], A[end]);
    }
}
int max(int i, int i1) {
    if(i > i1){
        return i;
    }else{
        return i1;
    }
}
int main()
{
   int size;
   cin >> size;
   int *array = new int[size];
   for(int i = 0; i < size; i++){
       cin >> array[i];
   }
   cout << sum_div_N_conq(array, 0, size);
}