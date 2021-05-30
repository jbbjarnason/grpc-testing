#pragma once

#include <functional>
#include <asio/io_context.hpp>
#include <asio/signal_set.hpp>

class Server {
public:
    Server() = default;
    virtual ~Server() = default;
    int init();
    int run();
private:
    std::function<void(const asio::error_code &, const int &)> exit();
    asio::io_context _loop;
    std::unique_ptr<asio::signal_set> _signals;


};
