/*
Title: hw11_2.cpp
Abstract:. Write a C++ (or Java) program called hw11_2.cpp (or hw11_2.java) to collect maximum number of coins on an n x m board which was covered in the class.
Name: Karandeep Singh
ID: 2004
Date: 5/10/2021
Link to source code: https://www.geeksforgeeks.org/find-whether-path-two-cells-matrix/
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Coordinates{
    int x;
    int y;
};

vector<Coordinates> backPath;

void printPath(){
    reverse(backPath.begin(), backPath.end());
    cout << "Path:";
    for (int i = 0; i < backPath.size(); i++){
        cout << "(" << backPath.at(i).x+1 << "," << backPath.at(i).y+1 << ")";
        if (i < backPath.size()-1){
            cout << "->";
        }
    }
}

void setBackPath(const vector<vector<int>>& coinMap){
    Coordinates current = backPath.at(backPath.size()-1);
    
    if (current.x == 0 && current.y == 0){
        return;
    } else if (current.x == 0 && current.y != 0){
        current.y--;
    } else if (current.x != 0 && current.y == 0){
        current.x--;
    } else {
        if (coinMap.at(current.y-1).at(current.x) > coinMap.at(current.y).at(current.x-1)){
            current.y--;
        } else {
            current.x--;
        }
    }
    backPath.push_back(current);
    setBackPath(coinMap);
}

int main() {
    
    int sizeRow, sizeCol;
    vector<vector<int>> coinMap;
    cin >> sizeRow >> sizeCol;
    for (int i = 0; i < sizeCol; i++){
        vector<int> row;
        for (int k = 0; k < sizeRow; k++){
            int num;
            cin >> num;
            row.push_back(num);
        }
        coinMap.push_back(row);
    }
    
    for (int i = 0; i < sizeCol; i++) {
        for (int k = 0; k < sizeRow; k++) {
            int indexUpper = i-1;
            int indexLeft = k-1;
            if ((indexLeft < 0 && indexUpper < 0) || coinMap.at(i).at(k) == -1){
                continue;
            } else if (indexLeft < 0) {
                coinMap.at(i).at(k) += coinMap.at(indexUpper).at(k);
            } else if (indexUpper < 0) {
                coinMap.at(i).at(k) += coinMap.at(i).at(indexLeft);
            } else {
                if (coinMap.at(indexUpper).at(k) > coinMap.at(i).at(indexLeft)){
                    coinMap.at(i).at(k) += coinMap.at(indexUpper).at(k);
                } else {
                    coinMap.at(i).at(k) += coinMap.at(i).at(indexLeft);
                }
            }
        }
    }
    
    Coordinates last{};
    last.x = sizeRow-1;
    last.y = sizeCol-1;
    backPath.push_back(last);
    setBackPath(coinMap);
    cout << "Max coins: " << coinMap.at(sizeCol-1).at(sizeRow-1) << endl;
    printPath();
    
}