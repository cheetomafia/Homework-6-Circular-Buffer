#include <iostream>
#include "CharCircularBuffer.h"
using namespace std;

const bool SHOW_PROMTPS = false;

int main()
{
    // Locals to store buffer capacity and message to buffer
    int capacity;
    string msg;

    // Query user for buffer capacity
    if( SHOW_PROMTPS ){
      cout << "Enter buffer capacity: ";
    }
    
    cin >> capacity;

    // Create the char circular buffer, print status
    CharCircularBuffer buff(capacity);
    buff.printStatus();

    // Grab message to place into buffer
    if( SHOW_PROMTPS ){
      cout << "Enter message: ";
    }
    getline(cin >> ws, msg);

    // Buffer each character in char circular buffer
    cout << "Putting values in buffer" <<endl;
    for(int i=0; i<msg.size(); ++i)
    {
        buff.put(msg.at(i));
    }
    buff.printStatus();

    // After buffer process print out what is in the circular buffer
    cout << "Buffer contents: ";
    while(!buff.isEmpty())
    {
        cout << buff.get();
    }
    cout << endl;

    // Test resetting the buffer and print status
    cout << "Resetting buffer" << endl;
    buff.reset();
    buff.printStatus();

    return 0;
}
