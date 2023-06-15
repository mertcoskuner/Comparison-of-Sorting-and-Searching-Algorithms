
#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"
template <class Comparable>
class heap_sort
{
public:
    void heapSort( );
    
    void insert(const Comparable &firstName, const Comparable & lastName, const Comparable & phoneNumber, const  Comparable & City);
    
private:
    struct Info{
        Comparable firstName;
        Comparable lastName;
        Comparable phoneNumber;
        Comparable City;
        

        Info( const Comparable & firstname = Comparable( ),const Comparable & lastname = Comparable( ),const Comparable & phonenumber = Comparable( ),const Comparable & city = Comparable( ) ): firstName( firstname ),lastName(lastname),  phoneNumber(phonenumber), City(city) { }
    };
    inline void swap( Info & obj1,Info & obj2 );
    void percDown( vector<Info> & a, int i, int n );
    void heapsort(vector<Info> & a);



    vector<Info> info;
    bool compare(Info a, Info b);
 };

#include "heap_sort.cpp"
#endif




