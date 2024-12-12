#include <iostream>
#include <string>
#include <fstream>
#include "PIPEclass.h"
#include "CSclass.h"
#include "SaveLoad.h"
#include "Functions.h"
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <format>

void PrintMainMenu() {
	std::cout <<
		"1. Add a pipe\n"
		"2. Add a compressor station\n"
		"3. View all objects\n"
		"4. Save\n"
		"5. Load\n"
		"6. Search\n"
		"0. Exit\n\n";
}

void Printaddmenu() {
	std::cout <<
		"1. Search pipe by name\n"
		"2. Search pipe by state\n"
		"3. Search compressor station by name\n"
		"4. Search compressor station by workshops\n"
		"0. Return to main menu\n\n";
}

void PrintChois() {
	std::cout << "1.Change" << std::endl << "2.Delete" << std::endl;
}

void savepipe(std::ofstream& fout, std::unordered_map<int, Pipe>& Pipemap) {
	for (auto& p : Pipemap) {
		fout << p.second;
	}
}

void savecs(std::ofstream& fout, std::unordered_map<int, CS>& KSmap) {
	for (auto& g : KSmap) {
		fout << g.second;
	}
}

void MainMenu(std::unordered_map<int, Pipe>& Pipemap, std::unordered_map<int, CS>& KSmap) {
	std::string data;
	std::string name;
	bool state;
	int work;
	int chois;
	std::unordered_set <int> res;
	int userChoice;
	while (1) {
		PrintMainMenu();
		userChoice = GetCorrectNumber(0, 6);
		switch (userChoice) {
		case 1:
			PipesCreate(Pipemap);
			break;
		case 2:
			KSCreate(KSmap);
			break;
		case 3:
			PipesPrint(Pipemap);
			KSPrint(KSmap);
			break;
		case 4: {
			std::ofstream fout;
			std::cout << "Enter ";
			INPUT_LINE(std::cin, data);
			fout.open(data, std::ios::out);
			if (fout.is_open()) {
				fout << Pipemap.size() << std::endl;
				savepipe(fout, Pipemap);
				fout << KSmap.size() << std::endl;
				savecs(fout, KSmap);
				std::cout << "Saved succesfully" << std::endl;
			}
			else {
				std::cout << "Failed to write to the file..." << std::endl;
			}
			break;
		}
		case 5:
			Load(Pipemap, KSmap);
			break;
		case 6: {
			int searchChoice;
			bool exitSubMenu = false;
			while (!exitSubMenu) {
				Printaddmenu();
				searchChoice = GetCorrectNumber(0, 4);
				switch (searchChoice) {
				case 1:
					if (Pipemap.empty()) {
						std::cout << "No objects" << std::endl;
						break;
					}
					else {
						std::cout << "Enter a name for the search ";
						INPUT_LINE(std::cin, name);
						res = FindPipeFilter(Pipemap, checknamepipe, name);
						PrintChois();
						chois = GetCorrectNumber(1, 2);
						if (chois == 1) {
							ChangePipe(Pipemap, res);
						}
						if (chois == 2) {
							DeleteObjectById<Pipe>(Pipemap, res);
						}
					}
					break;
				case 2:
					if (Pipemap.empty()) {
						std::cout << "No objects" << std::endl;
						break;
					}
					else {
						std::cout << "Enter a state for the search";
						state = GetCorrectNumber(0, 1);
						res = FindPipeFilter(Pipemap, checkstate, state);
						PrintChois();
				case 3:
					if (Pipemap.empty()) {
						std::cout << "No objects" << std::endl;
						break;
					}
					else {
						std::cout << "Enter a state for the search";
						state = GetCorrectNumber(0, 1);
						res = FindPipeFilter(Pipemap, checkstate, state);
						PrintChois();
						chois = GetCorrectNumber(1, 2);
						if (chois == 1) {
							ChangePipe(Pipemap, res);
						}
						if (chois == 2) {
							DeleteObjectById<Pipe>(Pipemap, res);
						}
					}
					break;
				case 4:
					if (KSmap.empty()) {
						std::cout << "No objects" << std::endl;
						break;
					}
					else {
						std::cout << "Enter a name for the search ";
						INPUT_LINE(std::cin, name);
						res = FindKSFilter(KSmap, checknameks, name);
						PrintChois();
						chois = GetCorrectNumber(1, 2);
						if (chois == 1) {
							ChangeKS(KSmap, res);
						}
						if (chois == 2) {
							DeleteObjectById<CS>(KSmap, res);
						}
					}
					break;
				case 5:
					if (KSmap.empty()) {
						std::cout << "No objects" << std::endl;
						break;
					}
					else {
						std::cout << "Enter CS for search";
						work = GetCorrectNumber(0, 100);
						res = FindKSFilter(KSmap, workshops, work);
						PrintChois();
						chois = GetCorrectNumber(1, 2);
						if (chois == 1) {
							ChangeKS(KSmap, res);
						}
						if (chois == 2) {
							DeleteObjectById<CS>(KSmap, res);
						}
					}
					break;
				case 0:
					exitSubMenu = true;
					break;
				default:
					std::cout << "Incorrect input. Try again.\n";
					break;
					}
				}
			}
		case 0:
			return;
		}
		}
	}