/*#pragma once
#include "stdafx.h"
#include "RefPtr.h"
#include "Material.h"
#include <vector>

class Mesh;
typedef RefPtr<Mesh> MeshPtr;

class Model;
typedef RefPtr<Model> ModelPtr;

class Model
{
public:
	~Model();

	ModelPtr& AddChild(ModelPtr child);
	ModelPtr& AddChild(MeshPtr child);

	static ModelPtr New(MaterialPtr material, MeshPtr mesh)
	{
		return ModelPtr(new Model(material, mesh));
	}

	static ModelPtr New()
	{
		return ModelPtr(new Model());
	}

	Model& SetPosition(glm::vec3 pos);
	Model& SetScale(float scale);
	Model& SetScale(float x, float y, float z);
	Model& Rotate(float angle, glm::vec3 axis);
	Model& SetForward( glm::vec3 fwd, glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f) );

	const glm::vec3& GetPosition() const;

	void Draw(glm::mat4& world, Material::Pass::Enum pass);

private:
	Model(MaterialPtr& material, MeshPtr& mesh);
	Model();

	MaterialPtr	m_material;
	MeshPtr		m_mesh;

	glm::mat4	m_world;
	bool		m_worldDirty;

	glm::vec3	m_pos;
	glm::vec3	m_scale;
	glm::mat4	m_rot;

	std::vector<ModelPtr> m_children;
};*/
