/*
 * object.cpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#include "object.hpp"
#include <cmath>


std::pair<bool,Point3f> Sphere::intersect(const Ray& ray) const {
	Vec3f oc = center - ray.origin();
	float tca = (oc).dot(ray.direction());
	float thcSquared = powf(radius, 2) - powf(oc.length(), 2) + powf(tca, 2);

	if(thcSquared < 0.0f) {
		return std::pair<bool,Point3f>(false, Point3f());
	}
	else {
		float t1 = tca + sqrtf(thcSquared);
		float t2 = tca - sqrtf(thcSquared);

		Point3f p1 = ray.origin() + (ray.direction() * t1);
		Point3f p2 = ray.origin() + (ray.direction() * t2);

		float r1 = (center - p1).length();
		float r2 = (center - p2).length();

		if ( (radius - r1) > (radius - r2) )
			return std::pair<bool,Point3f>(false, p2);
		else
			return std::pair<bool,Point3f>(false, p1);
	}
}

Color Sphere::getColor(const Point3f& p) const {
	return material->getColor(p);
}


Vec3f Sphere::getNormal(const Point3f& p) const {
	return (p - center);
}
