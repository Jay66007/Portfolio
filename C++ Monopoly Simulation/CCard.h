// NAME-JASKIRAT SINGH ,STUDENT ID- G20879985
#pragma once
#include<stdio.h>
#include<string>
#include<iostream>
#include <stdlib.h>
#include<time.h>
#include <fstream>
#include<sstream>
#include <cstdlib>
using namespace std;
class CCard
{
protected:

    string mcardName;
                                 //variables to store different things from file
    int mcardtype;

public:
    CCard(int type, string name);     //default constructor if it's generic CCard

 

   

   



     string GetCardName();
     int GetCardType();           //getter function to get card name and type
     virtual int GetCardPower();   //virtual function when we call in main a base class object but it's type is derived class it will automatically point to derived class 
};

