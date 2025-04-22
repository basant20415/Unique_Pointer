#include<iostream>
using namespace std;
// to run this file comment the main function inside try file
template<typename T>
class custom_unique_ptr{
public:
//constructor-->request resource
// custom_unique_ptr(T* new_ptr){//1
// this->m_pointer=new_ptr;
// }
// this keyword is,when we create an object from the class in the main we can access this object inside the class by using this->m_pointer 
// and using this helps the compiler to decrease the searching time for m_pointer in namespaces and the classes where we inherit from
explicit custom_unique_ptr(){//2

new int;
}

// explicit custom_unique_ptr(){//3

// new int;
// }
// overloading operator "*" to access pointer
T operator*(){
return *(m_pointer);

}

void set_value(int value){
  *m_pointer=value;  
}

void change_pointer(T* p){
delete m_pointer;
m_pointer=p;
}

void get_address(){
    cout<<m_pointer;
}

//destructor--->release resource
~custom_unique_ptr(){
    delete m_pointer;
}

private:
T *m_pointer;

};

void print(custom_unique_ptr<int>a){

}

int main(){
// custom_unique_ptr<int>p(new int);//1
custom_unique_ptr<int>p;//2
p.set_value(100);
cout<<*p;
// ---
// Why This Causes a Segmentation Fault:

// the change_pointer method deletes the memory pointed to by m_pointer. Initially, m_pointer points to heap-allocated memory (new int), so this works correctly for the first delete.
// After assigning &x to m_pointer, m_pointer points to a variable on the stack (x). The destructor of custom_unique_ptr or subsequent calls to delete on m_pointer attempt to free stack memory, which is undefined behavior and causes a segmentation fault.
// int x=1000;
// p.change_pointer(&x);
// cout<<*p;

// ----
// 3.
// usnig explicit keyword in constructor
// int x=100;
// print(&x); //some compilers will not cause any error when passing an address of variable to a function needs an object from custom_unique_ptr class 
// as inside the custom_unique_ptr class the constructor takes a pointer 
// but when using explicit it force me to make an object from the class and use it in the print function as follows
// custom_unique_ptr<int>a;
// print(a);

}