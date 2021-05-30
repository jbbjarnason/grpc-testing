#include <functional>
#include "Server.hpp"

int Server::init() {
    _signals = std::make_unique<asio::signal_set>(
            _loop,
            SIGINT,
            SIGTERM,
            SIGQUIT
    );
    _signals->async_wait(exit());
    return 0;
}

int Server::run() {
    if (_loop.run() <= 0)
        return -1;
    return 0;
}

std::function<void(const asio::error_code &, const int &)> Server::exit() {
    return [this](auto, auto){
        _loop.stop();
    };
}
