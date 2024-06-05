#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vector<int> insertionSort(vector<int> vec) {
    for(int i = 1; i < vec.size(); i++) {
        for(int j = i; j > 0; j--) {
            if(vec[j] < vec[j-1]) {
                swap(vec[j], vec[j-1]);
            } else {
                break;
            }
        }
    }

    return vec;
}

int main() {
    adhamet;

    int n;  cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    
    vector<int> ans = insertionSort(vec);

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    
    return 0;
}
