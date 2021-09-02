
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int input;
    string copy, convert;
    cin >> input;
    convert = to_string(input);
    copy = convert;
    reverse(copy.begin(), copy.end());
    for(int i = 0; i < copy.length(); i++){
        if (copy[i] == '0'){
            copy.erase(copy.begin()+i);
            i--;
        }
    }
    cout << copy;
}