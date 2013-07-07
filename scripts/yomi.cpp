
#include <cstring>
#include <iostream>
#include "ruby.h"
using namespace std;

int main(int argc, const char* argv[])
{
    if (argc < 2) {
        cout << "usage: yomi [MODEL]" << endl;
        return 1;
    }

    // Handle options
    bool html = false;
    int i = 1;
    for (; i < argc - 1; i++) {
        if (!strcmp(argv[i], "-html")) {
            html = true;
        } else {
            cout << "invalid option is specified.";
            return 1;
        }
    }

    auto model = argv[i];

    try {
        Ruby ruby(model);
        
        if (html) {
            // TODO: use std::regex
            regex_t re;
            regmatch_t m[2];
            regcomp(&re, "<p[^>]*>([^<]*)</p>", REG_EXTENDED);
            string line;
            while (getline(cin, line)) {
                if (!regexec(&re, line.c_str(), 2, m, 0)) {
                    int text_len = m[1].rm_eo - m[1].rm_so;
                    auto text = ruby.Process(line.substr(m[1].rm_so, text_len), Ruby::HTML);
                    line = line.replace(m[1].rm_so, text_len, text);
                }
                cout << line << endl;
            }
        } else {
            string line;
            while (getline(cin, line)) {
                cout << ruby.Process(line, Ruby::Corpus) << endl;
            }
        }
    } catch (...) {
        cout << "fatal error!!!";
        return 1;
    }

    return 0;
}

// vim: et ts=4 sw=4 cin cino={1s ff=unix
