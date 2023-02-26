class Solution {
public:
    bool dfs(unordered_map<string, vector<string>>& recipes, string curr, 
             unordered_set<string>& supplies, 
             unordered_map<string, bool>& v
            ) {
        // Set visited to false originally
        if(v[curr]) return true;
        v[curr] = false;
        
        for(string ing : recipes[curr]) {
            if(supplies.find(ing) == supplies.end()) {
                if(recipes.find(ing) == recipes.end()) return false;
                if(v.find(ing) != v.end() && !v[ing]) return false;
                if(!dfs(recipes, ing, supplies, v)) return false;
            }
        }
        
        v[curr] = true;
        return true;
    }
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> result;
        
        // Make a hash set of available supplies for better access - O(n)
        // Make a map of recipes : ingredients (hash table of vectors)
        unordered_set<string> supplySet;
        unordered_map<string, vector<string>> recipeMap;
        
        for(string supply : supplies) supplySet.insert(supply);
        for(int i = 0; i < recipes.size(); i++) recipeMap[recipes[i]] = ingredients[i];
        
        // Now for each recipe, if an ingredient is in supplies or is another recipe
        //      where all ingredients are in supplies, we can make said recipe
        unordered_map<string, bool> visited;
        for(string recipe : recipes) {
            if(dfs(recipeMap, recipe, supplySet, visited)) result.push_back(recipe);
        }
        
        
        return result;
    }
};