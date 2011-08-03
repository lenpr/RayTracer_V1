/*
 * Ray.hpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#ifndef RAY_HPP_
#define RAY_HPP_

#include "point3f.hpp"
#include "vec3f.hpp"

class Ray {
public:
	Ray();
	Ray(const Point3f& origin, const Vec3f& direction);

	Point3f origin() const { return origPoint; }
	Vec3f direction() const { return directVec; }

private:
	Point3f origPoint;
	Vec3f directVec;
	unsigned int bounce;
};

#endif /* RAY_HPP_ */
