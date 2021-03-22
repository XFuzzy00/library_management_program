#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Global Variables
string book_name[5] = {"The Fault In Our Stars", "The Boy Who Loved", "Me Before You", "Macbeth", "The Water Keeper"};
string author[5] = {"John Green", "Durjoy Datta", "Jojo Moyes", "William Shakespeare", "Charles Martin"};
int book_id[5] = {101, 102, 103, 104, 105};
int price[5] = {150, 200, 300, 250, 100};
int stock[5] = {5, 5, 5, 5, 5};
string user_1 = " ", user_2 = " ", user_3 = " ";
string user1_data[2] = {" ", " "};
string user2_data[2] = {" ", " "};
string user3_data[2] = {" ", " "};
long cont_1, cont_2, cont_3;

// Global Functions
int borrow(); int return_book(); int stock_scr(); int borrow_another(); int return_another();


int returnIndex(string array[], string item)
{
	int index = 0;
	int sizeofArray = 4;

	while (index < sizeofArray)
	{
		if (array[index] == item)
		{
			break;
		}
		index++;
	}

	return index;
}

int main_menu()
{
	int input;

	cout << endl;
	cout << "--- MAIN MENU ---" << endl;
	cout << "1 : Borrow" << endl;
	cout << "2 : Return" << endl;
	cout << "3 : Stock" << endl;
	cout << "4 : Price" << endl;
	cout << "0 : Exit" << endl;
	cout << ">> ";
	cin >> input;

	switch (input)
	{
		case 1:
			borrow();
			break;
		case 2:
			return_book();
			break;
		case 3:
			stock_scr();
			break;
		case 4:
			for (int i = 0; i <= 4; i++)
			{
				cout << endl;
				cout << book_name[i] << "  : " << price[i] << " Credits.";
				cout << endl;
			}
			main_menu();
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "!! Invalid Choice !!";
			main_menu();
			break;
	}

	return 0;
}

int borrow()
{
	string bk_name, borw_name;
	int bk_id;
	long cnt_num;

	cout << endl;
	cout << "--- BORROW ---" << endl;
	cout << "Book Name : ";
	cin.ignore();
	getline(cin, bk_name);
	cout << endl;
	cout << "Book ID : ";
	cin >> bk_id;
	cout << endl;
	cout << "Borrower's Name : ";
	cin.ignore();
	getline(cin, borw_name);
	cout << endl;
	cout << "Contact Number : ";
	cin >> cnt_num;
	cout << endl;

	int index = returnIndex(book_name, bk_name);

	if (stock[index] > 0)
	{
		if (user_1 == " " || borw_name == user_1)
		{
			user_1 = borw_name;
			if (user1_data[0] == " ")
			{
				user1_data[0] = bk_name;
			}
			else if (user1_data[1] == " ")
			{
				user1_data[1] = bk_name;
			}
			else
			{
				cout << "!! Can't Borrow Any More Books !!";
			}
		}

		if (user_2 == " " || borw_name == user_2)
		{
			user_2 = borw_name;
			if (user2_data[0] == " ")
			{
				user2_data[0] = bk_name;
			}
			else if (user2_data[1] == " ")
			{
				user2_data[1] = bk_name;
			}
			else
			{
				cout << "!! Can't Borrow Any More Books !!";
			}
		}

		if (user_3 == " " || borw_name == user_3)
		{
			user_3 = borw_name;
			if (user3_data[0] == " ")
			{
				user3_data[0] = bk_name;
			}
			else if (user3_data[1] == " ")
			{
				user3_data[1] = bk_name;
			}
			else
			{
				cout << "!! Can't Borrow Any More Books !!";
			}
		}

		int currentStock = stock[index];
		stock[index] = currentStock - 1;

	}
	else
	{
		cout << "!! Sorry ! This Book Is Currently Out Of Stock !!";
	}

	borrow_another();
	return 0;
}

int return_book()
{
	string bk_name, ret_name;
	int bk_id;
	long cnt_num;

	cout << endl;
	cout << "--- RETURN ---" << endl;
	cout << "Book Name : ";
	cin.ignore();
	getline(cin, bk_name);
	cout << endl;
	cout << "Book ID : ";
	cin >> bk_id;
	cout << endl;
	cout << "Returner's Name : ";
	cin.ignore();
	getline(cin, ret_name);
	cout << endl;
	cout << "Contact Number : ";
	cin >> cnt_num;
	cout << endl;

	int index = returnIndex(book_name, bk_name);


	if (stock[index] < 5)
	{
		if (ret_name == user_1)
		{
			if (bk_name == user1_data[0])
			{
				user1_data[0] = " ";
		}
			if (bk_name == user1_data[1])
			{
				user1_data[1] = " ";
			}
			else
			{
				cout << "!! You Do Not Have Any Borrowed Book Left !!";
			}
		}

		if (ret_name == user_2)
		{
			if (bk_name == user2_data[0])
			{
				user2_data[0] = " ";
			}
			if (bk_name == user2_data[1])
			{
				user2_data[1] = " ";
			}
			else
			{
				cout << "!! You Do Not Have Any Borrowed Book Left !!";
			}
		}

		if (ret_name == user_1)
		{
			if (bk_name == user3_data[0])
			{
				user3_data[0] = " ";
			}
			if (bk_name == user3_data[1])
			{
				user3_data[1] = " ";
			}
			else
			{
				cout << "!! You Do Not Have Any Borrowed Book Left !!";
			}
		}

		int currentStock = stock[index];
		stock[index] = currentStock + 1;

	}


	return_another();
	return 0;
}

int borrow_another()
{
	int input;

	cout << endl;
	cout << "1 : Borrow Another Book" << endl;
	cout << "0 : Exit" << endl;
	cout << ">> ";
	cin >> input;

	switch (input)
	{
		case 1:
			borrow();
			break;
		case 0:
			main_menu();
			break;
		default:
			cout << "!! Invalid Choice !!";
			borrow_another();
			break;
	}

	return 0;
}

int return_another()
{
	int input;

	cout << endl;
	cout << "1 : Return Book" << endl;
	cout << "0 : Exit" << endl;
	cout << ">> ";
	cin >> input;

	switch (input)
	{
		case 1:
			return_book();
			break;
		case 0:
			main_menu();
			break;
		default:
			cout << "!! Invalid Choice !!";
			return_another();
			break;
	}

	return 0;
}

int stock_scr()
{
	cout << endl;
	cout << "---STOCK---" << endl;

	for (int a = 0; a <= 4; a++)
	{
		cout << endl;
		cout << "Book Name : " << book_name[a] << endl;
		cout << "Book Author : " << author[a] << endl;
		cout << "Book ID : " << book_id[a] << endl;
		cout << "Price : " << price[a] << endl;
		cout << "Available Stock : " << stock[a] << endl;
	}

	main_menu();
	return 0;
}










int main()
{
	main_menu();
	return 0;
}
