# Vector Class in Python

This repository contains a custom implementation of a `Vector` class in Python, designed to emulate the functionality of a dynamic array or vector that can resize itself as elements are added or removed. The class includes a variety of methods for managing and manipulating vector data, including resizing, adding/removing elements, and element-wise operations.

## Features

- **Dynamic Resizing**: Automatically increases the capacity when the vector is full and shrinks to fit its size when elements are removed.
- **Element Access**: Supports access to individual elements using indices and slicing.
- **Push and Pop**: Allows adding elements to both ends of the vector (`push_back`, `push_front`) and removing them (`pop_back`, `pop_front`).
- **Element Operations**: Supports addition, subtraction, multiplication, division, modulo, and comparison between vectors.
- **Erasing Elements**: Erase elements by index or value, with support for multiple occurrences.
- **Capacity Management**: Shrink the vector's capacity to match its size (`shrink_to_fit`).
- **Vector Copy and Swap**: Copy another vector or swap contents between two vectors.
- **Equality and Comparison**: Check if two vectors are equal or compare them lexicographically.

## Installation

You can download or clone the repository using:

```bash
git clone https://github.com/yourusername/Algorithms-and-Data-Structures.git
```

### Dependencies

- Python 3.x
- NumPy (for array manipulation)

You can install NumPy using:

```bash
pip install numpy
```

## Usage

### Create a Vector

To create a new vector, simply instantiate the `Vector` class:

```python
from vector import Vector

v = Vector()
```

### Add Elements

To add elements to the vector, use the `push_back` (to add to the end) or `push_front` (to add to the front):

```python
v.push_back(10)
v.push_front(5)
```

### Remove Elements

To remove elements, use `pop_back` (from the end) or `pop_front` (from the front):

```python
v.pop_back()
v.pop_front()
```

### Erase Elements by Index or Value

You can erase elements by index or value:

```python
v.erase_by_index(1)  # Removes element at index 1
v.erase_by_value(10, 1)  # Removes one occurrence of 10
```

### Access Elements

You can access elements using indexing or slicing:

```python
v[0]  # Access the first element
v[1:3]  # Access a slice of the vector
```

### Resize and Capacity Management

The vector will resize itself automatically when full, but you can also manually shrink its capacity:

```python
v.shrink_to_fit()
```

### Element-wise Operations

You can perform element-wise operations on vectors (e.g., addition, subtraction, etc.):

```python
v1 = Vector()
v1.push_back(1)
v1.push_back(2)

v2 = Vector()
v2.push_back(3)
v2.push_back(4)

result = v1 + v2  # Vector addition
result = v1 - v2  # Vector subtraction
result = v1 * v2  # Vector multiplication
```

### Comparison Operations

You can compare vectors using the following operators:

```python
v1 == v2  # Equal
v1 < v2   # Less than
v1 > v2   # Greater than
```

### Swap Vectors

To swap contents between two vectors:

```python
v1.swap(v2)
```

### Clear the Vector

To remove all elements from the vector:

```python
v.clear()
```

### Copy a Vector

To copy the contents of one vector into another:

```python
v1.copy(v2)
```

## Methods Summary

| Method              | Description                                                    |
|---------------------|----------------------------------------------------------------|
| `push_back(element)` | Add an element to the end of the vector.                       |
| `push_front(element)`| Add an element to the front of the vector.                     |
| `pop_back()`         | Remove the last element from the vector.                       |
| `pop_front()`        | Remove the first element from the vector.                      |
| `erase_by_index(i)`  | Erase the element at the specified index.                      |
| `erase_by_value(val, count)` | Erase elements by value, remove a specific count.        |
| `shrink_to_fit()`    | Shrink the vector’s capacity to its current size.              |
| `at(index)`          | Access an element at a specific index.                         |
| `front()`            | Get the first element of the vector.                           |
| `back()`             | Get the last element of the vector.                            |
| `swap(other)`        | Swap contents with another vector.                            |
| `clear()`            | Clear all elements from the vector.                            |
| `copy(other)`        | Copy elements from another vector.                            |
| `==`, `!=`, `<`, `>`, `<=`, `>=` | Comparison operations between vectors.                 |

## Contributing

Feel free to fork the repository and submit pull requests with improvements or bug fixes. If you encounter any issues, please open an issue on the GitHub page.

