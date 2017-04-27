#include <bits/stdc++.h>
#define INF 67108864
using namespace std;

inline int readchar() {
    const int N = 4194304;
    static char buf[N];
    static char *p = buf, *end = buf;
    bool fin = 0;
    if (fin) return EOF;
    if (p == end) {
        if ((end = buf + fread(buf, 1, N, stdin)) == buf) {
        	fin = 1;
        	return EOF;
    	}
        p = buf;
    }
    return *p++;
}
inline bool isdigit(char ch) { return ch>='0' && ch<='9'; }
inline int readUInt() {
	char ch;
	unsigned int r=0;
	while (!isdigit(ch=readchar()))
		if (ch == EOF) return EOF;
	r = ch-'0';
	while (isdigit(ch=readchar()))
		r = (r<<3) + (r<<1) + ch-'0';

	while (ch!=' ' && ch!='\n' && ch!='\t')
		ch = readchar();
	return r;
}

// ----------------------------------------------------------------------

int C[143][143];
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T = readUInt();
	for (int cse=1; cse <= T; ++cse) {
		cout << "Case #" << cse << ": ";
		int n = readUInt(),
			m = readUInt(),
			k = readUInt(),
			bp = INF, ba = 1;

		for (int i=1; i<=n; ++i)
			for (int j=0, x; j<m; ++j) {
				bp = min(bp, x=readUInt());
				C[i][j] = C[i-1][j] + x;
			}

		if (bp > k)
			cout << "0 0\n";

		else {
			for (int i1=0; i1<n; ++i1)
				for (int i2=i1+1; i2<=n; ++i2) {
					int h = i2 - i1,
						sum = 0, 
						lj = 0;

					for (int j=0; j<m; ++j) {
						sum += C[i2][j] - C[i1][j];
						while (sum > k)
							sum -= C[i2][lj] - C[i1][lj],
							++lj;

						int ar = h * (j - lj + 1);
						if (ar > ba || (ar == ba && sum < bp)) {
							bp = sum;
							ba = ar;
						}
					}
				}
			cout << ba << ' ' << bp << '\n';
		}
	}
}
