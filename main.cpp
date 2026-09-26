#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int TOTAL_VARIANTS = 30;

int getVariant(const string& name) {
    if (name.empty()) {
        return 0;
    }

    unsigned char firstLetter = static_cast<unsigned char>(name[0]);
    unsigned char upperLetter = toupper(firstLetter);
    
    int variant = upperLetter % TOTAL_VARIANTS;

    if (variant == 0) {
        variant = TOTAL_VARIANTS;
    }

    return variant;
}

int main(int argc, char* argv[]) {
    string name;
    
    if (argc > 1) {
        name = argv[1];
    } else {
        cout << "Введите имя: ";
        getline(cin, name);
    }

    int variant = getVariant(name);

    cout << "имя: " << name << endl;
    cout << "номер варианта: " << variant << endl;

    return 0;
}