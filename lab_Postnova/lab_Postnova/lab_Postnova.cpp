#include <iostream>
#include <list>
#include <limits>

using namespace std;

struct Pipe {
    char mark_kilometr = '0km';
    float length = 0.0, diameter = 0.0, repair = 0.0;
};

struct CS {
    char name='name';
    int count_shop = 0, count_workshop = 0;
    char perfomance = 'ok';
};

Pipe add_pipe()
{
    Pipe new_pipes;
    cout << "Enter the pipe name in the 'numberkm' format\n";
    cin >> new_pipes.mark_kilometr;
    cout << "Enter the length of the pipe\n";
    cin >> new_pipes.length;
    cout << "Enter the diameter of the pipe\n";
    cin >> new_pipes.diameter;
    cout << "Enter the repair of the pipe\n";
    cin >> new_pipes.repair;
    return new_pipes;
}

void input_pipe(Pipe new_pipes)
{
    cout << "information pipes\n";
    cout << "pipe name" << " " << new_pipes.mark_kilometr << '\n';
    cout << "pipe length" << " " << new_pipes.length << '\n';
    cout << "pipe diameter" << " " << new_pipes.diameter << '\n';
    cout << "pipe repair" << " " << new_pipes.repair << '\n';
}

void add_cs()
{
    CS new_station;
    cout << "Enter the  name of the compression station\n";
    cout << "Enter the count shop of the compression station\n";
    cout << "Enter the count workshop of the compression station\n";
    cout << "Enter the perfomance compression station in the format ok, good, bad\n"; 
}

void correct_input;

void edit_pipe;

void edit_cs;


int main()
{
    Pipe new_pipe;
    CS new_cs;
    int number;
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
            break;
        case 3:
            cout << "All objects\n";
            input_pipe(new_pipe);
            break;
        case 4:
            break;
        case 5:
            cout << "Edit KS\n";
            cout << "Enter the pipe attribute that you want to edit\n";
            break;
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
