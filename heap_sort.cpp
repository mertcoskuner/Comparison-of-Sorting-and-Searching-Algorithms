
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"
#include "heap_sort.h"

template <class Comparable>
void heap_sort<Comparable>::heapSort( )
{
    heapsort(info);
}

template <class Comparable>
void heap_sort<Comparable>::insert(const Comparable &firstName, const Comparable & lastName, const Comparable & phoneNumber, const  Comparable & City){

    info.push_back(Info(firstName,lastName, phoneNumber,City));
}


template <class Comparable>
bool heap_sort<Comparable>::compare(Info a,  Info b){
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
inline void heap_sort<Comparable>::swap( Info & obj1,Info & obj2 )
{
     Info tmp = obj1;
     obj1 = obj2;
     obj2 = tmp;
}

template <class Comparable>
void heap_sort<Comparable>::heapsort(vector<Info> & a)
{
    // buildHeap
    for (int i = a.size()/2; i >=0; i--)
        percDown(a, i, a.size());

    // sort
    for (int j = a.size()-1; j >0; j--)
    {
         swap(a[0], a[j]);    // swap max to the last pos.
          percDown(a, 0, j); // re-form the heap
    }
}
inline int leftChild( int i )
{
    return 2*i+1;
}

template <class Comparable>  // for deleteMax
// a is the array, i is the position to percolate down from
// n is the logical size of the array
void heap_sort<Comparable>::percDown( vector<Info> & a, int i, int n )
{
      int child;
      Info tmp;

      for (tmp=a[i] ; leftChild(i) < n; i = child )
      {
            child = leftChild(i);
            if ( child != n-1 &&compare(a[ child  ] , a[ child+1 ] ) )
                 child++;
                 if ( compare(tmp,a[ child  ]) )
                      a[i] = a[ child ];
                 else
                      break;
       }
       a[ i ] = tmp;
}
 

