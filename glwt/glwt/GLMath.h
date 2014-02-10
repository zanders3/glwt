/**
 * Copyright Alex Parker 2013
 *
 * OpenGL Window Toolkit Header File
 *
 * This header file contains vec3, mat4 data structures and associated operations.
 **/

#ifndef __glwt_math_h
#define __glwt_math_h

#include <math.h>

#ifdef WIN32
#define M_PI 3.14159265f
#endif

inline float rad2deg(float radians)
{
    return radians * (180.0f/M_PI);
}

inline float deg2rad(float deg)
{
    return (deg * M_PI) / 180.0f;
}

struct vec2
{
    vec2() : x(0.0f), y(0.0f)
    {
    }
    
    vec2(float x, float y) : x(x), y(y)
    {
    }
    
    float x, y;
};

struct vec3
{
    float x, y, z;
    
    vec3() : x(0.0f), y(0.0f), z(0.0f)
    {
    }
    
    vec3(float x, float y, float z) : x(x), y(y), z(z)
    {
    }
    
    inline vec3 operator *(float scalar) const
    {
        return vec3(
                    x * scalar, y * scalar, z * scalar
                    );
    }
    
    inline vec3 operator +(const vec3& other) const
    {
        return vec3(
                    x + other.x, y + other.y, z + other.z
                    );
    }
    
    inline vec3 operator -(const vec3& other) const
    {
        return vec3(
                    x - other.x, y - other.y, z - other.z
                    );
    }
    
    inline float dot(const vec3& other) const
    {
        return x*other.x + y*other.y + z*other.z;
    }
    
    inline float lengthSq() const
    {
        return dot(*this);
    }
    
    inline float length() const
    {
        return sqrtf(lengthSq());
    }
    
    void normalize()
    {
        float len = length();
        x /= len;
        y /= len;
        z /= len;
    }
    
    inline vec3 cross(const vec3& other) const
    {
        return vec3(
                    y*other.z - z*other.y,
                    z*other.x - x*other.z,
                    x*other.y - y*other.x
                    );
    }
};

struct mat4
{
    float rows[16];
    
    mat4 operator *(const mat4& other)
    {
        mat4 res;
        for (int i = 0; i<16; i+=4)
            for (int j = 0; j<4; j++)
                res.rows[i+j] =
                other.rows[i]*rows[j] +
                other.rows[i+1]*rows[j+4] +
                other.rows[i+2]*rows[j+8] +
                other.rows[i+3]*rows[j+12];
        
        return res;
    }
    
    static mat4 axisangle(const vec3& axis, float angle)
    {
        float c = cosf(angle), ic = 1.0f - c;
        float s = sinf(angle);
        mat4 mat = {{
            c+ic*axis.x*axis.x,         ic*axis.x*axis.y-axis.z*s,  ic*axis.x*axis.z+axis.y*s, 0.0f,
            ic*axis.x*axis.y+axis.z*s,  c+ic*axis.y*axis.y,         ic*axis.y*axis.z-axis.x*s, 0.0f,
            ic*axis.x*axis.z-axis.y*s,  ic*axis.y*axis.z+axis.x*s,  c+ic*axis.z*axis.z,        0.0f,
            0.0f,                       0.0f,                       0.0f,                      1.0f
        }};
		return mat;
    }
    
    static mat4 translate(float x, float y, float z)
    {
        mat4 mat = {{
            1.0f, 0.0f, 0.0f, x,
            0.0f, 1.0f, 0.0f, y,
            0.0f, 0.0f, 1.0f, z,
            0.0f, 0.0f, 0.0f, 1.0f
        }};
		return mat;
    }
    
    static mat4 identity()
    {
        mat4 mat = {{
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        }};
		return mat;
    }
    
    static mat4 proj(float fov, float aspect, float n, float f)
    {
        float yScale = 1.0f/tanf(fov*0.5f);
        float xScale = yScale / aspect;
        
        mat4 mat = {{
            xScale, 0.0f,   0.0f, 0.0f,
            0.0f,   yScale, 0.0f, 0.0f,
            0.0f,   0.0f,   f/(f-n), (-f*n)/(f-n),
            0.0f,   0.0f,   1.0f, 0.0f
        }};
		return mat;
    }
};

#endif
