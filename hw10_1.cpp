/*
Title: hw10_1.cpp
Abstract: Write a C++ (or Java) program called hw10_1.cpp (or hw10_1.java) to conduct heap operations. 
Name: Karandeep Singh
ID: 2004
Date: 4/30/2021
Link to source code: https://www.tutorialspoint.com/cplusplus-program-to-implement-binary-heap
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class BHeap {
private:
    vector <int> heap;
    int l(int parent);
    int r(int parent);
    int par(int child);
    void heapifyup(int index);
    void heapifydown(int index);
public:
    BHeap() {}
    BHeap(const vector <int>& arr);
    void Insert(int element);
    void DeleteMax();
    int ExtractMax();
    void showHeap();
    int Size();
    void display();
    void displayMax();
    void deleteEl(int val);
    void update(int pos, int val);
};
int main() {
    int size;
    cin >> size;
    vector<int> arr;
    for (int i = 0; i < size; i++){
        int val;
        cin >> val;
        arr.push_back(val);
    }
    BHeap heap(arr);
    int inst;
    cin >> inst;
    for (int i = 0; i < inst; i++){
        string s;
        cin >> s;
        if (s == "display"){
            heap.display();
        } else if (s == "update"){
            int pos, val;
            cin >> pos >> val;
            heap.update(pos-1, val);
        } else if (s == "delete"){
            int val;
            cin >> val;
            heap.deleteEl(val);
        } else if (s == "deleteMax"){
            heap.DeleteMax();
        } else if (s == "insert"){
            int val;
            cin >> val;
            heap.Insert(val);
        } else if (s == "displayMax"){
            heap.displayMax();
        }
    }
    return 0;
}
BHeap::BHeap(const vector<int>& arr) {
    heap = arr;
    for (int i = arr.size()-1; i > 0 ; i-=2){
        this->heapifydown(par(i));
    }
    if (heap == arr){
        cout << "This is a heap.\n";
    } else {
        cout << "This is NOT a heap.\n";
    }
}
void BHeap::display(){
    for (int i = 0; i < heap.size(); i++){
        cout << heap.at(i) << " ";
    }
    cout << endl;
}
int BHeap::Size() {
    return heap.size();
}
void BHeap::Insert(int ele) {
    heap.push_back(ele);
    heapifyup(heap.size() -1);
}
void BHeap::DeleteMax() {
    if (heap.size() == 0) {
        cout<<"Heap is Empty"<<endl;
        return;
    }
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
}
int BHeap::ExtractMax() {
    if (heap.size() == 0) {
        return -1;
    }
    else
        return heap.front();
}
void BHeap::showHeap() {
    auto pos = heap.begin();
    cout<<"Heap --> ";
    while (pos != heap.end()) {
        cout<<*pos<<" ";
        pos++;
    }
    cout<<endl;
}
int BHeap::l(int parent) {
    int l = 2 * parent + 1;
    if (l < heap.size())
        return l;
    else
        return -1;
}
int BHeap::r(int parent) {
    int r = 2 * parent + 2;
    if (r < heap.size())
        return r;
    else
        return -1;
}
int BHeap::par(int child) {
    int p = (child - 1)/2;
    if (child == 0)
        return -1;
    else
        return p;
}
void BHeap::heapifyup(int in) {
    if (in >= 0 && par(in) >= 0 && heap[par(in)] < heap[in]) {
        int temp = heap[in];
        heap[in] = heap[par(in)];
        heap[par(in)] = temp;
        heapifyup(par(in));
    }
}
void BHeap::heapifydown(int in) {
    int child = l(in);
    int child1 = r(in);
    if (child >= 0 && child1 >= 0 && heap[child] < heap[child1]) {
        child = child1;
    }
    if (child > 0 && heap[in] < heap[child]) {
        int t = heap[in];
        heap[in] = heap[child];
        heap[child] = t;
        heapifydown(child);
    }
}
void BHeap::displayMax() {
    cout << ExtractMax() << endl;
}
void BHeap::deleteEl(int val) {
    int ind = find(heap.begin(), heap.end(), val) - heap.begin();
    if (ind >= 0){
        int temp = heap[heap.size()-1];
        heap[heap.size()-1] = heap[ind];
        heap[ind] = temp;
        heap.pop_back();
        heapifyup(ind);
        heapifydown(ind);
    }
}
void BHeap::update(int pos, int val) {
    heap[pos] = val;
    heapifyup(pos);
    heapifydown(pos);
}