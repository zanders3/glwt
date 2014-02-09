/**
 * Copyright Alex Parker 2013
 *
 * OpenGL Window Toolkit
 **/

#include "glwt.h"
#include <math.h>
#include <iostream>
#include "Model.h"
#define BUFFER_OFFSET(i) ((char *)NULL + (i))

const char* vertexShaderCode = "#version 150 \r\n\
in vec3 inVertex;\r\n\
uniform mat4 wvp;\
void main()\r\n\
{\r\n\
    gl_Position = wvp * vec4(inVertex, 1.0);\r\n\
}\r\n\
";

const char* fragmentShaderCode = "#version 150 \n\
out vec4 FragColor;\n\
void main()\n\
{\n\
    FragColor = vec4(0.0, 0.0, 1.0, 1.0);\n\
}\n\
";

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
        return {{
            c+ic*axis.x*axis.x,         ic*axis.x*axis.y-axis.z*s,  ic*axis.x*axis.z+axis.y*s, 0.0f,
            ic*axis.x*axis.y+axis.z*s,  c+ic*axis.y*axis.y,         ic*axis.y*axis.z-axis.x*s, 0.0f,
            ic*axis.x*axis.z-axis.y*s,  ic*axis.y*axis.z+axis.x*s,  c+ic*axis.z*axis.z,        0.0f,
            0.0f,                       0.0f,                       0.0f,                      1.0f
        }};
    }
    
    static mat4 translate(float x, float y, float z)
    {
        return {{
            1.0f, 0.0f, 0.0f, x,
            0.0f, 1.0f, 0.0f, y,
            0.0f, 0.0f, 1.0f, z,
            0.0f, 0.0f, 0.0f, 1.0f
        }};
    }
    
    static mat4 identity()
    {
        return {{
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        }};
    }
    
    static mat4 proj(float n, float f)
    {
        return {{
            1.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f,
            0.0f, 0.0f, f/(f-n), (-f*n)/(f-n),
            0.0f, 0.0f, 1.0f, 0.0f
        }};
    }
};

Model* model;

GLuint vertexBuffer, indexBuffer, vertexLayout, vertexShader, fragmentShader, shaderProgram;

bool Game::Setup(int argc, const char** argv)
{
    Window::Open(800, 600, false, "Hello World!");
    
    GL::ClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    vec3 verts[] =
    {
        { 0.0f, 3.00f, 4.0f },
        { -0.5f, 0.25f, 4.0f },
        { 0.5f, 0.25f, 4.0f }
    };
    unsigned short inds[] =
    {
        0, 1, 2
    };
    
    //Create the vertex buffer object, then set it as the current buffer, then copy the vertex data onto it.
    GL::GenBuffers(1, &vertexBuffer);
    GL::BindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    GL::BufferData(GL_ARRAY_BUFFER, sizeof(verts), &verts, GL_STATIC_DRAW);
    
    //Create the index buffer object, set it as the current index buffer, then copy index data to it.
    GL::GenBuffers(1, &indexBuffer);
    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    GL::BufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(inds), &inds, GL_STATIC_DRAW);
    
    //Create the vertex layout
    GL::GenVertexArrays(1, &vertexLayout);
    GL::BindVertexArray(vertexLayout);
    
    //The vertex layout has 3 floats for position
    GL::VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vec3), BUFFER_OFFSET(0));
    GL::EnableVertexAttribArray(0);
    
    //Create the shader program
    shaderProgram = GL::CreateProgram();
    
    //Create the vertex and fragment shader
    vertexShader = GL::CreateShader(GL_VERTEX_SHADER);
    fragmentShader = GL::CreateShader(GL_FRAGMENT_SHADER);
    int vertexCodeLen = (int)strlen(vertexShaderCode);
    int fragmentCodeLen = (int)strlen(fragmentShaderCode);
    
    //Load the shader source code and compile it
    GL::ShaderSource(vertexShader, 1, &vertexShaderCode, &vertexCodeLen);
    GL::ShaderSource(fragmentShader, 1, &fragmentShaderCode, &fragmentCodeLen);
    GL::CompileShader(vertexShader);
    GL::CompileShader(fragmentShader);
    
    char log[255];
    int len;
    bool hadError = false;
    GL::GetShaderInfoLog(vertexShader, 255, &len, (char*)&log);
    if (len > 0) {
        std::cout << "Vertex Compile error:" << std::endl << log << std::endl;
        hadError = true;
    }
    GL::GetShaderInfoLog(fragmentShader, 255, &len, (char*)&log);
    if (len > 0) {
        std::cout << "Fragment Compile error:" << std::endl << log << std::endl;
        hadError = true;
    }
    
    if (hadError)
        return false;
    
    GL::AttachShader(shaderProgram, fragmentShader);
    GL::AttachShader(shaderProgram, vertexShader);
    
    //Bind the vertex position to the inVertex variable in the vertex shader
    GL::BindAttribLocation(shaderProgram, 0, "inVertex");
    
    //Link the shader program
    GL::LinkProgram(shaderProgram);
    GL::UseProgram(shaderProgram);
    
    model = Model::LoadObj("/Users/alex/Code/native/glwt/Villager.obj");
    
    return true;
}

float timeC = 0.0f;

void Game::Draw(float deltaTime)
{
    GL::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //GL::BindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    /*vec3 verts[] =
    {
        { 0.0f, 3.00f, 0.0f },
        { -0.5f, 0.25f, 0.0f },
        { 0.5f, 0.25f, 0.0f }
    };*/
    //GL::BufferData(GL_ARRAY_BUFFER, sizeof(verts), &verts, GL_STATIC_DRAW);
    
    timeC += deltaTime;
    GLuint wvpParam = GL::GetUniformLocation(shaderProgram, "wvp");
    mat4 mvpMatrix = mat4::axisangle(vec3(0.0f, 1.0f, 0.0f), timeC) * mat4::translate(0.0f, 0.0f, 5.0f) * mat4::proj(0.01f, 15.0f);
    GL::UniformMatrix4fv(wvpParam, 1, GL_TRUE, mvpMatrix.rows);
    
    //GL::BindVertexArray(vertexLayout);
    
    //GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    //GL::DrawRangeElements(GL_TRIANGLES, 0, 3, 3, GL_UNSIGNED_SHORT, NULL);
    
    model->Draw();
}