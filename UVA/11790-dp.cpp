#include <bits/stdc++.h>
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

	while (ch!=' ' && ch!='\n')
		ch = readchar();
	return r;
}

// -----------------------------------------------------------------------

int DP[10043], H[10043], W[10043], n;
int LIS(bool comp(int, int)) {
	int result = DP[0] = W[0];
	for (int i=1; i<n; ++i) {
		DP[i] = W[i];
		int k = -1;
		for (int j=0; j<i; ++j)
			if ((k<0 || DP[j]>DP[k]) && comp(H[j], H[i]))
				k = j;

		if (k>=0)
			DP[i] += DP[k];

		result = max(result, DP[i]);
	}
	return result;
}

bool isLt(int a, int b) { return a < b; }
bool isGt(int a, int b) { return a > b; }

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int T = readUInt();;
	for (int cse=1; cse<=T; ++cse) {
		n = readUInt();
		for (int i=0; i<n; ++i)
			H[i] = readUInt();
		
		for (int j=0; j<n; ++j)
			W[j] = readUInt();
		
		int incr = LIS(isLt),
			decr = LIS(isGt);
		
		cout << "Case " << cse << ".";
		if (incr >= decr) {
			cout << " Increasing (" << incr << ").";
			cout << " Decreasing (" << decr << ").";
		}
		else {
			cout << " Decreasing (" << decr << ").";
			cout << " Increasing (" << incr << ").";
		}
		cout << "\n";
	}
}
