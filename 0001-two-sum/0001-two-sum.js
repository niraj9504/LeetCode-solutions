/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, t) {
    const map1=new Map();
    for(let i=0;i<nums.length;i++){
        const v=t-nums[i];
        if(map1.has(v)){
            return [map1.get(v),i];
        }
        // map1[nums[i]]=i;
        map1.set(nums[i],i);
    }
    return [-1,-1];
};