#include "String.hh"

String::String() {
	capacity = 1;
	len = 1;
	s = new char[1];
	s[0] = ' ';
}

String::String(const char str[]) {
	int size = stringlen(str);
	s = new char[size];
	len = size;
	capacity = size;
	for(int i = 0; i < size; i++)
		s[i] = str[i];
}
	
String::String(const char str[], uint32_t mult) {
	int size = stringlen(str) * mult;
	s = new char[size];
	len = size;
	capacity = size;
	int i = 0;
	while( i < size){
		for(int j = 0; j < stringlen(str); j++)
			s[i++] = str[j];
	}
}

String::~String() {
	delete [] s;
}

uint32_t String::length() const{
	return len;
}
	//copy constructor
String::String(const String& orig) {
	s = new char[orig.length()];
	for(int i = 0; i < orig.length(); i++){
		s[i] = orig[i];
	}
	capacity = orig.length();
	len = orig.length();
}

//operator functions
String& String::operator =(const String& orig) {
	char* temp = new char[orig.length()];

	for(int i = 0; i < orig.length(); i++)	
		temp[i] = orig[i];

	s = new char[orig.length()];
	for(int i = 0; i < orig.length(); i++)	
		s[i] = temp[i];

	capacity = orig.length();
	len = orig.length();

	delete [] temp;
	return *this;
}

String& String::operator +=(const String& right) {
	int size = right.length() + length();
	char* temp = new char[size];

	int i;
	for(i = 0; i < length(); i++)
		temp[i] = s[i];
	for(int j = 0; j < right.length(); j++)
		temp[i + j] = right[j];
	
	s = new char[size];
	len = size;
	capacity = size;

	for(i = 0; i < length(); i++)
		s[i] = temp[i];

	delete [] temp;

	return *this; 
}
String String::operator +(const String& right) {
	int size = right.length() + length();
	char* temp = new char[size];

	int i;
	for(i = 0; i < length(); i++)
		temp[i] = s[i];
	for(int j = 0; j < right.length(); j++)
		temp[i + j] = right[j];

	return String(temp);
}
char String::operator [](const uint32_t pos)const {
	return s[pos];
}
char& String::operator [](uint32_t pos) {
	return s[pos];
}

std::ostream& operator<<(std::ostream& stream, const String& str) {
	for(int i = 0; i < str.len; i++)
		stream << str.s[i];
	return stream;
}

	
