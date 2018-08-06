#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int * LIS_Lengths(vector<int> a) {
    int* lis = new int[a.size()];
    int b[a.size()];
    int maxLength = 1, lowerBound;
    lis[0] = 1, b[0] = a[0];
 
    for (size_t i = 1; i < a.size(); i++) {
        lowerBound = lower_bound(b, b + maxLength, a[i]) - b;
        lis[i] = lowerBound + 1;
        if (lowerBound == maxLength)    b[maxLength++] = a[i];
        else    b[lowerBound] = a[i];
    }
    return lis;
}
 
int main() {
    int N, n;
    while (cin >> N) {
        vector<int> a;
        while (N-- && (cin >> n)) a.push_back(n);
        int* lis = LIS_Lengths(a);
        reverse(a.begin(), a.end());
        int* lds = LIS_Lengths(a);
        reverse(lds, lds + a.size());
 
        int MAX_LIS = -1;
        for (size_t i = 0; i < a.size(); i++)
            MAX_LIS = max(MAX_LIS, min(lis[i], lds[i]));
 
        cout << MAX_LIS * 2 - 1 << endl;
    }
    return 0;
}