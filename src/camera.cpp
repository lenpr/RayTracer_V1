/*
 * camera.cpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#include "camera.hpp"
#include <vector>

Camera::Camera(const Point3f& eye, const Point3f& upperLeft, const Point3f& lowerRight, unsigned int resWidth, unsigned int resHeight)
 : eye(eye), imagePlane(upperLeft, lowerRight, resWidth, resHeight) {}


RayGrid Camera::createPrimaryRay() {
	// TODO
	return std::vector<std::vector<Ray> >();
}
