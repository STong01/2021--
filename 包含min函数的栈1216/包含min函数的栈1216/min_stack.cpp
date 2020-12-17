#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

template <typename T> class StackWithMin
{
public:
	StackWithMin() {}
	virtual ~StackWithMin() {}

	T& top();

	const T& top() const;

	void push(const T& value);

	void pop();

	const T& min() const;

	bool empty() const;

	size_t size() const;

private:
	std::stack<T>   m_data;     // 数据栈，存放栈的所有元素
	std::stack<T>   m_min;      // 辅助栈，存放栈的最小元素
};

//定义栈的数据结构，在该类型中实现一个能够得到栈的最小元素的min函数，在该栈中，调用min，push以及pop的时间复杂度都是O（1）
//实现该类型中push（压入）功能
template<typename T>void StackWithMin<T>::push(const T& value)
{
	m_data.push(value);
	if (m_min.size() == 0 || value < m_min.top())
	{
		m_min.push(value);
	}
	else
	{
		m_min.push(m_min.top());
	}
}

//实现该类型中pop（输出）功能
template<typename T>void StackWithMin<T>::pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	m_data.pop();
	m_min.pop();
}

//实现该类型中的min（最小元素）功能
template<typename T>const T& StackWithMin<T>::min()const
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	return m_min.top();
}


template <typename T> T& StackWithMin<T>::top()
{
	return m_data.top();
}

template <typename T> const T& StackWithMin<T>::top() const
{
	return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const
{
	return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const
{
	return m_data.size();
}

int main()
{

	system("pause");
	return 0;
}