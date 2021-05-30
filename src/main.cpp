#include <cstdio>
#include "Server.hpp"

int main() {
    auto app = Server();
    if (app.init() != 0) {
        printf("Unable to initialize application, aborting!\n");
        return 0;
    }

    if (app.run() != 0) {
        printf("Unable to run application, aborting!\n");
        return 0;
    }

    printf("App exited normally\n");
    return 0;
}
