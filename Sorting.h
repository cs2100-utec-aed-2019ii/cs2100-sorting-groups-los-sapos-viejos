//
// Created by Gabriel Spranger Rojas on 2019-08-21.
//

#ifndef SORTINGCLASS_SORTING_H
#define SORTINGCLASS_SORTING_H

#include <vector>

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

    void insertion_sort() {}
    void selection_sort() {}
    void bubble_sort() {}
    void merge_sort() {}
    void heap_sort() {}
    void quick_sort() {}

    // Extras

    void shell_sort() {}

};


#endif //SORTINGCLASS_SORTING_H
