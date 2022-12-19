#include "LongestSubstr.h"
#include <string>
#include <stack>

using std::string;

int LongestSubstr::get_operand(std::stack<int>& stack) {
  if (stack.empty()) {
    throw std::out_of_range("stack is empty!");
  }
  int operand = stack.top();
  stack.pop();
  return operand;
}

void LongestSubstr::plus(vector<vector<vector<int>>>& dp, int word_length, int k, std::stack<int>& stack) {
  int operand2 = get_operand(stack);
  int operand1 = get_operand(stack);
  for (int i = 0; i <= word_length; ++i) {
    for (int j = i; j <= word_length; ++j) {
      dp[k][i][j] = dp[operand1][i][j] || dp[operand2][i][j];
    }
  }
}

void LongestSubstr::concatenation(vector<vector<vector<int>>>& dp, int word_length, int k, std::stack<int>& stack) {
  int operand2 = get_operand(stack);
  int operand1 = get_operand(stack);
  for (int i = 0; i <= word_length; ++i) {
    for (int j = i; j <= word_length; ++j) {
      for (int t = i; t <= j; ++t) {
        dp[k][i][j] |= dp[operand1][i][t] && dp[operand2][t][j];
      }
    }
  }
}

void LongestSubstr::kleene_star(vector<vector<vector<int>>>& dp, int word_length, int k, std::stack<int>& stack) {
  int operand = get_operand(stack);
  for (int i = 0; i <= word_length; ++i) {
    dp[k][i][i] = true;
  }
  for (int i = 0; i <= word_length; ++i) {
    for (int j = i + 1; j <= word_length; ++j) {
      for (int t = i; t <= j; ++t) {
        dp[k][i][j] |= dp[k][i][t] && dp[operand][t][j];
      }
    }
  }
}

void LongestSubstr::empty_word(vector<vector<vector<int>>>& dp, int word_length, int k) {
  for (int i = 0; i <= word_length; ++i) {
    dp[k][i][i] = true;
  }
}

void LongestSubstr::letter(vector<vector<vector<int>>>& dp, int word_length, int k, string regex, string word) {
  if (!('a' <= regex[k] && regex[k] <= 'c')) {
    throw logic_error("symbol '" + regex.substr(k, 1) + "' is not valid");
  }
  for (int i = 0; i < word_length; ++i) {
    if (word[i] == regex[k]) {
      dp[k][i][i + 1] = true;
    }
  }
}

void LongestSubstr::parse_regex(vector<vector<vector<int>>>& dp, int word_length,
                                int regex_length, string regex, string word, std::stack<int>& stack) {
  for (int k = 0; k < regex_length; ++k) {
    switch (regex[k]) {
      case '+':plus(dp, word_length, k, stack);
        break;
        case '.':
          concatenation(dp, word_length, k, stack);
          break;
          case '*':
            kleene_star(dp, word_length, k, stack);
            break;
            case '1':
              empty_word(dp, word_length, k);
              break;
              default:letter(dp, word_length, k, regex, word);
    }
    stack.push(k);
  }
}

int LongestSubstr::get_longest_substr_length(string regex, string word) {
  if (regex.empty()) {
    throw logic_error("regular expression is empty!");
  }
  regex.erase(remove_if(regex.begin(), regex.end(), ::isspace), regex.end());
  int regex_length = regex.size();
  int word_length = word.size();
  vector<vector<vector<int>>> dp(regex_length, vector<vector<int>> (
      word_length + 1, vector<int>(word_length + 1, false)
      ));
  std::stack<int> stack;
  try {
    parse_regex(dp, word_length, regex_length, regex, word, stack);
  } catch (std::out_of_range& e) {
    throw logic_error(
        "string '" + regex + "' is not a valid regular expression: there are LESS operands than required");
  }
  if (stack.size() > 1) {
    throw logic_error(
        "string '" + regex + "' is not a valid regular expression: there are MORE operands than required");
  }

  size_t max_length = 0;
  for (int i = 0; i <= word_length; ++i) {
    for (int j = word_length; j > i; --j) {
      if (dp[regex_length - 1][i][j]) {
        max_length = std::max(max_length, static_cast<size_t>(j - i));
      }
    }
  }
  return max_length;
}
