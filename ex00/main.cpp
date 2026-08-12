#include "Entity.hpp"
#include <iostream>
#include <vector>


int main()
{
    std::vector<Entity> entity;
    entity.reserve(4);

    entity.emplace_back(Entity{7, "orc", 30});
    entity.emplace_back(Entity{2, "bat", 8});
    entity.emplace_back(Entity{42, "boss", 300});
    entity.emplace_back(Entity{13, "rat", 4});

    std::cout << "-- roster --\n";

    for(auto it = entity.begin(); it != entity.end();)
    {
        std::cout << it->id << " " << it->name << " (hp " << it->hp << ")\n";

        if(it->hp <= 5)
        {
            it = entity.erase(it);
        }
        else
        {
            ++it;
        }
    }

    std::cout << "-- survivors --\n";  

    for(const auto& it : entity)
    {
        std::cout << it.id << " " << it.name << " (hp " << it.hp << ")\n";
    }

    return 0;
}