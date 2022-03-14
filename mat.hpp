#pragma once

#include <string>
#include <iostream>
using namespace std;

namespace ariel{

    string mat (int col , int row , char sym1 , char sym2);
    string create_pref(int size, char s1, char s2);
    string create_post(int size, char s1, char s2);
}
