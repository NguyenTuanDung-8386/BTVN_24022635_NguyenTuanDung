#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visited[MAXN];

int main() {
    int n, m;
    cin >> n >> m;
    // danh sach ke
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // dfs
    int start = 1;
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}
