#include "LongestSubstr.h"

int main() {
  std::string regex, word;
  std::cin >> regex >> word;
  std::cout << LongestSubstr::get_longest_substr_length(regex, word);
}
