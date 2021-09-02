//
// Name: Karandeep Singh
// Date: 3/5/2021
// ID: 2004
// Abstract: . Write a C++ (or Java) program named hw5_1.cpp (or hw5_1.java) which checks if an input string is a palindrome or not. In the problem, 
// a palindrome means an alphanumeric string which reads the same front to back. For the problem, 
// you should ignore case and remove all non-alphanumeric characters in the input string. 
// For example, “Race car”, “I did, did I?”, “7...8 Don't nod 87.” are all palindromes. But “CSUMB” is not a palindrome.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

bool rec_pal(string input, int index = 0) {
    if (input.length()/2 == index){
        return true;
    } else {
        return (rec_pal(input, index+1) && input[index] == input[input.length()-index-1]);
    }
}

int main(){

    string input, up_input, empty;


    getline(cin, input);

    for(int i = 0; i < input.length(); i++){
        input[i] = toupper(input[i]);
        up_input = input;
    }

    for(int j = 0; j < input.length(); j++){
        if((input[j] >= '0' && input[j] <= '9') || (input[j] >= 'A' && input[j] <= 'Z')){
            empty += input[j];
        }
    }
    input = empty;

    if(rec_pal(input)){
        cout << "TRUE" << endl;
    }else{
        cout << "FALSE" << endl;
    }


}


