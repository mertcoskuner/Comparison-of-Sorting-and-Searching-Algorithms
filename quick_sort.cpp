#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"
#include "quick_sort.h"


/**
 * Quicksort algorithm (driver).
*/
template <class Comparable>
void quick_sort<Comparable>::quicksort( )
{
      quicksort( info, 0, info.size( ) - 1 );
}
/**
* Standard swap
*/
template <class Comparable>
inline void quick_sort<Comparable>::swap( Info & obj1,
                           Info & obj2 )
{
     Info tmp = obj1;
     obj1 = obj2;
     obj2 = tmp;
}
template <class Comparable>

bool quick_sort<Comparable>::compare(Info a,  Info b){
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




/**
* Internal quicksort method that makes recursive calls.
* Uses median-of-three partitioning and a cutoff of 10.
* a is an array of Comparable items.
* left is the left-most index of the subarray.
* right is the right-most index of the subarray.
*/
template <class Comparable>
void quick_sort<Comparable>::quicksort( vector<Info> & a,int left, int right )
{
    if ( left + 10 <= right )
    {
         Info pivot = median3( a, left, right );
        // Begin partitioning
        int i = left, j = right - 1;
        for ( ; ; )
        {
            while (compare(a[ ++i ] , pivot) ) { }

            while (compare(pivot , a[ --j ])) { }

            if ( i < j )
                  swap( a[ i ], a[ j ] );
            else
                  break;
        }
        swap( a[ i ], a[ right - 1 ] );   // Restore pivot

        quicksort( a, left, i - 1 );       // Sort small elements
        quicksort( a, i + 1, right );    // Sort large elements
   }
   else  // Do an insertion sort on the subarray
        insertionSort( a, left, right );
    
}


/**
   * Internal insertion sort routine for subarrays
   * that is used by quicksort.
   * a is an array of Comparable items.
   * left is the left-most index of the subarray.
   * right is the right-most index of the subarray.
   */
  template <class Comparable>
  void quick_sort<Comparable>:: insertionSort( vector<Info> & a, int left, int right )
  {
      int j;
      for (int p = 1;  p < info.size(); p++)
      {
          Info tmp = info[p];
          for(j=p ; j>0 && compare(tmp,info[j-1]) ; j--){
              info[j] =info[j-1];
          }
          info[j] = tmp;
      }
  }


template <class Comparable>
void quick_sort<Comparable>::insert(const Comparable &firstName, const Comparable & lastName, const Comparable & phoneNumber, const  Comparable & City){

    info.push_back(Info(firstName,lastName, phoneNumber,City));
}
