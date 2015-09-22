// Object.hpp

#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

class Object
{
	public:
		Object();
		Object(int p_Value);
		~Object();

		int GetValue() const;

		void SetValue(int p_Value);

	private:
		int m_Value;
};

#endif
