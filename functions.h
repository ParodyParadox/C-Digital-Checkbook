#include <iostream>
#include <string>

int firstTimeRun();
void clearConsole(int size);
double calcBalance(std::string userChoice, double balance);
void makeChanges(char* currentTime, double beforeBalance, double currentBalance, std::string operation = "No Changes Made", std::string note = "No Notes Given");
void updateBalance(double toUpdateBalance);
double getBalance();
void displayCheckingBook();
void clearData();
