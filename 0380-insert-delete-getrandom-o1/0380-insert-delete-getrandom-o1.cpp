class RandomizedSet {
public:
    unordered_map<int,int> map;
    vector<int> nums;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val)!=map.end())return false;
        nums.push_back(val);
        map[val]=nums.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val)==map.end())return false;
        int temp=map[val];
        nums[temp]=nums[nums.size()-1];
        map[nums[nums.size()-1]]=temp;
        map.erase(val);
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */