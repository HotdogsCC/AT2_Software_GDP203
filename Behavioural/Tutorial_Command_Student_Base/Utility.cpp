#include "Utility.h"
#include "LightsOutBoard.h"
#include <random>
#include <vector>

void Toggle(LightsOutBoard* board, int x, int y) //toggle [x,y] position
{
    const struct {
        int ox, oy;
    }
    offsets[] = { {0,-1},
          {-1,0}, {0, 0} ,{1,0},
                  {0, 1}
    };

    for (const auto [ox, oy] : offsets) {
        if (!board->Valid(x + ox, y + oy))
            continue;
        board->Set(x + ox, y + oy, !board->Get(x + ox, y + oy));
    }
}

void LightsOutLevelMaker(LightsOutBoard* board, int steps, int seed)
{
    if (seed == -1)
        seed = std::random_device()();

    std::default_random_engine dre(seed);
    std::uniform_int_distribution<int> uid(0, board->GetDim() - 1);

    std::vector<int> positions;
    for (int i = 0; i < board->GetDim() * board->GetDim(); ++i) {
        positions.push_back(i);
    }

    std::shuffle(std::begin(positions), std::end(positions), dre);

    for (int i = 0; i < steps; ++i) {
        Toggle(board, positions[i] % board->GetDim(), positions[i] / board->GetDim());
    }
};

bool IsGameOver(LightsOutBoard* b) {
    return b->AllClear();
}
