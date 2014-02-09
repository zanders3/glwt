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
    GL::VertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(0));
    GL::VertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(3));
    GL::VertexAttribPointer(6, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(6));
    GL::EnableVertexAttribArray(0);
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
    
    GL::DrawRangeElements(GL_TRIANGLES, 0, mNumVerts, mNumVerts, GL_UNSIGNED_SHORT, NULL);
}

Model* Model::LoadObj(const char *objFile)
{
    vector<Vertex> vertices;
    vector<int> indices;
    
    Model* model = NULL;
    
    string line;
    ifstream file(objFile);
    if (file.is_open())
    {
        while (getline(file, line, '\n'))
        {
            cout << line << endl;
            switch (line[0])
            {
                case 'v':
                {
                    istringstream liness(line);
                    getline(liness, line, ' ');
                    
                    string x, y, z;
                    getline(liness, x, ' ');
                    getline(liness, y, ' ');
                    getline(liness, z, ' ');
                    vertices.push_back({
                        (float)atof(x.c_str()),
                        (float)atof(y.c_str()),
                        (float)atof(z.c_str()),
                        0.0f,
                        0.0f,
                        0.0f,
                        0.0f,
                        0.0f
                    });
                }
                break;
                case 'f':
                {
                    istringstream liness(line);
                    getline(liness, line, ' ');
                    
                    int inds[4];
                    for (int i = 0; i<4; i++)
                    {
                        string indBits;
                        getline(liness, indBits, ' ');
                        istringstream iss(indBits);
                        string bit;
                        while (getline(iss, bit, '/'))
                        {
                            inds[i] = atoi(bit.c_str());
                            break;
                        }
                    }
                    
                    indices.push_back(inds[0]);
                    indices.push_back(inds[1]);
                    indices.push_back(inds[2]);
                    
                    /*indices.push_back(inds[0]);
                    indices.push_back(inds[2]);
                    indices.push_back(inds[3]);*/
                }
                break;
            }
        }
        
        model = new Model((Vertex*)vertices.data(), (int)vertices.size(), (int*)indices.data(), (int)indices.size());
    }
    file.close();
    
    return model;
}
