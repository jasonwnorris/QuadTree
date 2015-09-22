// Vector2.cpp

#include "Vector2.hpp"

Vector2f::Vector2f()
{
	X = 0.0f;
	Y = 0.0f;
}

Vector2f::Vector2f(float p_Unit)
{
	X = p_Unit;
	Y = p_Unit;
}

Vector2f::Vector2f(float p_X, float p_Y)
{
	X = p_X;
	Y = p_Y;
}

Vector2f::~Vector2f()
{
}
