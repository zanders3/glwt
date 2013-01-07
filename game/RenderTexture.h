#pragma once
#include "glwt.h"
#include "RefPtr.h"

class Texture;
typedef RefPtr<Texture> TexturePtr;

class RenderTexture;
typedef RefPtr<RenderTexture> RenderTexturePtr;

class RenderTexture
{
public:
	static RenderTexturePtr New(int width, int height)
	{
		return RenderTexturePtr(new RenderTexture(width, height));
	}

	~RenderTexture();

	void Bind();
	void Complete();
	TexturePtr GetTexture();

    static int RestoreWidth, RestoreHeight;
private:
	RenderTexture(int width, int height);

	RenderTexture(const RenderTexture&/* other*/) {}
	void operator=(RenderTexture&/* other*/) {}

	unsigned int m_frameBuffer;
	unsigned int m_depthBuffer;
	int m_width, m_height;
	TexturePtr m_texture;
};