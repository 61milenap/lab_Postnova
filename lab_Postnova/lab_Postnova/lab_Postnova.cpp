#include <iostream>
#include <list>

using namespace std;
int main()
{
    //меню приложения
    cout << "Menu:\n";
    cout << "1. Add pipes;\n" << "2. Add KC;\n" 
        << "3. All objects;\n" << "4. Edit pipes;\n"
        << "5. Edit KC;\n" << "6. Save;\n" 
        << "7. Download;\n" << "0. Exit\n";
    cout << "Enter the number\n";
    int number;
    list<string>objects{};
    do {
        cin >> number;
        if (number == 1) {
            cout << "Add pipes\n";
            objects.push_back( "Pipes" );
        }
        else if (number == 2) {
            cout << "Add KC\n";
            objects.push_back( "KC" );
        }
        else if (number == 3) {
            cout << "All objects\n";
            if (objects.size() != 0) {
                for (string n : objects)
                    std::cout << n << "\n";
            }
            else {
                cout << "No objects\n";
            }
        }
        else if (number == 4) {
            cout << "Edit pipes\n";
        }
        else if (number == 5) {
            cout << "Edit KC\n";
        }
        else if (number == 6) {
            cout << "Save\n";
        }
        else if (number == 7) {
            cout << "Download\n";
        }
        else if (number >= 8) {
            cout << "Enter another command number\n";
        }
    } while (number != 0);
    cout << "End\n";
}