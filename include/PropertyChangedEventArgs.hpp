// PropertyChangedEventArgs.hpp

#ifndef __PROPERTYCHANGEDEVENTARGS_HPP__
#define __PROPERTYCHANGEDEVENTARGS_HPP__

#include <string>

class PropertyChangedEventArgs
{
	public:
		PropertyChangedEventArgs(const std::string p_PropertyName);
		~PropertyChangedEventArgs();

		const std::string& GetPropertyName() const;

	private:
		std::string m_PropertyName;
};

#endif
