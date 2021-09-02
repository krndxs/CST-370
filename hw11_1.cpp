/*
Title: hw11_1.cpp
Abstract:. Write a C++ (or Java) program called hw11_1.cpp (or hw11_1.java) to simulate the operations of linear probing covered in the class. 
Name: Karandeep Singh
ID: 2004
Date: 5/10/2021
Link to source code: https://www.geeksforgeeks.org/implementing-hash-table-open-addressing-linear-probing-cpp/
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
class HashNode{
    
public:
    HashNode();
    HashNode(int value, string word);
    int getValue();
    string getWord();
    void setValue(int value);
    void setWord(string word);
private:
    int value;
    string word;
};

HashNode::HashNode() {
    *this = HashNode(0, "Empty");
}

HashNode::HashNode(int value, string word) {
    this->value = value;
    this->word = word;
}

int HashNode::getValue() {
    return value;
}

string HashNode::getWord() {
    return word;
}

void HashNode::setValue(int value) {
    this->value = value;
}

void HashNode::setWord(string word) {
    this->word = word;
}

class HashMap {
    
public:
    HashMap();
    HashMap(int capacity);
    bool search(int value);
    void displayStatus(int index);
    int getCapacity();
    int hashCode(int value);
    void reHashTheHashTable();
    void insertNode(int value);
    void deleteNode(int value);
    int get(int value);
    int sizeofMap();
    bool isEmpty();
    void display();
private:
    int capacity;
    int size;
    vector<HashNode> hashArr;
    
};

HashMap::HashMap() {
    *this = HashMap(11);
}

HashMap::HashMap(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    hashArr = vector<HashNode>();
    for (int i = 0; i < capacity; i++){
        hashArr.emplace_back();
    }
}

bool HashMap::search(int value) {
    if (hashArr.at(hashCode(value)).getValue() == value){
        return true;
    } else {
        int index = hashCode(value);
        for (int counter = 0; counter < capacity; counter++){
            if (hashArr.at(index%capacity).getWord() == "Active" && hashArr.at(index%capacity).getValue() == value){
                return true;
            }
            index++;
        }
    }
    return false;
}

void HashMap::displayStatus(int index) {
    if (hashArr.at(index).getWord() == "Empty"){
        cout << "Empty\n";
        return;
    }
    cout << hashArr.at(index).getValue() << " " << hashArr.at(index).getWord() << endl;
}

int HashMap::getCapacity() {
    return capacity;
}

int HashMap::hashCode(int value) {
    return value%capacity;
}

void HashMap::reHashTheHashTable() {
    int newCapacity = capacity*2;
    while (!isPrime(newCapacity)){
        newCapacity++;
    }
    HashMap newHashMap(newCapacity);
    for (int i = 0; i < capacity; i++){
        if (hashArr.at(i).getWord() == "Active"){
            newHashMap.insertNode(hashArr.at(i).getValue());
            hashArr.at(i).setWord("Deleted");
        }
    }
    *this = newHashMap;
}

void HashMap::insertNode(int value) {
    size++;
    if (size/(double)capacity > 0.5){
        reHashTheHashTable();
    }
    int index = hashCode(value);
    if (hashArr.at(index).getWord() == "Active"){
        for (int counter = 0; counter < capacity; counter++){
            if (hashArr.at(index%capacity).getWord() != "Active"){
                hashArr.at(index%capacity) = HashNode(value, "Active");
                break;
            }
            index++;
        }
    } else {
        hashArr.at(index) = HashNode(value, "Active");
    }
}

void HashMap::deleteNode(int value) {
    if (!isEmpty()){
        if (hashArr.at(hashCode(value)).getWord() == "Active" && hashArr.at(hashCode(value)).getValue() == value){
            hashArr.at(hashCode(value)).setWord("Deleted");
        } else {
            int index = hashCode(value);
            for (int counter = 0; counter < capacity; counter++){
                if (hashArr.at(index%capacity).getWord() == "Active" && hashArr.at(index%capacity).getValue() == value){
                    hashArr.at(index%capacity).setWord("Deleted");
                    break;
                }
                index++;
            }
        }
        size--;
    }
}

int HashMap::sizeofMap() {
    return size;
}

bool HashMap::isEmpty() {
    return size==0;
}

void HashMap::display() {
    for (auto i : hashArr){
        cout << i.getValue() << " " << i.getWord() << endl;
    }
}

int main(){
    int size, commands;
    cin >> size >> commands;
    HashMap h(size);
    for (int i = 0; i < commands; i++){
        string s;
        int val;
        cin >> s;
        if (s == "insert"){
            cin >> val;
            h.insertNode(val);
        } else if (s == "displayStatus"){
            cin >> val;
            h.displayStatus(val);
        } else if (s == "tableSize"){
            cout << h.getCapacity() << endl;
        } else if (s == "search"){
            cin >> val;
            cout << val << " " << ((h.search(val)) ? ("Found\n") : ("Not found\n"));
        } else if (s == "delete"){
            cin >> val;
            h.deleteNode(val);
        } else if (s == "display"){
            h.display();
        }
    }
}