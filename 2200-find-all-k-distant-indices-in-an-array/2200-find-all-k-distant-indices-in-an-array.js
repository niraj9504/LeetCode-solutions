/**
 * @param {number[]} nums
 * @param {number} key
 * @param {number} k
 * @return {number[]}
 */
var findKDistantIndices = function(nums, key, k) {
    const map1=new Set();
    for(let i=0;i<nums.length;i++){
        if(nums[i]===key){
            map1.add(i);
        }
    }
    var ans=[];
    for(let i=0;i<nums.length;i++){
        for(const it of map1){
            if(Math.abs(it-i)<=k){
                ans.push(i);
                 break;
            }
        }
    }
    return ans;
};