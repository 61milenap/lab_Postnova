#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <istream>

class Pipe
{
private:
    std::string mark_kilometr = "no";
    bool repair = false;
    int diameter = 0;
    double length = 0.00;
    int id;
    static int maxid;
public:
    Pipe();
    int GetId();
    std::string Getname() const;
    bool Getstate() const;
    void SetState(bool newState) { state = newState; }
    void changeofstate();
    friend std::ifstream& operator >> (std::ifstream& fin, Pipe& p);
    friend std::ofstream& operator << (std::ofstream& fout, const Pipe& p);

    friend std::istream& operator >> (std::istream& in, Pipe& p);
    friend std::ostream& operator << (std::ostream& out, const Pipe& p);
};
