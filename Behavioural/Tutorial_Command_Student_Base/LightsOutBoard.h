#pragma once

class LightsOutBoard
{
private:
    int dim;
    bool* lights;
public:
    LightsOutBoard(int d);
    bool AllClear() const;
    bool Valid(int x, int y) const;
    bool Get(int x, int y) const;
    void Set(int x, int y, bool v);
    int GetDim() const;
};