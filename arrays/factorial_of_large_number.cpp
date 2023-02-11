// link - https://www.hackerearth.com/practice/notes/factorial-of-large-number/


class Solution {
  public: vector < int > factorial(int N) {
    vector < int > arr(MAX, -1);
    arr[MAX - 1] = 1;
    int carry = 0;
    for (int i = 1; i <= N; ++i) {
      int carry = 0;
      int j = MAX - 1;
      while (arr[j] != -1) {
        int prod = arr[j] * i + carry;
        arr[j--] = prod % 10;
        carry = prod / 10;
      }
      while (carry) {
        arr[j--] = carry % 10;
        carry /= 10;
      }

    }
    for (int k = 0; k < MAX; ++k) {
      if (arr[k] != -1) {
        arr.erase(arr.begin(), arr.begin() + k);
        return arr;
      }
    }
  }
};
