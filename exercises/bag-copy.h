#ifndef BAG_COPY_H
#define BAG_COPY_H

#include <string>
#include <utility>
#include <vector>

class BagCopy
{
public:
    using Item = std::pair<std::string, int>;

    void insert(const Item& item)
    {
        _items.push_back(item);
    }
    Item find_by_int(int key) const
    {
        for (const auto& item: _items)
            if (key == item.second)
                return item;
        return Item("", 0);
    }
    int /*nremoved*/ remove_by_int(int key)
    {
        int nremoved = 0;
        for (auto iter=_items.begin(); iter!= _items.end();)
            if (iter->second == key) {
                iter = _items.erase(iter);
                ++nremoved;
            }                
            else
                ++iter;
        return nremoved;
    }

private:
    std::vector<Item> _items;
};

#endif
