/**
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function(n, trust) {
    let indegree=new Array(n).fill(0);
    let outdegree=new Array(n).fill(0);
    for(let it of trust){
        // console.log(it);
        indegree[it[1]-1]++;
        outdegree[it[0]-1]++;
    }
    for(let i=0;i<n;i++){
        // console.log(indegree[i]);
        // console.log(outdegree[i]);
        if(indegree[i]===n-1 && outdegree[i]===0)return i+1;
    }
    return -1;
};