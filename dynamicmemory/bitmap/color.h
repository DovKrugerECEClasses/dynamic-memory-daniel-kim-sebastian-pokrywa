#include <stdint.h>
#pragma once

class Color {
private:
	uint32_t rgba;
public:

Color(uint8_t r, uint8_t g, uint8_t b);

char returnColor() const;
};


/*
//Black, Green, Blue, Red, White
Color(uint8_t r, uint8_t g, uint8_t b) {
	rgba = (r << 16) + (g << 8) + b;
	}

char returnColor() const{
	if (rgba == 0xFF0000){
		return 'r';
	}
	else if (rgba == 0x00FF00) {
		return 'g';
	}
	else if (rgba == 0x0000FF) {
		return 'b';
	}
	else{
		return 'B';
	}
}

};
*/
