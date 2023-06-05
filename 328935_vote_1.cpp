// Zadanie: Glosowanie
// Autor: Adrian Fabisiewicz
// Nr indeksu: 328935

#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int* candidates = new int[N + 1]{0};
    int vote, leader = 0;

    for (int i = 1; i <= M; i++) //petla przechodzaca przez kazdy oddany glos
    {
        cin >> vote;
        candidates[vote]++; //dodanie glosu do tablicy pod indeksem kandydata o danym numerze

        if (candidates[vote] > leader && vote != 0) //jezeli glos nie jest niewazny i liczba glosów na aktualnego kandydata jest najwieksza, kandydat staje sie nowym liderem
        {
            leader = candidates[vote];
        }
    }

    for (int i = 1; i <= N; i++) //petla przechodzaca przez tablice z kandydatami
    {
        if (candidates[i] == leader) //jesli dany kandydat ma najwieksza liczbe glosow, jest wpisywany jego numer
        {
            cout << i << " ";
        }
    }

    delete[] candidates;
}
