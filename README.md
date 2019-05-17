# Cpp.Structures.DynamicArray
This repository contains hand-made dynamic array structure with test unit.

DynArray can:
* relocate buffer with new capacity;
* append new elements;
* get elements from buffer;
* remove elements from buffer;
* insert element in any position.

All buffer operations uses some coefficients like:
* Increase coefficient 2.0 (Used in append/insert actions when buffer overfilled);
* Decrease coefficient 1.5 (Used in remove actions when buffer to large and need to be reduced);
