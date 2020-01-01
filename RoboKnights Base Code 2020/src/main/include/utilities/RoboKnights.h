#pragma once

using namespace std;

#include <iostream>
#include <string>
#include <fstream>
#include <list>

class RoboKnights {
private:
    string values[20];
    string names[20];
public:
    RoboKnights();
     //Member Function Declarations
    //Gets the values in the config files
    string GetValue(string sName);
    
    //Set the Value for a setting
    void SetValue(string sName, int iValue);
        
    //Reads the file into the arrays.
    void ReadFile();
};