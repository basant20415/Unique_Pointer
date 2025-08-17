#include <bits/stdc++.h>
using namespace std;

template <typename T> class custom_unique_ptr {
public:
  // 1-constructor

  explicit custom_unique_ptr(T *ptr) : m_ptr(ptr) {}
  // explicit custom_unique_ptr():m_ptr(new int){}

  // operator overloading *
  T operator*() {
    return *(m_ptr);
  }

  void set_value(T &&val) {
    *m_ptr = move(val); // move semantics
  }

  // when using this->m_ptr=val; in setvalue function i found an error  error:
  // invalid conversion from ‘int’ to ‘int*’ [-fpermissive]
  //    23 | this->m_ptr=val;
  //       |             ^~~
  //       |             |
  //       |             int
  // -> is actually member access through a pointer.

  // If m_ptr were a pointer to a struct/class, you’d use m_ptr->member.

  // But here, m_ptr points to a primitive type (int), so you need *m_ptr, not
  // m_ptr->.

  void change_ptr(T *ptr) {
    delete m_ptr;
    m_ptr = ptr;
  }

  T get_address() { return m_ptr; }

  void print() { cout << *m_ptr; }

  // destructor
  ~custom_unique_ptr() { delete m_ptr; }

private:
  T *m_ptr;
};

int main() {

  custom_unique_ptr<int> p(new int);
  // custom_unique_ptr<int>p;
  p.set_value(1000);
  p.print();

  // -------
  // int x;
  // x=10;
  // p.change_ptr(&x);
  // p.print();

  //  Why This code Causes a Segmentation Fault:
  // the change_pointer method deletes the memory pointed to by m_pointer.
  // Initially, m_pointer points to heap-allocated memory (new int), so this
  // works correctly for the first delete. After assigning &x to m_pointer,
  // m_pointer points to a variable on the stack (x). The destructor of
  // custom_unique_ptr or subsequent calls to delete on m_pointer attempt to
  // free stack memory, which is undefined behavior and causes a segmentation
  // fault.
  // ---------------
  // usnig explicit keyword in constructor
  // int x=100;
  // print(&x); //some compilers will not cause any error when passing an
  // address of variable to a function needs an object from custom_unique_ptr
  // class as inside the custom_unique_ptr class the constructor takes a
  // pointer but when using explicit it force me to make an object from the
  // class and use it in the print function as follows
  // custom_unique_ptr<int>a;
  // print(a);
  //   ---------
  // this keyword is,when we create an object from the class in the main we can
  // access this object inside the class by using this->m_pointer and using this
  // helps the compiler to decrease the searching time for m_pointer in
  // namespaces and the classes where we inherit from
}