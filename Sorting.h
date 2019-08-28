
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
    Sorting() {}

    std::vector<T>& get_lista() {
        return lista;
    }

    void set_lista(std::vector<T>& new_lista) {
        lista = new_lista;
    }

    void print_lista(){
        for(auto x : lista)
            std::cout<<x<<std::endl;
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



    void merge(std::vector <T>& v, int liminf, int mid, int limsup) {
        int aux1 = mid - liminf + 1;

        int aux2 =  limsup - mid;

        std::vector <T> temp1(aux1);

        std::vector <T> temp2(aux2);

        for (int i = 0; i < aux1; i++) {
            temp1[i] = v[liminf + i];
        }

        for (int i = 0; i < aux2; i++) {
            temp2[i] = v[mid + i + 1];
        }

        int cont1 = 0;

        int cont2 = 0;

        int cont3 = liminf;

        while (cont1 < aux1 && cont2 < aux2) {
            if (temp1[cont1] < temp2[cont2]) {
                v[cont2] = temp1[cont1];
                cont1++;
            }
            else {
                v[cont3] = temp2[cont2];
                cont2++;
            }
            cont3++;
        }

        while (cont1 < aux1) {
            v[cont3] = temp1[cont1];
            cont1++;
            cont3++;
        }
        while (cont2 < aux2) {
            v[cont3] = temp2[cont2];
            cont2++;
            cont3++;
        }

    }

    void merge_sort(std::vector <T> &v, int liminf, int limsup) {
        if (liminf < limsup) {
            int mid = (liminf + (limsup - 1)) / 2;
            merge_sort(lista, liminf, mid);
            merge_sort(lista, mid + 1, limsup);
            merge(lista, liminf, mid,limsup);
        }
    }


    ///Heapsort
    void heapify(T n, T i) {
        T largest = i;
        T left = 2*i + 1;
        T right = 2*i + 2;

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


    /// Quick Sort

    void swap(int* a, int* b){
        int t = *a;
        *a = *b;
        *b = t;
    }

    int get_size(){
        return lista.size();
    }

    int partition (int low, int high){
        int pivot = lista[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++){
            if (lista[j] <= pivot){
                i++;
                swap(&lista[i], &lista[j]);
            }
        }
        swap(&lista[i + 1], &lista[high]);
        return (i + 1);
    }
    // low = 0 y high = lista.get_size()
    void quick_sort(int low, int high){
        if (low < high) {
            int part = partition(low, high);
            quick_sort(low, part - 1);
            quick_sort(part + 1, high);
        }
    }

    // Extras

    void shell_sort() {
            int n=lista.size();
            for (int gap = n/2; gap > 0; gap /= 2)
            {
                for (int i = gap; i < n; i += 1)
                {
                    int temp = lista[i];

                    int j;
                    for (j = i; j >= gap && lista[j - gap] > temp; j -= gap)
                        lista[j] = lista[j - gap];
                    lista[j] = temp;
                }
            }

        }

};


#endif //SORTINGCLASS_SORTING_H
