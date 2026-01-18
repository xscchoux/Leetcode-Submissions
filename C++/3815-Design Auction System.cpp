class AuctionSystem {
public:
    // hmap = {itemId :(bidAmount, userId), ...}
    // mp = {userId:itemId:bidAmount, ...}
    unordered_map<int, unordered_map<int, int>> hmap;
    map<int, set<pair<int, int>, greater<>>> mp;
    AuctionSystem() {

    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        int oldBitAmount = -1;
        if (hmap.contains(userId) && hmap[userId].contains(itemId)) {
            oldBitAmount = hmap[userId][itemId];
        }
        if (oldBitAmount != -1) {
            mp[itemId].erase({oldBitAmount, userId});
        }

        // update hmap and mp
        hmap[userId][itemId] = bidAmount;
        mp[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int oldBitAmount = hmap[userId][itemId];

        // update hmap and mp
        hmap[userId][itemId] = newAmount;
        mp[itemId].erase({oldBitAmount, userId});
        mp[itemId].insert({newAmount, userId});       
    }
    
    void removeBid(int userId, int itemId) {
        int oldBitAmount = hmap[userId][itemId];
        hmap[userId].erase(itemId);
        mp[itemId].erase({oldBitAmount, userId});
        if (mp[itemId].empty()) {
            mp.erase(itemId);
        }
    }
    
    int getHighestBidder(int itemId) {
        if (!mp.contains(itemId)) return -1;

        auto it = mp[itemId].begin();
        return it->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */