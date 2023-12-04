#include<iostream>
#include<vector>
#include<string.h>
#include<cstring>
#include<unordered_map>
#include<algorithm>
#include<limits.h>
#define ll long long int
#define d double
#define pb push_back
#define v vector
#define vi vector<int>
#define bp __builtin_popcount
#define bpll __builtin_popcountll
// (char)('A' | (1 << 5))
// (char)('a' |~(1 << 5))
using namespace std;
bool isSafe(int** arr, int** sol, int x, int y, int r, int c) {
    if ((x >= 0 && x < r) && (y >= 0 && y < c) && sol[x][y] != 1 && arr[x][y] == 1) {
        return true;
    }
    return false;
}
void Solve(int** arr, int** sol, int x, int y, int r, int c) {

    if (x == r - 1 && y == c - 1) {
        sol[x][y] = 1;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << sol[i][j] << "   ";
            }
            cout << endl;
        }

        return;
    }

    sol[x][y] = 1;

    if (isSafe(arr, sol, x + 1, y, r, c)) {
        Solve(arr, sol, x + 1, y, r, c);
    }

    if (isSafe(arr, sol, x, y+1, r, c)) {
        Solve(arr, sol, x , y+1, r, c);
    }

    sol[x][y] = 0;

}
int main() {
    int n;
    cin >> n;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int** sol = new int* [n];
    for (int i = 0; i < n; i++) {
        sol[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sol[i][j] = 0;
        }
    }

    Solve(arr, sol, 0, 0, n, n);

    return 0;
}