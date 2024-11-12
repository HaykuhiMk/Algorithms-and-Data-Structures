import numpy as np
from typing import Union

class Vector:
    def __init__(self) -> None:
        self.arr: np.ndarray = np.array([], dtype="int")
        self._v_size: int = 0
        self._v_capacity: int = 0
    
    @property
    def v_size(self) -> int:
        """Return the current number of elements."""
        return self._v_size
    
    @v_size.setter
    def v_size(self, size: int) -> None:
        if size < 0:
            raise ValueError("New size cannot be negative")
        if not isinstance(size, int):
            raise TypeError("Size must be an integer.")
        self._v_size = size

    @property
    def v_capacity(self) -> int:
        """Return the current capacity."""
        return self._v_capacity
    
    @v_capacity.setter
    def v_capacity(self, capacity: int) -> None:
        if not isinstance(capacity, int):
            raise TypeError("Capacity must be an integer.")
        self._v_capacity = capacity

    def __str__(self) -> str:
        return str(self.arr[:self.v_size])
    
    def __repr__(self) -> str:
        return f"Vector(arr = {self.arr}, size = {self._v_size}, capacity = {self._v_capacity})"

    def is_empty(self) -> bool:
        """Return True if the vector is empty."""
        return self.v_size == 0
    
    def __resize(self) -> None:
        """Resize the vector if the capacity is full."""
        self.v_capacity = 2 if not self.v_capacity else self.v_capacity * 2
        self.arr = np.pad(self.arr, (0, self.v_capacity - self.v_size), 'constant', constant_values=0)

    def push_back(self, element: int) -> None:
        """Add an element to the end of the vector."""
        if self.v_size == self.v_capacity: 
            self.__resize()
        self.arr[self.v_size] = element
        self.v_size += 1
            
    def pop_back(self) -> int:
        """Remove the last element from the vector."""
        if self.is_empty():
            raise IndexError("Pop from empty vector")
        self.v_size -= 1
        return self.arr[self.v_size]
    
    def shrink_to_fit(self) -> None:
        """Shrink the vector capacity to fit its current size."""
        if self.v_size == self.v_capacity:
            return
        self.arr.resize(self.v_size)
        self.v_capacity = self.v_size

    def at(self, index: int) -> int:
        """Access an element at a specific index with bounds checking."""
        return self[index]
    
    def push_front(self, element: int) -> None:
        """Add an element to the front of the vector."""
        if self.v_size == self.v_capacity:
            self.__resize()
        for i in range(self.v_size, 0, -1):
            self.arr[i] = self.arr[i - 1]
        self.arr[0] = element
        self.v_size += 1
        
    def pop_front(self) -> Union[int, None]:
        """Remove the first element from the vector."""
        if self.is_empty():
            print("Vector is empty!")
            return None
        retval = self.arr[0]
        for i in range(self.v_size - 1):
            self.arr[i] = self.arr[i + 1]
        self.v_size -= 1
        return retval
        
    def front(self) -> int:
        """Return the first element of the vector."""
        if self.is_empty():
            raise IndexError("Vector is empty")
        return self.arr[0]
    
    def back(self) -> int:
        """Return the last element of the vector."""
        if self.is_empty():
            raise IndexError("Vector is empty")
        return self.arr[self.v_size - 1]
    
    def __index_validator(self, index: int) -> bool:
        return isinstance(index, int) and (0 <= index < self.v_size)
        
    def erase_by_index(self, *args: int) -> None:
        """Erase elements by index."""
        if len(args) == 2:
            start, end = args
            if self.__index_validator(start) and self.__index_validator(end) and start < end:
                for i in range(self.v_size - end):
                    self.arr[start + i] = self.arr[end + i]
                self.v_size -= (end - start)
                return
        elif len(args) == 1:
            if self.__index_validator(args[0]):
                for i in range(args[0], self.v_size - 1):
                    self.arr[i] = self.arr[i + 1]
                self.v_size -= 1
                return
        print("Invalid function call.")

    def erase_by_value(self, value: int, count: int = 1) -> None:
        """Erase elements by value."""
        if count < 0:
            raise ValueError("Count cannot be negative.")
        founded_count = 0
        i = 0
        while(i != self.v_size):
            if self.arr[i] == value:
                founded_count += 1
                self.erase_by_index(i)
            else:
                i += 1
            if founded_count == count:
                break
        print(f"Deleted {founded_count}/{count} elements.")

    def swap(self, other: 'Vector') -> None:
        """Swap contents with another vector."""
        if not isinstance(other, Vector):
            raise TypeError("Argument must be a Vector.")
        size = max(self.v_size, other.v_size)
        if self.v_capacity < size:
            self.__resize()
        if other.v_capacity < size:
            other.__resize()
        for i in range(size):
            self.arr[i], other.arr[i] = other.arr[i], self.arr[i]
        self.v_size, other.v_size = other.v_size, self.v_size
        self.v_capacity, other.v_capacity = other.v_capacity, self.v_capacity

    def clear(self) -> None:
        """Clear the vector."""
        self.v_size = 0

    def copy(self, other: 'Vector') -> None:
        """Copy the contents of another vector."""
        if not isinstance(other, Vector):
            raise TypeError("Argument must be a Vector.")
        if self.v_capacity < other.v_size:
            self.__resize()
        for i in range(other.v_size):
            self.arr[i] = other.arr[i]
        self.v_size = other.v_size
    
    def __eq__(self, other: "Vector") -> bool:
        """Check if two vectors are equal."""
        if self.v_size != other.v_size:
            return False
        return all(self.arr == other.arr)
    
    def __le__(self, other: "Vector") -> bool:
        """Check if the vector is less than or equal to another vector."""
        min_size = min(self.v_size, other.v_size)
        for i in range(min_size):
            if self.arr[i] > other.arr[i]:
                return False
        return self.v_size <= other.v_size or self == other

    def __lt__(self, other: "Vector") -> bool:
        """Check if the vector is less than another vector."""
        min_size = min(self.v_size, other.v_size)
        for i in range(min_size):
            if self.arr[i] > other.arr[i]:
                return False
            elif self.arr[i] < other.arr[i]:
                return True
        return self.v_size < other.v_size
    
    def __gt__(self, other: "Vector") -> bool:
        """Check if the vector is greater than another vector."""
        return not self <= other
    
    def __ge__(self, other: "Vector") -> bool:
        """Check if the vector is greater than or equal to another vector."""
        return not self < other
    
    def __format__(self) -> str:
        """String representation for formatting."""
        return self.__str__()
    
    def __getitem__(self, index: Union[int, slice]) -> Union[int, np.ndarray]:
        """Access an element or slice of the vector."""
        if isinstance(index, int):
            if not -self.v_size <= index < self.v_size:
                raise IndexError("Index out of bounds.")
            return self.arr[index]
        
        elif isinstance(index, slice):
            start, stop, step = index.indices(self.v_size)  
            return self.arr[start:stop:step]
        
        else:
            raise TypeError("Index must be an integer or slice.")

    
    def __add__(self, other: "Vector") -> "Vector":
        """Add two vectors element-wise."""
        min_size = min(self.v_size, other.v_size)
        v = Vector()
        for i in range(min_size):
            v.push_back(self.arr[i] + other.arr[i])
        if self.v_size != other.v_size:
            if self.v_size < other.v_size:
                for i in range(self.v_size, other.v_size):
                    v.push_back(other.arr[i])
            else:
                for i in range(other.v_size, self.v_size):
                    v.push_back(self.arr[i])
        return v
    
    def __sub__(self, other: "Vector") -> "Vector":
        """Subtract two vectors element-wise."""
        min_size = min(self.v_size, other.v_size)
        v = Vector()
        for i in range(min_size):
            v.push_back(self.arr[i] - other.arr[i])
        if self.v_size != other.v_size:
            if self.v_size < other.v_size:
                for i in range(self.v_size, other.v_size):
                    v.push_back(-other.arr[i])
            else:
                for i in range(other.v_size, self.v_size):
                    v.push_back(self.arr[i])
        return v
    
    def __mul__(self, other: "Vector") -> "Vector":
        """Multiply two vectors element-wise."""
        min_size = min(self.v_size, other.v_size)
        v = Vector()
        for i in range(min_size):
            v.push_back(self.arr[i] * other.arr[i])
        if self.v_size != other.v_size:
            if self.v_size < other.v_size:
                for i in range(self.v_size, other.v_size):
                    v.push_back(other.arr[i])
            else:
                for i in range(other.v_size, self.v_size):
                    v.push_back(self.arr[i])
        return v
    
    def __imul__(self, other: "Vector") -> "Vector":
        """Multiply the vector by another element-wise and update the vector."""
        if not isinstance(other, Vector):
            raise TypeError("Argument must be a Vector.")
        
        min_size = min(self.v_size, other.v_size)
        
        for i in range(min_size):
            self.arr[i] *= other.arr[i]
        self.v_size = min_size
        return self

    def __iadd__(self, other: "Vector") -> "Vector":
        """Add another vector to this vector and update the vector."""
        if not isinstance(other, Vector):
            raise TypeError("Argument must be a Vector.")
        
        min_size = min(self.v_size, other.v_size)
        
        for i in range(min_size):
            self.arr[i] += other.arr[i]
        
        if self.v_size < other.v_size:
            for i in range(self.v_size, other.v_size):
                self.push_back(other.arr[i])
        
        return self

    def __isub__(self, other: "Vector") -> "Vector":
        """Subtract another vector from this vector and update the vector."""
        if not isinstance(other, Vector):
            raise TypeError("Argument must be a Vector.")
        
        min_size = min(self.v_size, other.v_size)
        
        for i in range(min_size):
            self.arr[i] -= other.arr[i]
        
        if self.v_size < other.v_size:
            for i in range(self.v_size, other.v_size):
                self.push_back(-other.arr[i])
        
        return self

    def __itruediv__(self, other: "Vector") -> "Vector":
        """Divide this vector by another vector element-wise and update."""
        if not isinstance(other, Vector):
            raise TypeError("Argument must be a Vector.")
        
        min_size = min(self.v_size, other.v_size)
        
        for i in range(min_size):
            if other.arr[i] == 0:
                raise ZeroDivisionError("Cannot divide by zero.")
            self.arr[i] /= other.arr[i]
        
        if self.v_size < other.v_size:
            for i in range(self.v_size, other.v_size):
                if other.arr[i] == 0:
                    raise ZeroDivisionError("Cannot divide by zero.")
                self.push_back(0)  
        return self
    

    def __ifloordiv__(self, other: "Vector") -> "Vector":
        """Floor divide this vector by another vector element-wise."""
        if not isinstance(other, Vector):
            raise TypeError("Argument must be a Vector.")
        
        min_size = min(self.v_size, other.v_size)
        
        for i in range(min_size):
            if other.arr[i] == 0:
                raise ZeroDivisionError("Cannot divide by zero.")
            self.arr[i] //= other.arr[i]
        
        if self.v_size < other.v_size:
            for i in range(self.v_size, other.v_size):
                if other.arr[i] == 0:
                    raise ZeroDivisionError("Cannot divide by zero.")
                self.push_back(0)  
        
        return self

    def __imod__(self, other: "Vector") -> "Vector":
        """Modulo this vector by another vector element-wise."""
        if not isinstance(other, Vector):
            raise TypeError("Argument must be a Vector.")
        
        min_size = min(self.v_size, other.v_size)
        
        for i in range(min_size):
            self.arr[i] %= other.arr[i]
        
        if self.v_size < other.v_size:
            for i in range(self.v_size, other.v_size):
                self.push_back(0)
        
        return self
