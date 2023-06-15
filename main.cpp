//
//  main.cpp
//  HW5
//
//  Created by Mert Coskuner on 20.05.2023.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "quick_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "sequantial_search.h"
#include "strutils.h"
#include "bnry_search.h"

using namespace std;

void insertion_s(string filename){
    insertion_sort<string> insert_sort;

    
    ifstream  myFile(filename) ;
    string line;
    vector<string> variables;
    string myvar ;
    int index = 0 ;
    while(getline(myFile, line)){
        while(index != string::npos){
            index = line.find(" ") ;
            myvar = line.substr(0,index) ;
            line = line.substr(index+1 , line.length());
            variables.push_back(myvar) ;
        }
        insert_sort.insert(UpperString(variables[0]),UpperString(variables[1]), variables[2],variables[3]);
      
     
        variables.clear() ;
        index = 0 ;
    }
    insert_sort.insertionSort();
 
}

void quick_s(string filename){
    quick_sort<string> quick_sort;

    ifstream  myFile(filename) ;
    string line;
    vector<string> variables;
    string myvar ;
    int index = 0 ;
    while(getline(myFile, line)){
        while(index != string::npos){
            index = line.find(" ") ;
            myvar = line.substr(0,index) ;
            line = line.substr(index+1 , line.length());
            variables.push_back(myvar) ;
        }
        quick_sort.insert(UpperString(variables[0]),UpperString(variables[1]), variables[2],variables[3]);
      
     
        variables.clear() ;
        index = 0 ;
    }
    quick_sort.quicksort();
    
}
void  merge_s(string filename){
    merge_sort<string> merge_sort;

    ifstream  myFile(filename) ;
    string line;
    vector<string> variables;
    string myvar ;
    int index = 0 ;
    while(getline(myFile, line)){
        while(index != string::npos){
            index = line.find(" ") ;
            myvar = line.substr(0,index) ;
            line = line.substr(index+1 , line.length());
            variables.push_back(myvar) ;
        }
        merge_sort.insert(UpperString(variables[0]),UpperString(variables[1]), variables[2],variables[3]);
      
     
        variables.clear() ;
        index = 0 ;
    }
    merge_sort.mergeSort();
}
void  heap_s(string filename){
    heap_sort<string> heap_sort;

    ifstream  myFile(filename) ;
    string line;
    vector<string> variables;
    string myvar ;
    int index = 0 ;
    while(getline(myFile, line)){
        while(index != string::npos){
            index = line.find(" ") ;
            myvar = line.substr(0,index) ;
            line = line.substr(index+1 , line.length());
            variables.push_back(myvar) ;
        }
        heap_sort.insert(UpperString(variables[0]),UpperString(variables[1]), variables[2],variables[3]);
      
     
        variables.clear() ;
        index = 0 ;
    }
    heap_sort.heapSort();
}



void sequantial_search1(bool partial, string filename,string query, bool print ){
    sequantial_search<string> sequantial_search;

    ifstream  myFile(filename) ;
    string line;
    vector<string> variables;
    string myvar ;
    int index = 0 ;
    while(getline(myFile, line)){
        while(index != string::npos){
            index = line.find(" ") ;
            myvar = line.substr(0,index) ;
            line = line.substr(index+1 , line.length());
            variables.push_back(myvar) ;
        }
        sequantial_search.insert(UpperString(variables[0]),UpperString(variables[1]), variables[2],variables[3]);
      
     
        variables.clear() ;
        index = 0 ;
    }
    sequantial_search.insertionSort();
    sequantial_search.search_helper(query,partial,print);
    
    
}


void binary_search1(bool partial, string filename,string query, bool print ){
    
    bnry_search<string> binary_search;
    
    ifstream  myFile(filename) ;
    string line;
    vector<string> variables;
    string myvar ;
    int index = 0 ;
    while(getline(myFile, line)){
        while(index != string::npos){
            index = line.find(" ") ;
            myvar = line.substr(0,index) ;
            line = line.substr(index+1 , line.length());
            variables.push_back(myvar) ;
        }
        binary_search.insert(UpperString(variables[0]),UpperString(variables[1]), variables[2],variables[3]);
      
     
        variables.clear() ;
        index = 0 ;
    }
    binary_search.insertionSort();
    binary_search.search_helper(query,partial,print);
}










int main(){
    string filename,query;
    ofstream  output;
    cout<<"Enter the file name: " ;
    cin>>filename;
    
    
    int k = 100;
    auto start_insertion_sort = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < k; i++)
    {
        insertion_s(filename);

    }
    auto insertion_sort_time = std::chrono::duration_cast<std::chrono::nanoseconds>
    (std::chrono::high_resolution_clock::now() - start_insertion_sort);
    
    auto start_quick_sort = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < k; i++)
    {
        quick_s(filename);
    }
    auto quick_sort_time = std::chrono::duration_cast<std::chrono::nanoseconds>
    (std::chrono::high_resolution_clock::now() - start_quick_sort);
    
    auto start_merge_sort = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < k; i++)
    {
        merge_s(filename);
    }
    auto merge_sort_time = std::chrono::duration_cast<std::chrono::nanoseconds>
    (std::chrono::high_resolution_clock::now() - start_merge_sort);
    
    auto start_heap_sort = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < k; i++)
    {
        heap_s(filename);
    }
    auto heap_sort_time = std::chrono::duration_cast<std::chrono::nanoseconds>
    (std::chrono::high_resolution_clock::now() - start_heap_sort);
    
    
    cout << "Please enter the word to be queried: " ;
    cin.ignore();
    getline(cin,query);
    cout<<endl;
    cout<<endl;
    cout<<"Sorting the vector copies"<<endl;
    cout<<"======================================"<<endl;
    cout<<"Quick Sort Time: "<< quick_sort_time.count()/k<< " Nanoseconds"<<endl;
    cout << "Insertion Sort Time: "<< insertion_sort_time.count()/k<<  " Nanoseconds"<<endl;
    cout<< "Merge Sort Time: "<< merge_sort_time.count()/k<<  " Nanoseconds" <<endl;
    cout<< "Heap Sort Time: "<< heap_sort_time.count()/k<< " Nanoseconds" <<endl;
    cout<<endl;
    cout<< "Searching for "<< query<<endl;
    cout<<"======================================"<<endl;
    query = UpperString(query);
    double binary, sequential;
    int index = query.find(" ") ;
    if(index == string::npos){
        binary_search1(true,filename,query,true);

        auto start_binary_search = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < k; i++)
        {
            binary_search1(true,filename,query,false);

        }
        auto binary_search_time = std::chrono::duration_cast<std::chrono::nanoseconds>
        (std::chrono::high_resolution_clock::now() - start_binary_search);
        cout<< "Binary Search Time: "<< binary_search_time.count()/k<< " Nanoseconds" <<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Search results for Sequential Search:"<<endl;
        sequantial_search1(true,filename,query,true);
        cout<<endl;
        cout<<endl;
        auto start_sequential_search = std::chrono::high_resolution_clock::now();
        
        for (int i = 0; i < k; i++)
        {
            sequantial_search1(true,filename,query,false);

        }
        auto sequential_search_time = std::chrono::duration_cast<std::chrono::nanoseconds>
        (std::chrono::high_resolution_clock::now() - start_sequential_search);
        cout<< "Sequential Search Time: "<< sequential_search_time.count()/k<< " Nanoseconds" <<endl;
        cout<<endl;
        cout << "SpeedUp between Search Algorithms"<<endl;
        cout<<"======================================"<<endl;
        if((double)(sequential_search_time.count()) >(double)(binary_search_time.count())){
            cout << "(Sequential Search/ Binary Search) SpeedUp = "<<(double)(sequential_search_time.count()) /(double)(binary_search_time.count())<<endl;
        }
        else{
            cout << "(Sequential Search/ Binary Search) SpeedUp = "<<(double)(binary_search_time.count())/(double)(sequential_search_time.count())<<endl;
        }
        
    }
    else{
        binary_search1(false,filename,query,true);
        auto start_binary_search = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < k; i++)
        {
            binary_search1(true,filename,query,false);

        }
        auto binary_search_time = std::chrono::duration_cast<std::chrono::nanoseconds>
        (std::chrono::high_resolution_clock::now() - start_binary_search);
        cout<< "Binary Search Time: "<< binary_search_time.count()/k<< " Nanoseconds" <<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Search results for Sequential Search:"<<endl;
        sequantial_search1(false,filename,query,true);
        cout<<endl;
        cout<<endl;

        
        auto start_sequential_search = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < k; i++)
        {
            sequantial_search1(true,filename,query,false);

        }
        auto sequential_search_time = std::chrono::duration_cast<std::chrono::nanoseconds>
        (std::chrono::high_resolution_clock::now() - start_sequential_search);
        cout<< "Sequential Search Time: "<< sequential_search_time.count()/k<< " Nanoseconds" <<endl;
        cout<<endl;
        cout << "SpeedUp between Search Algorithms"<<endl;
        cout<<"======================================"<<endl;
        if((double)(sequential_search_time.count()) >(double)(binary_search_time.count())){
            cout << "(Sequential Search/ Binary Search) SpeedUp = "<<(double)(sequential_search_time.count()) /(double)(binary_search_time.count())<<endl;
        }
        else{
            cout << "(Sequential Search/ Binary Search) SpeedUp = "<<(double)(binary_search_time.count())/(double)(sequential_search_time.count())<<endl;
        }
        
    

    }
    
    
 
    cout<<endl;
    cout<<"SpeedUps between Sorting Algorithms"<<endl;
    cout<<"======================================"<<endl;
    if((double)(insertion_sort_time.count()) >(double)(quick_sort_time.count())){
        cout<<"(Insertion Sort/ Quick Sort) SpeedUp = "<<(double)(insertion_sort_time.count()) /(double)(quick_sort_time.count())<<endl;
    }
    else{
        cout<<"(Insertion Sort/ Quick Sort) SpeedUp = "<<(double)(quick_sort_time.count())/(double)(insertion_sort_time.count())<<endl;
    }
    
    
    if((double)merge_sort_time.count()>(double)(quick_sort_time.count())){
        cout<<"(Merge Sort / Quick Sort) SpeedUp = "<<(double)merge_sort_time.count()/(double)(quick_sort_time.count())<<endl;
    }
    else{
        cout<<"(Merge Sort / Quick Sort) SpeedUp = "<<(double)(quick_sort_time.count())/(double)merge_sort_time.count()<<endl;
    }
    
    
    
    if((double)(heap_sort_time.count()) >(double)(quick_sort_time.count())){
        cout<<"(Heap Sort / Quick Sort) SpeedUp = "<<(double)(heap_sort_time.count())/(double)(quick_sort_time.count())<<endl;
    }
    else{
        cout<<"(Heap Sort / Quick Sort) SpeedUp = "<<(double)(quick_sort_time.count())/(double)(heap_sort_time.count())<<endl;
    }
    
    

    
    return 0;
}
