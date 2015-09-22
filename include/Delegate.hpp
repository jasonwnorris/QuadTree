// Delegate.hpp

#ifndef __DELEGATE_HPP__
#define __DELEGATE_HPP__

// STD Includes
#include <functional>
#include <vector>

template<typename Ret, typename... Args> class Delegate
{
	public:
		template<typename U> Delegate& Add(const U& p_Callback)
		{
			m_Callbacks.push_back(std::function<Ret(Args...)>(p_Callback));

			return *this;
		}

		template<typename U> Delegate& Remove(const U& p_Callback)
		{
			m_Callbacks.erase(m_Callbacks.remove(m_Callbacks.begin(), m_Callbacks.end(), p_Callback), m_Callbacks.end());

			return *this;
		}

		template<typename U> Delegate& RemoveAll()
		{
			m_Callbacks.clear();

			return *this;
		}

		std::vector<Ret> operator()(Args... p_Parameters)
		{
			std::vector<Ret> ret;
			for (auto func : m_Callbacks)
			{
				m_Callbacks.push_back(func(p_Parameters...));
			}

			return ret;
		}

	private:
		std::vector<std::function<Ret(Args...)>> m_Callbacks;
};

template<typename... Args> class Delegate<void, Args...>
{
	public:
		template<typename U> Delegate& Add(const U& p_Callback)
		{
			m_Callbacks.push_back(std::function<void(Args...)>(p_Callback));

			return *this;
		}

		template<typename U> Delegate& Remove(const U& p_Callback)
		{
			m_Callbacks.erase(m_Callbacks.remove(m_Callbacks.begin(), m_Callbacks.end(), p_Callback), m_Callbacks.end());

			return *this;
		}

		template<typename U> Delegate& RemoveAll()
		{
			m_Callbacks.clear();

			return *this;
		}

		void operator()(Args... params)
		{
			for (auto func : m_Callbacks)
				func(params...);
		}

	private:
		std::vector<std::function<void(Args...)>> m_Callbacks;
};

#endif
