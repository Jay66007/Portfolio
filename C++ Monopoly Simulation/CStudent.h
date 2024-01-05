// NAME-JASKIRAT SINGH ,STUDENT ID- G20879985

#pragma once
#include "CCard.h"
class CStudent :
    public CCard
{
protected:
   
    int mpower;                          
                               //variables to store power and resiliance for CStudent card
    int mresiliance;

public:




    CStudent(int type, string name, int power, int resiliance); //default constructor to intialize things


  

    int GetCardPower(); // get function to get card power 

};

