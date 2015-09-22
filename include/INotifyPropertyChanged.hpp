// INotifyPropertyChanged.hpp

#ifndef __INOTIFYPROPERTYCHANGED_HPP__
#define __INOTIFYPROPERTYCHANGED_HPP__

#include "Delegate.hpp"

template<typename T, typename E> class INotifyPropertyChanged
{
	public:
		Delegate<void, T*, const E&> PropertyChanged;
};

#endif
