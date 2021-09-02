/*
 * Link to source code:  https://www.geeksforgeeks.org/heaps-algorithm-for-generating-permutations/
 * Title: hw5_2.cpp
 * Write a C++ (or Java) program called hw5_2.cpp or (hw5_2.java) that reads an input graph data from a user. 
   Then, it should present a path for the travelling salesman problem (TSP). 
   In the assignment, you can assume that the maximum number of vertices in the input graph is less than or equal to 20. 

 * Author: Karandeep Singh
 * ID: 2004
 * Date: 3/5/2021
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int vertices, edges;

vector<int> populate(int vertices, bool all_same = true, int offset = 0, int num = -1, bool str = false){
    vector<int> v;
    v.reserve(vertices);
    for (int i = 0; i < vertices; i++){
        if (all_same){
            v.push_back(num);
        } else {
            v.push_back(i+offset);
        }
    }
    return v;
}

vector<string> populate_str(int vertices, const string& str){
    vector<string> v;
    v.reserve(vertices);
    for (int i = 0; i < vertices; i++){
        v.push_back(str);
    }
    return v;
}

vector<string> retrieve_map_keys(const unordered_map<string, int>& map_with_keys){
    vector<string> v = populate_str(map_with_keys.size(), "j");

    for (auto& p : map_with_keys){
        v.at(p.second) = p.first;
    }
    return v;
}

int main()
{
    vector<vector<int>> perm;
    unordered_map<int, vector<int>> matrix;
    unordered_map<string, int> index_map;
    cin >> vertices;
    
    for (int i = 0; i < vertices; i++){
        string cityName;
        cin >> cityName;
        matrix.insert(make_pair(i, populate(vertices)));
        index_map.insert(make_pair(cityName, i));
    }
    
    cin >> edges;
    for (int i = 0; i < edges; i++){
        string from, to;
        int val, index_to_write;
        cin >> from >> to >> val;
        index_to_write = index_map.at(to);
        matrix.at(index_map.at(from)).at(index_to_write) = val;
    }
    
    vector<int> vertices_indexes = populate(vertices-1, false, 1);
    
    do {
        perm.push_back(vertices_indexes);
    } while (next_permutation(vertices_indexes.begin(), vertices_indexes.end()));

    int best_path_val = -1;
    vector<int> best_perm;
    
    for(auto & i: perm){
        int cur_path_val = -1;
        for (int k = 0; k < i.size()+1; k++){
            int num, f, t;
            if(k == i.size()){
                f = i.at(k-1);
                t = 0;
            }else if(k == 0) {
                f = k;
                t = i.at(k);
            }else{
                f = i.at(k-1);
                t = i.at(k);
            }
            num = matrix.at(f).at(t);
            if (num > 0){
                if (cur_path_val == -1) {
                    cur_path_val = 0;
                }
                cur_path_val += num;
            }else{
                cur_path_val = -1;
                break;
            }
        }
        if (best_path_val == -1 || (best_path_val > cur_path_val && cur_path_val > 0)){
            best_path_val = cur_path_val;
            best_perm = i;
        }

    }

    vector<string> vertices_str = retrieve_map_keys(index_map);

    cout << "Path:";
    if (best_path_val > 0){
        cout << vertices_str.at(0) << "->";
        for (auto& i : best_perm){
            cout << vertices_str.at(i) << "->";
        }
        cout << vertices_str.at(0);
    }
    
    cout << endl << "Cost:"<< best_path_val << endl;
}