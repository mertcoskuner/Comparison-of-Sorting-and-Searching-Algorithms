#ifndef _INSERTION_SORT_H
#define _INSERTION_SORT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"
template <class Comparable>
class insertion_sort
{
public:
    
    void insertionSort () ;
    vector<Comparable>  vector_help () ; 
    void insert(const Comparable &firstName, const Comparable & lastName, const Comparable & phoneNumber, const  Comparable & City);
private:
    struct Info{
        Comparable firstName;
        Comparable lastName;
        Comparable phoneNumber;
        Comparable City;
        

        Info( const Comparable & firstname = Comparable( ),const Comparable & lastname = Comparable( ),const Comparable & phonenumber = Comparable( ),const Comparable & city = Comparable( ) ): firstName( firstname ),lastName(lastname),  phoneNumber(phonenumber), City(city) { }
    };
    vector<Info> info;
    bool compare(Info a, Info b);
 };

#include "insertion_sort.cpp"
#endif



















