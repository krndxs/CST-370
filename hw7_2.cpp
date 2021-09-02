/*
 * Link to source code:  https://replit.com/@YBYUN/BFS
 * Title: hw7_2.cpp
 * Write a C++ (or Java) program named hw7_2.cpp (or hw7_2.java) that displays the city names in the range of hop(s) from a starting city. 
 * Author: Karandeep Singh
 * ID: 2004
 * Date: 3/26/2021
 */
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, bool>mark;
map<string, vector<string>> read_graph() {
    
    map<string, vector<string>> g;
    vector<string> temp_vertex;
    int v_size, e_size;
    cin >> v_size;
    
    string vertex;
    
    for (int i = 0; i < v_size; i++){
        cin >> vertex;
        temp_vertex.reserve(v_size);
        g.insert(make_pair(vertex, temp_vertex));
        mark.insert(make_pair(vertex, false));
    }
    
    cin >> e_size;
    string key, next_vertex;
    
    for (int i = 0; i < e_size; i++){
        cin >> key;
        cin >> next_vertex;
        g.at(key).push_back(next_vertex);
    }
    return g;
}

void print_graph(const map<string, vector<string>> &g) {
    for (auto& i : g)
    {
        cout << i.first;
        for (auto& j : i.second)
        {
            cout << " -> " << j;
        }
        cout << endl;
    }
}

void bfs(map<string, vector<string>> & g, const string& src, int path_limit)
{
    queue<string> q;
    q.push(src);
    mark.at(src) = true;
    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        bool flag = false;
        for (auto& neighbor : g.at(curr))
        {
            if(!mark.at(neighbor) && path_limit > 0)
            {
                mark.at(neighbor) = true;
                q.push(neighbor);
                flag = true;
            }
        }
        if(flag){
            path_limit--;
        }
    }
}

void print_mark_sorted(){
    vector<string> visited;
    for (auto& i : mark){
        if (i.second){
            visited.push_back(i.first);
        }
    }
    sort(visited.begin(), visited.end());
    for (auto& i : visited){
        cout << i << endl;
    }
}

int main()
{
    map<string, vector<string>> g = read_graph();

    int path_limit;
    string src;
    cin >> src >> path_limit;
    bfs(g, src, path_limit);
    print_mark_sorted();
    return 0;
}