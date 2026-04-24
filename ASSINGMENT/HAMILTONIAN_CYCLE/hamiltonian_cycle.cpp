#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int place, const vector<vector<int>> &graph,
            const vector<int> &path) {
    if (graph[path[place - 1]][node] == 0) {
        return false;
    }

    for (int i = 0; i < place; i++) {
        if (path[i] == node) {
            return false;
        }
    }

    return true;
}

bool findCycle(int place, const vector<vector<int>> &graph, vector<int> &path,
               int n) {
    if (place == n) {
        return graph[path[n - 1]][path[0]] == 1;
    }

    for (int node = 1; node < n; node++) {
        if (isSafe(node, place, graph, path)) {
            path[place] = node;

            if (findCycle(place + 1, graph, path, n)) {
                return true;
            }

            path[place] = -1;
        }
    }

    return false;
}

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0) {
        cout << "false\n";
        return 0;
    }

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> path(n, -1);
    path[0] = 0;

    if (findCycle(1, graph, path, n)) {
        cout << "true\n";
        cout << "Hamiltonian Cycle: ";

        for (int i = 0; i < n; i++) {
            cout << path[i] << " ";
        }
        cout << path[0] << '\n';
    } else {
        cout << "false\n";
    }

    return 0;
}
