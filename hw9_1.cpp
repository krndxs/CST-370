/* Title: hw9_1.cpp
* Abstract: Write a C++ (or Java) program called hw9_1.cpp (or hw9_1.java) that connects several connected components of a graph with minimum number of edges to create a single connected component of the graph.
* Link to source code: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
* Author: Karandeep Singh
* ID: 2004
* Date: 4/20/2021
*/
#include <map>
#include <list>
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
    int V;    // No. of vertices
    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;
public:
    Graph(int V);  // Constructor
    // function to add an edge to graph
    void addEdge(int v, int w);
    // prints BFS traversal from a given source s
    vector <bool> BFS(int s);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v's list.
}
vector <bool> Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    vector <bool> visited;
    visited.reserve(V);
    for(int i = 0; i < V; i++)
        visited.push_back(false);
    // Create a queue for BFS
    list<int> queue;
    // Mark the current node as visited and enqueue it
    visited.at(s) = true;
    queue.push_back(s);
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
//        cout << s << " ";
        queue.pop_front();
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited.at(*i))
            {
                visited.at(*i) = true;
                queue.push_back(*i);
            }
        }
    }
    return visited;
}
int findNotVisited(vector<bool> visited){
    for (int i = 0; i < visited.size(); i++){
        if (visited.at(i) == 0){
            return i;
        }
    }
    return -1;
}
vector<bool> merge(vector<bool> visited1, vector<bool> visited2){
    for (int i = 0; i < visited1.size(); i++){
        if (visited1.at(i) || visited2.at(i)){
            visited1.at(i) = true;
        }
    }
    return visited1;
}
int main(){
    int size, edges;
    cin >> size;
    Graph g(size);
    cin >> edges;
    for(int i = 0; i < edges; i++){
        int start, end;
        cin >> start >> end;
        g.addEdge(start, end);
    }
    vector<int> starting;
    starting.push_back(0);
    vector <bool> visited = g.BFS(0);
//    for(auto i: visited){
//        cout << i << endl;
//    }
    while(true){
        int next = findNotVisited(visited);
        if (next > 0){
            starting.push_back(next);
            visited = merge(visited, g.BFS(next));
        } else {
            break;
        }
    }
    if (starting.size() < 2) {
        cout << "No new edge:\n";
    } else {
        for(int i = 0; i < starting.size()-1; i++){
            cout << "Edge: " << starting.at(i) << "-" << starting.at(i+1) << endl;
        }
    }
}