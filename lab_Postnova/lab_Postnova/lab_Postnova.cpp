#include <iostream>
#include <limits>
#include <fstream>
#include <string>

using namespace std;

struct Pipe {
    string mark_kilometr="no";
    bool repair;
    int diameter;
    double length;
};

struct CS {
    string name="no";
    int count_shop, count_workshop;
    float perfomance;
};

bool correct_string(const std::string& input) {
    return !input.empty();
}

string correct_strings(string& string_data) {
    do {
        cin >> string_data;
        if (not correct_string(string_data)) {
            cout << "Enter string format output\n";
        }
    } while (correct_string(string_data));
    return string_data;
}


int correct_int(int& int_data)
{
    cin >> int_data;
    while (cin.fail() || cin.peek() != '\n' || int_data <= 0)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter an integer data type greater than 0\n";
        cin >> int_data;
    }
    return int_data;
}

double correct_double(double& double_data)
{
    cin >> double_data;
    while (cin.fail() || cin.peek() != '\n' || double_data <= 0)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a double data type greater than 0\n";
        cin >> double_data;
    }
    return double_data;
}


bool correct_bool(bool& bool_data)
{
    cin >> bool_data;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter a boolean data type\n";
        cin >> bool_data;
    }
    return bool_data;
}

Pipe add_pipe()
{
    Pipe new_pipe;
    cout << "Enter the pipe name format\n";
    correct_strings(new_pipe.mark_kilometr);
    cout << "Enter the length of the pipe\n";
    correct_double(new_pipe.length);
    cout << "Enter the diameter of the pipe\n";
    correct_int(new_pipe.diameter);
    cout << "Enter the repair of the pipe in 0 or 1\n";
    correct_bool(new_pipe.repair);
    return new_pipe;
}

void output_pipe(Pipe new_pipe)
{
    if (new_pipe.mark_kilometr == "no") {
        cout << "No new pipe\n";
    }
    else {
        cout << "information pipes\n";
        cout << "pipe name" << " " << new_pipe.mark_kilometr << '\n';
        cout << "pipe length" << " " << new_pipe.length << '\n';
        cout << "pipe diameter" << " " << new_pipe.diameter << '\n';
        cout << "pipe repair" << " " << new_pipe.repair << '\n';
    } 
}


CS add_cs()
{
    CS new_station;
    string name;
    int count_workshop;
    bool fl_cs = 0;
    cout << "Enter the  name of the compression station\n";
    correct_strings(new_station.name);
    cin >> new_station.name;
    cout << "Enter the count shop of the compression station\n";
    correct_int(new_station.count_shop);
    cout << "Enter the count workshop of the compression station\n";
    do {
        cin >> count_workshop;
        correct_int(count_workshop);
        if (count_workshop <= new_station.count_shop) {
            fl_cs = 1;
        }
    } while (fl_cs = 1);
    new_station.count_workshop = count_workshop;
    cout << "Enter the perfomance compression station in the format ok, good, bad\n"; 
    cin >> new_station.perfomance;
    return new_station;
}

void output_cs(CS new_station)
{
    if (new_station.name == "no") {
        cout << "No new station\n";
    }
    else {
        cout << "information station\n";
        cout << "cs name" << " " << new_station.name << '\n';
        cout << "cs count shop" << " " << new_station.count_shop << '\n';
        cout << "cs count workshop" << " " << new_station.count_workshop << '\n';
        cout << "cs perfomance" << " " << new_station.perfomance << '\n';
    }
}


int main()
{
    Pipe new_pipe;
    CS new_station;
    int number, attribute_pipe, attribute_cs;
    while (true) {
        //меню приложения
        cout << "Menu:\n";
        cout << "1. Add pipes;\n" << "2. Add KC;\n"
            << "3. All objects;\n" << "4. Edit pipes;\n"
            << "5. Edit KC;\n" << "6. Save Pipe;\n"
            << "7. Download Pipe;\n" << "8. Save KC;\n"
            << "9. Download;\n" << "0. Exit\n";
        cout << "Enter the number\n";
        cin >> number;
        switch (number)
        {
        case 1:
            cout << "Add pipes\n";
            new_pipe = add_pipe();
            output_pipe(new_pipe);
            break;
        case 2:
            cout << "Add KC\n";
            new_station = add_cs();
            output_cs(new_station);
            break;
        case 3:
            cout << "All objects\n";
            output_pipe(new_pipe);
            output_cs(new_station);
            break;
        case 4:
            cout << "Edit pipe\n";
            if (new_pipe.mark_kilometr == "no") {
                cout << "No new pipe\n";
            }
            else {
                cout << "editing the under repair attribute for a pipe\n";
                correct_bool(new_pipe.repair);
            }
            break;
        case 5:
            cout << "Edit CS\n";
            if (new_station.name == "no") {
                cout << "No new station\n";
            }
            else {
                int count_workshop;
                bool fl_cs = 0;
                cout << "Change the number of workshops\n";
                do{
                    cin >> count_workshop;
                    correct_int(count_workshop);
                    if (count_workshop <= new_station.count_shop) {
                        fl_cs = 1;
                    }
                }
                while(fl_cs=1);
                new_station.count_workshop = count_workshop;
            }
            break;
        case 6:
            cout << "Save Pipe\n";
            break;
        case 7:
            cout << "Download Pipe\n";
            break;
        case 8:
            cout << "Save KS\n";
            break;
        case 9:
            cout << "Download KS\n";
            break;
        case 0:
            cout << "End command\n";
            return 0;
            break;
        default:
            cout << "There is no such command, write the command number from the menu\n";
        }
    }
}
