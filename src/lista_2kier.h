#ifndef LISTA2K
#define LISTA2K
#include <string>

template <class T>
struct lista2kElem {
    T dane_;
    lista2kElem* nast_;
    lista2kElem* poprz_;
    lista2kElem(T dane);

};

/// Implementacja listy dynamicznej dwukierunkowej.

/// Standardowa dynamiczna struktura danych, alokacja i dealokacja pamięci przebiegają automatycznie.
template <class T>
class lista_2kier
{
private:
    lista2kElem<T> *glowa_;
    lista2kElem<T> *ogon_;
    int dlugosc_;

public:
    ~lista_2kier();
    /// Tworzy pustą listę dwukierunkową.
    lista_2kier();
    /// Tworzy pustą listę dwukierunkową i wypełnia ją danymi z pliku.
    /// @param sciezka Lokalizacja pliku.
    lista_2kier(std::string sciezka);
    /// Znajduje długość listy.
    /// @returns Chwilowa długość listy.
    int dlugosc();
    /// Wypisuje zawartość listy do konsoli.
    void druk();
    /// Zapisuje zawartość listy do pliku.
    /// @param sciezka Lokalizacja pliku.
    void druk(std::string sciezka);
    /// Umieszcza nowy element na końcu listy.
    /// @param dane Wartość dodawanego elementu.
    void dodaj(T dane);
    /// Umieszcza nowy element na określonej pozycji.
    /// @param dane Wartość dodawanego elementu.
    /// @param pozycja Indeks pozycji, poczynając od 0.
    void dodaj(T dane, int pozycja);
    /// Usuwa ostatni element listy.
    /// @param dane Wartość usuniętego elementu, zwracana przez referencję.
    void usun(T& dane);
    /// Usuwa pierwszy napotkany element listy o danej wartości.
    /// @param dane Wartość szukanego elementu do usunięcia.
    void usun_napotkany(T dane);
    /// Usuwa element na określonej pozycji.
    /// @param pozycja Indeks pozycji, poczynając od 0.
   /// @param dane Wartość usuniętego elementu, zwracana przez referencję. 
    void usun(int pozycja, T& dane);
    /// Sortuje listę.
    void sortuj();
    
};

#endif