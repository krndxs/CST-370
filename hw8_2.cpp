/*
* Link to source code:  https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
* Title: hw8_2.cpp
* Write a C++ (or Java) program called hw8_2.cpp (or hw8_2.java) that conducts the topological sorting based on the Kahn’s algorithm covered in the class. 
* Author: Karandeep Singh
* ID: 2004
* Date: 4/9/2021
*/

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
    
public:
    Graph(int V);
    void addEdge(int u, int v);
    void topologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::topologicalSort(){
    
    vector<int> in_degree(V, 0);
    
    for (int u = 0; u < V; u++) {
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) {
            in_degree[*itr]++;
        }
    }
    
    for (int i = 0; i < in_degree.size(); i++){
        cout << "In-degree[" << i << "]:" << in_degree.at(i) << endl;
    }
    
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0){
            q.push(i);
        }
    int cnt = 0;
    
    vector<int> top_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) {
            if (--in_degree[*itr] == 0) {
                q.push(*itr);
            }
        }
        cnt++;
    }
    
    if (cnt != V) {
        cout << "No Order:\n";
        return;
    }
    
    cout << "Order:";
    for (int i = 0; i < top_order.size(); i++) {
        if (i > 0){
            cout << "->";
        }
        cout << top_order[i];
    }
    
    cout << endl;
}

int main(){
    int vert, edge;
    cin >> vert >> edge;
    Graph g(vert);
    for (int i = 0; i < edge; i++){
        int from, to;
        cin >> from >> to;
        g.addEdge(from, to);
    }
    g.topologicalSort();
    return 0;
}