#pragma once

#include <string>
#include <map>
#include <vector>
#include "RefPtr.h"
#include "Texture.h"

class Shader;
typedef RefPtr<Shader> ShaderPtr;

class Shader
{
public:
	struct Type
	{
		enum Enum
		{
			Vertex,
			Pixel
		};
	};

	~Shader();

	static ShaderPtr New(const char* vertexShaderfile, const char* pixelShaderFile)
	{
		ShaderPtr ptr = ShaderPtr(new Shader(vertexShaderfile, pixelShaderFile));
		ptr->Load();
		m_shaders.push_back(ptr);
		return ptr;
	}

	bool Load();
	void Bind();

	template <typename T> static void SetGlobalParameter(const char* paramName, T value)
	{
		for (std::vector<ShaderPtr>::iterator iter = m_shaders.begin(); iter != m_shaders.end(); ++iter)
		{
			(*iter)->Bind();
			(*iter)->SetParameter(paramName, value);
		}
	}

	static void ReloadAll()
	{
		for (std::vector<ShaderPtr>::iterator iter = m_shaders.begin(); iter != m_shaders.end(); ++iter)
		{
			(*iter)->Load();
		}
	}

	void SetParameter(const char* paramName, glm::mat4x4& matrix);
	void SetParameter(const char* paramName, glm::vec4& vector);
	void SetParameter(const char* paramName, glm::vec3& vector);
	void SetParameter(const char* paramName, TexturePtr texture);
	void SetParameter(const char* paramName, GLuint value);
	void SetParameter(const char* paramName, float value);
	void SetParameter( const char* paramName, glm::vec2& vector );
private:
	Shader(const char* vertexShaderfile, const char* pixelShaderFile);
	Shader(const Shader&/* other*/) {}
	void operator =(const Shader&/* other*/) {}

	std::string LoadFile( const char* file);
	void Preprocess(std::string& shader);
	bool LoadAndCompile(const char* shaderFile, Type::Enum type);
	bool Link();
	void PrintLog(GLint shader);
    void PrintProgramLog(GLint program);

	std::map<std::string, std::pair<size_t, TexturePtr> > m_textures;
	GLuint m_vertexShader, m_pixelShader, m_program;
	const char *m_vertexShaderFile, *m_pixelShaderFile;

	static std::vector<ShaderPtr> m_shaders;
};
