// Binary Indexed Tree

// éQçl
// ï€ç‚ òaçG, Binary Indexed Tree ÇÃÇÕÇ»Çµ, http://hos.ac/slides/20140319_bit.pdf
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <array>
#include <cmath>
#include <limits>

using namespace std;

const int MAX_NODES = 100000;
int nodes[MAX_NODES + 1];
inline int LSB(int i) {
	return i & (-i);
}
void add(int i, int value) {
	for(; i <= MAX_NODES; i += LSB(i))
		nodes[i] += value;
}
// sum [1, i]
int sum(int i) {
	int sumV = 0;
	for (; i > 0; i -= LSB(i))
		sumV += nodes[i];
	return sumV;
}
int main() {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int comp, x, y;
		cin >> comp >> x >> y;
		switch (comp) {
		case 0:
			add(x, y);
			break;
		case 1:
			printf("%d\n", sum(y) - sum(x - 1));
			break;
		}
	}

	return 0;
}