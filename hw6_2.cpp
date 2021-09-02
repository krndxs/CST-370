/*
 * Link to source code:  https://www.geeksforgeeks.org/iterative-depth-first-traversal/
 * Title: hw6_2.cpp
 * Write a C++ (or Java) program called hw6_2.cpp (or hw6_2.java) that implements the Depth-First Search (DFS) algorithm using a stack and a mark array as you learned in the class. 
 * Author: Karandeep Singh
 * ID: 2004
 * Date: 3/12/2021
 */
#include<iostream>
#include<algorithm>
#include<iomanip>
#include <list>
#include <vector>
#include <stack>
using namespace std;
void dfs(vector<pair<int, vector<int>>> &G, int vertex, int &count){
    count++;
    G.at(vertex).first = count;
    for(int i = 0; i < G.at(vertex).second.size(); i++){
        if(G.at(G.at(vertex).second.at(i)).first == 0){
            dfs(G, G.at(vertex).second.at(i), count);
        }
    }
}
void DFS(vector<pair<int, vector<int>>> &G){
    int count = 0;
    for(int i = 0; i < G.size(); i++){
        if(G.at(i).first == 0){
            dfs(G, i, count);
        }
    }
}
int main()
{
    int size, edges;
    vector<pair<int, vector<int>>> G;
    cin >> size;
    cin >> edges;
    G.reserve(size);
    for(int i = 0; i < size; i++){
        G.emplace_back(0, vector <int> ());
    }
    for(int i = 0; i < edges; i++){
        int index, edge;
        cin >> index;
        cin >> edge;
        G.at(index).second.push_back(edge);
    }
    DFS(G);
    for(int i = 0; i < G.size(); i++){
        cout << "Mark[" << i << "]:" <<  G.at(i).first << endl;
    }
    return 0;
}