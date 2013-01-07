#pragma once
#include "RefPtr.h"

typedef void (*TextureShaderCallback)(float&,float&,float&,float,float);

class Texture;
typedef RefPtr<Texture> TexturePtr;

class Shader;
class RenderTexture;

class Texture
{
public:
	friend class Shader;
	friend class RenderTexture;

	Texture();
	~Texture();

	static TexturePtr Load(const char* filename);
	void Create(int width, int height, void* pixels);

	static TexturePtr CreateFromShader(TextureShaderCallback callback, int width, int height);

protected:
	Texture(const Texture& other);
	void operator =(const Texture& other);

	unsigned int m_texture;
};
