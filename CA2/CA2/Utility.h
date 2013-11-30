#ifndef GUARD_Utility_h
#define GUARD_Utility_h

#include <string>

using namespace std;

int getValidInput(const string& prompt, const int& lo, const int& hi);
bool getValidYesNoInput(const string& prompt);
int getRandomNumber(const int& lo, const int& hi);
void printMessageWithBorders(const string& message);

#endif