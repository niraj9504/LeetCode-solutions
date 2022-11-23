/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, t) {
    const map1={};
    for(let i=0;i<nums.length;i++){
        const v=t-nums[i];
        if(v in map1){
            return [map1[v],i];
        }
        map1[nums[i]]=i;
    }
    return [-1,-1];
};