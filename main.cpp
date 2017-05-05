/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin
 *
 * Created on April 21, 2017, 2:36 PM
 */

#include <cstdlib>

#include "SortingClass.hpp"

using namespace std;

/*
 * 
 */
int main() {
    SortingClass sortingClass(20,20,200);
    //SortingClass sortingClass1(20);
    //SortingClass sortingClass2;
    sortingClass.compareSorts();
    return 0;
}

