
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
#define REPCLS(i,n) FORCLS(i,1,n)

using Int = long;

Int h, w;

Int sol1(Int h, Int w) {
    Int h1,h2,h3;
    h1 = h / 2;
    h2 = h - h1;
    h3 = h;
    Int w12, w3;
    Int s1,s2,s3;
    Int r = h * w;
    for (Int m = 1; m < w; m++){
        w12 = m;
        w3 = w - m;
        s1 = h1 * w12;
        s2 = h2 * w12;
        s3 = h3 * w3;
        Int r2 = max({s1,s2,s3}) - min({s1,s2,s3});
        if (r2 < r) r = r2;
    }
    return r;
}
Int sol2(Int h, Int w) {
    if (h == 2) return h*w;
    
    Int h1,h2,h3;
    h1 = h / 3;
    h2 = (h - h1) / 2;
    h3 = (h - h1 - h2);
    return (max({h1,h2,h3}) - min({h1,h2,h3})) * w;
}
void solve() {
    cin >> h >> w ;
    Int rs[] = {sol1(h,w), sol1(w,h), sol2(h,w), sol2(w,h)};
    cout << *min_element(rs, rs + 4) << endl;
}

#ifdef DEBUG
#define MAIN hoge
#else
#define MAIN main
#endif

int MAIN() {
    solve();
    
    return 0;
}
