#include <iostream>
#include "Function.h"
#include "SaveLoad.h"
#include "cs.h"

int CS::maxid = 0;

CS::CS()
{
    name = "no";
    count_shop = 0;
    count_workshop = 0;
    performance = 0.00;
}

std::string CS::Getname() const
{
    return name;
}

int CS::GetId()
{
    return id;
}

int CS::GetCountShop() const
{
    return count_shop;
}

int CS::GetCountWorkshop() const
{
    return count_workshop;
}

double CS::GetPerformance() const
{
    return performance;
}

std::ifstream& operator>>(std::ifstream& fin, CS& g)
{
    fin >> g.id;
    fin >> std::ws;
    getline(fin, g.name);
    fin >> g.count_shop;
    fin >> g.count_workshop;
    fin >> g.performance;
    g.maxid = g.id;
    return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const CS& g)
{
    fout << g.id << std::endl
        << g.name << std::endl
        << g.count_shop << std::endl
        << g.count_workshop << std::endl
        << g.performance << std::endl;
    return fout;
}

std::istream& operator>>(std::istream& in, CS& g)
{
    std::cout << "\nEnter the name for the compressor station: ";
    INPUT_LINE(in, g.name);

    g.id = ++g.maxid;
    std::cout << "Enter the number of shops: ";
    g.count_shop = GetCorrectNumber(1, 10000); 
    std::cout << "Enter the number of workshops: ";
    g.count_workshop = GetCorrectNumber(0, g.count_shop);  
    std::cout << "Enter the performance: ";
    g.performance = GetCorrectNumber(0.0, 100.0);  
    std::cout << std::endl;

    return in;
}

std::ostream& operator<<(std::ostream& out, const CS& g)
{
    if (g.name.empty()) {
        out << "No data to display" << "\n";
    }
    else {
        out << "\n";
        out << "ID: " << g.id << std::endl;
        out << "Name: " << g.name << std::endl;
        out << "Number of shops: " << g.count_shop << std::endl;
        out << "Number of workshops: " << g.count_workshop << std::endl;
        out << "Performance: " << g.performance << std::endl << std::endl;
    }
    return out;
}