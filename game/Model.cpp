/*#include "Model.h"
#include "Mesh.h"

Model::Model( MaterialPtr& material, MeshPtr& mesh ) :
	m_material(material),
	m_mesh(mesh),
	m_world(),
	m_worldDirty(true),
	m_pos(),
	m_scale(1.0f, 1.0f, 1.0f),
	m_rot(),
	m_children()
{
}

Model::Model() :
	m_material(),
	m_mesh(),
	m_world(),
	m_worldDirty(true),
	m_pos(),
	m_scale(1.0f, 1.0f, 1.0f),
	m_rot(),
	m_children()
{
}

Model::~Model()
{
}

ModelPtr& Model::AddChild( ModelPtr child )
{
	m_children.push_back(child);
	return m_children.back();
}

ModelPtr& Model::AddChild( MeshPtr child )
{
	m_children.push_back(ModelPtr(new Model(m_material, child)));
	return m_children.back();
}

Model& Model::SetPosition( glm::vec3 pos )
{
	m_pos = pos;
	m_worldDirty = true;

	return *this;
}

Model& Model::Rotate( float angle, glm::vec3 axis )
{
	m_rot = glm::rotate(m_rot, angle, axis);
	m_worldDirty = true;
	return *this;
}

Model& Model::SetScale( float scale )
{
	m_scale.x = scale;
	m_scale.y = scale;
	m_scale.z = scale;
	m_worldDirty = true;

	return *this;
}

Model& Model::SetScale( float x, float y, float z )
{
	m_scale.x = x;
	m_scale.y = y;
	m_scale.z = z;
	m_worldDirty = true;

	return *this;
}

const glm::vec3& Model::GetPosition() const
{
	return m_pos;
}

void Model::Draw( glm::mat4& world, Material::Pass::Enum pass )
{
	if (m_worldDirty)
	{
		m_worldDirty = false;

		m_world = glm::scale(glm::translate(glm::mat4(), m_pos) * m_rot, m_scale);
	}

	glm::mat4 localWorld = world * m_world;

	if (m_mesh.valid() && m_material.valid() && m_material->Bind(pass, localWorld))
	{
		m_mesh->Draw();
	}

	for (std::vector<ModelPtr>::iterator iter = m_children.begin(); iter != m_children.end(); ++iter)
	{
		(*iter)->Draw(localWorld, pass);
	}
}

Model& Model::SetForward( glm::vec3 fwd, glm::vec3 up )
{
    if(glm::all(glm::equal(fwd, up)))
        m_rot = glm::mat4(1.0f);
    else
    {
        glm::vec3 rotationAxis = glm::cross(up, fwd);
        float angle = glm::degrees(glm::acos(glm::dot(fwd, up)));
        m_rot = glm::rotate(angle, rotationAxis);
        m_worldDirty = true;
    }

	return *this;
}*/
