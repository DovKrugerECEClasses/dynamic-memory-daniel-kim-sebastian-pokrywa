#include <iostream>
using namespace std;


template<typename T>
void sort(T a [], int size){
	int i,j;
	for(i = 0; i < size-1; i++){
		for(j=0; j < size-i-1; j++){
			if(a[j] > a[j+1])
				swap(a[j], a[j+1]);
		}
	}
}

template<typename T>
const void print(T a [], int size){
	for(int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

template<typename T>
const T sum(T a [], int size){
	T sum = 0;
	for(int i = 0; i < size; i++)
		sum += a[i];
	return sum;
}

int main() {
	int a[] = {5, 4, 3, 1, 7, 8, 9, 2, 1};
	sort(a, sizeof(a)/sizeof(int));
	print(a, sizeof(a)/sizeof(int));
	
	double b[] = {5.5, 4.5, 1.2, 2.9, 9.2, 5.2};
	sort(b, sizeof(b)/sizeof(double));
	print(b, sizeof(b)/sizeof(double));

	cout << sum(a, sizeof(a)/sizeof(int)) << '\n';
	cout << sum(b, sizeof(b)/sizeof(double)) << '\n';

	string c[] = {"yo", "ho", "test", "foo", "bar"};
	sort(c, sizeof(c)/sizeof(string));
	print(c, sizeof(c)/sizeof(string));
	//TODO?	cout << sum(c, sizeof(c)/sizeof(string)) << '\n';
}
