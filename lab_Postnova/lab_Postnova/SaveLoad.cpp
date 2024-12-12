#include <iostream>
#include "SaveLoad.h"
#include <string>
#include <fstream>
#include "Function.h"
#include <unordered_map>


void PipesCreate(std::unordered_map<int, Pipe>& m) {
    Pipe p;
    std::cin >> p;
    m.emplace(p.GetId(), p);

}

void KSCreate(std::unordered_map<int, CS>& m) {
    CS g;
    std::cin >> g;
    m.emplace(g.GetId(), g);

}

void PipesPrint(std::unordered_map<int, Pipe>& m) {
    if (m.empty()) {
        std::cout << '\n';
        std::cout << "No pipes." << std::endl;
        return;
    }
    for (const auto& Pipe : m) {
        std::cout << Pipe.second;
    }
}

void KSPrint(std::unordered_map<int, CS>& m) {
    if (m.empty()) {
        std::cout << "No CS." << std::endl;
        std::cout << '\n';
        return;
    }
    for (const auto& CS : m) {
        std::cout << CS.second;
    }
}

void Load(std::unordered_map<int, Pipe>& Pipemap, std::unordered_map<int, CS>& KSmap) {
    std::ifstream fin;
    std::string data;

    std::cout << "Enter files name: ";
    INPUT_LINE(std::cin, data);

    fin.open(data);

    if (fin.is_open()) {
        int countpipes;
        fin >> countpipes;
        LoadObject(Pipemap, countpipes, fin);
        int countks;
        fin >> countks;
        LoadObject(KSmap, countks, fin);

        std::cout << "Succesfully loaded" << std::endl;
    }
    else {
        std::cout << "Error" << std::endl;
    }
    fin.close();
}

void ChangePipe(std::unordered_map<int, Pipe>& Pipemap, std::unordered_set <int>& res) {
    std::string idInput;
    std::cout << "Enter the IDs of the objects to change  (separated by spaces): ";
    INPUT_LINE(std::cin, idInput);
    // Парсинг строки с ID в вектор
    std::istringstream idStream(idInput);
    std::unordered_set<int> ids;
    int id;
    while (idStream >> id) {
        ids.emplace(id);
    }

    // Удаление объектов по каждому ID из списка
    for (int id : ids) {
        if (res.find(id) == res.end()) {
            std::cout << "Object with ID " << id << "not found.\n";
            continue;
        }
        Pipemap.at(id).changeofstate();
        std::cout << "Object with ID " << id << " succesfully changed\n";
    }
}

void ChangeKS(std::unordered_map<int, CS>& KSmap, std::unordered_set<int>& res) {
    std::string idInput;
    std::cout << "Enter the IDs of the objects to modify (separated by spaces): ";
    INPUT_LINE(std::cin, idInput);

    // Parsing the ID string into a set
    std::istringstream idStream(idInput);
    std::unordered_set<int> ids;
    int id;
    while (idStream >> id) {
        ids.emplace(id);
    }

    int change;
    std::cout << "Enter the number of workshops: ";
    change = GetCorrectNumber(0, 100);

    // Updating objects for each ID in the list
    for (int id : ids) {
        if (res.find(id) == res.end()) {
            std::cout << "Object with ID " << id << " not found.\n";
            continue;
        }

        if (KSmap.at(id).UpdateWorkshopsInUse(change)) {
            std::cout << "Object with ID " << id << " successfully updated.\n";
        }
        else {
            std::cout << "Error updating the object." << std::endl;
        }
    }
}
