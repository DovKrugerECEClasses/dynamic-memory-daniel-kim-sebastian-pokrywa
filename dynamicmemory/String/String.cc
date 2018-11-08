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

uint32_t String::length(){
	return len;
}
	//copy constructor
String::String(const String& orig) {

}
String& String::operator =(const String& orig) {

}

char String::operator [](const uint32_t pos)const {

}
char& String::operator [](uint32_t pos) {

}

std::ostream& operator<<(std::ostream& stream, const String& str) {
	for(int i = 0; i < str.len; i++)
		stream << str.s[i];
	return stream;
}

	
