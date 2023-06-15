#ifndef _QUICK_SORT_H
#define _QUICK_SORT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"
template <class Comparable>
class quick_sort
{
public:
    
    void quicksort( );
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
    vector<Info> info;
    Info median3( vector<Info> & a,int left, int right ){
        /** Return median of left, center, and right.
            *   Order these and hide the pivot.
          */
        int center = ( left + right ) / 2;
     
        if ( compare(a[ center ] , a[ left ]) )
          swap( a[ left ], a[ center ] );
      
        if (compare(a[ right ] , a[ left ]) )
          swap( a[ left ], a[ right ] );
      
        if (  compare(a[ right ] ,a[ center ]))
          swap( a[ center ], a[ right ] );

        // Place pivot at position right - 1
        swap( a[ center ], a[ right - 1 ] );
        return a[ right - 1 ];
    }

    bool compare(Info a, Info b);
    void insertionSort( vector<Info> & a, int left, int right );
    void quicksort( vector<Info> & a,int left, int right );
    
    
    
    
 };

#include "quick_sort.cpp"
#endif




