
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"
#include "merge_sort.h"


template <class Comparable>
void merge_sort<Comparable>::insert(const Comparable &firstName, const Comparable & lastName, const Comparable & phoneNumber, const  Comparable & City){

    info.push_back(Info(firstName,lastName, phoneNumber,City));
}


template <class Comparable>
bool merge_sort<Comparable>::compare(Info a,  Info b){
    if(a.firstName == b.firstName){
        if(a.lastName< b.lastName){
            return true;
        }
        else{
            return false ;
        }
    }
    else if(a.firstName < b.firstName){
        return true;
    }
    else{
        return false;
    }
    

}


template <class Comparable>
void merge_sort<Comparable>::mergeSort( )
{
     vector<Info> tmpArray( info.size( ) );

     mergeSort( info, tmpArray, 0, info.size( ) - 1 );
}

/**
* Internal method that makes recursive calls.
* a is an array of Comparable items.
* tmpArray is an array to place the merged result.
* left is the left-most index of the subarray.
* right is the right-most index of the subarray.
*/
template <class Comparable>
void merge_sort<Comparable>::mergeSort( vector<Info> & a,vector<Info> & tmpArray, int left, int right )
{
     if ( left < right )
     {
           int center = ( left + right ) / 2;
           mergeSort( a, tmpArray, left, center );
           mergeSort( a, tmpArray, center + 1, right );
           merge( a, tmpArray, left, center + 1, right );
     }
    
}

/**
* Internal method that merges two sorted halves of a subarray.
* a is an array of Comparable items.
* tmpArray is an array to place the merged result.
* leftPos is the left-most index of the subarray.
* rightPos is the index of the start of the second half.
* rightEnd is the right-most index of the subarray.
*/
template <class Comparable>
void merge_sort<Comparable>::merge(  vector<Info> & a,vector<Info> & tmpArray, int leftPos, int rightPos, int rightEnd )
{
      int leftEnd = rightPos - 1;
      int tmpPos = leftPos;
      int numElements = rightEnd - leftPos + 1;

   
    
    // Main loop
    while ( leftPos <= leftEnd && rightPos <= rightEnd )
         if ( compare(a[ leftPos ],  a[ rightPos ] ) )
             tmpArray[ tmpPos++ ] = a[ leftPos++ ];
         else
             tmpArray[ tmpPos++ ] = a[ rightPos++ ];

    while ( leftPos <= leftEnd )    // Copy rest of first half
        tmpArray[ tmpPos++ ] = a[ leftPos++ ];

    while ( rightPos <= rightEnd )  // Copy rest of right half
        tmpArray[ tmpPos++ ] = a[ rightPos++ ];

    // Copy tmpArray back
    for ( int i = 0; i < numElements; i++, rightEnd-- )
        a[ rightEnd ] = tmpArray[ rightEnd ];
}



    
