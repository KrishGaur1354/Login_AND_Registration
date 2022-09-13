#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read( username + ".xlsx");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;

    cout << "1: REGITRATION\n2 :LOGIN\nYour Choice: "; cin >> choice;
    if (choice == 1)
    {
        string username, password;

        cout << "Select a Usename: "; cin >> username;
        cout << "Select a Password: "; cin >> password;

        ofstream file;
        file.open( username + ".xlsx"); 

        file << username << endl << password;
        file.close() ;

        main();
    }
    else if (choice == 2)
    {
        bool status = IsLoggedIn();

        if (status == false)
        {
            cout << "Wrong username or password!" << endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            cout << "Succesfully Logged In!" << endl;
            system("PAUSE");
            return 1;

        }
    }
}