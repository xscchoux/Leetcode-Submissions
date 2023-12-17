class FoodRatings {
public:
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, set<pair<int, string>>> foodRatingCuisine;  // cuisine:{rating, food}
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0; i<foods.size(); i++){
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            foodRatingCuisine[cuisines[i]].insert({-ratings[i], foods[i]});
        }
        
    }
    
    void changeRating(string food, int newRating) {
        int rating = foodRating[food];
        string cuisine = foodCuisine[food];
        auto it = foodRatingCuisine[cuisine].find({-rating, food});
        foodRatingCuisine[cuisine].erase(it);
        foodRating[food] = newRating;
        foodRatingCuisine[cuisine].insert({-newRating, food});
        
    }
    
    string highestRated(string cuisine) {
        auto it = foodRatingCuisine[cuisine].begin();
        return (*it).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */