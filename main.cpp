/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin Faucher, Alexia Nebrao
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
    SortingClass sortingClass(50000,10,5000);
    SortingClass sortingClass1(50000);
    SortingClass sortingClass2;
    sortingClass.compareSorts();
    return 0;
}

