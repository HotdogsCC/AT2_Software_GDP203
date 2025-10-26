#include "LightsOutBoard.h"
#include <stdexcept>

    LightsOutBoard::LightsOutBoard(int d) : dim{ d } {
        lights = new bool[dim * dim];
        for (int i = 0; i < dim * dim; ++i) {
            lights[i] = false;
        }
    }

    bool LightsOutBoard::AllClear() const {
        for (int i = 0; i < dim * dim; ++i) {
            if (lights[i] == true)
                return false;
        }
        return true;
    }

    bool LightsOutBoard::Valid(int x, int y) const {
        return x >= 0 && x < dim && y >= 0 && y < dim;
    }

    bool LightsOutBoard::Get(int x, int y) const {
        if (!Valid(x, y)) throw std::runtime_error("Bad cell index");
        return lights[x + y * dim];
    }

    void LightsOutBoard::Set(int x, int y, bool v) {
        if (!Valid(x, y)) throw std::runtime_error("Bad cell index");
        lights[x + y * dim] = v;
    }

    int LightsOutBoard::GetDim() const { return dim; }
