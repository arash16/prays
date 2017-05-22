#include <bits/stdc++.h>
using namespace std;


int X[16][16], M[16][16], n;
void click(int i, int j) {
    if (i) M[i-1][j] = !M[i-1][j];
    if (j) M[i][j-1] = !M[i][j-1];
    if (i<n-1) M[i+1][j] = !M[i+1][j];
    if (j<n-1) M[i][j+1] = !M[i][j+1];
}


int best;
void backtrack(int i, int j, int step) {
    if (step >= best) return;
    if (i && j && M[i-1][j-1]) return;
    if (j == n) ++i, j=0;

    if (i < n) {
        backtrack(i, j+1, step);
        if (!X[i][j]) {
            click(i, j);
            backtrack(i, j+1, step+1);
            click(i, j);
        }
        return;
    }

    for (int k=0; k<n; ++k)
        if (M[n-1][k])
            return;
    best = step;
}


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int T;
    cin >> T;
    for (int cse=1; T-- && cin >> n; ++cse) {
        memset(M, 0, sizeof(M));
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                cin >> X[i][j];
                if (X[i][j])
                    click(i, j);
            }

        best = 616;
        backtrack(0, 0, 0);
        cout << "Case " << cse << ": " << (best==616 ? -1 : best) << '\n';
    }
}
