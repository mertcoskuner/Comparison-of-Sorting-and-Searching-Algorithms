#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"
#include "insertion_sort.h"

template <class Comparable>
void insertion_sort<Comparable>::insert(const Comparable &firstName, const Comparable & lastName, const Comparable & phoneNumber, const  Comparable & City){

    info.push_back(Info(firstName,lastName, phoneNumber,City));
}


template <class Comparable>
bool insertion_sort<Comparable>::compare(Info a,  Info b){
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
void insertion_sort<Comparable>::insertionSort ()
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


