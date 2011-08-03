#ifndef POINT3F_HPP
#define POINT3F_HPP

#include <iostream>
#include "vec3f.hpp"

using std::istream;
using std::ostream;

class Point3f {

public:
    /* constructors and assignment operator*/
    Point3f();
    Point3f(float x, float y, float z);
    Point3f(const Point3f& p);

    Point3f& operator= (const Point3f& p);

    /* getter and setter for private members */
    float x() const { return xVal; }
    float y() const { return yVal; }
    float z() const { return zVal; }

    float data() const { return dataVal; }
    void setData(float data) { dataVal = data; }

    Vec3f normal() const { return normalVec; }
    void setNormal(const Vec3f& normal) { normalVec = normal; }

    const Point3f operator - (void) const {
        return Point3f( -x(), -y(), -z() );
    }

    /* reading and writing from/to streams */
    friend ostream& operator<< (ostream& out, const Point3f& p) {
        out << "(" << p.xVal << ", " << p.yVal << ", " << p.zVal << ")";
        return out;
    }

    friend istream& operator>> (istream& in, Point3f& p) {
        in >> p.xVal >> p.yVal >> p.zVal;
        return in;
    }

private:
    float xVal, yVal, zVal;

    /* field to store additional data for a point, e.g. the distance to
     * a reference point when performing k nearest neighbor search */
    float dataVal;

    Vec3f normalVec;
};

/* arithmetic functions */
inline const Vec3f operator - (const Point3f& v1, const Point3f& v2) {
    return Vec3f( v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z() );
}

inline const Point3f operator + (const Point3f& p, const Vec3f& v) {
    return Point3f(p.x() + v.x(), p.y() + v.y(), p.z() + v.z());
}

inline const Point3f operator - (const Point3f& p, const Vec3f& v) {
    return Point3f(p.x() - v.x(), p.y() - v.y(), p.z() - v.z());
}

inline bool operator == ( const Point3f& v1, const Point3f& v2 ) {
    return v1.x() == v2.x() && v1.y() == v2.y() && v1.z() == v2.z();
}

inline bool operator != ( const Point3f& v1, const Point3f& v2 ) {
    return v1.x() != v2.x() || v1.y() != v2.y() || v1.z() != v2.z();
}

#endif // POINT3F_HPP
