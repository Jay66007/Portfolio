// NAME-JASKIRAT SINGH ,STUDENT ID- G20879985

#include "CStudent.h"



CStudent::CStudent(int type, string name, int power, int resiliance): CCard( type, name)
{
	
	mpower = power;
	
	mresiliance = resiliance;   // setting up power and resiliance for CStudent Card
}



int CStudent::GetCardPower()
{
	return mpower;                           //getter function to return power while playing the game
}
