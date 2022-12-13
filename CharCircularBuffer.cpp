#include <memory>
#include <iostream>
#include "CharCircularBuffer.h"
using namespace std;

CharCircularBuffer::CharCircularBuffer(int capacity)
    : capacity(capacity), buffer(unique_ptr<char[]>(new char[capacity]))
{
    reset();
  
}

void CharCircularBuffer::printStatus() const
{
    cout << "------------------------------------\n";
    cout << "Buffer Capacity: " <<  getCapacity() << endl;
    cout << "Buffer Size: " <<  getSize() << endl;
    cout << "Buffer isEmpty: " << isEmpty() << endl;
    cout << "Buffer isFull: " << isFull() << endl;
    cout << "------------------------------------\n";
}

void CharCircularBuffer::put(const char ch){
buffer[head] = ch;

  if(full){
    tail= (tail+1) % capacity;
  }
  head = (head+1) % capacity;
  if (head==tail){
    full = true;
  }
  
}

char CharCircularBuffer::get(){
  if(isEmpty()){
    return char();
  }
  auto value = buffer[tail];
  full = false;
  tail = (tail+1) % capacity;

  return value;
}

void CharCircularBuffer::reset(){
  head = 0;
  tail = 0;
  full = false;
}
bool CharCircularBuffer::isFull() const{
  return full;
}
bool CharCircularBuffer::isEmpty() const{
  return(!full && (head == tail));
}
int CharCircularBuffer::getCapacity()  const{
  return(capacity);
}
int CharCircularBuffer::getSize() const{
  int size = capacity;
  if(!full){
    size = head - tail;
  }
  else if(full){
    size = capacity +head - tail;
  }
  return size;
}
