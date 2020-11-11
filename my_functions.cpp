#include <iostream>
#include <fstream>
#include <string>
#include "functions.h"

using namespace std;

int firstTimeRun() {
    fstream logFile;
    logFile.open("log.txt", ios::out | ios::in);
    if (logFile.is_open()) {
        string chp;
        getline(logFile, chp);
        if (chp == "0") {
            logFile.close();
            return 1;
        }
        else {
            logFile.close();
            return 0;
        }
    }
}

void clearConsole(int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << '\n'; // prints a new line
}

double calcBalance(string userChoice, double balance) {
    if (userChoice[0] == '+') {
        userChoice = userChoice.erase(0, 1);
        double num = stod(userChoice);
        balance += num;
        return balance;
    }
    else if (userChoice[0] == '-') {
        userChoice = userChoice.erase(0, 1);
        double num = stod(userChoice);
        balance -= num;
        return balance;
    }
}

void makeChanges(char* currentTime, double beforeBalance, double currentBalance, string operation, string note) {

    ofstream file;
    file.open("accountInfo.txt", ios::out | ios::app);
    if (file.is_open()) {
        //Format for account iformation
        file << "Date: " << currentTime << "\n";
        file << "Previous Balance: " << beforeBalance << ".          New Balance: " << currentBalance << ".\n";
        file << "Change Made: " << operation << ".\n";
        file << "Reason/Note: " << note << "\n------------------------------------------------------\n\n";
        //End Format
        file.close();
    }
}

double getBalance() {
    ifstream balfile;
    string stringBalance;
    balfile.open("accountBalance.txt");
    if (balfile.is_open()) {
        getline(balfile, stringBalance);
        balfile.close();
    }
    double realBalance = stod(stringBalance);
    return realBalance;
}

void updateBalance(double toUpdateBalance) {
    ofstream balf;
    string stringBalance;
    balf.open("accountBalance.txt");
    if (balf.is_open()) {
        balf << toUpdateBalance;
        balf.close();
    }
    
}

void displayCheckingBook() {
    ifstream accountf;
    accountf.open("accountInfo.txt");
    if (accountf.is_open()) {
        clearConsole(5);
        cout << accountf.rdbuf();
        accountf.close();
    }
}

void clearData() {
    ofstream dataFile;
    dataFile.open("accountInfo.txt");
    if (dataFile.is_open()) {
        dataFile << " ";
        dataFile.close();
    }
}