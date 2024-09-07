#ifndef VEC_H_
#define VEC_H_

#include <cmath>

namespace Vectors {

template <class T>
class vec3;

template <class T> T Dot(const vec3<T>& vec1, const vec3<T>& vec2);
template <class T> T Len(const vec3<T>& vec);
template <class T> vec3<T> Norm(const vec3<T>& vec);

template <class T>
class vec3 {
public:
    union { T x, r; };
    union { T y, g; };
    union { T z, b; };

    vec3(T x = T(),
         T y = T(),
         T z = T());

    vec3<T>& operator=(const vec3<T>& other);

    vec3<T>  operator+(const vec3<T>& other) const;
    vec3<T>  operator-(const vec3<T>& other) const;
    vec3<T>  operator*(const vec3<T>& other) const;
    vec3<T>  operator*(const T&      scalar) const;
    vec3<T>  operator/(const T&      scalar) const;

    friend T Len <T>(const vec3<T>& vec);
    friend T Dot <T>(const vec3<T>& vec1,
                     const vec3<T>& vec2);

    friend vec3<T> Norm<T>(const vec3<T>& vec);
};

template <class T>
vec3<T>::vec3(T new_x, T new_y, T new_z)
    : x(new_x),
      y(new_y),
      z(new_z) {}

template <class T>
vec3<T> vec3<T>::operator+(const vec3<T>& other) const {
    return vec3<T>(x + other.x,
                   y + other.y,
                   z + other.z);
}

template <class T>
vec3<T> vec3<T>::operator-(const vec3<T>& other) const {
    return vec3<T>(x - other.x,
                   y - other.y,
                   z - other.z);
}

template <class T>
vec3<T>& vec3<T>::operator=(const vec3<T>& other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return *this;
}

template <class T>
vec3<T> vec3<T>::operator*(const T& scalar) const {
    return vec3<T>(x * scalar,
                   y * scalar,
                   z * scalar);
}

template <class T>
vec3<T> vec3<T>::operator*(const vec3<T>& other) const {
    return vec3<T>(x * other.x,
                   y * other.y,
                   z * other.z);
}

template <class T>
vec3<T> vec3<T>::operator/(const T& scalar) const {
    return vec3<T>(x / scalar,
                   y / scalar,
                   z / scalar);
}

template <class T>
T Dot(const vec3<T>& vec1, const vec3<T>& vec2) {
    return vec1.x * vec2.x +
           vec1.y * vec2.y +
           vec1.z * vec2.z;
}

template <class T>
vec3<T> Norm(const vec3<T>& vec) {
    return vec / Len(vec); 
}

template <class T>
T Len(const vec3<T>& vec) {
    return std::sqrt(vec.x * vec.x + 
                     vec.y * vec.y +
                     vec.z * vec.z);
}

}; // namespace Vectors

#endif // VEC_H_
