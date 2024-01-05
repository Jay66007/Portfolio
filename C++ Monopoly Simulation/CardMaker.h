// NAME-JASKIRAT SINGH ,STUDENT ID- G20879985

#pragma once
#include "CCard.h"

enum class ECardtype :int
{
	CStudent = 1       //Setting CStudent card as type 1 
};


CCard* NewCard(ECardtype card, int type,string name, int power, int resiliance); // creating a function of type ccard pointer so that we can take cards from the file assign set up correct object type