//https://www.hackerrank.com/challenges/kangaroo/problem

string kangaroo(int x1, int v1, int x2, int v2) {
    if (v1 == v2) {
        return (x1 == x2) ? "YES" : "NO";
    }

    // Check if (x1 - x2) is divisible by (v2 - v1) and the result is non-negative
    if ((x1 - x2) % (v2 - v1) == 0 && (x1 - x2) / (v2 - v1) >= 0) {
        return "YES";
    }

    return "NO";

}