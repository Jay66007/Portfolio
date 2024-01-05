// NAME-JASKIRAT SINGH ,STUDENT ID- G20879985
#include<stdio.h>
#include<string>
#include<iostream>
#include <stdlib.h>
#include<time.h>
#include <fstream>
#include<sstream>
#include <cstdlib>
#include"CCard.h"
#include "Vector"
#include "CardMaker.h"
using namespace std;


struct SProffesor
{
    string name;
    int prestige = 0;

    // structure to store name and prestige for each player as it is more convinient 



};


struct SHand
{
    string name = "empty";
    int power = 0;
    int type = 1;
};


vector <CCard*> PlagiaristCardList;   //vector of CCard of type CCard pointers to store list of cards for each player
vector <CCard*> PifflePaperCardList;

int Random(int max)
{
    return int(float(rand()) / (RAND_MAX + 1) * float(max));                     // random number generator with max value( in this case 1) to generate random number between particular range
}






void InitializeDeck(string txt, string p)
{

    




        // variable names to be used in function
        fstream file;
        const int maxwords = 10;
        string Txtfilelinechar[maxwords];
        string name;
        int power;
        int type;
        int resiliance;
        int count = 0, c = 0;
        file.open(txt, ios::in); //opening file to read
        if (file.is_open()) {   //check if the file is open
            string CardValues;
            while (getline(file, CardValues)) { //getting data from file and putting it in string

                int card;

                int i = 0;
                stringstream ss(CardValues); // using stringstream to store card values
                string word;
                while (ss >> word)
                {
                    Txtfilelinechar[i] = word;  // store values in array
                    i++;
                }
                // putting each particular value of array  in variables
                stringstream c1(Txtfilelinechar[0]);;
                c1 >> type;
                card = type;
                if (type != 0) {
                    name = Txtfilelinechar[1] + " " + Txtfilelinechar[2];
                    stringstream c2(Txtfilelinechar[3]);
                    stringstream c3(Txtfilelinechar[4]);
                    c2 >> power;
                    c3 >> resiliance;
                    if (p == "player1")
                    {
                        PlagiaristCardList.push_back(NewCard(ECardtype(type), type, name, power, resiliance));



                    }                                                // Calling setter functions to set values of card for deck for each array element 

                    if (p == "player2")
                    {
                        PifflePaperCardList.push_back(NewCard(ECardtype(type), type, name, power, resiliance));

                      

                    }



                }

            }
        }
        else
        {
            cout << "Error opening file";
        }

     
       
    



  
}




int main()
{

    {








    // passing text files to initialize deck for each player and including player 1 and 2 strings to specifiy which deck of player do we need put values into
   InitializeDeck("plagiarist.txt", "player1"); //
    InitializeDeck("piffle-paper.txt", "player2");


     

    int seed{};
    fstream newfile;

    newfile.open("seed.txt", ios::in); //open the seed file for random number generator
    if (newfile.is_open()) {   //checking if  the file is open
        string tp;
        while (getline(newfile, tp)) { //read data from file object and put it into string for using for srand
            stringstream c2(tp);
            c2 >> seed;
        }
        newfile.close(); //close the file object.
    }
    else
    {
        cout << "Error opening file";
    }

   



    SProffesor* Pplayer1 = new SProffesor;
    Pplayer1->name = "Professor Plagiarist";
    Pplayer1->prestige = 30;

    SProffesor* Pplayer2 = new SProffesor;
    Pplayer2->name = "Professor Piffle-Paper";                
    Pplayer2->prestige = 30;

    SHand* Pplayer1card0 = new SHand;
    SHand* Pplayer1card1 = new SHand;

    SHand* Pplayer2card0 = new SHand;
    SHand* Pplayer2card1 = new SHand;

    cout << "Welcome to U-Can't. Let the winnowing begin..." << endl;
    cout << "--------------------" << endl;

    int randomnum;
    int round = 0;

    int MaxNumberRange = 2;
    int totalrounds = 30;
    int studentcard = 1;
    srand(seed);

    int initialround = 0;


    for (int j = initialround; j <= totalrounds; j++)  // for loop to simulate game for 30 rounds
    {



        if (j == initialround)  // if it's round one display what cards players start with
        {
            cout << Pplayer1->name << " " << "starts with" << " " << PlagiaristCardList[j]->GetCardName() << endl;
            cout << Pplayer2->name << " " << "starts with" << " " << PifflePaperCardList[j]->GetCardName() << endl;
            Pplayer1card0->name = PlagiaristCardList[j]->GetCardName();
            Pplayer1card0->power = PlagiaristCardList[j]->GetCardPower();   // calling getter function get name for specific array deck
            Pplayer1card0->type = PlagiaristCardList[j]->GetCardType();
            Pplayer2card0->name = PifflePaperCardList[j]->GetCardName();
            Pplayer2card0->power = PifflePaperCardList[j]->GetCardPower();
            Pplayer2card0->type = PifflePaperCardList[j]->GetCardType();

        }


        if (j != initialround)
        {
            round++;

            //process for player 1
            cout << "--------------------" << endl;
            cout << "ROUND" << "" << round << endl;
            cout << "--------------------" << endl;

            cout << Pplayer1->name << " " << "draws" << " " << PlagiaristCardList[j]->GetCardName() << endl;
            if (Pplayer1card0->name == "empty")
            {
                Pplayer1card0->name = PlagiaristCardList[j]->GetCardName();
                Pplayer1card0->power = PlagiaristCardList[j]->GetCardPower();
                Pplayer1card0->type = PlagiaristCardList[j]->GetCardType();

            }                                                              //putting cards where it value is not empty 
            if (Pplayer1card1->name == "empty")                                    // updating both name and power of the card 
            {

                Pplayer1card1->name = PlagiaristCardList[j]->GetCardName();
                Pplayer1card1->power = PlagiaristCardList[j]->GetCardPower();
                Pplayer1card1->type = PlagiaristCardList[j]->GetCardType();

            }
            randomnum = Random(MaxNumberRange); //calling random number function to generate a random number and put into variable
            cout << "random number= " << randomnum << endl;
            if (randomnum == 0)
            {
                cout << Pplayer1->name << " " << "plays" << " " << Pplayer1card0->name << endl;

                if (Pplayer1card0->type == studentcard)
                {
                    Pplayer2->prestige = Pplayer2->prestige - Pplayer1card0->power;             //If random number is zero player plays the card in position zero and updating prestige by deducting by the power of the card


                    Pplayer1card0->power = Pplayer1card1->power;
                    cout << Pplayer1card0->name << " " << "attacks" << " " << Pplayer2->name << "." << " " << Pplayer2->name << " 's prestige is now" << " " << Pplayer2->prestige << endl;


                    //if random number is 0. we play card 0 from hand then card 1 takes place of card 0 



                }
                Pplayer1card0->name = Pplayer1card1->name;
                Pplayer1card0->power = Pplayer1card1->power;
                Pplayer1card0->type = Pplayer1card1->type;

                Pplayer1card1->name = "empty";


            }


            if (randomnum == 1)
            {
                cout << Pplayer1->name << " " << "plays" << " " << Pplayer1card1->name << endl;
                //if random number is one . player plays the card in position one and updating prestige by deducting by the power of the card

                if (Pplayer1card1->type == studentcard)
                {

                    Pplayer2->prestige = Pplayer2->prestige - Pplayer1card1->power;

                    Pplayer1card1->power = 0;
                    cout << Pplayer1card1->name << " " << "attacks" << " " << Pplayer2->name << "." << " " << Pplayer2->name << " 's prestige is now" << " " << Pplayer2->prestige << endl;

                    // we only attack the enemy if we get a student card
                }
                Pplayer1card1->name = "empty";


            }
            cout << "--------------------" << endl;





          


            if (Pplayer2->prestige <= 0)
            {
                cout << "--------------------" << endl;
                cout << "--------------------" << endl;

                cout << "Game Over" << endl;
                cout << Pplayer2->name << " " << "has no presitige and is sacked " << endl;                       // to check if after player 1's turn  player 2's prestige is zero or not
                cout << Pplayer1->name << "'s prestige is " << " " << Pplayer1->prestige << endl;
                cout << Pplayer2->name << "'s prestige is " << " " << Pplayer2->prestige << endl;
                cout << Pplayer1->name << " " << "wins." << endl;
                break;
            }





            //process for player 2
            cout << Pplayer2->name << " " << "draws" << " " << PifflePaperCardList[j]->GetCardName() << endl;
            if (Pplayer2card0->name == "empty")
            {
                Pplayer2card0->name = PifflePaperCardList[j]->GetCardName();
                Pplayer2card0->power = PifflePaperCardList[j]->GetCardPower();               //putting cards where it value is not empty
                Pplayer2card0->type = PifflePaperCardList[j]->GetCardType();
            }                                                               // updating both name and power of the card
            if (Pplayer2card1->name == "empty")
            {

                Pplayer2card1->name = PifflePaperCardList[j]->GetCardName();
                Pplayer2card1->power = PifflePaperCardList[j]->GetCardPower();
                Pplayer2card1->type = PifflePaperCardList[j]->GetCardType();

            }
            randomnum = Random(MaxNumberRange);        //calling random number function to generate a random number and put into variable
            cout << "random number= " << randomnum << endl;

            if (randomnum == 0)
            {
                cout << Pplayer2->name << " " << "plays" << " " << Pplayer2card0->name << endl;

                if (Pplayer2card0->type == studentcard)
                {


                    Pplayer1->prestige = Pplayer1->prestige - Pplayer2card0->power;

                    //If random number is zero player plays the card in position zero and updating prestige by deducting by the power of the card
                    Pplayer2card0->power = Pplayer2card1->power;
                    cout << Pplayer2card0->name << " " << "attacks" << " " << Pplayer1->name << "." << " " << Pplayer1->name << " 's prestige is now" << " " << Pplayer1->prestige << endl;





                }

                Pplayer2card0->name = Pplayer2card1->name;
                Pplayer2card0->power = Pplayer2card1->power;
                Pplayer2card0->type = Pplayer2card1->type;
                Pplayer2card1->name = "empty";

            }


            if (randomnum == 1)
            {

                cout << Pplayer2->name << " " << "plays" << " " << Pplayer2card1->name << endl;

                if (Pplayer2card1->type == studentcard)
                {

                    Pplayer1->prestige = Pplayer1->prestige - Pplayer2card1->power;
                    //if random number is one player plays the card in position one and updating prestige by deducting by the power of the card

                    Pplayer2card1->power = 0;
                    cout << Pplayer2card1->name << " " << "attacks" << " " << Pplayer1->name << "." << " " << Pplayer1->name << " 's prestige is now" << " " << Pplayer1->prestige << endl;


                }

                Pplayer2card1->name = "empty";


            }

            if (Pplayer1->prestige <= 0)
            {
                cout << "--------------------" << endl;
                cout << "--------------------" << endl;

                cout << "Game Over" << endl;
                cout << Pplayer1->name << " " << "has no presitige and is sacked " << endl;                //to check if after player 2's turn  player 1's prestige is zero or not
                cout << Pplayer1->name << "'s prestige is " << " " << Pplayer1->prestige << endl;
                cout << Pplayer2->name << "'s prestige is " << " " << Pplayer2->prestige << endl;
                cout << Pplayer2->name << " " << "wins." << endl;
                break;
            }




        }






        if (j == totalrounds)
        {


            if (Pplayer1->prestige < Pplayer2->prestige)
            {
                cout << "--------------------" << endl;
                cout << "--------------------" << endl;

                cout << "Game Over" << endl;
                cout << Pplayer1->name << "'s prestige is " << " " << Pplayer1->prestige << endl;
                cout << Pplayer2->name << "'s prestige is " << " " << Pplayer2->prestige << endl;
                cout << Pplayer2->name << " " << "wins." << endl;
                break;
            }


            if (Pplayer1->prestige > Pplayer2->prestige)                                                 //If game goes to 30 round we check by using if statement who has higher prestige and that player is the winner
            {
                cout << "--------------------" << endl;
                cout << "--------------------" << endl;

                cout << "Game Over" << endl;
                cout << Pplayer1->name << "'s prestige is " << " " << Pplayer1->prestige << endl;
                cout << Pplayer2->name << "'s prestige is " << " " << Pplayer2->prestige << endl;
                cout << Pplayer1->name << " " << "wins." << endl;
                break;
            }



        }























    }





    delete (Pplayer1);
    delete (Pplayer2);
    delete (Pplayer1card0);
    delete (Pplayer1card1);
    delete (Pplayer2card0);
    delete (Pplayer2card1);



                                             //to delete all the dynamically allocated objects

    for (auto card : PifflePaperCardList)
    {
        delete card;
    }


    for (auto card : PlagiaristCardList)
    {
        delete card;
    }


}
   


    _CrtDumpMemoryLeaks();






    

  
    
    




}

