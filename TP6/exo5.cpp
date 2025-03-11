#include <iostream>
#include <list>
#include <unordered_map>
#include <memory>

using namespace std;

class LRUCache {
private:
    struct Node {
        int key;
        shared_ptr<int> value;
        Node(int k, shared_ptr<int> v) : key(k), value(v) {}
    };

    int capacity;
    list<Node> items;
    unordered_map<int, list<Node>::iterator> cacheMap;

public:
    LRUCache(int cap) : capacity(cap) {}

    void access(int key) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            items.splice(items.begin(), items, it->second);
            cout << key << " ";
        } else {
            if (cacheMap.size() >= capacity) {
                auto last = items.back().key;
                items.pop_back();
                cacheMap.erase(last);
                cout << "-> Eviction de la clé " << last << " ";
            }
            auto value = make_shared<int>(key);
            items.emplace_front(key, value);
            cacheMap[key] = items.begin();
            cout << key << " ";
        }
    }

    void printCache() {
        cout << "\nCache actuel :" << endl;
        for (auto& node : items) {
            cout << node.key << " ";
        }
        cout << endl;
    }
};

int main() {
    LRUCache cache(4);
    cout << "Accès aux clés : 1 2 3 1 4" << endl;
    cache.access(1);
    cache.access(2);
    cache.access(3);
    cache.access(1);
    cache.access(4);
    cache.printCache();

    cout << "Accès à la clé 5 ";
    cache.access(5);
    cache.printCache();

    return 0;
}