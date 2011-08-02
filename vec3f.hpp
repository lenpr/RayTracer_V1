#ifndef VEC3F_HPP
#define VEC3F_HPP

#include <iostream>

using std::istream;
using std::ostream;

class Vec3f {
public:
    /* constructors and assignment operator */
    Vec3f();
    Vec3f(float x, float y, float z);
    Vec3f(const Vec3f& v);

    Vec3f& operator = (const Vec3f& v);

    /* getter for coordinates */
    float x() const { return xVal; }
    float y() const { return yVal; }
    float z() const { return zVal; }

    /* arithmetic functions */
    float length() const;

    void normalize();

    void flip();

    float dot(const Vec3f& b) const;

    const Vec3f cross(const Vec3f& b) const;

    /* stream reading/writing */
    friend istream& operator >> (istream& in, Vec3f& a) {
        in >> a.xVal >> a.yVal >> a.zVal;
        return in;
    }

    friend ostream& operator<< (ostream& out, const Vec3f& a) {
        out << "(" << a.x() << ", " << a.y() << ", " << a.z() << ")";
        return out;
    }

private:
    float xVal, yVal, zVal;

};


/* arithmetic functions on vectors */
inline const Vec3f operator + (const Vec3f& a, const Vec3f& b) {
    return Vec3f(a.x() + b.x(), a.y() + b.y(), a.z() + b.z());
}

inline const Vec3f operator - (const Vec3f& a, const Vec3f& b) {
    return Vec3f(a.x() - b.x(), a.y() - b.y(), a.z() - b.z());
}

inline const Vec3f operator * (const Vec3f& a, const float& s) {
    return Vec3f(a.x() * s, a.y() * s, a.z() * s);
}

inline const Vec3f operator * (const float& s, const Vec3f& a) {
    return Vec3f(a.x() * s, a.y() * s, a.z() * s);
}

inline bool operator == (const Vec3f& a, const Vec3f& b) {
    return (a.x() == b.x()) && (a.y() == b.y()) && (a.z() == b.z());
}

#endif // VEC3F_HPP
