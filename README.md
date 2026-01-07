# ResourceManager++

A modern and extensible C++20 resource management framework built using templates, interfaces, and strict ownership through `std::unique_ptr`.  
Designed to demonstrate clean architecture, type safety, semantic resource handling, and modern C++ practices.

---

## 🚀 Features

- **IResource interface** defining a unified, polymorphic resource model  
- **Resource** implementation with:
  - name
  - value
  - unique auto-incrementing ID
- **Template-based ResourceManager<T>**
  - supports any resource type derived from `IResource`
  - stores resources using `std::unique_ptr`
- **Semantic ownership transfer**
  - resources are identified and moved by ID
  - no index-based manipulation
- **Memory-safe design**
  - no raw pointers
  - no manual memory management
- **Modular header-only architecture**

---

## 🧩 Architecture Overview

