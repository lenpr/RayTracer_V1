/*
 * scene.cpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#include "scene.hpp"
#include  <algorithm>

bool isLight (const Object& obj) { return obj.isLightSource(); }

Scene::Scene(const std::vector<Object>& objects) : objects(), lights() {

	std::copy(objects.begin(), objects.end(), this->objects.begin());

	std::remove_copy_if(objects.begin(), objects.end(), this->objects.begin(), isLight);
}
