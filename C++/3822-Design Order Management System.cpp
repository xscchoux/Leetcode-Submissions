class OrderManagementSystem {
public:
    // orderId:{type, price}
    // type:{price:{set of ids}}
    map<int, pair<string, int>> hmap;
    map<string, map<int, unordered_set<int>>> typePriceId;
    OrderManagementSystem() {

    }
    
    void addOrder(int orderId, string orderType, int price) {
        hmap[orderId] = {orderType, price};
        typePriceId[orderType][price].insert(orderId);
    }
    
    void modifyOrder(int orderId, int newPrice) {
        auto [preType, prePrice] = hmap[orderId];
        hmap[orderId] = {preType, newPrice};

        typePriceId[preType][prePrice].erase(orderId);
        if (typePriceId[preType][prePrice].empty()) {
            typePriceId[preType].erase(prePrice);
        }
        typePriceId[preType][newPrice].insert(orderId);    
    }
    
    void cancelOrder(int orderId) {
        auto [preType, prePrice] = hmap[orderId];
        hmap.erase(orderId);
        
        typePriceId[preType][prePrice].erase(orderId);
        if (typePriceId[preType][prePrice].empty()) {
            typePriceId[preType].erase(prePrice);
        }        
    }
    
    vector<int> getOrdersAtPrice(string orderType, int price) {
        vector<int> res;
        if (typePriceId.contains(orderType) && typePriceId[orderType].contains(price)) {
            for (int orderId:typePriceId[orderType][price]) {
                res.push_back(orderId);
            }
        }

        return res;
    }
};

/**
 * Your OrderManagementSystem object will be instantiated and called as such:
 * OrderManagementSystem* obj = new OrderManagementSystem();
 * obj->addOrder(orderId,orderType,price);
 * obj->modifyOrder(orderId,newPrice);
 * obj->cancelOrder(orderId);
 * vector<int> param_4 = obj->getOrdersAtPrice(orderType,price);
 */