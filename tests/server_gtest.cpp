#include <gtest/gtest.h>


#include "Server.hpp"

class ServerTest: public ::testing::Test {
public:
    void SetUp() override {
        _server = std::make_unique<Server>();
    }
    void TearDown() override {};

    std::unique_ptr<Server> _server;
};

TEST_F(ServerTest, creatable) {
    ASSERT_TRUE(_server);
}