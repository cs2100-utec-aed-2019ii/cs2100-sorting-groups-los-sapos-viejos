//
// Created by Gabriel Spranger Rojas on 2019-08-21.
//

#ifndef SORTINGCLASS_SORTING_H
#define SORTINGCLASS_SORTING_H

#include <vector>

namespace Help {
    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
}

template <class T>
class Sorting {
    static_assert(std::is_arithmetic<T>::value, "T debe ser numérico.");
    std::vector<T> lista;

public:

    // Lista

    std::vector<T>& get_lista() {
        return lista;
    }

    void set_lista(std::vector<T>& new_lista) {
        lista = new_lista;
    }

    // Algoritmos de Ordenamiento

    void insertion_sort() {
        int i, j;
        T pivote;
        for (i = 1; i < lista.size(); ++i) {
            pivote = lista[i];
            j = i - 1;

            while (j >= 0 && lista[j] > pivote) {
                lista[j + 1] = lista[j];
                j -= 1;
            }
            lista[j + 1] = pivote;
        }
    }

    void selection_sort() {
        int i, j, indice_del_min_val;

        for (i = 0; i < lista.size()-1; ++i) {
            indice_del_min_val = i;

            for (j = i+1; j < lista.size(); ++j)
                if (lista[j] < lista[indice_del_min_val])
                    indice_del_min_val = j;

            Help::swap(&lista[indice_del_min_val], &lista[i]);
        }
    }

    void bubble_sort() {
        for (int i = 0; i < lista.size; i++) {
            for (int j = 0; j < lista.size-i-1; j++) {
                if (lista[j] > lista[j+1]) {
                    T temp = lista[j];
                    lista[j] = lista[j+1];
                    lista[j+1] = temp;
                }
            }
        }
    }

    void merge_sort() {}

    ///Heapsort
    void heapify(int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < n && lista[left] > lista[largest])
            largest = left;

        if (right < n && lista[right] > lista[largest])
            largest = right;

        if (largest != i) {
            std::swap(lista[i], lista[largest]);
            heapify(n, largest);
        }
    }

    void heap_sort() {
        for (int i = lista.size() / 2 - 1; i >= 0; i--)
            heapify(lista.size(), i);

        for (int i=lista.size()-1; i>=0; i--){
            std::swap(lista[0], lista[i]);
            heapify(i, 0);
        }
    }
    void quick_sort() {}

    // Extras

    void shell_sort() {}

};


#endif //SORTINGCLASS_SORTING_H
