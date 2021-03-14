#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10000];
bool used[10000];

void dfs(int v) {
    used[v] = true;
    cout << "DFS at vertex " << v  << endl;

    for (int u: graph[v]) {
        if (!used[u])
            dfs(u);
    }

    cout << "Finish DFS at vertex " << v << endl;
}

int main() {
    int N;
    cin >> N;
    int M;
    cin >> M;
    int x, y;
    for (int i = 0; i < M; ++i) {
        cin >> x >> y;
        graph[x].push_back(y);
    }
    cin >> x;
    dfs(x);
    return 0;
}
