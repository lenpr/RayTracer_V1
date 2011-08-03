#include "vec3f.hpp"
#include <cmath>

Vec3f::Vec3f() : xVal(0.0f), yVal(0.0f), zVal(0.0f) {}

Vec3f::Vec3f(float x, float y, float z) : xVal(x), yVal(y), zVal(z) {}

Vec3f::Vec3f(const Vec3f& v) : xVal(v.x()), yVal(v.y()), zVal(v.z()) {}

Vec3f& Vec3f::operator = (const Vec3f& v) {
    xVal = v.x(); yVal = v.y(); zVal = v.z();
    return *this;
}

float Vec3f::length() const {
    return sqrtf(xVal*xVal + yVal*yVal + zVal*zVal);
}

void Vec3f::normalize() {
    float l = length();
    if(l != 0.0f) {
        l = 1.0f / length();
        xVal *= l; yVal *= l; zVal *= l;
    }
}

void Vec3f::flip() {
    xVal *= -1.0f; yVal *= -1.0f; zVal *= -1.0f;
}

float Vec3f::dot(const Vec3f& b) const {
    return xVal*b.x() + yVal*b.y() + zVal*b.z();
}

const Vec3f Vec3f::cross(const Vec3f& b) const {
    return Vec3f( yVal*b.z() - zVal*b.y(), zVal*b.x() - xVal*b.z(), xVal*b.y() - yVal*b.x() );
}
