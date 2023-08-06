// cppl-homeworks_10_3.cpp 

#include <iostream>

class Counter
{
public:
    int a;
    Counter(int in_a): a(in_a) {}
};

template <class T>
class uniq_ptr
{
public:
    
    template <typename... Args>
    uniq_ptr(Args&&... args)
    {
        ptr_ = new T(std::forward<Args>(args)...);
        std::cout << "created object" << "\n";
    }

    uniq_ptr(T* a): ptr_(a)
    {
        std::cout << "created object" << "\n";
    }

    ~uniq_ptr()
    {
        delete[] ptr_;
        std::cout << "deleted object" << "\n";
    }

    T& operator* ()
    {
        std::cout << "call oper* = " << ptr_ << std::endl;
        return *ptr_;
    }

    T* release()
    {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    T* get_adress()
    {
        return ptr_;
    }

private:
    T* ptr_ = nullptr;
    uniq_ptr(const uniq_ptr& other) {}
    void operator = (const uniq_ptr& other) {}
};

int main()
{ 
    uniq_ptr <int> r;
    std::cout << r.get_adress() << std::endl;
    uniq_ptr <int> f;
    std::cout << "f.release()= " << f.release() << std::endl;
    std::cout << "f.ptr_ = " << f.get_adress() << std::endl;
    std::cout << "__________________"<<std::endl;
    uniq_ptr <int>x(10);
    std::cout << x.get_adress()<<std::endl;
    std::cout << "__________________"<<std::endl;
    std::cout << f.get_adress() << std::endl;
    std::cout << "__________________"<<std::endl;
    std::cout << "data =" << *x << std::endl;
    std::cout << "__________________"<<std::endl;
    uniq_ptr<int> ppp(100);

    
    std::cout << "\n" << "RELEASE()_" << std::endl;
    auto a = ppp.release();
    std::cout << "ppp.ptr_ = " << ppp.get_adress() << std::endl;
    std::cout << *a << " must be 100" << std::endl;
    std::cout << "___________" << "\n" << std::endl;

    //int* ptrx=a;
    //std::cout << "ptrx = " << &ptrx << std::endl;
    //uniq_ptr <int*> ptrx_x(ptrx);
    //std::cout << "ptrx_x->ptrx = " << *ptrx_x << std::endl;

    std::cout << "\n" << "Counter* ptrx " << std::endl;
    Counter* ptrx = new Counter(3);
    std::cout << "ptrx = " << ptrx << std::endl;
    uniq_ptr<Counter> c(ptrx);
    std::cout << "c->ptrx = " << c.release() << std::endl;
    std::cout << "___________" << "\n" << std::endl;

    return 0;
}
