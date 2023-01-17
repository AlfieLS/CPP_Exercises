#include <iostream>
#include <set>
#include <map>
#include <sstream>

std::set<std::string> make_exit_commands()
{
    return std::set<std::string> {"q", "quit", "e", "exit"};
}

void print(const std::map<std::string, std::string>& history) {
}

int main()
{
    std::map<std::string, std::string> history;
    auto exitSet = make_exit_commands();
    while (true)
    {
        std::string line;
        std::getline(std::cin, line);

        std::cout << line << std::endl;

        if (exitSet.count(line) == 1)
        {
            return 0;
        }

        std::stringstream stream(line);

        std::string first;
        stream >> first;
        
        if(first == "add") {
            std::string a, b;
            stream >> a >> b;
            history.insert({a, b});
            std::cout << a << " => " << history[a] << std::endl;
            print(history);

            std::string translate;
            std::getline(std::cin, translate);
            std::stringstream streamTranslate(translate);
            std::string firstTranslate;
            streamTranslate >> firstTranslate;
            if(firstTranslate == "translate") {
                std::string tmp;
                while (streamTranslate >> tmp)
                {
                    std::cout << history[tmp] << std::endl;
                }
                
            }
        }
    }

    return 0;
}