#include "Camera.h"

/*Camera::Camera(
	int width, 
	int height 
) :	m_time(1.0f),
	m_pos(glm::vec3(0.0f, 0.0f, -30.0f)),
	m_fwd(glm::vec3(0.0f, 0.0f, 1.0f)),
	m_dirty(true)
{
	Resize(width, height);
}

Camera::~Camera()
{
}

void Camera::Move(float side, float forward)
{
	if (side != 0.0f || forward != 0.0f)
	{
		m_pos += m_fwd * forward;
		glm::vec3 sideV = glm::cross(m_fwd, glm::vec3(0.0f, 1.0f, 0.0f));
		m_pos += sideV * side;

		m_dirty = true;
	}
}

void Camera::Look(float side, float up)
{
	if (side != 0.0f || up != 0.0f)
	{
		m_rot.y += side;
		m_rot.x += up;

		m_dirty = true;
	}
}

void Camera::Resize( int width, int height )
{
	float aspect = static_cast<float>(width) / static_cast<float>(height);
	m_proj = glm::perspective(45.0f, aspect, 0.1f, 5000.0f);
	m_dirty = true;
}

glm::mat4x4& Camera::GetViewProjection()
{
	//Only recalculate view*proj if it changed.
	if (m_dirty)
	{
		glm::quat rot = glm::rotate(glm::quat(), m_rot.x, glm::vec3(1.0f, 0.0f, 0.0f));
		rot = glm::rotate(rot, m_rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
		m_fwd = ::glm::gtc::quaternion::inverse(rot) * glm::vec3(0.0f, 0.0f, 1.0f);
		glm::mat4 view = glm::mat4_cast(rot) * glm::translate(glm::mat4(), m_pos);
		
		m_viewProj = m_proj * view;
		m_dirty = false;
	}

	return m_viewProj;
}

glm::vec3 Camera::GetPosition()
{
	return -m_pos;
}

void Camera::SetPosition( glm::vec3 pos )
{
	m_pos = pos;
}

void Camera::SetRotation( float rotX, float rotY )
{
	m_rot.x = rotX;
	m_rot.y = rotY;
	m_dirty = true;
}

void Camera::TransitionTo( glm::vec3 pos, glm::vec2 rot, float time )
{
	m_sPos = m_pos;
	m_sRot = m_rot;
	m_dPos = pos - m_pos;
	m_dRot = rot - m_rot;
	m_time = 0.0f;
	m_dt = 1.0f/time;
}

bool Camera::Transition( float dt )
{
	if (m_time < 1.0f)
	{
		m_time += dt*m_dt;
		if (m_time >= 1.0f)
		{
			m_pos = m_sPos + m_dPos;
			m_rot = m_sRot + m_dRot;
			m_time = 1.0f;
			m_dirty = true;

			return true;
		}

		m_pos = m_dPos*m_time + m_sPos;
		m_rot = m_dRot*m_time + m_sRot;
		m_dirty = true;

		return false;
	}
	return true;
}

glm::vec2 Camera::GetRotation()
{
	return m_rot;
}*/
