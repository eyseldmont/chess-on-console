#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

class song
{
    public:
    string structure;
    int chordsNumber=0;
    string chords[10];
    int progression[11];
    string stucture;



    void ask();
    void print();
    void generateChords();
    void lastChords();
    void generateStructure();


};
void song::ask()
{
    ///Ask how many chords
    cout<<"How many chords?"<<endl;
    cin>>chordsNumber;
}
void song::print()
{
    cout<<"Number of chords: "<<chordsNumber<<endl;

}
void song::generateChords()
{
    ///For progression[i] numbers
    srand((unsigned) time(0));

    ///Variables
    int i,j,result;

    ///Check correct input
    do{
        ask();
        if(chordsNumber<2||chordsNumber>8)
        {
            cout <<"Chord Number must between 2 and 8"<<endl;
            system("pause>null");
            system("cls");
        }
    }
    while(chordsNumber<2 || chordsNumber>8);

    ///After choosing chords number



    cout<<"printing "<< chordsNumber <<" chords"<<endl;
     int MajMin = 1 + (rand() % 2);
    {
        if (MajMin == 1) ///Maj scale
        {
            cout<<"printing in Major"<<endl;
            for(i = 1; i<=chordsNumber; i++)
            {
                int randomNumber = 1 + (rand() % 6);
                switch (randomNumber)
                {
                    case 1:
                        chords[i] = "I";
                        break;
                    case 2:
                        chords[i] = "ii";
                        break;
                    case 3:
                        chords[i] = "iii";
                        break;
                    case 4:
                        chords[i] = "IV";
                        break;
                    case 5:
                        chords[i] = "V";
                        break;
                    case 6:
                        chords[i] = "vi";
                        break;
                    /*case 7:
                        chords[i] = "vii*"; Improve algorithm
                        break;*/
                    default:
                        chords[i] = "error";
                }
            }
        }
        else if (MajMin == 2) ///Min Scale
        {
            cout<<"printing in Minor"<<endl;
            for(i = 1; i<=chordsNumber; i++)
            {
                int randomNumber = 1 + (rand() % 6);
                switch (randomNumber)
                {
                    case 1:
                        chords[i] = "i";
                        break;
                    case 2:
                        chords[i] = "VII";///Should be 2nd dim, improve algorithm
                        break;
                    case 3:
                        chords[i] = "III";
                        break;
                    case 4:
                        chords[i] = "iv";
                        break;
                    case 5:
                        chords[i] = "v";
                        break;
                    case 6:
                        chords[i] = "VI";
                        break;
                    /*case 7:
                        chords[i] = "VII";
                        break;*/
                    default:
                        chords[i] = "error";
                }
            }
        }


        }

    cout<<"Chord progression :"<<endl;
    for(i = 1; i<=chordsNumber; i++)
        {
            if(i==chordsNumber)
            {
                cout<<(chords[i]);
            }
            else
            {
                cout<<(chords[i])<<" - ";
            }
        }
}
void song::lastChords()
{
    for(int i = 1; i<=chordsNumber; i++)
            {
                if(i==chordsNumber)
                {
                    cout<<(chords[i]);
                }
                else
                {
                    cout<<(chords[i])<<" - ";
                }
            }
}
void song::generateStructure()
{
    srand((unsigned) time(0));

    int partNumber = rand() % 4 + 7;

    cout<<partNumber<<endl;

    for(int i = 1; i < partNumber;i++)
    {
        ///Section 1
        if (i == 1)
        {
            int val = rand()%100+1;

            if (val < 5)
            {
                progression[i] = 2;     //Verse
            }
            else if (val < 15)
            {
                progression[i] = 4;     //Chorus
            }
            else
            {
                progression[i] = 1;     //Intro
            }
            cout<<progression[i]<<" ";
        }
        ///Section 2
        if (i == 2)
        {

            int val = rand()%100+1;

            if (val < 5)
            {
                 progression[i] = 3;     // Pre chorus
            }

            else
            {
                progression[i] = 2;     //  Verse
            }

            cout<<progression[i]<<" ";
        }
        ///Section 3
        if (i == 3)
        {
            if(progression[1]==1)
            {
                int val = rand()%100+1;

                if (val < 15)
                {
                    progression[i] = 3;     //  Pre-Chorus
                }
                else if (val < 30)
                {
                    progression[i] = 4;     //Chorus
                }
                else
                {
                    progression[i] = 11;    //Repeat Intro
                }

            }
            else
            {
                int val = rand()%100+1;

                if (val < 25)
                {
                    progression[i] = 3;     //  Pre-Chorus
                }
                else
                {
                    progression[i] = 4;     //Chorus
                }
            }

            cout<<progression[i]<<" ";
        }
        ///Section 4
        if (i == 4)
        {
            if(progression[3]==3)              ///only if a precho
            {
                progression[4]=4;       ///chorus
            }
            else
            {
                progression[4]=2;       ///verse
            }

            cout<<progression[i]<<" ";
        }
        ///Section 5
        if (i == 5)
        {
            if(progression[4]==2)              ///only if a precho
            {
                int val = rand()%100+1;
                if (val<(50))
                {
                    progression[i] = 3;     //Pre-Chorus
                }
                else
                {
                    progression[i] = 4;      //Verse
                }
            }
            else if(progression[4]==4)
            {
                int val = rand()%100+1;

                if (val < 15)
                {
                    progression[i] = 11;     //Intro repeated
                }
                else if (val<(30))
                {
                    progression[i] = 5;     //Instrumental
                }
                else
                {
                    progression[i] = 2;      //Verse
                }
            }

            cout<<progression[i]<<" ";
        }

        ///Section 7
        if (i == 5)
        {
            if(progression[6]==2)
            {
                int val = rand()%100+1;
                if (val<(50))
                {
                    progression[i] = 3;
                }
                else if (val<75)
                {
                    progression[i] = 4;
                }
                else
                {
                    progression[i] = 6;
                }
            }
            else if(progression[6]==2)
            {
                    progression[i] = 3;
            }
            else
            {
                    progression[i] = 2;
            }


            cout<<progression[i]<<" ";
        }


    }
    /*int numbers[] = { 1, 2, 4};
    int progression[i]Number = numbers[rand() % length];
    */

}
int main()
{
    song songMaker;

    int opc = 0;
    do{
        cout<<"What do you want to do?"<<endl;
        cout<<"1.- Generate chord progression"<<endl;
        cout<<"2.- Generate song structure"<<endl;
        cout<<"3.- Check last chord progression generated"<<endl;
        cout<<"4.- Check last chord progression generated"<<endl;
        cin>>opc;

        if(opc<1||opc>4)
        {
            cout <<"Please choose a valid option"<<endl;
            system("pause>null");
            system("cls");
        }
        else if(opc==1) ///Generate chords
        {
            system("cls");
            songMaker.generateChords();

        }
        else if(opc==2) ///Generate progression
        {
            system("cls");
            songMaker.generateStructure();
        }
        else if(opc==3) ///Get last chords
        {
            system("cls");
            songMaker.lastChords();
        }
        else if(opc==4)
        {
            system("cls");
            songMaker.generateChords();
        }
        system("pause>null");
        ///Return to menu
        opc = 0;
        system("cls");
    }
    while (opc<1||opc>4);
    return 0;
}
