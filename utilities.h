#include <Arduino.h>

#ifndef UTILITIES_H
#define UTILITIES_H

#define dword unsigned long
#define ulong unsigned long


//==============================
// Bit manipulation
//==============================
//------------------------------
//getbit
//------------------------------
//!Return the nth Bit of the variable x
/*!
    \param x value
    \param n bitnumber
*/
boolean getbit(byte x, int n);
boolean getbit(word x, int n);
boolean getbit(dword x, int n);

//------------------------------
//setbit
//------------------------------
//!Set the nth Bit of the variable x to b
/*!
    \param x value
    \param n bitnumber
    \param b bitvalue
*/
byte setbit(byte x, int n, boolean b);
word setbit(word x, int n, boolean b);
dword setbit(dword x, int n, boolean b);


//==============================
// Signalgeneration
//==============================
//------------------------------
// Blink
//------------------------------
//! Generate an alternating digital signal with a specific low and high time.
/*!
    If Blink::enable is set to true Blink::out is set to true for the
    timespan of Blink::timehigh. After this Blink::out is set to false for
    the timespan Blink::timelow.

    If Blink::out is set to false, Blink::out is set to false immediatly.

    The **smallest timespan** for either Blink::timelow or Blink::timehigh is **1ms**.

    A sample implementation can be found in `examples/blink/blink.ino`.
*/
class Blink {
private:
    ulong t0;
    boolean last_enable;
public:
    //!Input variable
    boolean enable;
    //!Output variable
    boolean out;
    //!low time in ms
    ulong timelow;
    //!high time in ms
    ulong timehigh;

    //!Constructor
    Blink();
    //!Constructor with low and high time
    Blink(long timelow, long timehigh);
    //!Call cyclic for data processing
    boolean process();
    //!Call cyclic for data processing
    /*!
        \param enable value for input variable
    */
    boolean process(boolean enable);
};
#endif
