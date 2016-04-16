#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
using namespace std;
int runningcount (int n);
int allcard[312],card2to11[11];

int main()
{
int allcardcounter = 0, anycard, temp = 0, temp1 = 0, effcounter = 0;
int players[6][10],dealer[10],dealt = 0;
int sum[6],Dsum = 0,dummy = 0;
int nextcard[6],Dnextcard = 2;
int rcount = 0;
bool Insurance[6],evenmoney[6],BOOL = 0;
for (int i = 0; i < 6; i++)
    for(int j = 0; j < 10; j++)
    {players[i][j] = 0;
    dealer[j] = 0;
    sum[i] = 0;
    Insurance[i] = 0;
    evenmoney[i] = 0;}

    //for (int i = 0; i < 10; i++)
       // cout << dealer[i] << "\t";
   // cout << endl;
//char str[6];
    srand(time(NULL)); // Set seed for randomizing.
     for (int i = 0; i < 11; i++)
     card2to11[i] = 0;

     for (int i = 0; i < 312; i++)
     allcard[i] = 0;

    while (allcardcounter < 312)
    {
      anycard = rand() % 10 + 2;
        //cout << anycard << endl;
      switch (anycard)
      {
      case 2:
          if (card2to11[2] < 24)
            {allcard[allcardcounter] = anycard;
            allcardcounter++;
            card2to11[2]++;}
            break;

            case 3:
          if (card2to11[3] < 24)
            {allcard[allcardcounter] = anycard;
            allcardcounter++;
            card2to11[3]++;}
            break;

            case 4:
          if (card2to11[4] < 24)
            {allcard[allcardcounter] = anycard;
            allcardcounter++;
            card2to11[4]++;}
            break;

            case 5:
          if (card2to11[5] < 24)
            {allcard[allcardcounter] = anycard;
            allcardcounter++;
            card2to11[5]++;}
            break;

            case 6:
          if (card2to11[6] < 24)
            {allcard[allcardcounter] = anycard;
            allcardcounter++;
            card2to11[6]++;}
            break;

            case 7:
          if (card2to11[7] < 24)
            {allcard[allcardcounter] = anycard;
            allcardcounter++;
            card2to11[7]++;}
            break;

            case 8:
          if (card2to11[8] < 24)
            {allcard[allcardcounter] = anycard;
            allcardcounter++;
            card2to11[8]++;}
            break;

            case 9:
          if (card2to11[9] < 24)
            {allcard[allcardcounter] = anycard;
            allcardcounter++;
            card2to11[9]++;}
            break;

            case 11:
          if (card2to11[11] < 24)
            {allcard[allcardcounter] = anycard;
            allcardcounter++;
            card2to11[11]++;}
            break;

            case 10:
          if (card2to11[10] < 96)
            {allcard[allcardcounter] = anycard;
            allcardcounter++;
            card2to11[10]++;}
            break;

            default:
                break;


      }

    }          //card Initialization done

    for (int m = 0; m < 312; m++)
    for (int l = 0; l < 312; l++)
    {
      anycard = rand() % 312;
      effcounter++;
      while (anycard < l)
        {anycard = rand() % 312;

        effcounter++;}


          temp = allcard[l];
          allcard[l] = allcard[anycard];
          allcard[anycard] = temp;

    }          // card sufling is done


    // we will deal for 6 players and one dealer
while (dealt < 260)
{
    for (int i = 0; i < 6; i++)
    for(int j = 0; j < 10; j++)
    {players[i][j] = 0;
    dealer[j] = 0;
    sum[i] = 0;
    Insurance[i] = 0;
    evenmoney[i] = 0;}
    Dsum = 0;
    temp1 = dealt;
    Dnextcard = 2;

    for (int i =0; i < 6; i++)
    {
        players[i][0] = allcard[dealt];
        rcount = rcount + runningcount(allcard[dealt]);
        dealt++;
        //cout << dealt << "  ";
    }
    //cout << endl;
    dealer[0] = allcard[dealt];
    rcount = rcount + runningcount(allcard[dealt]);
    dealt++;
    for (int i =0;i < 6; i++)
    {
        players[i][1] = allcard[dealt];
        rcount = rcount + runningcount(allcard[dealt]);
        dealt++;
    }
    dealer[1] = allcard[dealt];
    dealt++;

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 10; j++)
            sum[i] = sum[i] + players[i][j];    //sum total for players

                for (int j = 0; j < 10; j++)
                Dsum = Dsum + dealer[j];//sum total for dealer


    // All outputs start here, repitative display
    for(int i = 0; i < 6; i++)
        cout << players[i][0] << "\t";
        cout << dealer[0];
        cout << endl;

    for(int i = 0; i < 6; i++)
        cout << players[i][1] << "\t";
        cout << "-";
        cout << endl;
    for(int i = 0; i < 6; i++)
        cout << players[i][2] << "\t";
        cout << "-";
        cout << endl;
    for(int i = 0; i < 6; i++)
        cout << players[i][3] << "\t";
        cout << "-";
        cout << endl;
    for(int i = 0; i < 6; i++)
        cout << players[i][4] << "\t";
        cout << "-";
        cout << endl;
    for(int i = 0; i < 6; i++)
        cout << players[i][5] << "\t";
        cout << "-";
        cout << endl;

    cout << endl;

    for(int i = 0; i < 6; i++)
        cout << sum[i] << "\t";
        cout << "-";

    cout << endl;
    cout << "Running count is  " << rcount << endl;


    // Initial dealeing is done


switch (dealer[0])     //check for blackjack incase of 10 or 11 for dealer
{
case 10:
    if (dealer[1] == 11)
    {
        for(int i = 0; i < 6; i++)
        cout << players[i][0] << "\t";
        cout << dealer[0];
    cout << endl;
     for(int i = 0; i < 6; i++)
        cout << players[i][1] << "\t";
        cout << dealer[1];

    cout << endl;
    cout << endl;

    for(int i = 0; i < 6; i++)
        cout << sum[i] << "\t";
        cout << Dsum;

    cout << endl;
    cout << endl;
    }
    //calculation of who wins or losses incase dealer has a blackjack
    break;

case 11:
    cout << "Does anybody need insurance or even money?" << endl;
    for (int i = 0; i < 6; i++)

   {if (sum[i] == 21)
   {cout << "Player " << i+1 << " even money?" << endl;
   cin >> evenmoney[i];}
   else
    {cout << "Player " << i+1 << " Insurance?" << endl;
   cin >> Insurance[i];}
   }

    if (dealer[1] == 10)
    {
        for(int i = 0; i < 6; i++)
        cout << players[i][0] << "\t";
        cout << dealer[0];
    cout << endl;
     for(int i = 0; i < 6; i++)
        cout << players[i][1] << "\t";
        cout << dealer[1];

    cout << endl;
    cout << endl;

    for(int i = 0; i < 6; i++)
        cout << sum[i] << "\t";
        cout << Dsum;

    cout << endl;
    cout << endl;
    }
    //calculation of who wins or losses incase dealer has a blackjack

    break;
default:
    break;

}     //evenmoney,blackjack, insurance checked

//dealing will continue incase dealer has no blackjack

if (Dsum != 21)
        {
            for (int i = 0; i < 6; i++)
            {
                nextcard[i] = 2;
                while (sum[i] < 21)
                {
                    cout << "Player " << i <<" sum is " << sum[i] << "." << endl;
                    cout << "Enter, Stand:0, Hit:1, Doubledown:2" << endl;

                    cin >> dummy;
                    if (dummy == 0)
                        break;
                    if (dummy == 2)
                        {
                            players[i][2] = allcard[dealt];
                            sum[i] = sum[i] + allcard[dealt];
                            dealt++;
                            break;
                        }
                    if (dummy == 1)
                        {
                            players[i][nextcard[i]] = allcard[dealt];
                            nextcard[i]++;
                            sum[i] = sum[i] + allcard[dealt];
                            if (sum[i] > 21)
                            {
                                BOOL = 0;
                                for (int k = 0; k < nextcard[i]; k++)
                                {
                                    if (BOOL)
                                        break;
                                    if (players[i][k] == 11)
                                        {
                                            players[i][k] = 1;
                                            BOOL = 1;
                                        }
                                }
                                sum[i] = 0;
                                for (int k = 0; k < nextcard[i]; k++)
                                    sum[i] = sum[i] + players[i][k];
                            }

                            // All outputs start here, repitative display
    for(int i = 0; i < 6; i++)
        cout << players[i][0] << "\t";
        cout << dealer[0];
        cout << endl;

    for(int i = 0; i < 6; i++)
        cout << players[i][1] << "\t";
        cout << "-";
        cout << endl;
    for(int i = 0; i < 6; i++)
        cout << players[i][2] << "\t";
        cout << "-";
        cout << endl;
    for(int i = 0; i < 6; i++)
        cout << players[i][3] << "\t";
        cout << "-";
        cout << endl;
    for(int i = 0; i < 6; i++)
        cout << players[i][4] << "\t";
        cout << "-";
        cout << endl;
    for(int i = 0; i < 6; i++)
        cout << players[i][5] << "\t";
        cout << "-";
        cout << endl;

    cout << endl;

    for(int i = 0; i < 6; i++)
        cout << sum[i] << "\t";
        cout << "-";

    cout << endl;
    rcount = rcount + runningcount(allcard[dealt]);
    cout << "Running count is  " << rcount << endl;
                            dealt++;

                        }

                }

            }           //dealing cards for players done
        while (Dsum < 17)
        {
            dealer[Dnextcard] = allcard[dealt];
            Dsum = Dsum + allcard[dealt];
            Dnextcard++;
            if (Dsum > 21)
                {
                    BOOL = 0;
                    for (int k = 0; k < Dnextcard; k++)
                    {
                        if (BOOL)
                            break;
                        if (dealer[k] == 11)
                            {
                                dealer[k] = 1;
                                BOOL = 1;
                            }
                    }
                    Dsum = 0;
                    for (int k = 0; k < Dnextcard; k++)
                        Dsum = Dsum + dealer[k];
                }
            dealt++;

        }

        }


for (int i = 0; i < 6; i++)
    cout << sum[i] << "\t";
    cout << endl << Dsum;
    cout << endl;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < nextcard[i];j++)
            cout << players[i][j] << ",";
            cout << sum[i];
            cout <<endl;
    }
    for (int j = 0; j < Dnextcard; j++)
        cout << dealer[j] << ",";
    cout << Dsum << endl;

    for (int i = temp1; i < dealt; i++)
        cout << allcard[i] << "\t";
    cout << endl;
    cout << endl;
    cout << endl;
    system("PAUSE");
    cout << endl;
    cout << endl;

}

    return 0;
}

int runningcount(int n)
{
    int cardvalue;
    switch (n)
    {
    case 3:
        cardvalue = -1;
        break;
    case 4:
        cardvalue = -1;
        break;
    case 5:
        cardvalue = -1;
        break;
    case 6:
        cardvalue = -1;
        break;
    case 10:
        cardvalue = 1;
        break;
    default:
        cardvalue = 0;
        break;

    }
    return cardvalue;
}
