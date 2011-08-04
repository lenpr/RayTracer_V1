/*
 * camera.cpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#include "camera.hpp"
#include <vector>
#include <cmath>


CameraGrid::CameraGrid(const Point3f& upperLeft, const Point3f& lowerRight, unsigned int resWidth, unsigned int resHeight) : grid(resWidth) {

	// TODO: check ul.z == lr.z

	float x = upperLeft.x();
	float y = upperLeft.y();
	float z = upperLeft.z();

	float lengthX = fabs(lowerRight.x() - x);
	float deltaX = lengthX/resWidth;

	float lengthY = fabs(lowerRight.y() - y);
	float deltaY = lengthY / resWidth;

	for (unsigned int i = 0; i < resWidth; i++) {
		grid[i].resize(resHeight);

		for (unsigned int j = 0; j < resHeight; j++) {
			grid[i][j] = Point3f(x + i*deltaX, y + j*deltaY, z);
		}
	}
}


Camera::Camera(const Point3f& eye, const Point3f& upperLeft, const Point3f& lowerRight, unsigned int resWidth, unsigned int resHeight)
 : eye(eye), imagePlane(upperLeft, lowerRight, resWidth, resHeight) {}


RayGrid Camera::createPrimaryRay() {

	std::vector<std::vector<Ray> > rayGrid(imagePlane.width());

	for(int i = 0; i < imagePlane.width(); i++) {
		rayGrid[i].resize(imagePlane.height());

		for(int j = 0; j < imagePlane.height(); j++) {
			Vec3f direction = imagePlane.at(i,j) - eye;
			rayGrid[i][j] = Ray(eye, direction);
		}
	}

	return rayGrid;
}
