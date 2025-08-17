# Custom Unique Pointer (C++ Implementation)

This project implements a simplified version of `std::unique_ptr` in C++.  
The class `custom_unique_ptr<T>` demonstrates how smart pointers manage dynamic memory using the **RAII (Resource Acquisition Is Initialization)** principle, ensuring safe allocation and deallocation of resources.

---

## Features

- **RAII (Resource Acquisition Is Initialization)**  
  - Memory is acquired in the constructor (`new`) and released in the destructor (`delete`).  
  - Guarantees no memory leaks if the object goes out of scope.  
  - Follows the C++ principle: *"own the resource for the lifetime of the object."*

- **Custom Constructor**  
  Accepts a raw pointer to dynamically allocated memory.

- **Dereference Operator (`*`)**  
  Provides access to the underlying object.

- **Move Semantics in `set_value`**  
  Uses `std::move` to efficiently assign values to the managed object.

- **Change Pointer**  
  Replaces the managed pointer with a new one.  
  > ⚠️ Be careful: Assigning stack addresses (e.g., local variables) can cause undefined behavior.

- **Destructor**  
  Automatically deletes the managed memory when the object goes out of scope.

- **Helper Functions**  
  - `set_value(T&& val)` → Sets value of the managed object.  
  - `change_ptr(T* ptr)` → Changes ownership to a new pointer.  
  - `get_address()` → Returns the address being managed.  
  - `print()` → Prints the stored value.

---

## Example Usage

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create unique pointer (RAII principle: constructor acquires resource)
    custom_unique_ptr<int> p(new int);

    // Set value
    p.set_value(1000);

    // Print value
    p.print(); // Output: 1000

    // Destructor automatically releases memory when 'p' goes out of scope
    return 0;
}
