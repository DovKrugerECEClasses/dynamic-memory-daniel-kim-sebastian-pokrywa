#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>
#include <string>
using namespace std;

vector<int> buildVector(int a, int s, int b){
    vector<int> list;
    for(int i = a; i <= b; i+= s)
        list.push_back(i);
    return list;
}

void removeMultiples(vector<int> &list, int m){
    for(int i = 0; i < list.size(); i++){
        if(list[i] % m == 0)
           list.erase(list.begin() + i); 
    }
}

const void print(vector<int> list){
    for(int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    }
    cout << endl;
}

void load(map<string,double> &m, string filename){
    fstream f(filename);
    string line;

    while(getline(f, line)){
        istringstream iss(line);
        string stock;
        double price;
        iss >> stock >> price;
        if(price > 0)
            m.insert(pair<string,double>(stock, price));
    }
}

void load(unordered_map<string,double> &m, string filename){
    fstream f(filename);
    string line;

    while(getline(f, line)){
        istringstream iss(line);
        string stock;
        double price;
        iss >> stock >> price;
        if(price > 0)
            m.insert(pair<string,double>(stock, price));
    }
}




int main() {
	vector<int> list = buildVector(5, 10, 1000); // from 5 stepping by 10 to 1000
	removeMultiples(list, 3); // remove all numbers that are multiples of 3
	print(list);

	map<string,double> m;
	load(m, "stocks.dat"); // load the stock quotes into the map m
	// write code to print out the map.  Because it is a tree,
	// it will print in sorted order
    cout << "Ordered\n";
    cout << "Stock\tPrice" << endl;
    for(auto x:m)
        cout << x.first << '\t' << x.second << endl;

	cout << m["AAPL"] << '\n'; // O(log n)
	 
	unordered_map<string,double> hash;
	load(hash, "stocks.dat"); // load the stock quotes into the unordered_map hash
	// write code to print out the hashmap.  It will be in a random order because
	// hashmaps are not sorted (but they are faster for lookup).
    cout << "Unordered\n";
    cout << "Stock\tPrice" << endl;
    for(auto x:hash)
        cout << x.first << '\t' << x.second << endl;
	cout << hash["AAPL"] << '\n';
}