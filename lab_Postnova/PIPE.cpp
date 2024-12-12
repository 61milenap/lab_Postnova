#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include "Pipe.h"

int Pipe::maxid = 0;

Pipe::Pipe() {
    id = ++maxid;
}

int Pipe::GetId() const {
    return id;
}

std::string Pipe::GetMarkKilometr() const {
    return mark_kilometr;
}

bool Pipe::IsInRepair() const {
    return repair;
}

int Pipe::GetDiameter() const {
    return diameter;
}

double Pipe::GetLength() const {
    return length;
}

void Pipe::SetRepairState(bool newState) {
    repair = newState;
}

void Pipe::SetMarkKilometr(const std::string& newMark) {
    mark_kilometr = newMark;
}

void Pipe::SetDiameter(int newDiameter) {
    diameter = newDiameter;
}

void Pipe::SetLength(double newLength) {
    length = newLength;
}

std::ifstream& operator>>(std::ifstream& fin, Pipe& p) {
    fin >> p.id >> std::ws;
    getline(fin, p.mark_kilometr);
    fin >> p.repair;
    fin >> p.diameter;
    fin >> p.length;
    return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const Pipe& p) {
    fout << p.id << std::endl;
    fout << p.mark_kilometr << std::endl;
    fout << p.repair << std::endl;
    fout << p.diameter << std::endl;
    fout << p.length << std::endl;
    return fout;
}

std::istream& operator>>(std::istream& in, Pipe& p) {
    std::cout << "Mark kilometr: ";
    std::getline(in, p.mark_kilometr);
    std::cout << "In repair (0 - Нет, 1 - Да): ";
    in >> p.repair;
    std::cout << "Diameter: ";
    in >> p.diameter;
    std::cout << "Length: ";
    in >> p.length;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Pipe& p) {
    out << "ID: " << p.id << std::endl;
    out << "Mark kilometr: " << p.mark_kilometr << std::endl;
    out << "In repair: " << (p.repair ? "Yes" : "No") << std::endl;
    out << "Diameter: " << p.diameter << std::endl;
    out << "Length: " << p.length << std::endl;
    return out;
}
