#include <cmath>
#include "vec2.hpp"


Vec2& Vec2::operator+=(Vec2 const& v){
    x += v.x;
    y += v.y;

    return *this;
}
Vec2& Vec2::operator-=(Vec2 const& v){
    x -= v.x;
    y -= v.y;

    return *this;
}
Vec2& Vec2::operator*=(float s){
    x *= s;
    y *= s;

    return *this;
}
Vec2& Vec2::operator/=(float s){
    x /= s;
    y /= s;

    return *this;
}
Vec2 operator+(Vec2 const& u , Vec2 const& v){
    Vec2 res;
    res.x = u.x + v.x;
    res.y = u.y + v.y;

    return res;
}
Vec2 operator-(Vec2 const& u , Vec2 const& v){
    Vec2 res;
    res.x = u.x - v.x;
    res.y = u.y +-v.y;

    return res;
}
Vec2 operator*(Vec2 const& v , float s){
    Vec2 res;
    res.x = v.x * s;
    res.y = v.y * s;

    return res;
}
Vec2 operator/(Vec2 const& v , float s){
    Vec2 res;
    res.x = v.x / s;
    res.y = v.y / s;

    return res;
}
Vec2 operator*(float s , Vec2 const& v){
    Vec2 res;
    res.x = v.x * s;
    res.y = v.y * s;

    return res;
}
