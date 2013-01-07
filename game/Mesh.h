#pragma once
#include "glwt.h"
#include "RefPtr.h"

class Mesh;
typedef RefPtr<Mesh> MeshPtr;

class Mesh
{
public:
	Mesh( Vertex* verts, int numVerts, unsigned short* indices, int numIndices, GLenum drawMode = GL_TRIANGLES );
	~Mesh();

	//Generates a simple plane along the x z axis centered about 0,0,0
	static MeshPtr CreatePlane(float width, float height);

	//Generates a unit sphere about 0, 0, 0
	static MeshPtr CreateSphere(int rings, int segments, bool flip = false);

	//Generates a cone centered about 0,0,0 along +z
	static MeshPtr CreateCone(int segments);

	//Creates a set of lines from a unit sphere representing normals.
	static MeshPtr CreateSphereNormals(int rings, int segments);

	//Creates a unit cube about 0,0,0
	static MeshPtr CreateCube();

	//Creates a unit cylinder centred about 0,0,0 along z axis
	static MeshPtr CreateCylinder(int segments);

	static MeshPtr CreateIcoSphere(int recursion);

	static MeshPtr CreateSphereCube(int recursion);

	void Draw();

private:
	Mesh(const Mesh&/* other*/) {}
	void operator =(const Mesh&/* other*/) {}

	GLuint	m_vertexBuffer;
	GLuint	m_indexBuffer;
	GLuint	m_vertexLayout;
	int		m_numIndices;
	GLenum	m_drawMode;
};