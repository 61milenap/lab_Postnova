#include <iostream>
#include <list>

using namespace std;

struct Pipe {
    char mark_kilometr;
    double length = 0.0, diameter = 0.0, repair = 0.0;
};

struct KS {
    string name;
    int count_shop, count_workshop;
    char perfomance;
};

int main()
{
    int number;
    //меню приложения
    cout << "Menu:\n";
    cout << "1. Add pipes;\n" << "2. Add KC;\n" 
         << "3. All objects;\n" << "4. Edit pipes;\n"
         << "5. Edit KC;\n" << "6. Save;\n" 
         << "7. Download;\n" << "0. Exit\n";
    cout << "Enter the number\n";
    cin >> number;
    switch (number)
    {
    case 1:
        cout << "Add pipes\n";
        break;
    case 2:
        cout << "Add KC\n";
        break;
    case 3:
        cout << "All objects\n";
        break;
    case 4:
        cout << "Edit pipes\n";
        break;
    case 5:
        cout << "Edit KS\n";
        break;
    case 6:
        cout << "Save\n";
        break;
    case 7:
        cout << "Download\n";
        break;
    case 0:
        return false;
        break;
    default:
        cout << "There is no such command, write the command number from the menu\n";
    }



}