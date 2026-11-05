#include <iostream>
#include <cstring>
using namespace std;
#define INF 9999999
// кількість вершин графа (варіант 22)
#define V 8
// матриця суміжності (ваг); вершини 1..8 -> індекси 0..7
int G[V][V] = {
//   1    2    3    4    5    6    7    8
  {  0,   4,   1,   6,   0,   0,   0,   0}, // 1
  {  4,   0,   0,   8,   0,   3,   0,   0}, // 2
  {  1,   0,   0,   0,   0,   0,   0,   2}, // 3
  {  6,   8,   0,   0,   3,   0,   0,   0}, // 4
  {  0,   0,   0,   3,   0,   9,   5,   0}, // 5
  {  0,   3,   0,   0,   9,   0,   7,   1}, // 6
  {  0,   0,   0,   0,   5,   7,   0,   7}, // 7
  {  0,   0,   2,   0,   0,   1,   7,   0}  // 8
};
int main() {
    int no_edge = 0;          // кількість ребер у МКД
    bool selected[V];         // вершини, що вже включені до МКД (V_T)
    memset(selected, false, sizeof(selected));
    selected[0] = true;       // починаємо з вершини 1
    int x, y, total = 0;
    cout << "Edge : Weight" << endl;
    while (no_edge < V - 1) {
        int min = INF;
        x = 0; y = 0;
        // пошук ребра мінімальної ваги (v in V_T, u in V - V_T)
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i; y = j;
                        }
                    }
                }
            }
        }
        cout << x + 1 << " - " << y + 1 << " :  " << G[x][y] << endl;
        total += G[x][y];
        selected[y] = true;   // V_T <- V_T U {u*}
        no_edge++;
    }
    cout << "Total weight: " << total << endl;
    return 0;
}
