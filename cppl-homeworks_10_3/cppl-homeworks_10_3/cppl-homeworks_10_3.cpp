// cppl-homeworks_10_3.cpp 

#include <iostream>

template <class T>
class uniq_ptr
{
public:
   
    
    uniq_ptr() 
    {
        ptr_ = new T();
        std::cout << "created object" << "\n";
    }

    uniq_ptr(int size)
    {
        ptr_ = new T(size);
        std::cout << "created object" << "\n";
    }

    uniq_ptr<T>(uniq_ptr * other) 
    {
        ptr_=other->ptr_;
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

    T& release()
    { 
        uniq_ptr <T> temp;
        temp.ptr_ = ptr_;
        ptr_=nullptr;
        return *temp;
    }

    T* get_adress()
    {
        return ptr_;
    }

private:
    T* ptr_ = nullptr;
    uniq_ptr (const uniq_ptr& other){}
    void operator = (const uniq_ptr& other) {}
};

int main()
{ 
    uniq_ptr <int> r;
    std::cout << r.get_adress() << std::endl;
    uniq_ptr <int> f;
    std::cout << "f.release()= " << &f.release() << std::endl;
    std::cout << "f.ptr_ = " << f.get_adress() << std::endl;
    std::cout << "__________________"<<std::endl;
    uniq_ptr <int>x(10);
    std::cout << x.get_adress()<<std::endl;
    std::cout << "__________________"<<std::endl;
    std::cout << f.get_adress() << std::endl;
    std::cout << "__________________"<<std::endl;
    std::cout << "data =" << *x << std::endl;
    std::cout << "__________________"<<std::endl;

    
    return 0;
}
