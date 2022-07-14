#ifndef TURBO_OCTO_WAFFLE_THE_GAME_EXCEPTION_H
#define TURBO_OCTO_WAFFLE_THE_GAME_EXCEPTION_H

#include <string>
#include <utility>

class Exception : public std::exception {
public:
    explicit Exception(std::string msg) : msg(std::move(msg)) {}

    std::string getMessage() {
        return msg;
    }

    const char *what() const noexcept override {
        return this->msg.data();
    }

private:
    std::string msg;
};


#endif //TURBO_OCTO_WAFFLE_THE_GAME_EXCEPTION_H
