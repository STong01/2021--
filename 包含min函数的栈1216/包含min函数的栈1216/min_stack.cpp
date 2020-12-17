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
	std::stack<T>   m_data;     // ����ջ�����ջ������Ԫ��
	std::stack<T>   m_min;      // ����ջ�����ջ����СԪ��
};

//����ջ�����ݽṹ���ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min�������ڸ�ջ�У�����min��push�Լ�pop��ʱ�临�Ӷȶ���O��1��
//ʵ�ָ�������push��ѹ�룩����
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

//ʵ�ָ�������pop�����������
template<typename T>void StackWithMin<T>::pop()
{
	assert(m_data.size() > 0 && m_min.size() > 0);
	m_data.pop();
	m_min.pop();
}

//ʵ�ָ������е�min����СԪ�أ�����
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