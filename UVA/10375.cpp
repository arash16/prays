#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int p, q, r, s;
	while (scanf("%d%d%d%d", &p, &q, &r, &s)==4) {
		q = min(q, p-q);
		s = min(s, r-s);
		int mx = max(q, s);
		long double result = 1;
		for (int i=1; i<=mx; ++i) {
			if (i <= q)
				result *= (p-i+1.0)/i;

			if (i <= s)
				result *= i/(r-i+1.0);
		}
		printf("%.5Lf\n", result);
	}
}
