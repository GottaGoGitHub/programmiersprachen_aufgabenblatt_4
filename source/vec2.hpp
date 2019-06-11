# ifndef VEC2_HPP
# define VEC2_HPP
/*
Include Guards:
Include Guards (,oder header guards) sind dafür da, um mehrfache Inklusionen zu vermeiden.
Wenn wir in vec2.hpp unseren Datentyp definieren und nur 2 Dateien inkludieren, die beide diesen Datentyp (bzw. die vec2.hpp datei) inkludieren würde es zu einem Fehler kommen.
Dies lässt sich mit include guards vermeiden.
Included man jetzt vec2.hpp aus einer Datei, die vec2.hpp schon inkludiert kommt es so nicht zu dem oben genannten Fehler.
*/

// Vec2 data type definition
struct Vec2{
    float x = 0.0f;
    float y = 0.0f;
    Vec2& operator+=(Vec2 const& v);
    Vec2& operator-=(Vec2 const& v);
    Vec2& operator*=(float s);
    Vec2& operator/=(float s);
};

Vec2 operator+(Vec2 const& u , Vec2 const& v);
Vec2 operator-(Vec2 const& u , Vec2 const& v);
Vec2 operator*(Vec2 const& v , float s);
Vec2 operator/(Vec2 const& v , float s);
Vec2 operator*(float s , Vec2 const& v);

# endif // VEC2_HPP    