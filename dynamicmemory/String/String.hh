#pragma once
#include <cstdint>
#include <iostream>

class String {
private:
	uint32_t capacity;
	uint32_t len;
	char* s;
	uint32_t stringlen(const char* str) {
		uint32_t count = 0;
		while (*str++ != '\0')
			count++;
		return count;
	}
public:
  String();
	String(const char str[]);
	
	String(const char str[], uint32_t mult);
	~String();

	//utility functions
	uint32_t length() const;
	void replace(char a, char b);
	void insert(uint32_t pos, String msg);
	String substring(uint32_t pos, uint32_t length);
	
	//copy constructor
	String(const String& orig);

	//operators
	String& operator =(const String& orig);
	char  operator [](const uint32_t pos)const;
  char& operator [](uint32_t pos);
	String& operator +=(const String& right);
	String operator +(const String& right)const;

  friend std::ostream& operator<<(std::ostream& stream, const String& str);
};
