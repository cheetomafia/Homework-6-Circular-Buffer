#ifndef CHAR_CIRCULAR_BUFFER_H
#define CHAR_CIRCULAR_BUFFER_H
#include <memory>

class CharCircularBuffer
{

public:
    /**
     * Constructor
     * @param capacity - total number of characters buffer can store
     */
    CharCircularBuffer(int capacity);

    /**
     * Put a single character into circular buffer
     * Head is moved by one.
     * If buffer is full, last character (tail) is overwritten
     * Update full status after placement into buffer
     * @param ch - character to place in buffer
     */
    void put(const char ch);

    /**
     * Grab last character in buffer (tail)
     * If not empty tail is moved by one.
     * @return - Last character in the buffer (tail)
     */
    char get();

    /**
     * Reset head = tail, (Buffer empty)
     */
    void reset();

    /**
     * @return if the buffer is full
     */
    bool isFull() const;

    /**
     * @return if the buffer is empty
     */
    bool isEmpty() const;

    /**
     * @return total capacity allowed for buffer
     */
    int getCapacity() const;

    /**
     * @return total characters in the buffer
     */
    int getSize() const;

    /**
     * Helper function to print status of buffer
     */
    void printStatus() const;

private:
    /**
     * Smart pointer for storage of dynamic character array
     */
    std::unique_ptr<char[]> buffer;

    /**
     * Total character count allowed in buffer
     */
    const int capacity;

    /**
     * Index of the front (head) of the buffer
     * Putting new characters go here
     */
    int head;

    /**
     * Index of the end (tail) of the buffer
     * Getting characters come from here
     */
    int tail;

    /**
     * Keeps track of the full state of the buffer
     */
    bool full;

};

#endif
