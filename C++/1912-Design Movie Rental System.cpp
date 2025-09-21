// roughly O(NlogN + QlogN + M), Q:the number of rent, drop,  M:the number of search and report
using PII = pair<int, int>;
class MovieRentingSystem {
public:
    unordered_map<int, set<PII>> toRent; // movie:{price, shop}
    unordered_map<int, unordered_map<int, int>> priceMap; // movie: {shop: price}
    set<array<int, 3>> rentedSet; // {price, shop, movie}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e:entries) {
            int shop = e[0], movie = e[1], price = e[2];
            toRent[movie].insert({price, shop});
            priceMap[movie][shop] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> arr;
        int cnt = 0;
        for (auto it = begin(toRent[movie]); it != end(toRent[movie]) && cnt < 5; it++) {
            arr.push_back({it->second});
            cnt++;
        }
        return arr;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[movie][shop];
        toRent[movie].erase({price, shop});
        rentedSet.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[movie][shop];
        rentedSet.erase({price, shop, movie});
        toRent[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> arr;
        int cnt = 0;
        for (auto it = begin(rentedSet); it != end(rentedSet) && cnt < 5; it++) {
            arr.push_back({(*it)[1], (*it)[2]});
            cnt++;
        }
        return arr;        
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */