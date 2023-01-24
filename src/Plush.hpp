#pragma once

class Plush
{
public:
    int get_cost() const
    {
        return _cost;
    }

private:
    int _cost = 10;
};