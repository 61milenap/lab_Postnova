#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <istream>

class CS {
private:
    std::string name; 
    int count_shop; 
    int count_workshop; 
    double performance; 

public:
    CS() : name("no"), count_shop(0), count_workshop(0), performance(0.00) {} 

    std::string Getname() const { return name; }

    int GetCountShop() const { return count_shop; }

    int GetCountWorkshop() const { return count_workshop; }

    double GetPerformance() const { return performance; }

    bool UpdateWorkshopsInUse(int change) {
        int new_count_workshop = count_workshop + change;
        if (new_count_workshop >= 0 && new_count_workshop <= count_shop) {
            count_workshop = new_count_workshop;
            return true;
        }
        else {
            std::cout << " If added it would be higher than " << count_shop << ".\n";
            return false;
        }
    }

    friend std::ifstream& operator >> (std::ifstream& fin, CS& g);

    friend std::ofstream& operator << (std::ofstream& fout, const CS& g);

    friend std::istream& operator >> (std::istream& in, CS& g);

    friend std::ostream& operator << (std::ostream& out, const CS& g);
};