//Bebudo
//Created Jul 1st 2024

#include <iostream>
#include <fstream>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <unistd.h> // for usleep
#include "engine.h"
#include "inventory.h"

std::string username = "";

void loadUsername() {
    std::ifstream infile("save.txt");
    if (infile.is_open()) {
        std::getline(infile, username);
        infile.close();
    }
}

void saveUsername() {
    std::ofstream outfile("save.txt");
    if (outfile.is_open()) {
        outfile << username;
        outfile.close();
    }
}

int main(){
    system("clear");
    printLogo();
    loadUsername();
    if (username.empty()) {
        std::cout << "Enter a username: ";
        std::cin >> username;
        saveUsername();
        system("clear");
    } else {
        system("clear");
        printLogo();
        std::cout << "";
    }
    Engine engine;
    engine.waitForInput();
    return 0;
}