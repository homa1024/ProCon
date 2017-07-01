//
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <tuple>
//
//using namespace std;
//
//#define FOR(i,a,b) for(int i = (a); i < (b); i++)
//#define REP(i,n) FOR(i,0,n)
//#define FORCLS(i,a,b) for(int i = (a); i <= (b); i++)
//#define REPCLS(i,n) FORCLS(i,1,n)
//
//using Int = int;
//const Int N_MAX = 101;
//const Int W_MAX = 1000000004;
//Int dp[4][N_MAX];
//
//pair<Int, Int> wv[N_MAX];
//
//void solve() {
//    Int nn, ww;
//    cin >> nn >> ww;
//    REPCLS(i, nn){
//        cin >> wv[i].first >> wv[i].second;
//        wv[i].second *= -1;
//    }
//    sort(wv + 1, wv + nn + 1);
//    
//    
//    int i = 1;
//    for(int wi = 0; wi < 4; wi++) {
//        Int curW = wv[i].first;
//        dp[wi][0] = 0;
//        int j = 1;
//        while(curW == wv[i].first){
//            if (j * curW <= ww){
//                dp[wi][j] = dp
//            }
//        }
//        
//    }
//    REPCLS(i, nn) {
//        cout << wv[i].first << "," << wv[i].second << ":" << endl;
//    }
////    REP(i, ww + 1) {
////        dp[0][i] = 0;
////    }
////    for(int i = 1; i <= nn; i++) {
////        for(int j = 0; j <= ww; j++) {
////            Int v0 = dp[i-1][j];
////            Int v1 = (w[i] <= j) ? dp[i-1][j - w[i]] + v[i] : 0;
////            dp[i][j] = max(v0, v1);
////        }
////    }
//    
//    cout << dp[nn][ww] << endl;
//}
//
//#ifdef DEBUG
//#define MAIN hoge
//#else
//#define MAIN main
//#endif
//
//int MAIN() {
//    solve();
//    
//    return 0;
//}
