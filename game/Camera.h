#pragma once
/*#include "stdafx.h"

class Camera
{
public:
	Camera(int width, int height);
	~Camera();

	void Resize(int width, int height);

	glm::mat4& GetViewProjection();

	void SetPosition(glm::vec3 pos);
	void SetRotation(float rotX, float rotY);

	void Move(float side, float forward);
	void Look(float side, float up);

	void TransitionTo(glm::vec3 pos, glm::vec2 rot, float time);
	bool Transition(float dt);

	glm::vec3 GetPosition();
	glm::vec2 GetRotation();
private:
	glm::vec3	m_sPos, m_dPos;
	glm::vec2	m_sRot, m_dRot;
	float		m_time, m_dt;

	glm::vec3	m_pos, m_fwd;
	glm::vec2	m_rot;

	glm::mat4	m_viewProj;
	bool		m_dirty;
	glm::mat4	m_proj;
};*/