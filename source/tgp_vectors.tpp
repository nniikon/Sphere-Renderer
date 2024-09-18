template <class T>
vec2<T>::vec2(T new_x, T new_y)
    : x(new_x),
      y(new_y) {}

template <class T>
vec2<T> operator+(const vec2<T>& lhs, const vec2<T>& rhs) {
    return vec2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}

template <class T>
vec2<T> operator-(const vec2<T>& lhs, const vec2<T>& rhs) {
    return vec2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template <class T>
vec2<T> operator*(const vec2<T>& lhs, const vec2<T>& rhs) {
    return vec2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
}

template <class T>
vec2<T> operator*(const vec2<T>& lhs, const T& scalar) {
    return vec2<T>(lhs.x * scalar, lhs.y * scalar);
}

template <class T>
vec2<T> operator/(const vec2<T>& lhs, const T& scalar) {
    return vec2<T>(lhs.x / scalar, lhs.y / scalar);
}

template <class T>
T Dot(const vec2<T>& lhs, const vec2<T>& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

template <class T>
vec2<T> Norm(const vec2<T>& vec) {
    return vec / Len(vec);
}

template <class T>
T Len(const vec2<T>& vec) {
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
}


template <class T>
vec3<T>::vec3(T new_x, T new_y, T new_z)
    : x(new_x),
      y(new_y),
      z(new_z) {}

template <class T>
vec3<T>& vec3<T>::operator=(const vec3<T>& other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

template <class T>
vec3<T> operator+(const vec3<T>& lhs, const vec3<T>& rhs) {
    return vec3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

template <class T>
vec3<T> operator-(const vec3<T>& lhs, const vec3<T>& rhs) {
    return vec3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

template <class T>
vec3<T> operator*(const vec3<T>& lhs, const vec3<T>& rhs) {
    return vec3<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

template <class T>
vec3<T> operator*(const vec3<T>& lhs, const T& scalar) {
    return vec3<T>(lhs.x * scalar, lhs.y * scalar, lhs.z * scalar);
}

template <class T>
vec3<T> operator/(const vec3<T>& lhs, const T& scalar) {
    return vec3<T>(lhs.x / scalar, lhs.y / scalar, lhs.z / scalar);
}

template <class T>
T Dot(const vec3<T>& lhs, const vec3<T>& rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

template <class T>
vec3<T> Norm(const vec3<T>& vec) {
    return vec / Len(vec);
}

template <class T>
T Len(const vec3<T>& vec) {
    return std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}
