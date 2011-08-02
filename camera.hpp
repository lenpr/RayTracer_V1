/*
 * camera.hpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "point3f.hpp"
#include "ray.hpp"
#include <vector>

typedef std::vector<std::vector<Ray> > RayGrid;

class CameraGrid {

public:
	CameraGrid(const Point3f& upperLeft, const Point3f& lowerRight, unsigned int resWidth, unsigned int resHeight) : grid() {
		// TODO
	}

private:
	std::vector<std::vector<Point3f> > grid;
};


class Camera {
public:
	Camera(const Point3f& eye, const Point3f& upperLeft, const Point3f& lowerRight, unsigned int resWidth, unsigned int resHeight);

	RayGrid createPrimaryRay();

private:
	Point3f eye;
	CameraGrid imagePlane;
};

#endif /* CAMERA_HPP_ */
