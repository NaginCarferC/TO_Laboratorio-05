#include <iostream>

using namespace std;

// Plantilla primaria
template <class T>
class Contendor {
    T elemento;
public:
    Contendor(T arg) { elemento = arg; }
    T add() { return ++elemento; }
};

// Especialización total para el tipo char
template <>
class Contendor<char> {
    char elemento;
public:
    Contendor(char arg) { elemento = arg; }
    char uppercase() {
        if ((elemento >= 'a') && (elemento <= 'z')) {
            elemento = elemento + 'A' - 'a'; // Conversión a mayúscula
        }
        return elemento;
    }
};

int main() {
    Contendor<int> cint(5);
    Contendor<char> cchar('t');

    cout << cint.add() << endl;
    cout << cchar.uppercase() << endl;

    return 0;
}
