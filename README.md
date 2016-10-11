## Roman Numeral Calculator kata ##

The libcheck libraries are needed to build.
To install libcheck on Ubuntu 14.04: 
```
    sudo apt-get install check
```
My submission is on branch master. Other branches are me playing around.

To build the library and the test executable:
```
    make
```
Or, to build everything and run the tests:
```
    make test
```
My [continuous integration server](http://lion.guynes.net/ci/job/RomanNumeralCalculator/)
```
### For any that are concerned about my use of recursion. ###

There are three recursive functions.
```
    timesCharacterRepeatedInternal()
    toIntegerInternal()
    toRomanNumeralInternal()
```
All three implement tail-recursion.
Each function calls itself last and requires no further operations on the returned value. (e.g. my subcall's value returned plus 1)

The Makefile for the library compiles with -O2 flag which optimizes tail recursion to a loop. I have been investigating how to prove this optimization in a test but, short of disassembling the resulting library, I have not yet found a reasonable test method.

Any questions should be directed to wguynes@pillartechnology.com
