https://leetcode.com/problems/spiral-matrix-ii/description/
LEETCODE-59

Approach
---------
1. Boundaries:
   -> top → first row to fill
   -> bottom → last row to fill
   -> left → first column to fill
   -> right → last column to fill

2. Direction order:
   -> Left → Right (top row)
   -> Top → Bottom (right column)
   -> Right → Left (bottom row)
   -> Bottom → Top (left column)

After filling in one direction, move the boundary inward and change direction.



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        //4 pointers to top botton left right
        int top=0;
        int left=0;
        int right=n-1;
        int bottom=n-1;

        int num=1;  // always the 1st no. to be inserted

        while(top<=bottom && left<=right){
            //1. left->right(top row){
            for(int i=left; i<=right; i++){
                matrix[top][i]=num++;
            }
            top++;

            //2. top->bottom(right col)
            for(int i=top; i<=bottom; i++){
                matrix[i][right]=num++;
            }
            right--;

            if (top <= bottom) {
            //3. right->left (bottom row)
            for(int i=right; i>=left; i--){
                matrix[bottom][i]=num++;
            }
            bottom--;
            
            //4. bottom->top(left col)
            for(int i=bottom;i>=top; i--){
                matrix[i][left]=num++;
            }
            left++;
            }
        }
        return matrix;
    }
};
T.C=class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        //4 pointers to top botton left right
        int top=0;
        int left=0;
        int right=n-1;
        int bottom=n-1;

        int num=1;  // always the 1st no. to be inserted

        while(top<=bottom && left<=right){
            //1. left->right(top row){
            for(int i=left; i<=right; i++){
                matrix[top][i]=num++;
            }
            top++;

            //2. top->bottom(right col)
            for(int i=top; i<=bottom; i++){
                matrix[i][right]=num++;
            }
            right--;

            if (top <= bottom) {
            //3. right->left (bottom row)
            for(int i=right; i>=left; i--){
                matrix[bottom][i]=num++;
            }
            bottom--;
            
            //4. bottom->top(left col)
            for(int i=bottom;i>=top; i--){
                matrix[i][left]=num++;
            }
            left++;
            }
        }
        return matrix;
    }
};
T.C=class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        //4 pointers to top botton left right
        int top=0;
        int left=0;
        int right=n-1;
        int bottom=n-1;

        int num=1;  // always the 1st no. to be inserted

        while(top<=bottom && left<=right){
            //1. left->right(top row){
            for(int i=left; i<=right; i++){
                matrix[top][i]=num++;
            }
            top++;

            //2. top->bottom(right col)
            for(int i=top; i<=bottom; i++){
                matrix[i][right]=num++;
            }
            right--;

            if (top <= bottom) {
            //3. right->left (bottom row)
            for(int i=right; i>=left; i--){
                matrix[bottom][i]=num++;
            }
            bottom--;
            
            //4. bottom->top(left col)
            for(int i=bottom;i>=top; i--){
                matrix[i][left]=num++;
            }
            left++;
            }
        }
        return matrix;
    }
};
T.C=O(N^2)
S.C=O(1)
