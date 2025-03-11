// Exercice 3
#include <string>

using namespace std;

string encode_rle(const string& text) {
    if (text.empty()) {
        return "";
    }
    char current_char = text[0];
    int count = 1;
    string result;
    
    for (size_t i = 1; i < text.size(); ++i) {
        if (text[i] == current_char) {
            ++count;
        } else {
            result += current_char;
            result += to_string(count);
            current_char = text[i];
            count = 1;
        } }
    result += current_char;
    result += to_string(count);
    return result;
}