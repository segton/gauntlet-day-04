#include "Entity.hpp"
#include <iostream>
#include <map>


int main()
{
    std::map<int, Entity> entity;

    Entity orc{7, "orc", 30};
    Entity bat{2, "bat", 8};
    Entity boss{42, "boss", 300};
    Entity rat{13, "rat", 4};

    entity.insert({orc.id, orc});
    entity.insert({bat.id, bat});   
    entity.insert({boss.id, boss});
    entity.insert({rat.id, rat});

    auto e = entity.find(42);
    std::cout << "id 42: " << (e != entity.end() ? e->second.name : "(not found)") << '\n';

    auto it = entity.find(99);
    std::cout << "id 99: " << (it != entity.end() ? it->second.name : "(not found)") << '\n';


    std::cout << "-- entities by id --\n";  

    for(const auto& it : entity)
    {
        std::cout << it.first << " " << it.second.name << '\n';
    }

    return 0;
}