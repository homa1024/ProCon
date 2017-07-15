
template<typename T>
T extGcdRec(T r1, T r2, T x1, T x2, T y1, T y2, T &x, T &y) {
    if (r2 == 0) {
        x = x1; y = y1;
        return r1;
    }
    T r3 = r1 / r2;
    return extGcdRec(r2, r1 % r2, x2, x1 - r3 * x2, y2, y1 - r3 * y2, x, y);
}
template<typename T>
T extGcd(T a, T b, T &x, T &y) {
    if (a < b) return extGcd(b, a, y, x);
    return extGcdRec<T>(a, b, 1, 0, 0, 1, x, y);
}
template<typename T>
T invMod(T a, T m){ // Zm上乗法逆数
    T x, y;
    if (extGcd<T>(a, m, x, y) == 1) return (x + m) % m;
    return 0;
}
