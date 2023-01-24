#pragma once
#include <string>
#include "Plush.hpp"
#include <optional>
#include <set>
#include <iostream>

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
        auto value = 0;
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
            _plushs.insert(Plush{value});
        }
        return value;
    }

    int get_experience() const
    {
        return _experience;
    }

    std::optional<Plush> buy(int amount)
    {
        if (_stock_size == 0)
        {
            return std::nullopt;
        }
        for (auto it = _plushs.begin(); it != _plushs.end();)
        {
            const auto cost = it->get_cost();
            if (cost <= amount)
            {
                const auto res = *it;
                it = _plushs.erase(it);
                _stock_size--;
                _wealth_amount += cost;
                std::cout << res.get_cost() << std::endl;
                return res;
            }
            else
            {
                it++;
            }
        }
        return std::nullopt;
    }

private:
    std::string _name;
    int _wealth_amount = 0;
    int _stock_size = 0;
    int _debt_amount = 0;
    int _experience = 0;
    std::set<Plush> _plushs;
};