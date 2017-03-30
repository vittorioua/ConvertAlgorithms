#include <QCoreApplication>
#include <vector>
#include "numbers.h"
#include <map>
#include <list>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <qdebug.h>

using namespace std;

void Binary::fromDecimal(int var){
    int remainder=var/2;                //Calculates quotient for binary
    if(var==0) return;                  //If quotient = 0 stop recursion
    if(var%2==0){                       //Checking remainder
        data.push_front(0);             //Without remainder - push 0
    }else{
        data.push_front(1);             //With remainder - push 1
    }
    fromDecimal(remainder);
}
void Binary::printData(){
    std::cout<<"Result: ";
    for(auto it: data){
       std::cout<<it;
    }
    std::cout<<"\n"<<endl;
}

void Octal::fromDecimal(int var){
    int remainder=var/8;                //Calculates quotient for octal
    if(var==0) return;                  //If quotient = 0 stop recursion
    if(var%8==0){                       //Checking remainder
        data.push_front(0);             //Without remainder - push 0
    }else{
        data.push_front(var%8);         //With remainder - push remainder
    }
    fromDecimal(remainder);
}

void Octal::printData(){
    std::cout<<"Result: ";
    for(auto it: data){
       std::cout<<it;
    }
    std::cout<<",8\n"<<endl;            //Adding octal base
}

void Hex::initMask(int base){
    /*                                  Algorithm
     * The only addition to the algorithm when converting from decimal to hexadecimal
     * is that a table must be used to obtain the hexadecimal digit
     * if the remainder is greater than decimal 9.
     * Starting with 10 we add value 55 to 'i', because in ASCII table letters A-Z starts from 65.
     * In cases 0-9 we add '0' symbol to convert int to char.
     * For example: test case two - 692 and base 2.
     * Base is - 2, therefore mask is 0 - 0, 1 - 1, 2 - 2, it's all.
     * 692 % 16: quotient = 43, remainder = 4, our mask do not has data for key '4',
     * therefore it will be blank symbol - ' '.
     * 43 % 16: quotient = 2, remainder = 11, our mask do not has data for key '11',
     * therefore it will be blank symbol - ' '.
     * 2 % 16: quotient = 0, remainder = 2, out mask has data for key '2',
     * it will be '2'.
     * Result: 2  ,16.
     * But, if we choose, for example, 20 as base, we will have - 2B4,16 as result.
    */
    for(int i=0; i<=base; i++){
        if(i>=10){
            mask[i]=i+55;
        }else{
            mask[i]=i+'0';
        }
    }
}

void Hex::fromDecimal(int var){
    int remainder=var/16;              //Calculates quotient for hex
    if(var==0) return;                 //If quotient = 0 stop recursion
    if(var%16==0){                     //Checking remainder
        data.push_front(0+'0');        //Without remainder - push 0 with '0' symbol to convert int to char
    }else{
        data.push_front(mask[var%16]); //With remainder - push mask value by map key - value of remainder
    }
    fromDecimal(remainder);
}

void Hex::printData(){
    std::cout<<"Result: ";
    for(auto it: data){
       std::cout<<it;
    }
    std::cout<<",16\n"<<endl;          //Adding hex base
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //Begin
    while(true){
        std::cout<<"Decimal to Binary - 1"<<endl;
        std::cout<<"Decimal to Hex - 2"<<endl;
        std::cout<<"Decimal to Octal - 3"<<endl;
        std::cout<<"Exit - 4"<<endl;
        int state, number;
        std::cout<<"Choice: ";
        std::cin>>state;
        switch (state) {
        case 1:{
            Binary b1;
            std::cout<<"\nEnter number: ";
            std::cin>>number;
            b1.fromDecimal(number);
            b1.printData();
            break;
        }
        case 2:{
            int base;
            std::cout<<"\nEnter base: ";
            std::cin>>base;
            if(base>=2 && base<=36){     //Checking base range
                Hex h1(base);
                std::cout<<"Enter number: ";
                std::cin>>number;
                h1.fromDecimal(number);
                h1.printData();
            }else std::cout<<"Error: base element is out of range"<<endl;
            break;
        }
        case 3:{
            Octal o1;
            std::cout<<"\nEnter number: ";
            std::cin>>number;
            o1.fromDecimal(number);
            o1.printData();
            break;
        }
        default:{
            return false;
            break;
        }
        }
    }
    //End
    return a.exec();
}
