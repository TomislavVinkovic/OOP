#pragma once

#include <vector>
#include <utility> //include za pair

using namespace std;

template<typename K, typename V>
class Map {
    private:
        vector<pair<K, V>> container;
    public:
        Map();
        Map(const Map<K, V>&);
        ~Map();
        V& operator[](const K& k);

        void print();
        
        pair<K, V>* begin();
        pair<K, V>* end();
};

template<typename K, typename V>
Map<K, V>::Map() {}

template<typename K, typename V>
Map<K, V>::~Map() {}

template<typename K, typename V>
Map<K, V>::Map(const Map<K, V>& m) {
    container = m.container;
}

template<typename K, typename V>
V& Map<K, V>::operator[](const K& k) {
    for(auto& kv: container) {
        //key
        if(kv.first == k) {
            return kv.second;
        }
    }
    //V() vraca defaultnu vrijednost tipa
    // koji smo proslijedili u template
    container.push_back({k, V()});
    //vrati referencu na novokreirani element
    return container.back().second;
}

template<typename K, typename V>
pair<K, V>* Map<K, V>::begin() {
    return container.begin();
}

template<typename K, typename V>
pair<K, V>* Map<K, V>::end() {
    return container.end();
}

template<typename K, typename V>
void Map<K, V>::print() {
    for(auto&a: container) {
        cout << (a.first) << ": " << (a.second) << endl;
    }
}