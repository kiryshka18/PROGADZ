#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream infile("input.txt");
    std::ofstream outfile("output.txt");

    if (!infile.is_open() || !outfile.is_open()) {
        std::cerr << "Ошибка при открытии файлов!" << std::endl;
        return 1;
    }

    std::string line;
    bool question_opened = false;

    while (std::getline(infile, line)) {
        if (line.empty()) continue;

        if (isdigit(line[0]) && line.find('.') != std::string::npos) {
            if (question_opened) {
                outfile << "}\n\n";
            }
            outfile << line << " {\n";
            question_opened = true;
        } 
        else if (line[0] == '+') {
            outfile << " = " << line.substr(1) << "\n";
        } 
        else if (line[0] == '-') {
            outfile << " ~ " << line.substr(1) << "\n";
        }
    }

    if (question_opened) {
        outfile << "}\n";
    }

    infile.close();
    outfile.close();

    return 0;
}