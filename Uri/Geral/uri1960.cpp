#include <bits/stdc++.h>

using namespace std;

map<string, int, less <string> > dict;

char nums[5000][20];

void gen_roman() {
  char *roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
  int i, j, n, arab[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
  string key;

  for (i = 0; i < 5000; i++) {
    nums[i][0] = 0;
    for (n = i, j = 0; n; j++)
      for (; n >= arab[j]; n -= arab[j]) 
        strcat(nums[i],roman[j]);
    key = nums[i];
    dict[key] = i;
  }
}

char *to_roman(int n) {
  if (n < 1 || n >= 5000) return 0;
  return nums[n];
}

int to_arabic(char *in) {
  string key = in;

  if (!dict.count(key)) return -1;
  return dict[key];
}

int main() {
  int n;

  gen_roman();
  cin >> n;
    printf("%s\n",to_roman(n));
  return 0;
}
