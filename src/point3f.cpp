#include "point3f.hpp"

Point3f::Point3f() : xVal(0.0f), yVal(0.0f), zVal(0.0f), dataVal(0.0f), normalVec() {}

Point3f::Point3f(float x, float y, float z) : xVal(x), yVal(y), zVal(z), dataVal(0.0f), normalVec() {}

Point3f::Point3f(const Point3f& p) : xVal(p.x()), yVal(p.y()), zVal(p.z()), dataVal(0.0f), normalVec(p.normal()) {}

Point3f& Point3f::operator= (const Point3f& p) {
    xVal = p.x(); yVal = p.y(); zVal = p.z();
    normalVec = p.normal();
    return *this;
}
