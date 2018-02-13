//
// Created by Brian Swenson on 1/29/18.
//

#pragma once
#include <iostream>


template<typename T>
class Vec3 {
public:
    Vec3() {x = y = z = 0; };



    Vec3<T>(T xValue, T yValue, T zValue)
    {
        x = xValue;
        y = yValue;
        z = zValue;

    }

    Vec3<T>(T xvalue){
        x = y = z = xvalue;
    }


//
    Vec3 operator+(Vec3 &b) {
        Vec3 f;

        f.x = this->x + b.x;
        f.y = this->y + b.y;
        f.z = this->z + b.z;

        return f;

    }


    Vec3 operator-(Vec3 &b) {
        Vec3 g;


        g.x = this->x - b.x;
        g.y = this->y - b.y;
        g.z = this->z - b.z;

        return g;
    }

    void operator-=(const Vec3 &vector1)
    {
        x -= vector1.x;
        y -= vector1.y;
        z -= vector1.z;
    }

    void operator+=(const Vec3 &vector)
    {
        x += vector.x;
        y += vector.y;
        z += vector.z;
    }


    bool operator==(const Vec3 &vector)
    {
        return (x == vector.x)
               && (y == vector.y)
               && (z == vector.z);
    }

    bool operator!=(const Vec3 &vector)
    {
        return (x != vector.x)
                && (y != vector.y)
                && (z != vector.z);
    }
//
    Vec3<T> operator++(int){
        Vec3 d(*this);
        int k;
        k=this->x;
        this->x=this->z;
        this->z=this->y;
        this->y=k;
        return d;
    }



    Vec3<T> operator++(){
        Vec3 d(*this);
        int k;
        k=this->x;
        this->x=this->z;
        this->z=this->y;
        this->y=k;
        return *this;

    }

    Vec3<T> operator--(int){
        Vec3 d(*this);
        int k;
        k=this->x;
        this->x=this->y;
        this->y=this->z;
        this->z=k;
        return d;
    }

    Vec3<T> operator--(){
        Vec3 d(*this);
        int k;
        k=this->x;
        this->x=this->y;
        this->y=this->z;
        this->z=k;
        return *this;
    }

    T dot(const Vec3 &vec) const
    {
        return x * vec.x + y * vec.y + z * vec.z;
    }

    Vec3 operator*=(const T &value)
    {
        x *= value;
        y *= value;
        z *= value;
    }

    Vec3 operator/=(const T &value)
    {
        x /= value;
        y /= value;
        z /= value;
    }

    Vec3 operator/(const T &value) const
    {
        return Vec3<T>(x / value, y / value, z / value);
    }

    Vec3 operator*(const T &value) const
    {
        return Vec3<T>(x * value, y * value, z * value);
    }


    void set(const T &xValue, const T &yValue, const T &zValue) {
        x = xValue;
        y = yValue;
        z = zValue;
    }

    T getX() const { return x; }
    T getY() const { return y; }
    T getZ() const { return z; }

    void setX(const T &xValue) { x = xValue; }
    void setY(const T &yValue) { y = yValue; }
    void setZ(const T &zValue) { z = zValue; }



//fill in here

private:
    T x;
    T y;
    T z;
};

//for printing
template<typename T>
std::ostream& operator<<(std::ostream& stream, const Vec3<T>& vec) {
    stream << "X=" << vec.getX() << ", Y=" << vec.getY() << ", Z=" << vec.getZ();
    return stream;
}