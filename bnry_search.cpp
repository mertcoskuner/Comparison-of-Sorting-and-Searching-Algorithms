#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include "strutils.h"
#include "bnry_search.h"


template <class Comparable>
void bnry_search<Comparable>::search_helper(string query, bool check,bool print){
    search( info,query, check, print );
}


template <class Comparable>
void bnry_search<Comparable>::search( vector<Info> sorted_vector, string query,bool check,bool print  )
{
    

    vector<int> index;
    if(!check){
        int index1 = query.find(" ") ;
        string  firstName = query.substr(0,index1) ;
        string lastName = query.substr(index1+1 , query.length());
        int low=0 ;
        int high = sorted_vector.size() ;
        // Repeat until the pointers low and high meet each other
      while (low <= high) {
        int i = low + (high - low) / 2;
          if ((sorted_vector[i].firstName == firstName && sorted_vector[i].lastName == lastName)){
              index.push_back(i);
              break;

          }
          else if((sorted_vector[i].firstName == firstName && sorted_vector[i].lastName.substr(0,(lastName.length())) == lastName)&& sorted_vector[i].lastName.length()!= lastName.length() ){
              while( sorted_vector[i].lastName.substr(0,(lastName.length())) == lastName){
                  i--;
                   
              }
              i++ ;
              while( sorted_vector[i].lastName.substr(0,(lastName.length())) == lastName){
                  index.push_back(i);
                  i++;
                   
              }
              low=i ;
          }
          

          else if (sorted_vector[i].firstName < firstName ){
              low = i + 1;
          }
          
        
          else  if (sorted_vector[i].firstName ==  firstName && sorted_vector[i].lastName < lastName ){
              low = i + 1;
          }
            

          else{
              high = i - 1;
          }
          
      }

           
    }
    else{
        int low=0 ;
        int high = sorted_vector.size() ;
        // Repeat until the pointers low and high meet each other
      while (low <= high) {
        int i = low + (high - low) / 2;

          if (sorted_vector[i].firstName.substr(0,(query.length())) == query ){
              while(sorted_vector[i].firstName.substr(0,(query.length())) == query){
                  i--;
                   
              }
              i++ ;
              while(sorted_vector[i].firstName.substr(0,(query.length())) == query){
                  index.push_back(i);
                  i++;
                   
              }
              low=i ;
          }
       
          
          else if (sorted_vector[i].firstName.substr(0,(query.length())) < query ){
              low = i + 1;

          }

          else{
              high = i - 1;

          }
      }
      
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


