#ifndef NUMBERS_H
#define NUMBERS_H
#include <list>
#include <map>
#include <iostream>
//Class for binary numbers
class Binary{
public:
    void fromDecimal(int var);
    void printData();                   //Printing data function
private:
    std::list<int> data;
};

//Class for octal numbers
class Octal{
public:
    void fromDecimal(int var);
    void printData();                   //Printing data function
private:
    std::list<int> data;
};

//Class for hex numbers
class Hex{
public:
    explicit Hex(int base){
        initMask(base);
    }
    void fromDecimal(int var);
    void printData();                   //Printing data function
private:
    void initMask(int base);
    std::map<int,char> mask;
    std::list<char> data;
};

#endif // NUMBERS_H
