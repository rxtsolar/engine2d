#ifndef GS_VECT2_H
#define GS_VECT2_H

#include "debug.h"
#include "const.h"

namespace gs
{

template <class T>
class GsVect2 {
public:
    GsVect2(void)
    {
        x = 0;
        y = 0;
    }

    GsVect2(const T& val)
    {
        x = val;
        y = val;
    }

    GsVect2(const T& x, const T& y)
    {
        this->x = x;
        this->y = y;
    }

    GsVect2(const GsVect2<T>& vect)
    {
        *this = vect;
    }

    void setX(const T& x)
    {
        this->x = x;
    }

    void setY(const T& y)
    {
        this->y = y;
    }

    const T& getX(void) const
    {
        return x;
    }

    const T& getY(void) const
    {
        return y;
    }

    GsVect2<T> operator+(const GsVect2<T>& vect) const
    {
        return GsVect2<T>(x + vect.getX(), y + vect.getY());
    }

    GsVect2<T> operator-(const GsVect2<T>& vect) const
    {
        return GsVect2<T>(x - vect.getX(), y - vect.getY());
    }

    GsVect2<T> operator*(const T& fact) const
    {
        return GsVect2<T>(x * fact, y * fact);
    }

    GsVect2<T> operator*(const GsVect2<T>& vect) const
    {
        return GsVect2<T>(x * vect.getX(), y * vect.getY());
    }

    GsVect2<T> operator/(const T& fact) const
    {
        return GsVect2<T>(x / fact, y / fact);
    }

    GsVect2<T> operator/(const GsVect2<T>& vect) const
    {
        return GsVect2<T>(x / vect.getX(), y * vect.getY());
    }

    friend GsVect2<T> operator*(const T& fact, const GsVect2<T>& vect)
    {
        return GsVect2<T>(fact * vect.getX(), fact * vect.getY());
    }

    GsVect2<T> operator-(void) const
    {
        return GsVect2<T>(-x, -y);
    }

    GsVect2<T>& operator=(const GsVect2<T>& vect)
    {
        x = vect.getX();
        y = vect.getY();
        return *this;
    }

    GsVect2<T>& operator+=(const GsVect2<T>& vect)
    {
        return *this = *this + vect;
    }

    GsVect2<T>& operator-=(const GsVect2<T>& vect)
    {
        return *this = *this - vect;
    }

    GsVect2<T>& operator*=(const T& fact)
    {
        return *this = *this * fact;
    }

    GsVect2<T>& operator/=(const T& fact)
    {
        return *this = *this / fact;
    }

    bool operator==(const GsVect2<T>& vect) const
    {
        return fabs(x - vect.getX()) < GS_EPSILON &&
               fabs(y - vect.getY()) < GS_EPSILON;
    }

    bool operator!=(const GsVect2<T>& vect) const
    {
        return fabs(x - vect.getX()) > GS_EPSILON ||
               fabs(y - vect.getY()) > GS_EPSILON;
    }

    operator const GsVect2<int>(void) const
    {
        return GsVect2<int>(x, y);
    }

    operator const GsVect2<float>(void) const
    {
        return GsVect2<float>(x, y);
    }

    operator const GsVect2<double>(void) const
    {
        return GsVect2<double>(x, y);
    }

    T dot(const GsVect2<T>& vect) const
    {
        return x * vect.getX() + y * vect.getY();
    }

    T norm1(void) const
    {
        return fabs(x) + fabs(y);
    }

    T norm2(void) const
    {
        return sqrt(dot(*this));
    }

    T dist(const GsVect2<T>& vect) const
    {
        return (*this - vect).norm2();
    }

    GsVect2<T> normalize(void) const
    {
        return *this / this->norm2();
    }

    friend GsVect2<T> max(const GsVect2<T>& v0, const GsVect2<T>& v1)
    {
        T x = v0.getX() > v1.getX() ? v0.getX() : v1.getX();
        T y = v0.getY() > v1.getY() ? v0.getY() : v1.getY();
        return GsVect2<T>(x, y);
    }

    friend GsVect2<T> min(const GsVect2<T>& v0, const GsVect2<T>& v1)
    {
        T x = v0.getX() < v1.getX() ? v0.getX() : v1.getX();
        T y = v0.getY() < v1.getY() ? v0.getY() : v1.getY();
        return GsVect2<T>(x, y);
    }

    // theta is supposed to be degree
    GsVect2<T> rotate(const GsVect2<T>& vect, double theta) const
    {
        theta *= GS_DEG_TO_RAD;
        double c = cos(theta);
        double s = sin(theta);
        if (vect.norm2() < GS_EPSILON)
            gsBug("rotate around 0 vector");
        return GsVect2<T>(x * c - vect.getX() * s,
                          x * s + vect.getY() * c);
    }
private:
    T x;
    T y;
};

typedef GsVect2<int> GsVect2i;
typedef GsVect2<float> GsVect2f;
typedef GsVect2<double> GsVect2d;

} // namespace gs

#endif // GS_VECT2_H
