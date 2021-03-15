#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define n 100

int graph[n][n];

using namespace std;

void Floyd_Warshall(const int& x) {
    for (int k=0; k<x; ++k)
        for (int i=0; i<x; ++i)
            for (int j=0; j<x; ++j)
                if (graph[i][k] != -1 && graph[k][j] != -1 ) {
                    if (graph[i][j] == -1) {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                    else
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
}

int main() {
    int x;
    cin >> x;
    int y;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < x; ++j) {
            cin >> y;
            graph[i][j] = y;
        }
    }

    Floyd_Warshall(x);

    int diam = -1;
    int rad = 9999;
    for (int i = 0; i < x; ++i) {
        int max = -9999;
        for (int j = 0; j < x; ++j) {
            if(graph[i][j] > max)
                max = graph[i][j];
        }
        if(max > diam) {
            diam = max;
        }
        else if(max < rad) {
            rad = max;
        }
    }
    cout << diam << endl;
    cout << rad;
    return 0;
}
