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

using namespace std;

Model::Model(Vertex* vertices, int numVerts, int* indices, int numInds)
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

void Model::Bind()
{
    GL::BindVertexArray(mVertexLayout);
    GL::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);
    GL::BindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
}

Model* Model::LoadObj(const char *objFile)
{
    vector<Vertex> vertices;
    vector<int> indices;
    
    
    
    return new Model((Vertex*)vertices.data(), vertices.size(), (int*)indices.data(), (int)indices.size());
}
