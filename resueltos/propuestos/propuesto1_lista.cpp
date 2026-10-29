#include <iostream>
#include <string>

template <typename T>
class ListaEnlazada {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(const T& val) : dato(val), siguiente(nullptr) {}
    };

    Nodo* cabeza;
    size_t tamano;

public:
    ListaEnlazada() : cabeza(nullptr), tamano(0) {}

    ~ListaEnlazada() {
        limpiar();
    }

    void insertarFinal(const T& valor) {
        Nodo* nuevo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
        tamano++;
    }

    void mostrar() const {
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            std::cout << "[" << temp->dato << "] -> ";
            temp = temp->siguiente;
        }
        std::cout << "nullptr\n";
    }

    void limpiar() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
        cabeza = nullptr;
        tamano = 0;
    }
};

int main() {
    // Secuencia de edades (enteros)
    ListaEnlazada<int> listaEdades;
    listaEdades.insertarFinal(18);
    listaEdades.insertarFinal(20);
    listaEdades.insertarFinal(25);
    listaEdades.insertarFinal(30);

    std::cout << "Secuencia de Edades:\n";
    listaEdades.mostrar();

    // Secuencia de palabras (cadenas de texto)
    ListaEnlazada<std::string> listaPalabras;
    listaPalabras.insertarFinal("Universidad");
    listaPalabras.insertarFinal("Nacional");
    listaPalabras.insertarFinal("de");
    listaPalabras.insertarFinal("San");
    listaPalabras.insertarFinal("Agustin");

    std::cout << "\nSecuencia de Palabras:\n";
    listaPalabras.mostrar();

    return 0;
}
