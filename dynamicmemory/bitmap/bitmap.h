#pragma once
#include <iostream>
#include "color.h"

class Bitmap{
private:
	char *s;
	int row, col;
	
public:
	Bitmap(int col, int row) : row(row), col(col), s(new char[row * col]){
		for (int i = 0; i < row; i++){
			for (int j = 0; j < col; j++){
				s[(row*i)+col] = ' ';
			}
		}
	}
	void line(uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2, const Color& c1){
		double deltax = x2 - x1;
		double deltay = y2 - y1;
		double deltaerror = 0.0;

		if (deltay/deltax < 0){
			deltaerror = -(deltay/deltax);
		}
		else{
			deltaerror = deltay/deltax;
		}

		double error = 0.0;
		int y = y1;

		for (int i = x1; i<x2; i++){

			s[(col*i)+y] = c1.returnColor();

			error = deltaerror + error;
			if (error >= 0.5){
				if (deltay < 0){
					y = y - 1;
				}
				else{
					y = y + 1;
				}
				error = error - 1;
			}
		}
	}

	void horizLine(uint8_t x1, uint8_t x2, uint8_t y1 ,const Color& c1){
		for (int i = x1; i < x2; i++){
			s[(col*y1)+i] = c1.returnColor();
		}
	}

	void vertLine(uint8_t x1, uint8_t y1, uint8_t y2, const Color& c1){
		for (int i = y1; i < y2; i++){
			s[(col*i)+x1] = c1.returnColor();
		}
	}

	void fillRect(uint8_t x1, uint8_t y1, uint8_t width, uint8_t height,const Color& c1){
		for (int j = x1; j < x1+width; j++){
			for (int i = y1; i < y1 + height; i++){
				s[(col*i)+j] = c1.returnColor();
			}
		}

	}

	void drawRect(uint8_t x1, uint8_t y1, uint8_t width, uint8_t height, const Color& c1){
		for (int j = x1; j < x1+width; j++){
			for (int i = y1; i < y1 + height; i++){
				if (i == y1 || i == y1 + height - 1){
					s[(col*i)+j] = c1.returnColor();
				}
				else{
					if (j == x1 || j == x1 + width - 1){
						s[(col*i)+j] = c1.returnColor();
					}
				}
			}
		}
	}

	void ellipse(uint8_t x1, uint8_t y1, uint8_t width, uint8_t height, const Color& c1){
		
	}	

	friend std::ostream& operator << (std::ostream& o, const Bitmap& b) {
		for (int i = 0; i < b.row; i++){
			for (int j = 0; j < b.col; j++){
				o << b.s[(b.col * i) + j];
			}
			o << '\n';
		}
		return o;
	}
};