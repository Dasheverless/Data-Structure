#include<bits/stdc++.h>

template <class, class>
constexpr bool is_same_v = false; // determine whether arguments are the same type
template <class _Ty>
constexpr bool is_same_v<_Ty, _Ty> = true;

template<class T, class Container = std::vector<T>>
class stack
{
	typedef long long ll;
	using value_type = typename Container::value_type;
	/*test value_type and container's value_type*/
	static_assert(is_same_v<value_type, T>,"type not matched");
public:
	/*constuctor*/
	stack(T x)
	{
		c.push_back(x);
	}
	stack(const std::vector<T>& _c)
		:c(_c)
	{
	}
	stack(const stack& other)
	{
		c = other.c;
	}
	stack()
	{}
	/*modifier*/
	void push(T x)
	{
		c.push_back(x);
	}
	T pop()
	{
		int x = c.back();
		c.pop_back();
		return x;
	}
	/*access*/
	T top()
	{
		return c.back();
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
	stack operator = (const stack& other)
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
	std::stack<int> t;
	stack<int> stk(5);
	stk.push(1);
	stk.push(2);
	std::cout << stk.pop() << ' '; 
	std::cout << stk.top() << ' ';
	std::cout << stk.empty() << ' ';
	std::cout << stk.size() << '\n';
	stack<int> stk2 = stk;
	stack<int> stk3({ 1,2,3 });
	//test value match
	stack<int, std::list<long long>> stk4;
	stack<int, std::deque<int >> stk5;
}
