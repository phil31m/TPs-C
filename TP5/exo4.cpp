// Exercice 4
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <tuple>

using namespace std;

string process_word(const string& word) {
    size_t start = 0;
    while (start < word.size() && !isalnum(word[start])) {
        start++;
    }
    size_t end = word.size();
    while (end > start && !isalnum(word[end - 1])) {
        end--;
    }
    return word.substr(start, end - start);
}

void top_frequent_words(const string& text, int n) {
    map<string, pair<int, int>> word_info; // word -> (frequency, first index)
    vector<string> words;

    // Split into words
    string current_word;
    for (char c : text) {
        if (isspace(c)) {
            if (!current_word.empty()) {
                words.push_back(current_word);
                current_word.clear();
            }
        } else {
            current_word += c;
        }
    }
    if (!current_word.empty()) {
        words.push_back(current_word);
    }

    // Process each word and track frequency and first occurrence
    for (size_t i = 0; i < words.size(); ++i) {
        string word = process_word(words[i]);
        if (word.empty()) {
            continue;
        }
        if (word_info.find(word) == word_info.end()) {
            word_info[word] = make_pair(1, i);
        } else {
            word_info[word].first++;
        }
    }

    // Create vector of tuples (word, frequency, first index)
    vector<tuple<string, int, int>> vec;
    for (const auto& entry : word_info) {
        vec.emplace_back(entry.first, entry.second.first, entry.second.second);
    }

    // Sort by frequency descending, then first occurrence ascending
    sort(vec.begin(), vec.end(),
        [](const auto& a, const auto& b) {
            if (get<1>(a) != get<1>(b)) {
                return get<1>(a) > get<1>(b);
            } else {
                return get<2>(a) < get<2>(b);
            }
        });

    // Output top n
    int count = 0;
    for (const auto& entry : vec) {
        if (count >= n) {
            break;
        }
        cout << (count + 1) << ". " << get<0>(entry) << " -> " << get<1>(entry) << endl;
        count++;
    }
}

// Example usage:
int main() {
    string text = "C++ est rapide, C++ est puissant, C++ est utilisé";
    top_frequent_words(text, 3);
    return 0;
}