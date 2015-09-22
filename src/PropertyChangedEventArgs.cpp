// PropertyChangedEventArgs.cpp

#include "PropertyChangedEventArgs.hpp"

PropertyChangedEventArgs::PropertyChangedEventArgs(const std::string p_PropertyName) :
	m_PropertyName(p_PropertyName)
{
}

PropertyChangedEventArgs::~PropertyChangedEventArgs()
{
}

const std::string& PropertyChangedEventArgs::GetPropertyName() const
{
	return m_PropertyName;
}
