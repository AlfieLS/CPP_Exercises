#pragma once

class Plush
{
public:
    int get_cost() const
    {
        return _cost;
    }

    void set_cost(int cost)
    {
        _cost = cost;
    }

private:
    int _cost = 10;
};