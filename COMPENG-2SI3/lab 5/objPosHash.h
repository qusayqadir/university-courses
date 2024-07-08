// Interface for different Hash Tables

// Two Closed Hashing Probing Setups:
    // Quadratic        h(x) = sum of all digits{ ASCII Prefix digits, Number Digits}
    // Double           h2(x) = sum of all h(x) digits mod M
        // Come up with another secondary hashing function for better performance (?)
    
// Theory
    // All possible combinations of {capitalized PF, Num} are 26 x 100 = 2600
    // Using bit vector is very memory inefficient
    // Using BST suffers O(log n) complexity
    // Using closed hashing results in 37-element table (9+9+9+9 = 36) PLUS 0
    //  with O(1) complexity and less memory consumption if hashing function is well chosen
    //  - will need lazy deletion to check off collected elements

// Use printMe() for hasing table contents for cluster confirmation
// Use getLambda() for measuring the hash table load factor
// Use chrono for measuring performance improvement

// ** Also, use objPos.symbol for marking lazy deletion
    //  symbol == 0 indicates element is deleted / empty
    //  symbol != 0 indicates element valid

#ifndef OBJPOS_HASHING_TABLE_H
#define OBJPOS_HASHING_TABLE_H

#include "objPos.h"

#define TABLE_SIZE 37
#define MAX_PROBING_COUNT 1000  // arbitrary to avoid integer overflow

class objPos;  // forward declaration

class objPosHashTable  // this is NOT an interface but an abstract class!!
{
    protected:
        int tableSize;

    public:        
        virtual ~objPosHashTable(){};

        virtual bool insert(const objPos &thisPos) = 0;
        virtual bool remove(const objPos &thisPos) = 0;  // lazy delete 
        virtual bool isInTable(const objPos &thisPos) const = 0;
        virtual double getLambda() const = 0;
        virtual void printMe() const = 0;
};

#endif