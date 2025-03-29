#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/algorithm/string.hpp>
#include "../include/vector.h"

#include <iostream>
#include <string>
#include <thread>

namespace beast = boost::beast;
namespace http = beast::http;
namespace net = boost::asio;
using tcp = boost::asio::ip::tcp;

void handle_request(http::request<http::string_body> req, http::response<http::string_body>& res) {
    if (req.method() == http::verb::get && req.target().starts_with("/split")) {
        std::string target = std::string(req.target());
        std::string text = "hello,world";     // fallback
        std::string delim = ",";

        // parse query params
        auto pos = target.find('?');
        if (pos != std::string::npos) {
            auto query = target.substr(pos + 1);
            std::vector<std::string> parts;
            boost::split(parts, query, boost::is_any_of("&"));
            for (const auto& p : parts) {
                auto eq = p.find('=');
                if (eq != std::string::npos) {
                    std::string key = p.substr(0, eq);
                    std::string val = p.substr(eq + 1);
                    if (key == "text") text = val;
                    if (key == "delim") delim = val;
                }
            }
        }

        Vector v;
        auto result = v.split(text, delim);
        std::string body = "[";
        for (size_t i = 0; i < result.size(); ++i) {
            body += "\"" + result[i] + "\"";
            if (i < result.size() - 1) body += ", ";
        }
        body += "]";

        res = http::response<http::string_body>(
            http::status::ok, req.version());
        res.set(http::field::server, "Boost.Beast");
        res.set(http::field::content_type, "application/json");
        res.keep_alive(req.keep_alive());
        res.body() = body;
        res.prepare_payload();
    } else {
        res = http::response<http::string_body>(http::status::not_found, req.version());
        res.set(http::field::content_type, "text/plain");
        res.body() = "Not found";
        res.prepare_payload();
    }
}

void http_server() {
    try {
        net::io_context ioc{1};
        tcp::acceptor acceptor{ioc, {tcp::v4(), 8080}};
        for (;;) {
            tcp::socket socket = acceptor.accept();
            std::thread{[sock = std::move(socket)]() mutable {
                beast::flat_buffer buffer;
                http::request<http::string_body> req;
                http::read(sock, buffer, req);

                http::response<http::string_body> res;
                handle_request(std::move(req), res);
                http::write(sock, res);
            }}.detach();
        }
    } catch (std::exception& e) {
        std::cerr << "Server error: " << e.what() << std::endl;
    }
}


int main() {
    std::cout << "🚀 Starting HTTP server on http://localhost:8080 ..." << std::endl;
    http_server();  // call the function that runs the server loop
    return 0;
}