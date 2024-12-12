#include "Function.h"
#include <iostream>
#include "SaveLoad.h"
#include <unordered_set>

void fix() { 
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



bool checknamepipe(const Pipe& p, const std::string param)
{
    return p.Getname().find(param) != std::string::npos;
}
bool checkstate(const Pipe& p, bool param)
{
    return p.Getstate() == param;
}

bool checknameks(const CS& g, std::string param)
{
    return g.Getname().find(param) != std::string::npos;
}
bool workshops(const CS& g, int param)
{
    return g.Getworkshops() >= param;
}

void edit(std::unordered_map<int, Pipe>& Pipemap, std::unordered_set <int> res) {


    std::string idInput;
    std::cout << "Enter the IDs of the objects to change their state(separated by spaces) : ";
    std::getline(std::cin >> std::ws, idInput);

    std::istringstream idStream(idInput);
    int id;
    bool foundAny = false;

    while (idStream >> id) {
        // Проверяем, есть ли этот ID в отфильтрованных
        if (res.find(id) != res.end()) {
            Pipemap.at(id).changeofstate(); // Меняем состояние трубы с данным ID
            foundAny = true;
            std::cout << "State of pipe with ID " << id << "changed." << std::endl;
        }
        else {
            std::cout << "ID " << id << " wasnt found in filtered." << std::endl;
        }
    }

    if (!foundAny) {
        std::cout << "No ID  was found for the change of state." << std::endl;
    }
}