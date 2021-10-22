#include <funs.h>

bool isSamePos (Position C1, Position C2) {
    if (C1.x == C2.x &&
            C1.y == C2.y) {
        return true;
    }
    return false;
}
