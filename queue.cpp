#include<bits/stdc++.h>

template <class, class>
constexpr bool is_same_v = false; // determine whether arguments are the same type
template <class _Ty>
constexpr bool is_same_v<_Ty, _Ty> = true;

template<class T, class Container = std::deque<T>>
class queue
{
	typedef long long ll;
	using value_type = typename Container::value_type;
	/*test value_type and container's value_type*/
	static_assert(is_same_v<value_type, T>,"type not matched");
public:
	/*constuctor*/
	queue(T x)
	{
		c.push_back(x);
	}
	queue(const Container& _c)
		:c(_c)
	{
	}
	queue(const queue& other)
	{
		c = other.c;
	}
	queue()
	{}
	/*modifier*/
	void push(T x)
	{
		c.push_back(x);
	}
	T pop()
	{
		T x = c.front();
		c.pop_front();
		return x;
	}
	/*access*/
	T back()
	{
		return c.back();
	}
	T front()
	{
		return c.front();
	}
	ll size()
	{
		return c.size();
	}
	bool empty()
	{
		return c.empty();
	}
	/*copy*/
	queue operator = (const queue& other)
	{
		c = other.c;
	}
private:

public:
private:
	Container c;//container
};
int main()
{
	queue<int> q(5);
	q.push(1);
	q.push(2);
	q.push(3);
	std::cout << q.pop() << ' '; 
	std::cout << q.front() << ' ';
	std::cout << q.empty() << ' ';
	std::cout << q.size() << '\n';
	queue<int> q2 = q;
	queue<int> q3({ 1,2,3 });
	//test value match
	//queue<int, std::list<long long>> q4;
	queue<int, std::deque<int >> q5;
}
