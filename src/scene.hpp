/*
 * scene.hpp
 *
 *  Created on: 02.08.2011
 *      Author: LENPR
 */

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "camera.hpp"
#include "object.hpp"
#include <vector>


class Scene {
public:
	Scene(const std::vector<Object>& objects);

private:
	std::vector<Object> objects;
	std::vector<Object> lights;
};

#endif /* SCENE_HPP_ */
