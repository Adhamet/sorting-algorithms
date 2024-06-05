#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vector<int> bubbleSort(vector<int> vec) {
    bool isSorted = false;

    do {
        isSorted = true;
        for(int i = 1; i < vec.size(); i++) {
            if(vec[i] < vec[i-1]) {
                swap(vec[i], vec[i-1]);
                isSorted = false;
            }
        }
    } while (!isSorted);

    return vec;
}

int main() {
    adhamet;

    int n;  cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    
    vector<int> ans = bubbleSort(vec);

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    
    return 0;
}
