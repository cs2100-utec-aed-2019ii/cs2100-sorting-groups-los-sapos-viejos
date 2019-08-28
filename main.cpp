#include <iostream>
#incldue <vector>
#include "Sorting.h"

using namespace std;
int main() {

    vector<int> a={1,2,3,0,9,7,2,9,4};
    Sorting<int> h;
    h.set_lista(a);
    h.shell_sort(); //tipo de sort aqui
    h.print_lista();

    return 0;
}
