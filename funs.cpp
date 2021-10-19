#include <funs.h>

bool isSamePos (Cursor C1, Cursor C2) {
    if (C1.x == C2.x &&
            C1.y == C2.y) {
        return true;
    }
    return false;
}
