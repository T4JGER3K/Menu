#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>

using namespace std;

int Menu()
{
    int x;
    cout << endl;
    cout << "1. Dodaj element tablicy" << endl;
    cout << "2. Wstaw element tablicy" << endl;
    cout << "3. Usun element tablicy" << endl;
    cout << "4. Wyświetl elementy tablicy" << endl;
    cout << "5. Zapisz do pliku" << endl;
    cout << "6. Wczytaj z pliku" << endl;
    cout << "7. Wyjscie z programu" << endl;
    cin >> x;
    cout << endl;
    return x;
}

int main()
{
    int m;
    int *p = NULL;
    int n = 0;

    while (true)
    {
        m = Menu();
        switch (m)
        {
        case 7:
        {
            delete[] p;
            return 0;
        }
        case 1:
        {
            int *tmp = new int[n + 1];
            if (p != NULL)
            {
                for (int i = 0; i < n; i++)
                {
                    tmp[i] = p[i];
                }
                delete[] p;
            }
            cout << "Podaj wartosc elementu tablicy: ";
            cin >> tmp[n];
            p = tmp;
            n++;
            break;
        }
        case 2:
        {
            int indeks;
            cout << "Podaj indeks, na ktorym chcesz wstawic element: ";
            cin >> indeks;

            if (indeks < 0 || indeks > n)
            {
                cout << "Nieprawidlowy indeks!" << endl;
                break;
            }

            int wartosc;
            cout << "Podaj wartosc elementu: ";
            cin >> wartosc;

            int *tmp = new int[n + 1];
            for (int i = 0; i < indeks; i++)
            {
                tmp[i] = p[i];
            }
            tmp[indeks] = wartosc;
            for (int i = indeks; i < n; i++)
            {
                tmp[i + 1] = p[i];
            }

            delete[] p;
            p = tmp;
            n++;
            break;
        }
        case 3:
        {
            int indeks;
            cout << "Podaj indeks, ktory chcesz usunac: ";
            cin >> indeks;

            if (indeks < 0 || indeks >= n)
            {
                cout << "Nieprawidlowy indeks!" << endl;
                break;
            }

            int *tmp = new int[n - 1];
            for (int i = 0, j = 0; i < n; i++)
            {
                if (i != indeks)
                {
                    tmp[j] = p[i];
                    j++;
                }
            }

            delete[] p;
            p = tmp;
            n--;
            break;
        }
        case 4:
        {
            cout << "Zawartosc tablicy:" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << p[i] << ", ";
            }
            cout << endl;
            break;
        }
        case 5:
        {
            ofstream plik("dane.txt");
            if (plik.is_open())
            {
                for (int i = 0; i < n; i++)
                {
                    plik << p[i] << " ";
                }
                plik.close();
                cout << "Dane zapisane do pliku 'dane.txt'" << endl;
            }
            else
            {
                cout << "Błąd otwarcia pliku!" << endl;
            }
            break;
        }
        case 6:
        {
            string nazwaPliku;
            cout << "Podaj nazwe pliku do wczytania: ";
            cin >> nazwaPliku;

            ifstream plik(nazwaPliku.c_str());
            if (plik.is_open())
            {
                vector<int> wczytaneDane;
                int liczba;
                while (plik >> liczba)
                {
                    wczytaneDane.push_back(liczba);
                }

                delete[] p;
                n = wczytaneDane.size();
                p = new int[n];

                for (int i = 0; i < n; i++)
                {
                    p[i] = wczytaneDane[i];
                }

                plik.close();
                cout << "Dane wczytane z pliku '" << nazwaPliku << "'" << endl;
            }
            else
            {
                cout << "Błąd otwarcia pliku!" << endl;
            }
            break;
        }
        default:
        {
            cout << "Nieprawidlowa opcja" << endl;
            break;
        }
        }
    }

    return 0;
}
