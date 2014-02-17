/**
 * Copyright Alex Parker 2013
 *
 * OpenGL Window Toolkit
 **/

#include "glwt.h"
#include <iostream>
#include "Model.h"
#include "Maths.h"
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
    if (!Window::Open(800, 600, false, "Hello  World!"))
		return false;

    GL::ClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    model = Model::LoadObj("C:\\Users\\Alex\\Desktop\\villager.obj");
    
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

void Game::Resize(int width, int height)
{
	GL::Viewport(0, 0, width, height);
}

float timeC = 0.0f;

void Game::Update(float deltaTime)
{
	timeC += deltaTime;
}

void Game::Draw(float deltaTime)
{
    GL::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
	float w = (float)Window::Width();
	float h = (float)Window::Height();
    GLuint wvpParam = GL::GetUniformLocation(shaderProgram, "wvp");
    mat4 mvpMatrix = mat4::axisangle(vec3(0.0f, 1.0f, 0.0f), timeC) * mat4::translate(0.0f, -2.0f, 8.0f) * mat4::proj(deg2rad(30.0f), w/h, 0.01f, 15.0f);
    GL::UniformMatrix4fv(wvpParam, 1, GL_TRUE, mvpMatrix.rows);
    
	if (model)
		model->Draw();
}