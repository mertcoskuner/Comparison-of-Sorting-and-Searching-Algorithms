#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"


template <class Comparable>
void sequantial_search<Comparable>::search_helper(string query, bool check,bool print){
    search( info,query, check, print );
}

template <class Comparable>
void sequantial_search<Comparable>::search( vector<Info> sorted_vector, string query,bool check,bool print  )
{
    

    vector<int> index;
    if(!check){
        int index1 = query.find(" ") ;
        string  firstName = query.substr(0,index1) ;
        string lastName = query.substr(index1+1 , query.length());
        for (int i = 0; i < sorted_vector.size(); i++)
            if (sorted_vector[i].firstName == firstName &&sorted_vector[i].lastName == lastName){
                index.push_back(i);


            }
            else if((sorted_vector[i].firstName == firstName && sorted_vector[i].lastName.substr(0,(lastName.length())) == lastName)){
                index.push_back(i);
            }
    }
    else{
        string  firstName =query;
        for (int i = 0; i < sorted_vector.size(); i++)
            if (sorted_vector[i].firstName.substr(0,(firstName.length()))== firstName)
                index.push_back(i);
    }
    
    if(print){
        
        if(index.size()!= 0){
            for(int i =0 ;i< index.size(); i++){
                cout << sorted_vector[index[i]].firstName<< " "<<sorted_vector[index[i]].lastName<< " " << sorted_vector[index[i]].phoneNumber<< " " <<sorted_vector[index[i]].City<<endl  ;
            }
            
        }
        else{
            cout << query <<" does NOT exist in the dataset"<<endl;
            
        }
    }
   
}

