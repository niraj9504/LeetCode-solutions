/**
 * @param {number[]} nums
 * @return {number}
 */
var distinctAverages = function(nums) {
    if(nums.length==0)return 0;
    nums.sort(function(a,b){
        return a-b;
    });
    var n=nums.length;
    var set=new Set();
    // for(const it of nums)console.log(it);
    for(let i=0;i<n/2;i++){
        var avg=(nums[i]+nums[n-i-1])/2;
        // console.log(avg);
        set.add(avg);
    }
    return set.size;
};