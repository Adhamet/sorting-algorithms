#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
    cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

vector<int> selectionSort(vector<int> vec) {
    vector<int> sorted;

    while(vec.size()) {
        int idx_min = 0;
        for(int i = 1; i < vec.size(); i++) if(vec[i] < vec[idx_min]) 
            idx_min = i;

        sorted.push_back(vec[idx_min]);
        vec.erase(vec.begin() + idx_min);
    }

    return sorted;
}

int main() {
    adhamet;

    int n;  cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin >> vec[i];
    
    vector<int> ans = selectionSort(vec);

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    
    return 0;
}
