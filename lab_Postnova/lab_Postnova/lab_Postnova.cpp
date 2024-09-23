#include <iostream>
#include <list>
#include <limits>

using namespace std;

struct Pipe {
    string mark_kilometr, repair;
    float length, diameter;
};

struct CS {
    string name, perfomance;
    int count_shop, count_workshop;
};

Pipe add_pipe()
{
    Pipe new_pipe;
    cout << "Enter the pipe name in the 'numberkm' format\n";
    cin >> new_pipe.mark_kilometr;
    cout << "Enter the length of the pipe\n";
    cin >> new_pipe.length;
    cout << "Enter the diameter of the pipe\n";
    cin >> new_pipe.diameter;
    cout << "Enter the repair of the pipe in the %\n";
    cin >> new_pipe.repair;
    return new_pipe;
}

void input_pipe(Pipe new_pipe)
{
    cout << "information pipes\n";
    cout << "1. pipe name" << " " << new_pipe.mark_kilometr << '\n';
    cout << "2. pipe length" << " " << new_pipe.length << '\n';
    cout << "3. pipe diameter" << " " << new_pipe.diameter << '\n';
    cout << "4. pipe repair" << " " << new_pipe.repair << '\n';
}

void edit_pipe(Pipe new_pipes)
{
    cout << "Enter the pipe attribute that you want to edit\n";

}

CS add_cs()
{
    CS new_station;
    cout << "Enter the  name of the compression station\n";
    cin >> new_station.name;
    cout << "Enter the count shop of the compression station\n";
    cin >> new_station.count_shop;
    cout << "Enter the count workshop of the compression station\n";
    cin >> new_station.count_workshop;
    cout << "Enter the perfomance compression station in the format ok, good, bad\n"; 
    cin >> new_station.perfomance;
    return new_station;
}

void input_cs(CS new_station)
{
    cout << "information station\n";
    cout << "1. cs name" << " " << new_station.name << '\n';
    cout << "2. cs count shop" << " " << new_station.count_shop << '\n';
    cout << "3. cs count workshop" << " " << new_station.count_workshop << '\n';
    cout << "4. cs perfomance" << " " << new_station.perfomance << '\n';
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
            << "5. Edit KC;\n" << "6. Save;\n"
            << "7. Download;\n" << "0. Exit\n";
        cout << "Enter the number\n";
        cin >> number;
        switch (number)
        {
        case 1:
            cout << "Add pipes\n";
            new_pipe = add_pipe();
            input_pipe(new_pipe);
            break;
        case 2:
            cout << "Add KC\n";
            new_station = add_cs();
            input_cs(new_station);
            break;
        case 3:
            cout << "All objects\n";
            input_pipe(new_pipe);
            input_cs(new_station);
            break;
        case 4:
            cout << "Edit pipe\n";
            input_pipe(new_pipe);
            cout << "enter attribute edit\n";
            cin >> attribute_pipe;
            switch (attribute_pipe) {
            case 1:
                cout << "Enter the pipe name in the 'numberkm' format\n";
                cin >> new_pipe.mark_kilometr;
                break;
            case 2:
                cout << "Enter the length of the pipe\n";
                cin >> new_pipe.length;
                break;
            case 3:
                cout << "Enter the diameter of the pipe\n";
                cin >> new_pipe.diameter;
                break;
            case 4:
                cout << "Enter the repair of the pipe in the %\n";
                cin >> new_pipe.repair;
                break;
            default:
                cout << "Enter begin number number attribute 1, 2, 3, 4\n";
            }
        case 5:
            cout << "Edit KS\n";
            input_cs(new_station);
            cout << "enter attribute edit\n";
            cin >> attribute_cs;
            switch (attribute_cs) {
            case 1:
                cout << "Enter the  name of the compression station\n";
                cin >> new_station.name;
                break;
            case 2:
                cout << "Enter the count shop of the compression station\n";
                cin >> new_station.count_shop;
                break;
            case 3:
                cout << "Enter the count workshop of the compression station\n";
                cin >> new_station.count_workshop;
                break;
            case 4:
                cout << "Enter the perfomance compression station in the format ok, good, bad\n";
                cin >> new_station.perfomance;
                break;
            default:
                cout << "Enter begin number number attribute 1, 2, 3, 4\n";
            }
        case 6:
            cout << "Save\n";
            break;
        case 7:
            cout << "Download\n";
            break;
        case 0:
            cout << "End command\n";
            return false;
            break;
        default:
            cout << "There is no such command, write the command number from the menu\n";
        }
    }
}
