#include <iostream>
#include <list>

using namespace std;


struct Pipe {
    int mark_kilometr,length, diameter;
    char repair;
};

struct PC {

};

int main()
{
    //меню приложения
    cout << "Menu:\n";
    cout << "1. Add pipes;\n" << "2. Add KC;\n" 
        << "3. All objects;\n" << "4. Edit pipes;\n"
        << "5. Edit KC;\n" << "6. Save;\n" 
        << "7. Download;\n" << "0. Exit\n";
    cout << "Enter the number\n";
    int number, number_pipes, number_kc;
    int edit_objects;
    string name_pipe = "", name_kc, remont;
    int diametr_pipe, lenght_pipe;
    string name_kc, effections;
    int count_uex, count_uex_work;
    //создание списка с объектами
    list<string>objects{};
    do {
        cin >> number;
        if (number == 1) {
            cout << "Add pipes\n";
            objects.push_back( "Pipes" ); //добавление элементов в список
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
            edit_objects = 1;
            cout << "Enter the number of the characteristic you want to change\n";
            cout << "1";
           
        }
        else if (number == 5) {
            cout << "Edit KC\n";
            edit_objects = 2;
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