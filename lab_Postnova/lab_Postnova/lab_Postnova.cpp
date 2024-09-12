#include <iostream>
#include <list>

using namespace std;
int main()
{
    //меню приложения
    cout << "Menu:\n";
    cout << "1. Add pipes;\n" << "2. Add KC;\n" << "3. All objects;\n" << "4. Edit pipes;\n"
        << "5. Edit KC;\n" << "6. Save;\n" << "7. Download;\n" << "0. Exit\n";
    cout << "Enter the number\n";
    int number;
    list<string>objects{};
    do {
        cin >> number;
        if (number == 1) {
            cout << "Command 1. Add pipes\n";
            objects.push_back("Pipes");
        }
        else if (number == 2) {
            cout << "Command 2. Add KC\n";
            objects.push_back("KC");
        }
        else if (number == 3) {
            cout << "Command 3. All objects\n";
        }
        else if (number == 4) {
            cout << "Command 4. Edit pipes\n";
        }
        else if (number == 5) {
            cout << "Command 5. Edit KC\n";
        }
        else if (number == 6) {
            cout << "Command 6. Save\n";
        }
        else if (number == 7) {
            cout << "Command 7. Download\n";
        }
        else if (number >= 8) {
            cout << "Enter another command number\n";
        }
    } while (number != 0);
    cout << "End\n";
}