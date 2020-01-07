/* Assignment: 3
Campus: Ashdod
Author:oz ben zaken, ID: 204015614 */

#include "Menu.h"

Menu::Menu(){} //c'tor

//main function
void Menu::run()
{
	              //creating of the 5 CSets with defuat values
	CSet<int> int1;
	CSet<int> int2;
	CSet<char> chars;
	CSet<Date> date1;
	CSet<Date> date2;

	cout << "hello and welcome to the main menu." << endl << "you got here 5 groups (2 int, 2 date and 1 char)." << endl << "you can do what you want with them (within the limit of the choices)." << endl << "Have fun..." << endl << endl;
	bool exit = false;  // when exit is true the main menu will end and return to main
	bool didOperate; // almost for each big switch case there is a smaller switch case. this is to see if the smaller switch case operate
	int choice; //the choise of the user for each switch case

	int tempI; //when adding int to an arrey it will be saved here first
	char tempC;//when adding char to an arrey it will be saved here first
	Date tempD;//when adding Date to an arrey it will be saved here first

	//the main loop that contain all the menu
	while (!exit)
	{
		didOperate = false;
		cout << endl << "what would you like to do?" << endl;
		cout << "1) adding a member to a group." << endl;
		cout << "2) removeing a member from a group." << endl;
		cout << "3) print all the individual numbers in both of the int groups." << endl;
		cout << "4) print all the the dates that presence in both of the date groups." << endl;
		cout << "5) print all the numbers that presence in one group and not in the second." << endl;
		cout << "6) check if one group of the dates contain the second." << endl;
		cout << "7) print all the number that are part of one of the groups but not both." << endl;
		cout << "8) check equality between the date group." << endl;
		cout << "9) writing to file all the dates from the chosen group" << endl << "  thats not exist in the other group." << endl;
		cout << "10) print a group." << endl;
		cout << "11) exit." << endl << endl << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl << endl;
		cout << "your choice:  ";
		cin >> choice;
		cout << endl << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl << endl;
		switch (choice)
		{
		case 1: /////////////////////////////////////case 1///////////////////////////////////////
			while (!didOperate)
			{
				cout << "please choose a group to add member too:" << endl;
				cout << "1) int-A" << endl;
				cout << "2) int-B" << endl;
				cout << "3) chars" << endl;
				cout << "4) date-A" << endl;
				cout << "5) date-B" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:///////////////////////////////case 1 option 1/////////////////////////////////
					cout << "enter an integer" << endl;
					try
					{
						cin >> tempI;
						int1 += tempI;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					didOperate = true;
					break;
				case 2:///////////////////////////////case 1 option 2/////////////////////////////////
					cout << "enter an integer" << endl;
					try
					{
						cin >> tempI;
						int2 += tempI;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					didOperate = true;
					break;
				case 3:///////////////////////////////case 1 option 3/////////////////////////////////
					cout << "enter a char: " << endl;
					cin>>tempC;
					while (!tempC)
						cin >> tempC;
					try
					{
						chars += tempC;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					didOperate = true;
					break;
				case 4:///////////////////////////////case 1 option 4/////////////////////////////////
					try
					{
						cout << "enter a date" << endl;
						didOperate = true;
						cin >> tempD;
						date1 += tempI;
					}
					catch (Date temp)
					{
						cout << "a bad date, please notice that years must be above 2000, month must be 1-12,"<<endl<<" and day are 1-31(depend on the specific month)." << endl;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					break;
				case 5:///////////////////////////////case 1 option 5/////////////////////////////////
					try
					{
						cout << "enter a date" << endl;
						didOperate = true;
						cin >> tempD;
						date1 += tempI;
					}
					catch (Date temp)
					{
						cout << "a bad date, please notice that years must be above 2000, month must be 1-12," << endl << " and day are 1-31(depend on the specific month)." << endl;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					break;
				default:
					cout << "not a correct option please stay within the option range." << endl;
					break;
				}
			}
			break;

		case 2: /////////////////////////////////////case 2///////////////////////////////////////
			while (!didOperate)
			{
				cout << "please choose a group to remove a member from:" << endl;
				cout << "1) int-A" << endl;
				cout << "2) int-B" << endl;
				cout << "3) char" << endl;
				cout << "4) date-A" << endl;
				cout << "5) date-B" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:///////////////////////////////case 2 option 1/////////////////////////////////
					cout << "enter an integer" << endl;
					cin >> tempI;
					try
					{
						int1 -= tempI;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					didOperate = true;
					break;
				case 2:///////////////////////////////case 2 option 2/////////////////////////////////
					cout << "enter an integer" << endl;
					cin >> tempI;
					try
					{
						int2 -= tempI;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					didOperate = true;
					break;
				case 3:///////////////////////////////case 2 option 3/////////////////////////////////
					cout << "enter a char: " << endl;
					tempC = getchar();
					while (!tempC)
						tempC = getchar();
					try
					{
						chars -= tempC;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					didOperate = true;
					break;
				case 4:///////////////////////////////case 2 option 4/////////////////////////////////
					try
					{
						cout << "enter a date" << endl;
						didOperate = true;
						cin >> tempD;
						date1 -= tempI;
					}
					catch (Date temp)
					{
						cout << "a bad date, please notice that years must be above 2000, month must be 1-12," << endl << " and day are 1-31(depend on the specific month)." << endl;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					break;
				case 5:///////////////////////////////case 2 option 5/////////////////////////////////
					try
					{
						cout << "enter a date" << endl;
						didOperate = true;
						cin >> tempD;
						date1 -= tempI;
					}
					catch (Date temp)
					{
						cout << "a bad date, please notice that years must be above 2000, month must be 1-12," << endl << " and day are 1-31(depend on the specific month)." << endl;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					break;
				default:
					cout << "not a correct option please stay within the option range." << endl;
					break;
				}
			}
			break;

		case 3: /////////////////////////////////////case 3///////////////////////////////////////
			try
			{
				cout << "that group is: " << (int1 | int2) << endl;
			}
			catch (string temp)
			{
				cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
			}
			break;

		case 4: /////////////////////////////////////case 4///////////////////////////////////////
			try
			{
				cout << "that grop is: " << (date1 & date2) << endl;
			}
			catch (string temp)
			{
				cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
			}
			break;

		case 5: /////////////////////////////////////case 5///////////////////////////////////////
			while (!didOperate)
			{
				cout << "please select what to do:" << endl;
				cout << "1) print numbers from group int-A that are not in int-B." << endl;
				cout << "2) print numbers from group int-B that are not in int-A." << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:///////////////////////////////case 5 option 1/////////////////////////////////
					try
					{
						didOperate = true;
						cout << "that group is: " << (int1 - int2) << endl;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					break;
				case 2:///////////////////////////////case 5 option 2/////////////////////////////////
					try
					{
						didOperate = true;
						cout << "that group is: " << (int2 - int1) << endl;
					}
					catch (string temp)
					{
						cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
					}
					break;
				default:
					cout << "not a correct option please stay within the option range." << endl;
					break;
				}
			}
			break;

		case 6: /////////////////////////////////////case 6///////////////////////////////////////
			while (!didOperate)
			{
				cout << "please choose a group of dates to see if it contain the other one." << endl;
				cout << "1) date-A" << endl;
				cout << "2) date-B" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:///////////////////////////////case 6 option 1/////////////////////////////////
					didOperate = true;
						if (date1 > date2)
							cout << "The base Group contains the parameter Group" << endl;
						else
							cout << "The parameter Group is not contained in the base Group" << endl;
					break;
				case 2:///////////////////////////////case 6 option 2/////////////////////////////////
					didOperate = true;
						if (date2 > date1)
							cout << "The base Group contains the parameter Group" << endl;
						else
							cout << "The parameter Group is not contained in the base Group" << endl;
					break;
				default:
					cout << "not a correct option please stay within the option range." << endl;
					break;
				}
			}
			break;

		case 7: /////////////////////////////////////case 7///////////////////////////////////////
			try
			{
				cout << "that group is: " << (int1^int2) << endl;
			}
			catch (string temp)
			{
				cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
			}
			break;

		case 8: /////////////////////////////////////case 8///////////////////////////////////////
				if (date1 == date2)
					cout << "The two Groups are equal" << endl;
				else
					cout << "The two Groups are not equal" << endl;
				cout << "couldnt alloc avilable memory. didnt proceed with the requested action" << endl;
			break;

		case 9: /////////////////////////////////////case 9///////////////////////////////////////
			while (!didOperate)
			{
				cout << "please select what to do:" << endl;
				cout << "1) print dates from group date-A that are not in date-B." << endl;
				cout << "2) print dates from group date-B that are not in date-A." << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:///////////////////////////////case 9 option 1/////////////////////////////////
					try
					{
						date1.DifWrite(date2);
					}
					catch (string temp)
					{
						cout << "couldnt open the file corctly. didnt proceed with the requested action" << endl;
					}
					didOperate = true;
					break;
				case 2:///////////////////////////////case 9 option 2/////////////////////////////////
					try
					{
						date2.DifWrite(date1);
					}
					catch (string temp)
					{
						cout << "couldnt open the file corctly. didnt proceed with the requested action" << endl;
					}
					didOperate = true;
					break;
				default:
					cout << "not a correct option please stay within the option range." << endl;
					break;
				}
			}
			break;

		case 10: /////////////////////////////////////case 10///////////////////////////////////////
			while (!didOperate)
			{
				cout << "please choose the group to be printed" << endl;
				cout << "1) int-A" << endl;
				cout << "2) int-B" << endl;
				cout << "3) char" << endl;
				cout << "4) date-A" << endl;
				cout << "5) date-B" << endl;
				cin >> choice;
				switch (choice)
				{
				case 1:///////////////////////////////case 10 option 1/////////////////////////////////
					cout << "int-A: " << int1 << endl;
					didOperate = true;
					break;
				case 2:///////////////////////////////case 10 option 2/////////////////////////////////
					cout << "int-B: " << int2 << endl;
					didOperate = true;
					break;
				case 3:///////////////////////////////case 10 option 3/////////////////////////////////
					cout << "chars: " << chars << endl;
					didOperate = true;
					break;
				case 4:///////////////////////////////case 10 option 4/////////////////////////////////
					cout << "date-A: " << date1 << endl;
					didOperate = true;
					break;
				case 5:///////////////////////////////case 10 option 5/////////////////////////////////
					cout << "date-B: " << date2 << endl;
					didOperate = true;
					break;
				default:
					cout << "not a correct option please stay within the option range." << endl;
					break;
				}
			}
			break;

		case 11: /////////////////////////////////////case 11///////////////////////////////////////
			cout << "Thnx for using our Groups sorting system. have a nice day." << endl;
			exit = true;
			break;
		default:
			cout << "not an acurate choice. didnt executed any option. please try again" << endl;
		}
	}
}

Menu::~Menu(){} //d'tor