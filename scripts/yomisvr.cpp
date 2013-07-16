
#include <httplib.h>
#include <iostream>
#include "ruby.h"

using namespace std;
using namespace httplib;

int main(int argc, const char* argv[])
{
    if (argc < 3) {
        cout << "usage: yomisvr [MODEL] [PORT]" << endl;
        return 1;
    }

    const char* model = argv[1];
    int port = std::atoi(argv[2]);

    try {
        Ruby ruby(model);

        Server svr;
        svr.post("/yomi", [&](const Request& req, Response& res) {
            if (req.has_param("s")) {
                cout << req.params.at("s") << endl;
                const auto& s = ruby.Process(req.params.at("s"), Ruby::Corpus);
                cout << s << endl;
                res.set_content(s, "text/plain");
            }
        });
        svr.listen("localhost", port);

    } catch (...) {
        cout << "fatal error!!!";
        return 1;
    }

    return 0;
}

// vim: et ts=4 sw=4 cin cino={1s ff=unix
