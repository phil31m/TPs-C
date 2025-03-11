#include <regex>
#include <string>

using namespace std;

bool contains_email(const string& text) {
    static const regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_search(text, email_regex);
}