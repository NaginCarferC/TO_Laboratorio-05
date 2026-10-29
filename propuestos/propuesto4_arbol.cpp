#include <iostream>

template <typename T>
class ArbolBinario {
private:
    struct NodoArbol {
        T dato;
        NodoArbol* izquierdo;
        NodoArbol* derecho;
        NodoArbol(const T& val) : dato(val), izquierdo(nullptr), derecho(nullptr) {}
    };

    NodoArbol* raiz;

    void insertarAux(NodoArbol*& nodo, const T& valor) {
        if (!nodo) {
            nodo = new NodoArbol(valor);
        } else if (valor < nodo->dato) {
            insertarAux(nodo->izquierdo, valor);
        } else {
            insertarAux(nodo->derecho, valor);
        }
    }

    void inOrdenAux(NodoArbol* nodo) const {
        if (nodo) {
            inOrdenAux(nodo->izquierdo);
            std::cout << nodo->dato << " ";
            inOrdenAux(nodo->derecho);
        }
    }

    void destruirAux(NodoArbol* nodo) {
        if (nodo) {
            destruirAux(nodo->izquierdo);
            destruirAux(nodo->derecho);
            delete nodo;
        }
    }

public:
    ArbolBinario() : raiz(nullptr) {}

    ~ArbolBinario() {
        destruirAux(raiz);
    }

    void insertar(const T& valor) {
        insertarAux(raiz, valor);
    }

    void imprimirInOrden() const {
        inOrdenAux(raiz);
        std::cout << "\n";
    }
};

int main() {
    // Árbol con tipos numéricos enteros
    ArbolBinario<int> arbolEnteros;
    arbolEnteros.insertar(50);
    arbolEnteros.insertar(20);
    arbolEnteros.insertar(70);
    arbolEnteros.insertar(10);
    arbolEnteros.insertar(30);

    std::cout << "ABB Enteros (Recorrido In-Orden ordenado): ";
    arbolEnteros.imprimirInOrden();

    // Árbol con tipos numéricos de punto flotante
    ArbolBinario<float> arbolFlotantes;
    arbolFlotantes.insertar(15.5f);
    arbolFlotantes.insertar(3.2f);
    arbolFlotantes.insertar(28.7f);
    arbolFlotantes.insertar(1.1f);

    std::cout << "ABB Flotantes (Recorrido In-Orden ordenado): ";
    arbolFlotantes.imprimirInOrden();

    // Árbol con caracteres
    ArbolBinario<char> arbolCaracteres;
    arbolCaracteres.insertar('M');
    arbolCaracteres.insertar('B');
    arbolCaracteres.insertar('Z');
    arbolCaracteres.insertar('A');
    arbolCaracteres.insertar('F');

    std::cout << "ABB Caracteres (Recorrido In-Orden ordenado): ";
    arbolCaracteres.imprimirInOrden();

    return 0;
}
