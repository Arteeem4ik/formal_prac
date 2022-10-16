#ifndef FORMALKI
#define FORMALKI

#include <vector>
#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <string>
#include <iostream>
#include <stack>

using std::vector;
using std::string;
using std::logic_error;

namespace LongestSubstr {

int get_operand(std::stack<int> &);

void plus(vector<vector<vector<int>>>& dp, int word_length, int k, std::stack<int>& stack);

void concatenation(vector<vector<vector<int>>> &, int, int, std::stack<int> &);

void kleene_star(vector<vector<vector<int>>> &, int, int, std::stack<int> &);

void empty_word(vector<vector<vector<int>>> &, int, int);

void letter(vector<vector<vector<int>>>& dp, int word_length, int k, string regex, string word);

void parse_regex(vector<vector<vector<int>>> &, int, int, string, string, std::stack<int> &);

int get_longest_substr_length(string regex, string word);

}

#endif