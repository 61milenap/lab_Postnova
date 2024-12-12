#pragma once
#include "Pipe.h"
#include "cs.h"
#include <unordered_map>
#include <sstream> 
#include <vector>
#include "Function.h"

void KSCreate(std::unordered_map<int, CS>& m);
void PipesCreate(std::unordered_map<int, Pipe>& m);
void PipesPrint(std::unordered_map<int, Pipe>& m);
void KSPrint(std::unordered_map<int, CS>& m);

template <typename T>
std::unordered_map<int, T> LoadObject(std::unordered_map<int, T>& Object, int count, std::ifstream& fin) {
    for (int i = 0; i < count; i++) {
        T obj{};
        fin >> obj;
        Object.emplace(obj.GetId(), obj);
    }
    return Object;
}
void Load(std::unordered_map<int, Pipe>& Pipemap, std::unordered_map<int, CS>& KSmap);

template <typename T>
void DeleteObjectById(std::unordered_map<int, T>& objects, std::unordered_set <int>& res) {
    std::string idInput;
    std::cout << "Enter ID to delete (use spaces): ";
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
        auto it = objects.find(id);
        if (res.find(id) == res.end()) {
            std::cout << "Object with ID " << id << "not found.\n";
            continue;
        }
        if (it != objects.end()) {
            objects.erase(it);
            std::cout << "Object with ID " << id << "succesfully changed.\n";
        }
    }
}



void ChangePipe(std::unordered_map<int, Pipe>& Pipemap, std::unordered_set <int>& res);
void ChangeKS(std::unordered_map<int, CS>& KSmap, std::unordered_set <int>& res);