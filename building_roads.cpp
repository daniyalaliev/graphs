#include <iostream>
#include <vector>
using namespace std;

vector <int> G[100000], ans;
int n, m, num=0;
int used[100000];

void dfs (int u) {
    used[u]=1;
    for (int i=0; i<G[u].size(); i++) {
        if (used[G[u][i]]==0) {
            dfs(G[u][i]);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            ans.push_back(i);
            dfs (i);
        }
    }
    cout << ans.size() - 1 << endl;
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[0] + 1 << " " << ans[i] + 1 << endl;
    }
    return 0;
}