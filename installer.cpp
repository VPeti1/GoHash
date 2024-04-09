#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <filesystem>
#define clear std::cout << "\033[2J\033[1;1H";
using namespace std;
namespace fs = std::filesystem;


void dw() {
    clear
    std::string distro;
    std::cout << "Enter your Linux distribution (arch/debian/fedora/void/opensuse):\n";
    std::cout << "(Derivatives included)\n";
    std::cin >> distro;
    if (distro == "arch") {
        system("sudo pacman -S git wget go");
        system("sudo touch /usr/flex/arch.cw");
    } else if (distro == "debian") {
        system("sudo apt-get install git wget go");
        system("sudo touch /usr/flex/deb.cw");
    } else if (distro == "fedora") {
        system("sudo dnf install git wget go");
        system("sudo touch /usr/flex/fed.cw");
    }
    else if (distro == "void") {
        system("sudo xbps-install git wget go");
        system("sudo touch /usr/flex/void.cw");
    }
    else if (distro == "opensuse") {
        system("sudo zypper install git wget go");
        system("sudo touch /usr/flex/suse.cw");
    }
    else if (distro == "skip") {

    }
     else {
        std::cout << "Unsupported distribution. Please choose arch, debian, void, opensuse or fedora.\n";
        clear
        dw();
    }
}

int main() {
    clear;
    std::cout << "GoHash Installer" << std::endl;
    std::cout << "By VPeti" << std::endl;
    sleep(2);
    dw();
    clear
    system("read -p 'Press Enter to continue...'");
    system("sudo rm -rf /usr/gohash/");
    system("sudo rm -rf /bin/gohash");
    system("sudo mkdir /usr/gohash");
    system("sudo git clone https://github.com/VPeti1/GoHash.git /usr/gohash");
    system("sudo go build /usr/gohash/main.go");
    system("sudo cp main /usr/bin/gohash");
    system("sudo rm -r /usr/gohash/");
    std::cout << "GoHash Installer Completed!" << std::endl;
    system("exit");
}
