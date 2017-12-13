#include "GameObject.h"

namespace AEngine::Game
{
	GameObject::GameObject() :gameObject(this), m_parentObject(nullptr)
	{
	}

	GameObject * GameObject::GetParent()
	{
		return m_parentObject;
	}
}