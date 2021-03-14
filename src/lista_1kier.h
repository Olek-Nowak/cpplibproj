#ifndef LISTA1K
#define LISTA1K

template <class T>
struct lista1kElem {
    T dane_;
    lista1kElem* nast;
    lista1kElem(T dane);

};

/// Implementacja listy dynamicznej jednokierunkowej.

/// Standardowa dynamiczna struktura danych, alokacja i dealokacja pamięci przebiegają automatycznie.
template <class T>
class lista_1kier {
private:
    lista1kElem* głowa_;
    lista1kElem* ogon_;
    ~lista_1kier();

public:
    /// Tworzy pustą listę jednokierunkową.
    lista_1kier();
    /// Tworzy pustą listę jednokierunkową i wypełnia ją danymi z pliku.
    /// @param ścieżka Lokalizacja pliku.
    lista_1kier(string ścieżka);
    /// Wypisuje zawartość listy do konsoli.
    int druk();
    /// Zapisuje zawartość listy do pliku.
    /// @param ścieżka Lokalizacja pliku.
    int druk(string ścieżka);
    /// Dodaje nowy element do końca listy.
    /// @param dane Wartość dodawanego elementu.
    int dodaj(T dane);
    /// Dodaje nowy element do określonej pozycji
    /// @param dane Wartość dodawanego elementu.
    /// @param pozycja Indeks pozycji, poczynając od 0.
    int dodaj(T dane, int pozycja);
    /// Usuwa ostatni element listy.
    int usuń();
    /// Usuwa pierwszy napotkany element listy o danej wartości.
    /// @param dane Wartość szukanego elementu do usunięcia.
    /// @returns Zwraca indeks pozycji usuniętego elementu.
    int usuń(T dane);
    /// Usuwa element na określonej pozycji.
    /// @param pozycja Indeks pozycji, poczynając od 0.
    /// @returns Zwraca wartość usuniętego elementu.
    T usuń(int pozycja);

};

#endif