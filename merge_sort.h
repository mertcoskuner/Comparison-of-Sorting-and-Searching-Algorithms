
#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"
template <class Comparable>
class merge_sort
{
public:
    void mergeSort( );

    void insert(const Comparable &firstName, const Comparable & lastName, const Comparable & phoneNumber, const  Comparable & City);
private:
    struct Info{
        Comparable firstName;
        Comparable lastName;
        Comparable phoneNumber;
        Comparable City;
        

        Info( const Comparable & firstname = Comparable( ),const Comparable & lastname = Comparable( ),const Comparable & phonenumber = Comparable( ),const Comparable & city = Comparable( ) ): firstName( firstname ),lastName(lastname),  phoneNumber(phonenumber), City(city) { }
    };
    void mergeSort( vector<Info> & a,vector<Info> & tmpArray, int left, int right );
    void merge(  vector<Info> & a,vector<Info> & tmpArray,int leftPos, int rightPos, int rightEnd );
    vector<Info> info;
    bool compare(Info a, Info b);
 };

#include "merge_sort.cpp"
#endif



