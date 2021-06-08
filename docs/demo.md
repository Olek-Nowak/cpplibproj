@mainpage cpplibproj - demo

# Wstęp - kompilacja

cpplibproj jest dystrybuowana jako biblioteka statyczna, co oznacza że aby z niej skorzystać,
należy załączyć do pliku programu głównego **wszystkie pliki nagłówkowe** z których będziemy korzystać,
a sam program kompilować **wraz z plikiem biblioteki: cpplibproj.a**, poprzez skonfigurowanie automatycznego kompilatora bądź ręczne polecenia kompilacji.

---

# Przykład użycia - dodawanie macierzy

``` C++
#include "macierz.h"
using namespace std;

int main() {
    // Deklaracja dwóch macierzy liczbowych 4 x 4:
    macierz<int> m1 = macierz<int>(4);
    macierz<int> m2 = macierz<int>(4);
    // Wypełnienie pól macierzy:
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            m2(i, j) = i + j;
            m1(j, 1) = i - j;

        }           

    }
    // Deklaracja macierzy przechowującej wynik:
    macierz<int> wynik = macierz<int>(4);
    // Dodawanie macierzy:
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            wynik(i, j) = m1(i, j) + m2(i, j);

}

```