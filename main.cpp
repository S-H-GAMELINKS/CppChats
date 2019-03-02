#include <iostream>
#include <httplib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <array>
#include <vector>

const std::string load_assets(const std::string& path) {

    std::ifstream file(path.c_str(), std::ios::in);

    std::stringstream stream;

    stream << file.rdbuf();

    file.close();

    std::string assets(stream.str());

    return assets;
}

int main() {

    httplib::Server svr;

    std::string body = load_assets("./assets/index.html");

    std::string indexjs = load_assets("./assets/index.js");

    std::array<std::string, 3> routes = {"/", "/about", "/contact", "/chat"};

    std::vector<std::string> chats;

    svr.Get("/api/talks", [&](const httplib::Request& req, httplib::Response& res) {

        std::ostringstream chat;

        for(auto&& c : chats)
            chat << "<p>" << c.c_str() << "</p>";

        res.set_content(chat.str(), "text/plain");
    });

    for(auto&& r : routes)
        svr.Get(r.c_str(), [&](const httplib::Request& req, httplib::Response& res) {
            res.set_content(body, "text/html");
        });

    svr.Get("/index.js", [&](const httplib::Request& req, httplib::Response& res) {
        res.set_content(indexjs, "text/javascript");
    });

    svr.listen("localhost", 3000);

    return 0;
}