/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxK = function(nums) {
    var map1=new Map();
    var ans=-1;
    for(let i=0;i<nums.length;i++){
        if(map1.has(-nums[i])){
            ans=Math.max(Math.abs(nums[i]),ans);
        }
        map1.set(nums[i],i);
    }
    return ans;
};