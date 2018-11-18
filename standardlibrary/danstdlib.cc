#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <iterator>

using namespace std;

vector<int> buildVector(int start, int step, int end){
	vector<int> temp;
	for (int i = start; i < end; i = i + step){
		temp.push_back(i);
	}
	return temp;
}

const void print(vector<int> const temp){
	for (int i = 0; i <temp.size(); i++){
		cout<<temp[i]<<" , ";
	}
	cout<<'\n';
}

void removeMultiples(vector<int> &list, int multiple){
	for (int i = 0; i < list.size(); i++){
		if (list[i] % multiple == 0){
			list.erase(list.begin() + i);
		}	
	}
}

void printMap (map<string, double> m){
	map<string, double> :: iterator itr;

	for (itr = m.begin(); itr != m.end(); itr++){
		cout << "Key is " << itr -> first << " Value is " << itr -> second << '\n';
	}
}

int main() {
//	vector<int> list = buildVector(5, 10, 1000); // from 5 stepping by 10 to 1000
//	removeMultiples(list, 3); // remove all numbers that are multiples of 3
//	print(list);
	double n;
	string stock;

	ifstream f("2f.dat");
	f >> n;

	map<string,double> m;

	load(m, "stocks.dat"); // load the stock quotes into the map m
	// write code to print out the map.  Because it is a tree,
	// it will print in sorted order
	printMap(m);

//	cout << m["AAPL"] << '\n'; // O(log n)
	 
//	unordered_map<string,double> hash;
//	load(hash, "stocks.dat"); // load the stock quotes into the unordered_map hash
	// write code to print out the hashmap.  It will be in a random order because
	// hashmaps are not sorted (but they are faster for lookup).
//	cout << hash["AAPL"] << '\n';
}
