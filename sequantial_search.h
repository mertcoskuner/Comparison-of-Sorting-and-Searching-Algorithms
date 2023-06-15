
#ifndef _SEQUANTIAL_SEARCH_H
#define _SEQUANTIAL_SEARCH_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"

template <class Comparable>
class sequantial_search
{
public:
    void insertionSort () {
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
    vector<Comparable>  vector_help () ;
    void insert(const Comparable &firstName, const Comparable & lastName, const Comparable & phoneNumber, const  Comparable & City){
        info.push_back(Info(firstName,lastName, phoneNumber,City));
    }
    void search_helper(string query, bool check,bool print ); 
private:
    struct Info{
        Comparable firstName;
        Comparable lastName;
        Comparable phoneNumber;
        Comparable City;
        

        Info( const Comparable & firstname = Comparable( ),const Comparable & lastname = Comparable( ),const Comparable & phonenumber = Comparable( ),const Comparable & city = Comparable( ) ): firstName( firstname ),lastName(lastname),  phoneNumber(phonenumber), City(city) { }
    };
    vector<Info> info;
    void search( vector<Info> sorted_vector, string x, bool check,bool print );

    bool compare(Info a, Info b){
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
 };










#include "sequantial_search.cpp"
#endif





