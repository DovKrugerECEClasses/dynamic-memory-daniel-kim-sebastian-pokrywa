#include "String.hh"

String::String() {
	capacity = 1;
	len = 1;
	s = new char[1];
	s[0] = ' ';
}

String::String(const char str[]) {

}
	
String::String(const char str[], uint32_t mult) {

}

String::~String() {
	delete [] s;
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

	
