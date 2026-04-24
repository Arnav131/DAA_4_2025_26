#include <bits/stdc++.h>
using namespace std;

void printBoard(const vector<int> &q1, int n, int solutionNo) {
    cout << "Solution " << solutionNo << ":\n";

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (q1[row] == col) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << '\n';
    }

    cout << '\n';
}

void solveQueens(int row, int n, vector<int> &q1, vector<int> &colHash,
                 vector<int> &leftDiagHash, vector<int> &rightDiagHash,
                 int &total) {
    if (row == n) {
        total++;
        printBoard(q1, n, total);
        return;
    }

    for (int q2 = 0; q2 < n; q2++) {
        int leftDiag = row + q2;
        int rightDiag = row - q2 + n - 1;

        if (colHash[q2] == 0 && leftDiagHash[leftDiag] == 0 &&
            rightDiagHash[rightDiag] == 0) {
            q1[row] = q2;
            colHash[q2] = 1;
            leftDiagHash[leftDiag] = 1;
            rightDiagHash[rightDiag] = 1;

            solveQueens(row + 1, n, q1, colHash, leftDiagHash, rightDiagHash,
                        total);

            q1[row] = -1;
            colHash[q2] = 0;
            leftDiagHash[leftDiag] = 0;
            rightDiagHash[rightDiag] = 0;
        }
    }
}

int main() {
    int n;

    cout << "Enter number of queens (N): ";
    cin >> n;

    if (n <= 0) {
        cout << "N should be greater than 0.\n";
        return 0;
    }

    vector<int> q1(n, -1);
    vector<int> colHash(n, 0);
    vector<int> leftDiagHash(2 * n - 1, 0);
    vector<int> rightDiagHash(2 * n - 1, 0);
    int total = 0;

    solveQueens(0, n, q1, colHash, leftDiagHash, rightDiagHash, total);

    cout << "Total valid configurations: " << total << '\n';

    return 0;
}
