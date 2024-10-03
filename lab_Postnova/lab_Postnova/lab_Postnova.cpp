#include <iostream>
#include <limits>
#include <fstream>
#include <string>

using namespace std;


struct Pipe {
    string mark_kilometr = "no";
    bool repair = 0;
    int diameter = 0;
    double length = 0.0;
};


struct CS {
    string name = "no";
    int count_shop = 0, count_workshop = 0;
    double perfomance = 0.00;
};


int correct_int()
{
    int int_data;
    cin >> int_data;
    while (cin.fail() || cin.peek() != '\n' || int_data < 0)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nEnter an integer data type greater than 0\n";
        cin >> int_data;
    }
    return int_data;
}


double correct_double()
{
    double double_data;
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


bool correct_bool()
{
    bool bool_data;
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


double correct_double_perfomance()
{
    double double_data;
    cin >> double_data;
    while (cin.fail() || cin.peek() != '\n' || double_data <= 0 || double_data > 1)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "Enter perfomance 0.00 to 1.00\n";
        cin >> double_data;
    }
    return double_data;
}


Pipe add_pipe()
{
    Pipe new_pipe;
    cout << "Enter the pipe name\n";
    cin >> new_pipe.mark_kilometr;
    cout << "Enter the length of the pipe\n";
    new_pipe.length = correct_double();
    cout << "Enter the diameter of the pipe\n";
    new_pipe.diameter = correct_int();
    cout << "Enter the repair of the pipe reparing = 0 or unreparing=0\n";
    new_pipe.repair = correct_bool();
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
    bool fl_cs = false;
    cout << "Enter the  name of the compression station\n";
    cin >> new_station.name;
    cout << "Enter the count shop of the compression station\n";
    new_station.count_shop = correct_int();
    cout << "Enter the count workshop of the compression station\n";
    do {
        count_workshop = correct_int();
        if (count_workshop <= new_station.count_shop) {
            fl_cs = true;
        }
        else {
            cout << "Enter count workshop less count shop\n";
        }
    } while (fl_cs != true);
    new_station.count_workshop = count_workshop;
    cout << "Enter the perfomance compression station in the 0.00 to 1.00\n"; 
    new_station.perfomance = correct_double_perfomance();
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


void Save_Pipe(ofstream& fout, const Pipe& pipe) {
    if (pipe.mark_kilometr != "no") {
        fout << "information of pipe\n";
        fout << pipe.mark_kilometr << '\n';
        fout << pipe.length << '\n';
        fout << pipe.diameter << '\n';
        fout << pipe.repair << '\n';
    }
}


void Save_Cs(ofstream& fout, const CS& cs) {
    if (cs.name != "no") {
        fout << "information of cs\n";
        fout << cs.name << '\n';
        fout << cs.count_shop << '\n';
        fout << cs.count_workshop << '\n';
        fout << cs.perfomance << '\n';
    }
}


void Save(const Pipe& pipe, const CS& cs) {
    ofstream fout("information.txt");
    Save_Pipe(fout, pipe);
    Save_Cs(fout, cs);
    fout.close();
}


void Load_Pipe(ifstream& fin, Pipe& pipe) {
    getline(fin, pipe.mark_kilometr);
    fin >> pipe.length;
    fin >> pipe.diameter;
    fin >> pipe.repair;
}


void Load_Cs(ifstream& fin, CS& cs) {
    getline(fin, cs.name);
    fin >> cs.count_shop;
    fin >> cs.count_workshop;
    fin >> cs.perfomance;
}


void Load(Pipe& pipe, CS& cs) {
    ifstream fin("information.txt");
    string line;
    int flag = 0;
    if (fin.is_open()) {
        while (getline(fin, line)) {
            if (line == "information of pipe") {
                Load_Pipe(fin, pipe);
                cout << "Load pipe in structure\n";
                flag = 1;
            }
            else if (line == "information of cs") {
                Load_Cs(fin, cs);
                cout << "Load cs in structure\n";
                flag = 1;
            }
        if (flag == 0) cout << "\nNo information in file\n";
        }
        fin.close();
    }   
}

int main()
{
    Pipe new_pipe;
    CS new_station;
    int number;
    bool fl_cs = false;
    while (true) {
        //меню приложения
        cout << "Menu:\n";
        cout << "1. Add pipes;\n" << "2. Add CS;\n"
            << "3. All objects;\n" << "4. Edit pipes;\n"
            << "5. Edit CS;\n" << "6. Save;\n"
            << "7. Load\n" << "0. Exit\n";
        cout << "Enter the number\n";
        number = correct_int();
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
                cout << "editing the repair attribute for a pipe\n";
                new_pipe.repair = correct_bool();
            }
            break;
        case 5:
            int count_workshop;
            cout << "Edit CS\n";
            if (new_station.name == "no") {
                cout << "No new station\n";
            }
            else {
                cout << "editing the count workshop attribute for cs\n";
                do {
                    count_workshop = correct_int();
                    if (count_workshop < new_station.count_shop or count_workshop == new_station.count_shop) {
                        fl_cs = true;
                    }
                    else {
                        cout << "Enter count workshop less count shop\n";
                    }
                } while (fl_cs != true);
                new_station.count_workshop = count_workshop;
            }
            break;
        case 6:
            cout << "Save\n";
            Save(new_pipe, new_station);
            break;
        case 7:
            cout << "Load\n";
            Load(new_pipe, new_station);
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