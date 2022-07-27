#ifndef BAG_UNIQUE_H
#define BAG_UNIQUE_H

#include <string>
#include <utility>
#include <vector>
#include <memory>

class BagUnique
{
public:
    using Item = std::pair<std::string, int>;

    void insert(std::unique_ptr<Item>&& item)
    {
        _items.push_back(std::move(item));
    }

    const Item* find_by_int(int key) const
    {
        for (const auto& pitem: _items)
            if (key == pitem->second)
                return pitem.get();
        return nullptr;
    }

    int /*nremoved*/ remove_by_int(int key)
    {
        int nremoved = 0;
        for (auto iter=_items.begin(); iter!= _items.end();)
            if ((*iter)->second == key) {
                iter = _items.erase(iter);
                ++nremoved;
            }                
            else
                ++iter;
        return nremoved;
    }

private:
    std::vector<std::unique_ptr<Item>> _items;
};

#endif
