/*
 * light.hpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "object.hpp"
#include "color.hpp"
#include "point3f.hpp"
#include "vec3f.hpp"

// Standard point light
class Light : Object{
public:
	Light();

	std::pair<bool,Point3f> intersect(const Ray& ray) const { return std::pair<bool,Point3f>(); }

	Color getColor(const Point3f& p) const { return Color(); }
	Vec3f getNormal(const Point3f& p) const { return Vec3f(); }
};

#endif /* LIGHT_HPP_ */
