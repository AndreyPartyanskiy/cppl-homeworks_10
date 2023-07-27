// cppl-homeworks_10_3.cpp 

#include <iostream>

template <class T>
class uniq_ptr
{
public:
    T* ptr_ = nullptr;
    uniq_ptr() 
    {
        ptr_ = new T();
        std::cout << "created object" << "\n";
    }
    ~uniq_ptr()
    {
        delete[] ptr_;
        std::cout << "deleted object" << "\n";
    }
    
    

    void operator* ( uniq_ptr <T>& temp)
    {
        
         std::cout << "call oper* = " << this.ptr_ << std::endl;
    }

    void release(uniq_ptr <T>& in)
    { 
        this->ptr_ = in.ptr_;
        in.ptr_=nullptr;     
    }
private:

    uniq_ptr (const uniq_ptr& other){}
    void operator = (const uniq_ptr& other) {}
};

int main()
{ 
    uniq_ptr <int> r;
    std::cout << r.ptr_ << std::endl;
    uniq_ptr <int> f;
    f.release(r);
    std::cout << f.ptr_ << std::endl;
    
    return 0;
}
