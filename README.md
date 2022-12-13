# Homework-6-Circular-Buffer
Homework 6
===
In this homework you will be implementing a simple custom class
that implements a Circular Buffer that stores characters (char).
The class definition, main function  and some of the class implementations are provided for you. You 
will be required to complete the class implementation to enable the provided main function.
This homework will give you practice in writing code for a pre-defined class definition as well as tech you a commonly used data strcuture. 

Circular Buffer
===
As an electrical engineering, it is often you are writing programs/firmware 
for resource constrained platforms such as a microcontroller. 
The circular buffer (or ring buffer) is a data structure often used in embedded environments.

The circular buffer is a fixed-sized buffer that treats the memory as if it is a circular structure.
Two location pointers are used to enable a circular buffer:
1. Insertion location (head) for putting values
2. Extraction location (tail) for getting values

Upon initialization of a circular buffer the head and tail location are the same.
When a value is inserted into the buffer the head location is updated. 
However, when a value is extracted from the buffer the tail location is updated. 
It is possible that the circular buffer can become full.
When inserting into a full buffer, the head and tail are updated causing values to be overwritten. 
When implementing the circular buffer the head/tail locations often go past the capacity and will wrap back around.
This wrap around is intentional. When using a circular buffer, values are constantly being overwritten and 
valid data is only determined by those values that are between tail and head locations. 
See below for a visual of a circular buffer. 

![Circular_Buffer](circular_buffer.png)

More in complete details on Circular Buffers can be found at:
https://www.embedded.com/ring-buffer-basics/

Tasks
===
1. Read all the comments CharCircularBuffer.h they explain what each method/variable is/does.
2. Implement the non-provided class member functions
3. Pass the tests
4. DO NOT shift values copying them down, this is NOT a circular buffer!!!

Pseudo Code - Put
===
```
function put(character to put)

    Place new character at head location
    
    if (full)
        Move tail up one location
    
    Move head up one location
    
    Set full if head == tail 
```
Pseudo Code - Get
```
function get - Return oldest value
    
    if empty
        return char();
        
    Grab/store value at tail location
    
    Update full to false 
    
    Move tail up one location
    
    return value that was pulled out of buffer
```

Reset Condition
===
Upon reset or initialization:
```
head = tail = 0
full = false
```

Input
===
1. First input is an integer to specify the buffer capacity
2. Second input is string to push through the circular buffer

Hints
===
* Incrementing the tail/head can cause their locations to wrap around.
* The modulus operator can be used to handle the wrap around, consider the following equation 
```
next_position = (current_position + 1) % total_positions
```
* getSize calculations change based on head >= tail or not
* isEmpty is true when buffer is not full AND head == tail
* Using buffer, just use it like a normal array.
