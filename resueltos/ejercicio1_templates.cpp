#include <iostream>

// a) Función plantilla para operaciones aritméticas básicas
template<typename mitipo>
mitipo aritmetica(mitipo x, mitipo y) {
    return x + y;
}

// b) Función plantilla para obtener el elemento mayor
template <typename Tipo>
Tipo mayorDe(Tipo a, Tipo b) {
    return (a > b ? a : b);
}

// c) Clase plantilla para manipular un arreglo de tamaño fijo
template<typename T>
class Contenedor {
private:
    T array[4];
public:
    T metodol(int xx) {
        return array[xx];
    }

    void metodo2(T val, int i) {
        if (i >= 0 && i < 4) {
            array[i] = val;
        }
    }

    void mostrar() const {
        for (int i = 0; i < 4; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::cout << "--- 1.a) Aritmetica con Plantillas ---\n";
    std::cout << "Enteros (10 + 45): " << aritmetica<int>(10, 45) << "\n";
    std::cout << "Doubles (3.45 + 8.10): " << aritmetica<double>(3.45, 8.10) << "\n";
    std::cout << "Floats (0.14f + 0.147f): " << aritmetica<float>(0.14f, 0.147f) << "\n";

    std::cout << "\n--- 1.b) Mayor de dos elementos ---\n";
    char x = mayorDe<char>('e', 'z');
    int y = mayorDe<int>(9, 4);
    std::cout << "Caracter mayor entre 'e' y 'z': " << x << "\n";
    std::cout << "Numero mayor entre 9 y 4: " << y << "\n";

    std::cout << "\n--- 1.c) Clase Contenedor ---\n";
    Contenedor<int> z;
    z.metodo2(10, 0);
    z.metodo2(50, 1);
    z.metodo2(60, 2);
    z.metodo2(70, 3);
    std::cout << "Contenido del array: ";
    z.mostrar();

    return 0;
}
