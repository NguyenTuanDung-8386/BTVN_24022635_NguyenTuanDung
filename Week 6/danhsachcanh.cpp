#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> edges;

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    for (auto &e : edges) {
        cout << e.first << " " << e.second << "\n";
    }
}
