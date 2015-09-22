// Vector2.hpp

#ifndef __VECTOR2_HPP__
#define __VECTOR2_HPP__

class Vector2f
{
	public:
		Vector2f();
		Vector2f(float p_Unit);
		Vector2f(float p_X, float p_Y);
		~Vector2f();

	public:
		float X;
		float Y;
};

#endif
