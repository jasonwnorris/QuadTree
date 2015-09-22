// Rectangle.cpp

#include "Rectangle.hpp"

Rectangle::Rectangle() :
	m_Top(0.0f),
	m_Bottom(0.0f),
	m_Left(0.0f),
	m_Right(0.0f)
{
}

Rectangle::Rectangle(float p_Top, float p_Bottom, float p_Left, float p_Right) :
	m_Top(p_Top),
	m_Bottom(p_Bottom),
	m_Left(p_Left),
	m_Right(p_Right)
{
}

Rectangle::~Rectangle()
{
}

float Rectangle::GetTop() const
{
	return m_Top;
}

float Rectangle::GetBottom() const
{
	return m_Bottom;
}

float Rectangle::GetLeft() const
{
	return m_Left;
}

float Rectangle::GetRight() const
{
	return m_Right;
}

void Rectangle::Get(float& p_Top, float& p_Bottom, float& p_Left, float& p_Right) const
{
	p_Top = m_Top;
	p_Bottom = m_Bottom;
	p_Left = m_Left;
	p_Right = m_Right;
}

float Rectangle::GetWidth() const
{
	return m_Right - m_Left;
}

float Rectangle::GetHeight() const
{
	return m_Bottom - m_Top;
}

void Rectangle::SetTop(float p_Top)
{
	if (m_Top != p_Top)
	{
		m_Top = p_Top;

		PropertyChanged(this, PropertyChangedEventArgs("Top"));
	}
}

void Rectangle::SetBottom(float p_Bottom)
{
	if (m_Bottom != p_Bottom)
	{
		m_Bottom = p_Bottom;

		PropertyChanged(this, PropertyChangedEventArgs("Bottom"));
	}
}

void Rectangle::SetLeft(float p_Left)
{
	if (m_Left != p_Left)
	{
		m_Left = p_Left;

		PropertyChanged(this, PropertyChangedEventArgs("Left"));
	}
}

void Rectangle::SetRight(float p_Right)
{
	if (m_Right != p_Right)
	{
		m_Right = p_Right;

		PropertyChanged(this, PropertyChangedEventArgs("Right"));
	}
}

void Rectangle::Set(float p_Top, float p_Bottom, float p_Left, float p_Right)
{
	if (m_Top != p_Top || m_Bottom != p_Bottom || m_Left != p_Left || m_Right != p_Right)
	{
		m_Top = p_Top;
		m_Bottom = p_Bottom;
		m_Left = p_Left;
		m_Right = p_Right;

		PropertyChanged(this, PropertyChangedEventArgs("All"));
	}
}

bool Rectangle::Contains(const Rectangle& p_Rectangle) const
{
	return m_Top < p_Rectangle.GetLeft() && m_Bottom > p_Rectangle.GetBottom() && m_Left < p_Rectangle.GetLeft() && m_Right > p_Rectangle.GetRight();
}

bool Rectangle::Contains(Rectangle* p_Rectangle) const
{
	return m_Top < p_Rectangle->GetLeft() && m_Bottom > p_Rectangle->GetBottom() && m_Left < p_Rectangle->GetLeft() && m_Right > p_Rectangle->GetRight();
}

bool Rectangle::Intersects(const Rectangle& p_Rectangle) const
{
	return !(m_Right < p_Rectangle.GetLeft() || m_Left > p_Rectangle.GetRight() || m_Bottom < p_Rectangle.GetTop() || m_Top > p_Rectangle.GetBottom());
}

bool Rectangle::Intersects(Rectangle* p_Rectangle) const
{
	return !(m_Right < p_Rectangle->GetLeft() || m_Left > p_Rectangle->GetRight() || m_Bottom < p_Rectangle->GetTop() || m_Top > p_Rectangle->GetBottom());
}
