#include "color.h"

Color::Color(uint8_t r, uint8_t g, uint8_t b) {
	rgba = (r << 16) + (g << 8) + b;
	}


char Color::returnColor() const{
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
