/*
 * Ray.cpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#include "Ray.hpp"

Ray::Ray() : origPoint(), directVec(), bounce(0){}

Ray::Ray(const Point3f& origin, const Vec3f& direction) : origPoint(origin), directVec(directVec), bounce(0) {}
