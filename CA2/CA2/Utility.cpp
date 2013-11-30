#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

int getValidInput(const string& prompt, const int& lo, const int& hi)
{
	int value = 0;
	bool isNotValid = false;

	cout << endl;
	cout << prompt;

	do
	{
		if (!(cin >> value))
		{
			cout << "Not a valid character!" << endl;
			cout << endl;

			isNotValid = true;
			cin.clear(); //clear the stream input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			continue; //if we have reached this point we know that input is invalid, hence go back to the start 
		}
		else
		{
			isNotValid = (value < lo) || (value > hi);

			if (isNotValid)
			{
				cout << "Invalid input! Value outside of range " << lo << "-" << hi << endl;
				cout << endl;
			}
		}
	} while (isNotValid);
	cout << endl;

	return value;
}

bool getValidYesNoInput(const string& prompt)
{
	string availChoicesStr = " (y/n): ";

	char choice = '0';
	bool isNotValid = false;
	bool bYesNo = false;

	cout << endl;
	cout << prompt;
	cout << availChoicesStr;

	do
	{
		if (!(cin >> choice))
		{
			cout << "Not a valid character!" << endl;
			cout << endl;

			isNotValid = true;
			cin.clear(); //clear the stream input
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			continue; //if we have reached this point we know that input is invalid, hence go back to the start 
		}
		else
		{
			if (choice == 'y' || choice == 'Y')
			{
				isNotValid = false;
				bYesNo = true;
			}
			else if (choice == 'n' || choice == 'N')
			{
				isNotValid = false;
				bYesNo = false;
			}
			else
			{
				isNotValid = true;

				cout << "Please select the appropriate choice";
				cout << availChoicesStr << endl;
				cout << endl;
			}
		}
	} while (isNotValid);
	cout << endl;

	return bYesNo;
}

int getRandomNumber(const int& lo, const int& hi)
{
	return rand() % hi + lo;
}

void printMessageWithBorders(const string& message)
{
	cout << endl;
	cout << endl;
	for (unsigned i = 0; i < message.size(); i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << message;
	cout << endl;
	for (unsigned i = 0; i < message.size(); i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << endl;
}