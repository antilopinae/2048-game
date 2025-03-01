#include <emscripten.h>

static constexpr int boardSize = 4;

extern "C" {

EMSCRIPTEN_KEEPALIVE
bool isOutbounds(int x, int y) {
    return x >= boardSize || x<0 || y >= boardSize || y<0;
}

}