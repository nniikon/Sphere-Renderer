#ifndef TGP_VECTORS_H_
#define TGP_VECTORS_H_

#include <cmath>

// TODO: figure it out
// There's a solution with vec<type, N>
// vec2_base<type>
// vec3_base>type>
// vec2 : std::conditional(N == 2, vec2_base, vec3_base)

namespace TGP {

// VEC2

template <class T>
class vec2;

template <class T> T Dot(const vec2<T>& lhs, const vec2<T>& rhs);
template <class T> T Len(const vec2<T>& vec);
template <class T> vec2<T> Norm(const vec2<T>& vec);
template <class T> vec2<T> operator+(const vec2<T>& lhs, const vec2<T>& rhs);
template <class T> vec2<T> operator-(const vec2<T>& lhs, const vec2<T>& rhs);
template <class T> vec2<T> operator*(const vec2<T>& lhs, const vec2<T>& rhs);
template <class T> vec2<T> operator*(const vec2<T>& lhs, const T& scalar);
template <class T> vec2<T> operator/(const vec2<T>& lhs, const T& scalar);

template <class T>
class vec2 {
public:
    union { T x, r; };
    union { T y, g; };

    vec2(T x = T(), T y = T());
    vec2<T>& operator=(const vec2<T>& other) = default;
};

// VEC3

template <class T>
class vec3;

template <class T> T Dot(const vec3<T>& lhs, const vec3<T>& rhs);
template <class T> T Len(const vec3<T>& vec);
template <class T> vec3<T> Norm(const vec3<T>& vec);
template <class T> vec3<T> operator+(const vec3<T>& lhs, const vec3<T>& rhs);
template <class T> vec3<T> operator-(const vec3<T>& lhs, const vec3<T>& rhs);
template <class T> vec3<T> operator*(const vec3<T>& lhs, const vec3<T>& rhs);
template <class T> vec3<T> operator*(const vec3<T>& lhs, const T& scalar);
template <class T> vec3<T> operator/(const vec3<T>& lhs, const T& scalar);

template <class T>
class vec3 {
public:
    union { T x, r; };
    union { T y, g; };
    union { T z, b; };

    vec3(T x = T(), T y = T(), T z = T());
    vec3<T>& operator=(const vec3<T>& other);
};

typedef vec2<float>        vec2f;
typedef vec2<unsigned int> vec2u;
typedef vec2<int>          vec2i;

typedef vec3<float>        vec3f;
typedef vec3<unsigned int> vec3u;
typedef vec3<int>          vec3i;

#include "../source/tgp_vectors.tpp"

}; // namespace Vectors

#endif // TGP_VECTORS_H_
