#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "functions.h"

using namespace std;
//global date and time variables
time_t dt = time(0);
char* currentDate = ctime(&dt);

int main()
{
    double accountBalance = getBalance();
    double accountBalanceArchive = 0;
    string option;
        //Check if setup is needed and run setup
        if (firstTimeRun() == 1) {
            ofstream logFile;
            logFile.open("log.txt");
            logFile << "1\n";
            logFile.close();
            cout << "Welcome! Lets set some things up....\n";
            cout << "(This can only be used for one account) How Much Money Is Currently In The Account? ";
            cin >> accountBalance;
            accountBalanceArchive = accountBalance;
            updateBalance(accountBalance);
            cout << "Perfect. You can clear, see, and add to your virtual checking book now. Just reset the app to get started!" << endl;
        
            makeChanges(currentDate, accountBalanceArchive, accountBalance, "Initial Balance", "Starting Balance");

        }
        else {
            //programStart:
            do
            {
                clearConsole(4);
                cout << "_____Welcome!_____\n\n";
                cout << "Current Time/Date: " << currentDate << endl;
                cout << "Options: 'clear' (Clears checkbook, careful!), 'start' (add a new checkbook entry), 'list' (list current checkingbook data)\n";
                cout << "Choice: ";
                cin >> option;

                //Check what user picked
                string operation;
                string reason;
                if (option == "start") {
                    accountBalanceArchive = accountBalance;
                    clearConsole(5);
                    cout << "Enter The Operation You Want To Do (ex. -50, +65.45): ";
                    cin >> operation;
                    if (operation[0] == '+' || operation[0] == '-') { accountBalance = calcBalance(operation, accountBalance); updateBalance(accountBalance); 
                    cout << "Note For Transaction: ";
                    cin >> reason;
                    cout << "Your All Set!";
                    makeChanges(currentDate, accountBalanceArchive, accountBalance, operation, reason);
                    clearConsole(6);
                    }
                    else { cout << "Please Enter a Proper Value..."; clearConsole(5); }// <----- (remove "}" ) goto programStart; }
                    
                    //goto programStart;

                }
                else if (option == "list") {
                    displayCheckingBook();
                }
                else if (option == "quit" || option == "exit") {
                    break;
                }
                else if (option == "clear") {
                    string yesNo;
                    cout << "          Are You Sure? (Y/N): ";
                    cin >> yesNo;
                    if (yesNo == "y" || yesNo == "Y") {
                        clearData();
                    }
                    else {
                        cout << "Your safe, no data had been deleted :)";
                    }
                }
            } while (true);
        }
    
}

