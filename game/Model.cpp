//
//  ModelLoader.cpp
//  glwt
//
//  Created by Alex Parker on 27/01/2013.
//  Copyright (c) 2013 Alex Parker. All rights reserved.
//

#define BUFFER_OFFSET(i) ((char *)NULL + (i))
#include "Model.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Maths.h"
#include <assert.h>

using namespace std;

Model::Model(Vertex* vertices, int numVerts, int* indices, int numInds) : mNumVerts(numVerts), mNumInds(numInds)
{
    //Create the vertex buffer object, then set it as the current buffer, then copy the vertex data onto it.
    GL::GenBuffers(1, &mVertexBuffer);
    GL::BindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
    GL::BufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*numVerts, vertices, GL_STATIC_DRAW);
    
    //Create the index buffer object, set it as the current index buffer, then copy index data to it.
    GL::GenBuffers(1, &mIndexBuffer);
    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);
    GL::BufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*numInds, indices, GL_STATIC_DRAW);
    
    //Create the vertex layout
    GL::GenVertexArrays(1, &mVertexLayout);
    GL::BindVertexArray(mVertexLayout);
    
    //The vertex layout has 3 floats for position
    //GL::EnableVertexAttribArray(0);
    GL::EnableVertexAttribArray(0);
    GL::VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(0));
    GL::EnableVertexAttribArray(1);
    GL::VertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(12));
    GL::EnableVertexAttribArray(2);
    GL::VertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(24));
}

Model::~Model()
{
    GL::DeleteBuffers(1, &mVertexBuffer);
    GL::DeleteBuffers(1, &mIndexBuffer);
    GL::DeleteVertexArrays(1, &mVertexLayout);
}

void Model::Draw()
{
    GL::BindVertexArray(mVertexLayout);
    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);
    GL::BindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
    
    GL::DrawElements(GL_TRIANGLES, mNumInds, GL_UNSIGNED_INT, NULL);
}

Model* Model::LoadObj(const char *objFile)
{
    vector<Vertex> vertices;
    vector<vec2> texcoords;
    vector<vec3> normals;
    vector<int> indices;
    
    Model* model = NULL;
    
    string line;
    ifstream file(objFile);
    if (file.is_open())
    {
        while (getline(file, line, '\n'))
        {
            istringstream liness(line);
            getline(liness, line, ' ');

            if (line == "v")
            {
                string x, y, z;
                getline(liness, x, ' ');
                getline(liness, y, ' ');
                getline(liness, z, ' ');
				Vertex vert = {
					(float)atof(x.c_str()),
					(float)atof(y.c_str()),
					(float)atof(z.c_str()),
					0.0f,
					1.0f,
					0.0f,
					1.0f,
					1.0f
				};
                vertices.push_back(vert);
            }
            else if (line == "vt")
            {
                string u, v;
                getline(liness, u, ' ');
                getline(liness, v, ' ');
                
                texcoords.push_back(vec2(
					(float)atof(u.c_str()),
					(float)atof(v.c_str())
				));
            }
            else if (line == "vn")
            {
                string x, y, z;
                getline(liness, x, ' ');
                getline(liness, y, ' ');
                getline(liness, z, ' ');
                normals.push_back(vec3(
                    (float)atof(x.c_str()),
                    (float)atof(y.c_str()),
                    (float)atof(z.c_str())
                ));
            }
            else if (line == "f")
            {
                int inds[4];
                for (int i = 0; i<4; i++)
                {
                    string indBits;
                    getline(liness, indBits, ' ');
                    istringstream iss(indBits);
                    string bit;
                    
                    //Read Position
                    if (getline(iss, bit, '/'))
                    {
                        inds[i] = atoi(bit.c_str()) - 1;//indices are counted from 1 for some reason
                    }
                    //Failing to read at this point means
                    //this is a tri, not a quad.
                    else
                    {
                        assert(i == 3);//we should have failed to read the 4th position
                        inds[i] = -1;
                        
                        continue;
                    }
                    
                    //Read Tex Coords
                    if (getline(iss, bit, '/'))
                    {
                        int texInd = atoi(bit.c_str()) - 1;
                        vertices[inds[i]].tx = texcoords[texInd].x;
                        vertices[inds[i]].ty = texcoords[texInd].y;
                    }
                    else continue;
                    
                    //Read Normal
                    if (getline(iss, bit, '/'))
                    {
                        int normInd = atoi(bit.c_str());
                        vec3 normal = normals[normInd];
                        vertices[inds[i]].nx = normal.x;
                        vertices[inds[i]].ny = normal.y;
                        vertices[inds[i]].nz = normal.z;
                    }
                }
                
                indices.push_back(inds[0]);
                indices.push_back(inds[1]);
                indices.push_back(inds[2]);
                
                if (inds[3] != -1)
                {
                    indices.push_back(inds[0]);
                    indices.push_back(inds[2]);
                    indices.push_back(inds[3]);
                }
            }
        }
        
        model = new Model((Vertex*)vertices.data(), (int)vertices.size(), (int*)indices.data(), (int)indices.size());
    }
    file.close();
    
    return model;
}
