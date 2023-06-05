// Zadanie: Ranking
// Autor: Adrian Fabisiewicz
// Nr indeksu: 328935

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector < int > scores(n);

    // wczytanie wynikow do wektora scores
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    //utworzenie kopii wektora scores oraz posortowanie go malejaco
    vector < int > scores_sorted = scores;
    sort(scores_sorted.rbegin(), scores_sorted.rend());

    for (int i = 0; i < n; i++) {
        // znalezienie miejsca pierwszego wystapienia danego wyniku w wektorze z posortowanymi malejaco wynikami
        auto rank = find(scores_sorted.begin(), scores_sorted.end(), scores[i]);

        // wypisanie odleglosci miedzy poczatkiem posortowanego malejaco wektora a pierwszym wystapieniem w nim danego wyniku +1, czyli rankingu wyniku
        cout << distance(scores_sorted.begin(), rank) + 1 << ' ';
    }
}