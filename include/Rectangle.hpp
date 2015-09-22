// Rectangle.hpp

#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "INotifyPropertyChanged.hpp"
#include "PropertyChangedEventArgs.hpp"

class Rectangle : public INotifyPropertyChanged<Rectangle, PropertyChangedEventArgs>
{
	public:
		Rectangle();
		Rectangle(float p_Top, float p_Bottom, float p_Left, float p_Right);
		~Rectangle();

		float GetTop() const;
		float GetBottom() const;
		float GetLeft() const;
		float GetRight() const;
		void Get(float& p_Top, float& p_Bottom, float& p_Left, float& p_Right) const;
		float GetWidth() const;
		float GetHeight() const;

		void SetTop(float p_Top);
		void SetBottom(float p_Bottom);
		void SetLeft(float p_Left);
		void SetRight(float p_Right);
		void Set(float p_Top, float p_Bottom, float p_Left, float p_Right);

		bool Contains(const Rectangle& p_Rectangle) const;
		bool Contains(Rectangle* p_Rectangle) const;
		bool Intersects(const Rectangle& p_Rectangle) const;
		bool Intersects(Rectangle* p_Rectangle) const;

	private:
		float m_Top;
		float m_Bottom;
		float m_Left;
		float m_Right;
};

#endif
