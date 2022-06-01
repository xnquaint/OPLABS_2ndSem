
#include "header.h"

vector<string> split(string line, char sep) {
    vector<string> words;
    string temp_word;
    line += sep;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == sep) {
            if (temp_word.length() > 0) {
                words.push_back(temp_word);
            }
            temp_word = "";
        }
        else {
            temp_word += line[i];
        }
    }
    return words;
}



