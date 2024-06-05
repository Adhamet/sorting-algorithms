#include <bits/stdc++.h>
using namespace std;

#define adhamet ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define el '\n'
#define dbg(v)                                                                 \
  cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;

void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;

  int lArr[n1], rArr[n2];

  for(int i = 0; i < n1; i++) lArr[i] = arr[l+i];
  for(int i = 0; i < n2; i++) rArr[i] = arr[m+1+i];

  int i = 0, j = 0, k = l;
  while(i < n1 && j < n2) {
    if(lArr[i] <= rArr[j]) {
      arr[k] = lArr[i];
      i++;
    } else {
      arr[k] = rArr[j];
      j++;
    }
    k++;
  }

  while(i<n1) {
    arr[k] = lArr[i];
    i++;
    k++;
  }

  while(j<n2) {
    arr[k] = rArr[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if(l>=r) return;
  
  int mid = l + (r-l)/2;
  mergeSort(arr, l, mid);
  mergeSort(arr, mid+1, r);

  merge(arr, l, mid, r);
}

int main() {
  adhamet;

  int n;  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++) cin >> arr[i];
  
  mergeSort(arr, 0, n-1);

  for(int i = 0; i < n; i++) cout << arr[i] << " ";
  
  return 0;
}
