#pragma once
#include <string>
class PlushStore
{
public:
    PlushStore(const std::string &name)
        : _name{name}
    {
    }

    std::string get_name() const
    {
        return _name;
    }

    int get_wealth_amount() const
    {
        return _wealth_amount;
    }

    int get_stock_size() const
    {
        return _stock_size;
    }

    int get_debt_amount() const
    {
        return _debt_amount;
    }

    void loan(int wealth)
    {
        _wealth_amount += wealth;
        _debt_amount += wealth + wealth * 0.1;
    }

    int make_plush(int wealth)
    {
        int value;
        if (_wealth_amount > 0)
        {
            if (_wealth_amount > wealth)
            {
                _wealth_amount -= wealth;
                value = wealth + _experience;
            }
            else
            {
                value = _wealth_amount + _experience;
                _wealth_amount = 0;
            }

            _stock_size++;
            _experience++;
        }
        return value;
    }

    int get_experience() const
    {
        return _experience;
    }

private:
    std::string _name;
    int _wealth_amount = 0;
    int _stock_size = 0;
    int _debt_amount = 0;
    int _experience = 0;
};