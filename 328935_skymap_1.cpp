// Zadanie: Mapa nieba
// Autor: Adrian Fabisiewicz
// Nr indeksu: 328935

//algorytm z materialow na moodle

/*************************************************************************
 *
 *  Weighted quick union implementation of union-find algotithm
 *  with path compression by halving
 *
 *  A reference implementation
 *
 *
 *  Author: Jacek Marciniak
 *  Date: 2015-11-07
 *
 *************************************************************************/

#include <iostream>

#include <vector>

#include <string.h>

using namespace std;

// data
int cc; // number of components
int N; // number of elements
vector < int > id; // id[i] = parent of i
vector < int > sz; // sz[i] = number of elements in subtree rooted at i

// initializes data structures
void init(int size) {
    cc = size;
    N = size;

    id.resize(size);
    sz.resize(size);

    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

// gets component's identifier of the element
int find(int p) {
    while (p != id[p]) {
        id[p] = id[id[p]]; // path compression by halving
        p = id[p];
    }

    return p;
}

// check if 2 elements belongs to the same component
bool connected(int p, int q) {
    return find(p) == find(q);
}

// connect components
void make_union(int p, int q) {
    int pid = find(p);
    int qid = find(q);

    if (pid == qid) return;

    // make smaller root point to larger one
    if (sz[qid] < sz[pid]) {
        id[qid] = pid;
        sz[pid] += sz[qid];
    }
    else {
        id[pid] = qid;
        sz[qid] += sz[pid];
    }

    cc--;
}

int main() {
    int n;
    cin >> n;

    init(n * n);

    //stworzenie wektora o rozmiarze n*n, ktory bedzie przechowywac gwiazdy i nie-gwiazdy
    vector < int > sky(n * n);

    //wczytanie elementow do wektora
    for (int i = 0; i < n * n; i++) {
        cin >> sky[i];
    };

    for (int i = 0; i < n * n; i++) {
        //sprawdzenie czy aktualny element to gwiazda, bo laczymy jedynie takie elementy
        if (sky[i] == 1) {
            // sprawdzenie, czy aktualny element jest w drugim badz kolejnym rzedzie, aby mozna bylo go polaczyc z elementem wyzej z poprzedniego rzedu
            if (i >= n) {
                // jezeli element w rzedzie wyzej jest gwiazda, elementy sa laczone
                if (sky[i - n] == 1) {
                    make_union(i, i - n);
                }
            }

            // jezeli element jest pierwszy w rzedzie, nie laczymy go z poprzednim elementem, bo wtedy te dwa elementy nie sasiaduja
            if (i % n != 0) {
                // jezeli element z lewej strony jest gwiazda, elementy sa laczone
                if (sky[i - 1] == 1) {
                    make_union(i, i - 1);
                }
            }
        }
    }

    //zmienne przechowujace liczbe gwiazd z najwiekszej konstelacji oraz liczbe konstelacji
    int stars = 0;
    int constellations = 0;

    // 
    for (int i = 0; i < n * n; i++) {
        if (sky[i] == 1) {
            //jezeli aktualny element ma taki sam identyfikator, jak on sam, to wtedy jest to gwiazda, ktora nie jest polaczona z zadna inna gwiazda
            //albo jest to jedna z gwiazd konstelacji, ktorej identyfikator przyjely po polaczeniu pozostale gwiazdy z tej konstelacji
            //w obu przypadkach zwiekszamy liczbe konstelacji o 1
            if (i == id[i]) {
                constellations++;
            }

            //jezeli rozmiar konstelacji aktualnego elementu jest wiekszy od aktualnej najwiekszej liczby gwiazd w konstelacji, to aktualizujemy ta liczbe
            if (sz[i] > stars) {
                stars = sz[i];
            }

        }
    }

    cout << constellations << " " << stars;
}