#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#define _GLIBCXX_DEBUG
using namespace std;

// ある整数sup（数学用語としての上限の英訳）より小さい整数からsample_size個選んで配列として返す
vector<int> get_random_nums(int sup, int sample_size) {
  vector<int> nums(sup - 1);
  // numsを0から始まる整数列とする
  iota(nums.begin(), nums.end(), 0);
  vector<int> res;
  std::random_device seed_gen;
  std::mt19937 engine{seed_gen()};
  sample(nums.begin(), nums.end(), back_inserter(res), sample_size, engine);

  return res;
}

int main() {
  string str = "";
  int len = 16;
  int digit_count = 4;
  int symbol_count = 0;
  // 以下の記事にあるように、rand()には問題があるのでstd::random_deviceを使う
  // http://vivi.dyndns.org/tech/cpp/random.html
  random_device rnd;

  // （文字でなく）数字を使う箇所を決める
  vector<int> digit_indices = get_random_nums(len, digit_count);
  // for (int x : digit_indices) cout << x << endl;

  for (int i = 0; i < len; i++) {
    if (find(digit_indices.begin(), digit_indices.end(), i) != digit_indices.end()) {
      str += to_string(rnd() % 10);
    }
    else {
      // ランダムなアルファベットをstrに付け加える
      // https://stackoverflow.com/questions/20132650/how-to-select-random-letters-in-c
      if (rnd() % 2 == 0) str += 'a' + rnd() % 26;
      else str += 'A' + rnd() % 26;
    }
  }

  cout << str << endl;
}
