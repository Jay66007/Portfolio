// NAME-JASKIRAT SINGH ,STUDENT ID- G20879985
#include "CCard.h"
#include "CStudent.h"
CCard::CCard(int type, string name)
{

    mcardtype = type;
    mcardName = name;      // storing type and name for each card in a deck




}




string CCard::GetCardName()
{
    return mcardName;
}

int CCard::GetCardType()  // getter functions to be used in main() where game is played
{
    return mcardtype;
}

int CCard::GetCardPower()
{
    return 0;
}
