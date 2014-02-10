/**
 * Copyright Alex Parker 2013
 *
 * OpenGL Window Toolkit
 **/

#include "glwt.h"
#include <iostream>
#include "Model.h"
#include "GLMath.h"
#define BUFFER_OFFSET(i) ((char *)NULL + (i))

const char* vertexShaderCode = "#version 150 \r\n\
in vec2 inTex;\r\n\
in vec3 inNormal;\r\n\
in vec3 inVertex;\r\n\
out vec2 outTex;\r\n\
uniform mat4 wvp;\
void main()\r\n\
{\r\n\
    gl_Position = wvp * vec4(inVertex, 1.0);\r\n\
    outTex = inTex;\
}\r\n\
";

const char* fragmentShaderCode = "#version 150 \n\
in vec2 outTex;\n\
out vec4 FragColor;\n\
void main()\n\
{\n\
    FragColor = vec4(outTex, 0.0, 1.0);\n\
}\n\
";

Model* model;

GLuint vertexBuffer, indexBuffer, vertexLayout, vertexShader, fragmentShader, shaderProgram;

bool Game::Setup(int argc, const char** argv)
{
    Window::Open(800, 600, false, "Hello World!");
    
    GL::ClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    model = Model::LoadObj("/Users/alex/Code/native/glwt/Villager.obj");
    
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
    GL::BindAttribLocation(shaderProgram, 1, "inNormal");
    GL::BindAttribLocation(shaderProgram, 2, "inTex");
    
    //Link the shader program
    GL::LinkProgram(shaderProgram);
    GL::UseProgram(shaderProgram);
    
    //Enable culling and depth
    GL::Enable(GL_CULL_FACE);
    GL::CullFace(GL_FRONT);
    GL::Enable(GL_DEPTH_TEST);
    
    return true;
}

float timeC = 0.0f;

void Game::Draw(float deltaTime)
{
    GL::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    timeC += deltaTime;
    GLuint wvpParam = GL::GetUniformLocation(shaderProgram, "wvp");
    mat4 mvpMatrix = mat4::axisangle(vec3(0.0f, 1.0f, 0.0f), timeC) * mat4::translate(0.0f, -2.0f, 8.0f) * mat4::proj(deg2rad(30.0f), 800.0f/600.0f, 0.01f, 15.0f);
    GL::UniformMatrix4fv(wvpParam, 1, GL_TRUE, mvpMatrix.rows);
    
    model->Draw();
}