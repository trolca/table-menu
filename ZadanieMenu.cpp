#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>


using namespace std;

int rand(int end) {

    return rand() % end;
}

void copyArray(int fromArray[], int toArray[], int start, int end) {

    for (int i = start; i <= end; i++) {
        toArray[i] = fromArray[i];
    }



}

void printArray(int array[], int size) {

    string sa = "";

    for (int i = 0; i < size; i++) {
       cout << array[i] << ",";
    }

    cout << endl;
}

int main()
{
    srand(time(NULL));

    int size = 0;

    string trash = "";

    cout << "Podaj wielkosc tablicy (tablica jest int): ";
    cin >> size;
    int* tab = new int[size];

    for (int i = 0; i < size; i++) {
        tab[i] = rand(100);
    }

    bool exit = false;
    int choice = 0;

    while (!exit) {
        system("cls");

        cout << "---------------------------" << endl;
        cout << " [1] Dodaj element" << endl;
        cout << " [2] Wstaw element" << endl;
        cout << " [3] Usun element" << endl;
        cout << " [4] Wyswietl tablice" << endl;
        cout << " [5] Zapisz do pliku" << endl;
        cout << " [6] Odczyt z pliku" << endl;
        cout << " [0] Wyjscie" << endl;
        cout << "---------------------------" << endl;
        cout << "Podaj opcje: ";
        cin >> choice;

        system("cls");

        switch (choice)
        {

        case 0:
            {
             exit = true;
             break;
            }

        case 1:
        {
            int newNum;
            cout << "Napisz liczbe do dodania: ";
            cin >> newNum;

            size++;
            int* newTab = new int[size];
            copyArray(tab, newTab, 0, size - 1);
            newTab[size - 1] = newNum;
            delete[] tab;
            tab = newTab;


        }
            break;

        case 2: {
            int index;
            int newNum;
            do {
                system("cls");
                cout << "Podaj index: ";
                cin >> index;
            } while (index > size - 1);

            cout << "Podaj nowa liczbe: ";
            cin >> newNum;
            size++;
            int* newTab = new int[size];

            copyArray(tab, newTab, 0, index - 1);
            newTab[index] = newNum;
            for (int i = index+1; i < size; i++) {
                newTab[i] = tab[i - 1];

            }
            delete[] tab;

            tab = newTab;


        }
              break;

        case 3: {

            int index;

            do {
                system("cls");
                cout << "Podaj index liczby do usuniecia: ";
                cin >> index;
            } while (index > size - 1);

            size--;
            int* newTab = new int[size];

            copyArray(tab, newTab, 0, index - 1);

            for (int i = index; i < size; i++) {
                newTab[i] = tab[i + 1];
            }

            delete[] tab;

            tab = newTab;


        }
              break;

        case 4: {

            printArray(tab, size);

            cin >> trash;

        }
            break;


        case 5:
            {

            system("cls");
            fstream plik;

            string pathString;

            cout << "Napisz sciezke pliku: ";
            cin>>pathString;

            const char* path = pathString.c_str();


            plik.open(path, ios::out | ios::app);

            if(!plik.is_open()){
                cout << "Plik nie istnieje!" << endl;
                cin>>trash;
                plik.close();
                break;
            }

            for(int i=0; i < size; i++){
                plik << tab[i] << endl;
            }

            plik.close();

            break;

            }

        case 6:
            {
            system("cls");
            fstream plik;

            string pathString;

            cout << "Napisz sciezke pliku: ";
            cin>>pathString;

            const char* path = pathString.c_str();

            plik.open(path, ios::in);

            if(!plik.is_open()){
                cout << "Plik nie istnieje!" << endl;
                cin>>trash;
                plik.close();
                break;
            }
            string outputTab;

            int i = 0;
            while(!plik.eof()){

                getline(plik, outputTab);
                tab[i] = atoi(outputTab.c_str());
                i++;
            }

            cin >> trash;

            plik.close();

            break;

            }

        }


    }
}

