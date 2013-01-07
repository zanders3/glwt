#include "RefPtr.h"
#include <map>

class Shader;
typedef RefPtr<Shader> ShaderPtr;

class Material;
typedef RefPtr<Material> MaterialPtr;

struct MaterialProperty
{
	struct Type
	{
		enum Enum
		{
			Float,
			Vec2,
			Vec3,
			Vec4,
			None
		};
	};

	MaterialProperty();
	explicit MaterialProperty(float value);
	explicit MaterialProperty(glm::vec2 value);
	explicit MaterialProperty(glm::vec3 value);
	explicit MaterialProperty(glm::vec4 value);

	void Set(const char* property, ShaderPtr& shader);

	float x, y, z, w;
	Type::Enum type;
};

class Material
{
public:
	struct Pass
	{
		enum Enum
		{
			Color,
			Bloom
		};
	};

	Material(ShaderPtr& shader);
	Material();
	~Material();

	static MaterialPtr New(ShaderPtr& shader)
	{
		return MaterialPtr(new Material(shader));
	}
	static MaterialPtr New()
	{
		return MaterialPtr(new Material());
	}
	static MaterialPtr Clone( MaterialPtr mat );

	Material& Set(Pass::Enum pass, ShaderPtr& shader);

	template <typename T> Material& Set(Pass::Enum pass, const char* property, T value)
	{
		Set(pass, property, MaterialProperty(value));
		return *this;
	}

	Material& Set(Pass::Enum pass, const char* property, MaterialProperty value);

	bool Bind(Pass::Enum pass, glm::mat4& world);
private:
	ShaderPtr m_shaders[2];
	std::map<const char*, MaterialProperty> m_properties[2];
};