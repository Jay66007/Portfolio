// NAME-JASKIRAT SINGH ,STUDENT ID- G20879985

#include "CardMaker.h"
#include "CStudent.h"
CCard* NewCard(ECardtype card, int type, string name, int power, int resiliance)
{
    CCard* cardPtr = nullptr;
    switch (card)
    {
    case ECardtype::CStudent:
        {
        cardPtr = new CStudent(type, name,power, resiliance);
        break;
        }

    default:                                               // taking data from file assigning correct object type
    {
        cardPtr = new CCard(type, name);
            break;
    }
        
    }
   return cardPtr;
    
}
