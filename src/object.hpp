/*
 * object.hpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "material.hpp"
#include "ray.hpp"
#include "color.hpp"
#include "point3f.hpp"
#include "vec3f.hpp"

class Object {
public:
	//Object() : material(NULL), velocity(), isLight(false) {}
	Object(Material* material) : material(material), velocity(), isLight(false) {}
	Object(Material* material, const Vec3f& velocity) : material(material), velocity(velocity), isLight(false) {}
	Object(Material* material, const Vec3f& velocity, bool isLightSource) :
		material(material), velocity(velocity), isLight(isLightSource) {}

	bool isLightSource() const { return isLight; }

	virtual std::pair<bool,Point3f> intersect(const Ray& ray) const = 0;

	virtual Color getColor(const Point3f& p) const = 0;
	virtual Vec3f getNormal(const Point3f& p) const = 0;

private:
	Material* material;
	Vec3f velocity;
	bool isLight;
};

#endif /* OBJECT_HPP_ */
