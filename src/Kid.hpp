#pragma once
#include <string>
#include <ostream>
#include "PlushStore.hpp"

class Kid
{
public:
    Kid(const std::string &name, int money)
        : _name{name}, _money{money}
    {
    }

    std::string get_name() const
    {
        return _name;
    }

    int get_money() const
    {
        return _money;
    }

    friend std::ostream &operator<<(std::ostream &stream, const Kid &kid)
    {
        return stream << kid.get_name() << " has " << kid.get_money() << " euros.";
    }

    void buy_plush(PlushStore &plushStore)
    {
        auto plush = plushStore.buy(_money);
        _money -= plush->get_cost();
    }

private:
    std::string _name;
    int _money;
};
