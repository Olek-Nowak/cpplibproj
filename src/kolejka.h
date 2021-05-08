#ifndef KOLEJKA
#define KOLEJKA
#include <string>

/// Implementacja struktury danych typu FI-FO.

/// Standardowa struktura danych FI-FO o stałej maksymalnej długości, bazująca na buforze cyklicznym.
template <class T>
class kolejka
{
private:
    T* tablica_;
    int dlugosc_;
    int odczyt_;
    int zapis_;

public:
    ~kolejka();
    /// Tworzy pustą kolejkę o danej maksymalnej długości.
    /// @param dlugosc Maksymalna długość kolejki, większa od 0.
    kolejka(int dlugosc);
    /// Tworzy pustą kolejkę o danej maksymalnej długości i wypełnia ją danymi z pliku.
    /// @param dlugosc Maksymalna długość kolejki, większa od 0.
    /// @param sciezka Lokalizacja pliku.
    kolejka(int dlugosc, std::string sciezka);
    /// Zapisuje całą zawartość kolejki do pliku.
    /// @param sciezka Lokalizacja pliku.
    void druk(std::string sciezka);
    /// Podgląda wartość pierwszego elementu bez dekolejkowania go.
    /// @param returns Wartość pierwszego elementu kolejki.
    T podglad();
    /// Umieszcza nowy element na końcu kolejki.
    /// @param dane Wartość dodawanego elementu.
    void kolejkuj(T dane);
    /// Usuwa pierwszy element kolejki.
    /// @param returns Wartość zdekolejkowanego elementu.
    T dekolejkuj();

};

#endif