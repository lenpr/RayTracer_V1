/*
 * material.hpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

#include "point3f.hpp"
#include "color.hpp"

class Material {
public:
	// pure virtual function, needs to be implemented by every subclass
	virtual Color getColor(const Point3f& p) = 0;

	virtual float specularity(const Point3f& p) = 0;

	virtual float refraction(const Point3f& p) = 0;

	virtual float opacity(const Point3f& p) = 0;
};

//class GenericMaterial : Material {
//public:
//	Color getColor(const Point3f& p) { return Color(); }
//	float specularity(const Point3f& p) { return 0.0f; }
//	float refraction(const Point3f& p) { return 0.0f; }
//	float opacity(const Point3f& p) { return 0.0f; }
//};

#endif /* MATERIAL_HPP_ */
