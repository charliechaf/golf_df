//
//  main.cpp
//  MastersLineUpCreater
//
//  Created by Kory Carter on 4/9/19.
//  Copyright © 2019 Kory Carter. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream mastersFile;
    mastersFile.open("DKSalariesMasters.csv");
    
    ofstream results;
    results.open("results.txt");
    
    ofstream aggResults;
    aggResults.open("aggResults.txt");
    
    ifstream combos;
    combos.open("88combinations6.txt");
    
    string fileLine;
    string name;
    int counter;
    int playerNum;
    int randNum;
    int selectNum[6];
    int totalPrice;
    double totalScore;
    int comboCount;
    int topPlayers = 0;
    
    int readCount = 0;
    int currentIndexCombo[6];
    
    struct playerStats
    {
        string name;
        int salary;
        double avScore;
    };
    
    struct nameCombo
    {
        string name1;
        string name2;
        string name3;
        string name4;
        string name5;
        string name6;
        bool validCombo;
        double totalPrice;
        double totalScore;
    };
    
    nameCombo winStruct;
    nameCombo winStruct2;
    nameCombo winStruct3;
    nameCombo winStruct4;
    nameCombo winStruct5;
    nameCombo winStruct6;
    nameCombo winStruct7;
    nameCombo winStruct8;
    nameCombo winStruct9;
    nameCombo winStruct10;
    nameCombo tempStruct;
    
    
    
    playerStats playerStruct[89];
    nameCombo nameStruct;
    
    selectNum[0] = 100;
    selectNum[1] = 100;
    selectNum[2] = 100;
    selectNum[3] = 100;
    selectNum[4] = 100;
    selectNum[5] = 100;
    
    counter = 0;
    playerNum = 1;
    totalPrice = 0;
    totalScore = 0;
    comboCount = 1;
    fileLine = " ";
    
    winStruct.totalScore = 0;
    winStruct2.totalScore = 0;
    winStruct3.totalScore = 0;
    winStruct4.totalScore = 0;
    winStruct5.totalScore = 0;
    winStruct6.totalScore = 0;
    winStruct7.totalScore = 0;
    winStruct8.totalScore = 0;
    winStruct9.totalScore = 0;
    winStruct10.totalScore = 0;
    
    nameCombo aggWinStruct;
    nameCombo aggWinStruct2;
    nameCombo aggWinStruct3;
    nameCombo aggWinStruct4;
    nameCombo aggWinStruct5;
    nameCombo aggWinStruct6;
    nameCombo aggWinStruct7;
    nameCombo aggWinStruct8;
    nameCombo aggWinStruct9;
    nameCombo aggWinStruct10;
    
    aggWinStruct.totalScore = 0;
    aggWinStruct2.totalScore = 0;
    aggWinStruct3.totalScore = 0;
    aggWinStruct4.totalScore = 0;
    aggWinStruct5.totalScore = 0;
    aggWinStruct6.totalScore = 0;
    aggWinStruct7.totalScore = 0;
    aggWinStruct8.totalScore = 0;
    aggWinStruct9.totalScore = 0;
    aggWinStruct10.totalScore = 0;
    //Number of Runs--------------------------------------------
    
    //------------------------------------------Number of Runs--------
    
    getline(mastersFile, fileLine);
    while(mastersFile.is_open())
    {
        //This section builds up player database-----
        while (fileLine != "")
        {
            if (counter == 0)
            {
                string str = fileLine.substr(0,fileLine.find(","));
                fileLine.erase(0,str.length()+1);
                playerStruct[playerNum].name = str;
                counter++;
            }
            else if (counter == 1)
            {
                string str = fileLine.substr(0,fileLine.find(","));
                fileLine.erase(0,str.length()+1);
                playerStruct[playerNum].salary = stoi(str);
                counter++;
            }
            else if (counter == 2)
            {
                string str = fileLine.substr(0,fileLine.find("\r"));
                fileLine.erase(0,str.length()+1);
                playerStruct[playerNum].avScore = stod(str);
                counter = 0;
                playerNum ++;
                getline(mastersFile, fileLine);
            }
        }
        mastersFile.close();
        //------This section builds up player database
    }
    
    getline(combos, fileLine, ',');
    while (fileLine != "")
    {
        currentIndexCombo[0] = stoi(fileLine);
        for (int i = 1; i < 6; i++)
        {
            getline(combos, fileLine, ',');
            currentIndexCombo[i] = (stoi(fileLine));
        }
        
        //this adds the 6 players salaries and scores, and add the names to a list
        for (int i = 0; i < 6; i++)
        {
            totalPrice = totalPrice + playerStruct[currentIndexCombo[i]].salary;
            totalScore = totalScore + playerStruct[currentIndexCombo[i]].avScore;
            if (i == 0)
            {
                nameStruct.name1 = playerStruct[currentIndexCombo[i]].name;
            }
            else if (i == 1)
            {
                nameStruct.name2 = playerStruct[currentIndexCombo[i]].name;
            }
            else if (i == 2)
            {
                nameStruct.name3 = playerStruct[currentIndexCombo[i]].name;
            }
            else if (i == 3)
            {
                nameStruct.name4 = playerStruct[currentIndexCombo[i]].name;
            }
            else if (i == 4)
            {
                nameStruct.name5 = playerStruct[currentIndexCombo[i]].name;
            }
            else if (i == 5)
            {
                nameStruct.name6 = playerStruct[currentIndexCombo[i]].name;
                nameStruct.totalPrice = totalPrice;
                nameStruct.totalScore = totalScore;
            }
        }
        
        if (totalPrice <= 50000)
        {
            nameStruct.validCombo = true;
        }
        else
        {
            nameStruct.validCombo = false;
        }
        comboCount ++;
        totalPrice = 0;
        totalScore = 0;
        
        
        if (nameStruct.validCombo == true)
        {
            if (nameStruct.totalScore > winStruct10.totalScore)
            {
                winStruct10 = nameStruct;
            }
            if (winStruct10.totalScore > winStruct9.totalScore)
            {
                tempStruct = winStruct9;
                winStruct9 = winStruct10;
                winStruct10 = tempStruct;
            }
            if (winStruct9.totalScore > winStruct8.totalScore)
            {
                tempStruct = winStruct8;
                winStruct8 = winStruct9;
                winStruct9 = tempStruct;
            }
            if (winStruct8.totalScore > winStruct7.totalScore)
            {
                tempStruct = winStruct7;
                winStruct7 = winStruct8;
                winStruct8 = tempStruct;
            }
            if (winStruct7.totalScore > winStruct6.totalScore)
            {
                tempStruct = winStruct6;
                winStruct6 = winStruct7;
                winStruct7 = tempStruct;
            }
            if (winStruct6.totalScore > winStruct5.totalScore)
            {
                tempStruct = winStruct5;
                winStruct5 = winStruct6;
                winStruct6 = tempStruct;
            }
            if (winStruct5.totalScore > winStruct4.totalScore)
            {
                tempStruct = winStruct4;
                winStruct4 = winStruct5;
                winStruct5 = tempStruct;
            }
            if (winStruct4.totalScore > winStruct3.totalScore)
            {
                tempStruct = winStruct3;
                winStruct3 = winStruct4;
                winStruct4 = tempStruct;
            }
            if (winStruct3.totalScore > winStruct2.totalScore)
            {
                tempStruct = winStruct2;
                winStruct2 = winStruct3;
                winStruct3 = tempStruct;
            }
            if (winStruct2.totalScore > winStruct.totalScore)
            {
                tempStruct = winStruct;
                winStruct = winStruct2;
                winStruct2 = tempStruct;
            }
            for(const int playerRank : currentIndexCombo){
                if (playerRank<=10) {
                    topPlayers = topPlayers+1;
                }
            }
            if (topPlayers >2) {
                if (nameStruct.totalScore > aggWinStruct10.totalScore)
                {
                    aggWinStruct10 = nameStruct;
                }
                if (aggWinStruct10.totalScore > aggWinStruct9.totalScore)
                {
                    tempStruct = aggWinStruct9;q
                    aggWinStruct9 = aggWinStruct10;
                    aggWinStruct10 = tempStruct;
                }
                if (aggWinStruct9.totalScore > aggWinStruct8.totalScore)
                {
                    tempStruct = aggWinStruct8;
                    aggWinStruct8 = aggWinStruct9;
                    aggWinStruct9 = tempStruct;
                }
                if (aggWinStruct8.totalScore > aggWinStruct7.totalScore)
                {
                    tempStruct = aggWinStruct7;
                    aggWinStruct7 = aggWinStruct8;
                    aggWinStruct8 = tempStruct;
                }
                if (aggWinStruct7.totalScore > aggWinStruct6.totalScore)
                {
                    tempStruct = aggWinStruct6;
                    aggWinStruct6 = aggWinStruct7;
                    aggWinStruct7 = tempStruct;
                }
                if (aggWinStruct6.totalScore > aggWinStruct5.totalScore)
                {
                    tempStruct = aggWinStruct5;
                    aggWinStruct5 = aggWinStruct6;
                    aggWinStruct6 = tempStruct;
                }
                if (aggWinStruct5.totalScore > aggWinStruct4.totalScore)
                {
                    tempStruct = aggWinStruct4;
                    aggWinStruct4 = aggWinStruct5;
                    aggWinStruct5 = tempStruct;
                }
                if (aggWinStruct4.totalScore > aggWinStruct3.totalScore)
                {
                    tempStruct = aggWinStruct3;
                    aggWinStruct3 = aggWinStruct4;
                    aggWinStruct4 = tempStruct;
                }
                if (aggWinStruct3.totalScore > aggWinStruct2.totalScore)
                {
                    tempStruct = aggWinStruct2;
                    aggWinStruct2 = aggWinStruct3;
                    aggWinStruct3 = tempStruct;
                }
                if (aggWinStruct2.totalScore > aggWinStruct.totalScore)
                {
                    tempStruct = aggWinStruct;
                    aggWinStruct = aggWinStruct2;
                    aggWinStruct2 = tempStruct;
                }
            }
            topPlayers = 0;
        }
        getline(combos, fileLine, ',');
    }
    
    results << "1)\n" + winStruct.name1 + "\n" + winStruct.name2 + "\n" + winStruct.name3 + "\n" + winStruct.name4 + "\n" + winStruct.name5 + "\n" + winStruct2.name6 + "\n" + "Score: " + to_string(winStruct.totalScore) + "\n" + "Total Price: " + to_string(winStruct.totalPrice) + "\n\n";
    
    results << "2)\n" + winStruct2.name1 + "\n" + winStruct2.name2 + "\n" + winStruct2.name3 + "\n" + winStruct2.name4 + "\n" + winStruct2.name5 + "\n" + winStruct2.name6 + "\n" +  "Score: " + to_string(winStruct2.totalScore) + "\n" + "Total Price: " + to_string(winStruct2.totalPrice) + "\n\n";
    
    results << "3)\n" + winStruct3.name1 + "\n" + winStruct3.name2 + "\n" + winStruct3.name3 + "\n" + winStruct3.name4 + "\n" + winStruct3.name5 + "\n" + winStruct3.name6 + "\n"+ "Score: " + to_string(winStruct3.totalScore) + "\n" + "Total Price: " + to_string(winStruct3.totalPrice) + "\n\n";
    
    results << "4)\n" + winStruct4.name1 + "\n" + winStruct4.name2 + "\n" + winStruct4.name3 + "\n" + winStruct4.name4 + "\n" + winStruct4.name5 + "\n" + winStruct4.name6 + "\n" + "Score: " + to_string(winStruct4.totalScore) + "\n" + "Total Price: " + to_string(winStruct4.totalPrice) + "\n\n";
    
    results << "5)\n" + winStruct5.name1 + "\n" + winStruct5.name2 + "\n" + winStruct5.name3 + "\n" + winStruct5.name4 + "\n" + winStruct5.name5 + "\n" + winStruct5.name6 + "\n"+ "Score: " + to_string(winStruct5.totalScore) + "\n" + "Total Price: " + to_string(winStruct5.totalPrice) + "\n\n";
    
    results << "6)\n" + winStruct6.name1 + "\n" + winStruct6.name2 + "\n" + winStruct6.name3 + "\n" + winStruct6.name4 + "\n" + winStruct6.name5 + "\n" + winStruct6.name6 + "\n"+ "Score: " + to_string(winStruct6.totalScore) + "\n" + "Total Price: " + to_string(winStruct6.totalPrice) + "\n\n";
    
    results << "7)\n" + winStruct7.name1 + "\n" + winStruct7.name2 + "\n" + winStruct7.name3 + "\n" + winStruct7.name4 + "\n" + winStruct7.name5 + "\n" + winStruct7.name6 + "\n"+ "Score: " + to_string(winStruct7.totalScore) + "\n" + "Total Price: " + to_string(winStruct7.totalPrice) + "\n\n";
    
    results << "8)\n" + winStruct8.name1 + "\n" + winStruct8.name2 + "\n" + winStruct8.name3 + "\n" + winStruct8.name4 + "\n" + winStruct8.name5 + "\n" + winStruct8.name6 + "\n"+ "Score: " + to_string(winStruct8.totalScore) + "\n" + "Total Price: " + to_string(winStruct8.totalPrice) + "\n\n";
    
    results << "9)\n" + winStruct9.name1 + "\n" + winStruct9.name2 + "\n" + winStruct9.name3 + "\n" + winStruct9.name4 + "\n" + winStruct9.name5 + "\n" + winStruct9.name6 + "\n"+ "Score: " + to_string(winStruct9.totalScore) + "\n" + "Total Price: " + to_string(winStruct9.totalPrice) + "\n\n";
    
    results << "10)\n" + winStruct10.name1 + "\n" + winStruct10.name2 + "\n" + winStruct10.name3 + "\n" + winStruct10.name4 + "\n" + winStruct10.name5 + "\n" + winStruct10.name6 + "\n"+ "Score: " + to_string(winStruct10.totalScore) + "\n" + "Total Price: " + to_string(winStruct10.totalPrice) + "\n\n";
    
    aggResults << "1)\n" + aggWinStruct.name1 + "\n" + aggWinStruct.name2 + "\n" + aggWinStruct.name3 + "\n" + aggWinStruct.name4 + "\n" + aggWinStruct.name5 + "\n" + aggWinStruct2.name6 + "\n" + "Score: " + to_string(aggWinStruct.totalScore) + "\n" + "Total Price: " + to_string(aggWinStruct.totalPrice) + "\n\n";
    
    aggResults << "2)\n" + aggWinStruct2.name1 + "\n" + aggWinStruct2.name2 + "\n" + aggWinStruct2.name3 + "\n" + aggWinStruct2.name4 + "\n" + aggWinStruct2.name5 + "\n" + aggWinStruct2.name6 + "\n" +  "Score: " + to_string(aggWinStruct2.totalScore) + "\n" + "Total Price: " + to_string(aggWinStruct2.totalPrice) + "\n\n";
    
    aggResults << "3)\n" + aggWinStruct3.name1 + "\n" + aggWinStruct3.name2 + "\n" + aggWinStruct3.name3 + "\n" + aggWinStruct3.name4 + "\n" + aggWinStruct3.name5 + "\n" + aggWinStruct3.name6 + "\n"+ "Score: " + to_string(aggWinStruct3.totalScore) + "\n" + "Total Price: " + to_string(aggWinStruct3.totalPrice) + "\n\n";
    
    aggResults << "4)\n" + aggWinStruct4.name1 + "\n" + aggWinStruct4.name2 + "\n" + aggWinStruct4.name3 + "\n" + aggWinStruct4.name4 + "\n" + aggWinStruct4.name5 + "\n" + aggWinStruct4.name6 + "\n" + "Score: " + to_string(aggWinStruct4.totalScore) + "\n" + "Total Price: " + to_string(aggWinStruct4.totalPrice) + "\n\n";
    
    aggResults << "5)\n" + aggWinStruct5.name1 + "\n" + aggWinStruct5.name2 + "\n" + aggWinStruct5.name3 + "\n" + aggWinStruct5.name4 + "\n" + aggWinStruct5.name5 + "\n" + aggWinStruct5.name6 + "\n"+ "Score: " + to_string(aggWinStruct5.totalScore) + "\n" + "Total Price: " + to_string(aggWinStruct5.totalPrice) + "\n\n";
    
    aggResults << "6)\n" + aggWinStruct6.name1 + "\n" + aggWinStruct6.name2 + "\n" + aggWinStruct6.name3 + "\n" + aggWinStruct6.name4 + "\n" + aggWinStruct6.name5 + "\n" + aggWinStruct6.name6 + "\n"+ "Score: " + to_string(aggWinStruct6.totalScore) + "\n" + "Total Price: " + to_string(aggWinStruct6.totalPrice) + "\n\n";
    
    aggResults << "7)\n" + aggWinStruct7.name1 + "\n" + aggWinStruct7.name2 + "\n" + aggWinStruct7.name3 + "\n" + aggWinStruct7.name4 + "\n" + aggWinStruct7.name5 + "\n" + aggWinStruct7.name6 + "\n"+ "Score: " + to_string(aggWinStruct7.totalScore) + "\n" + "Total Price: " + to_string(aggWinStruct7.totalPrice) + "\n\n";
    
    aggResults << "8)\n" + aggWinStruct8.name1 + "\n" + aggWinStruct8.name2 + "\n" + aggWinStruct8.name3 + "\n" + aggWinStruct8.name4 + "\n" + aggWinStruct8.name5 + "\n" + aggWinStruct8.name6 + "\n"+ "Score: " + to_string(aggWinStruct8.totalScore) + "\n" + "Total Price: " + to_string(aggWinStruct8.totalPrice) + "\n\n";
    
    aggResults << "9)\n" + aggWinStruct9.name1 + "\n" + aggWinStruct9.name2 + "\n" + aggWinStruct9.name3 + "\n" + aggWinStruct9.name4 + "\n" + aggWinStruct9.name5 + "\n" + aggWinStruct9.name6 + "\n"+ "Score: " + to_string(aggWinStruct9.totalScore) + "\n" + "Total Price: " + to_string(aggWinStruct9.totalPrice) + "\n\n";
    
    aggResults << "10)\n" + aggWinStruct10.name1 + "\n" + aggWinStruct10.name2 + "\n" + aggWinStruct10.name3 + "\n" + aggWinStruct10.name4 + "\n" + aggWinStruct10.name5 + "\n" + aggWinStruct10.name6 + "\n"+ "Score: " + to_string(aggWinStruct10.totalScore) + "\n" + "Total Price: " + to_string(aggWinStruct10.totalPrice) + "\n\n";
    
    
    results << "Number of Combinations Checked: " + to_string(comboCount);
    
    results.close();
    return 0;
}

