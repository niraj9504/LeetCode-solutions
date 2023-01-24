// class Solution {
// public:
//     int snakesAndLadders(vector<vector<int>>& board) {
//         int n=board[0].size();
//         using pi=pair<int,int>;
//         queue<pi> q;
//         int cnt=1,l_to_r=1,steps=0;
//         q.push({n-1,0});
//         while(!q.empty()){
//             auto [x,y]=q.front();q.pop();
//             if(x==0 && y==0)return steps;
//             int maxi=cnt;
//             int r=x,c=y;
//             for(int i=1;i<=6;i++){
//                 if(l_to_r){
//                     c=y+i;
//                     if(c==n){
//                         r--;
//                         c--;
//                         l_to_r=0;
//                     }
//                 }
//                 else{
//                     c=y-i;
//                     if(c==-1){
//                         r--;
//                         c++;
//                         l_to_r=1;
//                     }
//                 }

//                 if(board[r][c]>0){
//                     if(board[r][c]%n==0){

//                     }
//                 }
//             }
//         }
//         return -1;
//     }
// };
/*
1. (3,2) =>15
n=6;
r=15/6=2 => 6-2-1=3 (n-1-board[r][c]/n)
c=15%6=3-1=> board[r][c]%n-1 (l_to_r=1)

2. 22 =>(2,2), n=6;
r=22/6=3 => 6-3-1=2 (n-1-board[r][c]/n);
c=22%6=4 => (l_to_r=0) => 6-4=2 => n-board[r][c]%n;

3. 11 =>(4,1)
r=5-1=4
c=6-5=1

4. 12 =>(4,0)
r=6-2=4 (n-board[r][c]/n)
c=
*/


class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size(), lbl = 1;
        vector<pair<int, int>> cells(n*n+1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[lbl++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n*n+1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr+6, n*n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n*n];
    }
};








