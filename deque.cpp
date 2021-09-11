#include <bits/stdc++.h>
namespace ttl
{
#ifndef __DEQUE_MAP_INIT_SIZE
#define __DEQUE_MAP_INIT_SIZE 8
#endif
template <class T>
struct __deque_buf_size
{
    static constexpr size_t value = sizeof(T) < 512 ? 512 / sizeof(T) : size_t(1);
};


template<class T, class Ref, class Ptr>
struct __deque_iterator
{
    typedef __deque_iterator<T, T&, T*> iterator;
    typedef __deque_iterator<T, const T&, const T*> const_iterator;
    typedef T value_type;
    typedef Ptr pointer;
    typedef Ref reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T** map_pointer;
    static const size_type buffer_size = __deque_buf_size<T>::value;

    typedef __deque_iterator self;
    T* cur;
    T* first;
    T* last;
    map_pointer node;
    void set_node(map_pointer new_node)
    {
        node = new_node;
        first = *new_node;
        last = first + difference_type(buffer_size);//
    }
};

template<class T>
class deque
{
public:
    typedef T value_type;
    typedef value_type* pointer;
    typedef pointer* map_pointer;
    typedef size_t size_type;
    std::allocator<T> data_Alloc;
    std::allocator<T*> map_Alloc;
    typedef std::allocator_traits<std::allocator<T>> data_allocator;
    typedef std::allocator_traits<std::allocator<T*>> map_allocator;
    typedef __deque_iterator<T, T&, T*> iterator;
    typedef __deque_iterator<T, const T&, const T*> const_iterator;
    static const size_type buffer_size = __deque_buf_size<T>::value;

    iterator begin() { return start; }
    iterator end() { return finish; }
    bool empty() { return start == finish; }
public:
    deque(int n, const value_type& value)
        :start(), finish(), map(0), map_size(0)
    {
        fill_initialize(n, value);
    }
    void fill_initialize(size_type n, const value_type& value)
    {
        creat_map_and_nodes(n);
        map_pointer cur;
        for (cur = start.node; cur < finish.node; cur++)
        {
            std::uninitialized_fill(*cur, *cur + buffer_size, value);
        }
        std::uninitialized_fill(finish.first, finish.cur, value);
    }

    void push_back(const value_type& v)
    {
        if (finish.cur != finish.last - 1)//放完当前元素后还有空间
        {
            data_allocator::construct(data_Alloc, finish.cur, v);
            finish.cur++;
        }
        else
        {
            push_back_aux(v);//缓冲区只剩一个空间(放了当前的就满了)
        }
    }
    void push_back_aux(const value_type& v)
    {
        value_type v_copy = v;
        //reserve_map_at_back();//判断需不需要扩容
        *(finish.node + 1) = allocate_node();
        //try
        data_allocator::construct(data_Alloc, finish.cur, v_copy);
        finish.set_node(finish.node + 1);
        finish.cur = finish.first;
    }

    void push_front(const value_type& v)
    {
        if (start.cur != start.first)//缓冲区还有空间
        {
            data_allocator::construct(data_Alloc, start.cur - 1, v);//反向生长
            start.cur--;
        }
        else//缓冲区满了
        {
            push_front_aux(v);
        }
    }
    void push_front_aux(const value_type& v)
    {
        value_type v_copy = v;
        //reserve_map_at_front();
        *(start.node - 1) = allocate_node();
        //try
        start.set_node(start.node - 1);
        start.cur = start.last - 1;
        data_allocator::construct(data_Alloc, start.cur, v);
        //catch
    }
    void creat_map_and_nodes(size_type num_elements)
    {
        size_type num_nodes = num_elements / buffer_size + 1;
        map_size = std::max(static_cast<size_type>(__DEQUE_MAP_INIT_SIZE), num_nodes + 2);//头和尾各预留一个节点
        map = map_allocator::allocate(map_Alloc, map_size);//分配map空间
        map_pointer nstart = map + (map_size - num_nodes) / 2;//初始尽量往中间放
        map_pointer nfinish = nstart + num_nodes - 1;
        map_pointer cur;
        for (cur = nstart; cur <= nfinish; cur++)
        {
            *cur = allocate_node();//分配缓存区空间
        }
        //设置迭代器内容
        start.set_node(nstart);
        finish.set_node(nfinish);
        start.cur = start.first;
        finish.cur = finish.first + num_elements % buffer_size;
    }
    T* allocate_node()
    {
        return data_allocator::allocate(data_Alloc, buffer_size);
    }

protected:
    iterator start; //第一个map节点
    iterator finish;//最后一个节点
    map_pointer map;
    size_type map_size;
    
};
}
void solve()
{
    
}
int main()
{
    int q = 1;
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    //cin >> q;
    while (q--)
    {
        solve();
    }
}
