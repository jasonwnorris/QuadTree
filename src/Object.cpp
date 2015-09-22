// Object.cpp

#include "Object.hpp"

Object::Object() :
	m_Value(0)
{
}

Object::Object(int p_Value) :
	m_Value(p_Value)
{
}

Object::~Object()
{
}

int Object::GetValue() const
{
	return m_Value;
}

void Object::SetValue(int p_Value)
{
	m_Value = p_Value;
}
