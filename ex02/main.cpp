#include <iostream>
#include <string>
#include <set>

int main()
{
    std::set<int> entity {7, 2, 7, 42, 13, 2, 42};
    
    for(const auto& e : entity)
    {
        std::cout << e <<'\n';
    }

    std::cout << "count: " << entity.size() << '\n';

    std::cout << "is 42 spawned? " << (entity.find(42) != entity.end() ? "yes" : "no") << '\n';
    std::cout << "is 99 spawned? " << (entity.find(99) != entity.end() ? "yes" : "no") << '\n';


    return 0;
}