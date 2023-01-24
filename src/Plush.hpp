#pragma once

class Plush
{
public:
    Plush(int cost)
        : _cost{cost}
    {
    }

    Plush()
    {
    }

    int get_cost() const
    {
        return _cost;
    }

    void set_cost(int cost)
    {
        _cost = cost;
    }

    bool operator<(const Plush &other) const
    {
        return _cost < other.get_cost();
    }

private:
    int _cost = 10;
};