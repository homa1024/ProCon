// nPi, i in [0,n]の順列を全列挙.
// 例 n = 3 {0,1,2}
// empty, 0, 01, 012, 02, 021, 1, 10, 102, 12, 120, 2, 20, 201, 21, 210
// 全パターン数 N = nP0 + ... + nP(n/2) + ... + nPn = O(n^n)
// 列挙計算時間 DFSで木を１回ずつ訪問 => O(N)
#include <cstdio>
#include <list>
#include <iterator>

using namespace std;

// iteratorを有効に保ったまま一時退避可能なList
// [begin, head, tail, end]: (head, tail)が有効範囲, [tail, end)が退避領域
template<class T>
class MyList : protected list<T> {
	using base = typename list<T>;
public:
	using iterator = typename list<T>::iterator;
	const iterator head; // headとtailの定義順は変えるな！
	const iterator tail; // メンバ変数は定義順に初期化される
	MyList(T headDummy, T tailDummy) :
		head([&] {push_back(headDummy); return prev(end()); }()),
		tail([&] {push_back(tailDummy); return prev(end()); }()) {
	}
	// elemをtoの直前に移動
	void moveElemTo(iterator elem, iterator to) {
		splice(to, *this, elem);
	}
	// 有効領域に新しい値を追加
	void push_tail(T elem) {
		insert(tail, elem);
	}
	iterator begin() { return base::begin(); }
	iterator end() { return base::end(); }
};

const int MAX = 4;
int pattern[MAX];
int elems[MAX];
MyList<int*> remainElems = [] {
	MyList<int*> re((int*)nullptr, (int*)nullptr);
	for (int i = 0; i < MAX; i++) {
		elems[i] = i;
		re.push_tail(&elems[i]);
	}

	return re; // moveか RVOされる
}();

void allPattern_rec(int d) {
	printf("pattern: ");
	for (int i = 0; i < d; i++) {
		printf("%d ", pattern[i]);
	}
	printf("\n");
	if (next(remainElems.head) == remainElems.tail) return;
	list<int*>::iterator cur = remainElems.head;
	while (next(cur) != remainElems.tail) {
		advance(cur, 1);
		list<int*>::iterator prevIte = prev(cur);
		list<int*>::iterator nextIte = next(cur);
		
		remainElems.moveElemTo(cur, end(remainElems));

		pattern[d] = *(*cur);
		
		allPattern_rec(d + 1);

		pattern[d] = -1;
		
		remainElems.moveElemTo(cur, nextIte);
	}
}
void allPattern() {
	allPattern_rec(0);
}
int main() {
	allPattern();
	return 0;
}
