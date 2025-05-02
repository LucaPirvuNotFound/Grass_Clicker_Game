# Touch Grass Game

This is a repo of a project that I make for my Object Oriented Programming class

The project is required to be in C++ and I chose to also use the Qt framework in order to complete the GUI interface. The app that I use is called **Qt Creator 16.0.1 (Community)**

## The main concepts

Thouch Grass Game will be a clicker-type game based on the temporary Discord mini-game called **"The Last Meadow"**

The purpose of the game is to farm grass by clicking and buying different upgrades that either produce grass automatically or boosts the power of the click harvest.

Throughout the stages of the game, the user will encounter different obstacles that can obstruct the window view or can cause passive grass loss.

---

# 🧠 Project Guidelines

This document outlines the requirements and best practices for your C++ object-oriented programming project. Follow these rules to ensure proper structure, design, and maintainability of your codebase.

---

## 📁 Code Structure

- 🔹 Separate all class code into **header** (`.h` / `.hpp`) and **source** (`.cpp`) files.
  - Small or closely related classes can share the same header-source pair.
- 🚫 **Do not** use `using namespace std;` in any file.

---

## 🧬 Inheritance

- ➕ Implement at least **one base class** and **three derived classes**.
- 🏗 The inheritance hierarchy must be **custom**—do **not** derive from standard library classes.

---

## 🔁 Virtual Functions

- ✅ Include **at least one virtual function** (can be pure or not) that is **project-specific**.
  - Must go beyond basic I/O or library methods (e.g., avoid trivial `draw()`, `print()`, etc.).
- 📌 Virtual functions must be:
  - Called through **base class pointers**.
  - Stored as **class attributes**, not temporary references or pointers in `main`.

---

## 🧪 Virtual Constructors (Clone Pattern)

- Implement **virtual constructors** via a `clone()` method.
  - These are **required**, but do **not** count as project-specific virtual functions.

---

## 🧱 Constructor Inheritance

- Ensure **derived class constructors explicitly call the base class constructor**.

---

## 📦 Polymorphic Containers

- Create a class that contains **pointers to base class objects**, and:
  - Use **virtual functions** via the base interface.
  - Implement:
    - 🔁 Safe downcasting via `dynamic_cast` or `std::dynamic_pointer_cast`.
    - 💡 Use of **smart pointers** is **strongly recommended** (`std::shared_ptr`, `std::unique_ptr`).

---

## 🛠 Static Members

- Use **static methods or attributes** where they make sense.

---

## 🧰 STL & Modern C++

- Leverage the **Standard Template Library (STL)** effectively.
- Use `const` wherever applicable for safety and clarity.

---

## 🔼 High-Level Design

- ⚠️ Avoid excessive use of **getters**, **setters**, or **low-level utility functions**.
- 🧠 Focus on designing **high-level abstractions** and meaningful class responsibilities.

---

## ✅ Summary Checklist

- [x] Classes split into `.h` / `.cpp`
- [x] No `using namespace std;`
- [x] Custom inheritance hierarchy
- [x] At least one meaningful virtual function
- [x] Virtual functions called via base class pointers
- [x] Clone method implemented
- [x] Base constructor explicitly called
- [x] Smart pointer-based container class
- [x] Static members where appropriate
- [x] STL usage

---



