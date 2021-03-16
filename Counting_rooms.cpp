#include <iostream>
#include <vector>
using namespace std;

int n, m;
char a[1000][1000];

void step(int i, int j) {
    a[i][j] = 'x';
    if(a[i+1][j] == '.' && i + 1 < n) {
        step(i+1, j);
    }
    if(a[i][j+1] == '.' && j + 1 < m) {
        step(i, j+1);
    }
    if(a[i-1][j] == '.' && i - 1 >= 0) {
        step(i-1, j);
    }
    if(a[i][j-1] == '.' && j - 1 >= 0) {
        step(i, j-1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(a[i][j] == '.') {
                ++count;
                step(i, j);
            }
        }
    }
    cout << count;
    return 0;
}
