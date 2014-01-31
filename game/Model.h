//
//  ModelLoader.h
//  glwt
//
//  Created by Alex Parker on 27/01/2013.
//  Copyright (c) 2013 Alex Parker. All rights reserved.
//

#ifndef __glwt__ModelLoader__
#define __glwt__ModelLoader__

#include "glwt.h"

struct Vertex
{
    float x, y, z, nx, ny, nz, tx, ty;
};

class Model
{
public:
    Model(Vertex* vertices, int numVerts, int* indices, int numInds);
    ~Model();
    
    void Bind();
    
    static Model* LoadObj(const char* objFile);
private:
    GLuint mVertexBuffer, mIndexBuffer, mVertexLayout;
};

#endif /* defined(__glwt__ModelLoader__) */
