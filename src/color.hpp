/*
 * color.hpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#ifndef COLOR_HPP_
#define COLOR_HPP_

class Color {
public:
	Color() : rVal(0.0f), gVal(0.0f), bVal(0.0f) {}
	Color(float r, float g, float b) : rVal(r), gVal(g), bVal(b) {}

	float r() const { return rVal; }
	float g() const { return gVal; }
	float b() const { return bVal; }

private:
	float rVal;
	float gVal;
	float bVal;
};

#endif /* COLOR_HPP_ */
