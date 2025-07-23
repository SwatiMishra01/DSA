https://leetcode.com/problems/pascals-triangle/description/
LEETCODE-118
  https://leetcode.com/problems/pascals-triangle-ii/description/
  LEETCODE-119

pascal triangle-
                       1                 -> row 1
                     1   1               -> row 2
                  1    2    1            -> row 3
               1    3    3     1         -> row 4
             1   4    6     4     1      -> row 5
           1   5    10   10    5    1    -> row 6

  types of ques asked->
  1. given (row,col) return element present at that.
       ex: (row,col)=(5,3),  element=6
  2. print Nth row of pascal triangle
       ex: N=5 , o/p-> 1  4  6  4  1
  3. given N, print entire pascal triangle
       ex: N=6, o/p-> the above shown triangle would be printed.

---------------------------------------
  VARIANT 1-> PRINTING ELEMENT
---------------------------------------
  int nCr(int n, int r){
int res=1;
for(int i=0; i<n; i++){
  res=res*(n-i);
  res=res/(i+1);
      }
  return res;
  }
int PascalTraingle(int row, int col){
  return nCr(row-1,col-1);
}


Time Complexity: O(c), where c = given column number.
Reason: We are running a loop for r times, where r is c-1.

Space Complexity: O(1) as we are not using any extra space.

  -------------------------------------------
    VARIANT 2-> PRINTING ENTIRE ROW
  --------------------------------------------
class Solution {
public:
    int nCr(int n, int r) {
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return (int)res;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> row;
        for (int c = 0; c <= rowIndex; c++) {
            row.push_back(nCr(rowIndex, c));
        }
        return row;
    }
};

T.C: O(n*r), where n is the given row number, and r is the column index
S.C: O(1)

 --------------------
| OPTIMAL APPROACH-> |
----------------------
  void pascalTriangle(int n) {
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    //Printing the rest of the part:
    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

T.C=O(N)
S.C=O(1)
  
  ------------------------------------
   VARIANT 3-> PASCAL TRIANGLE PRINT
---------------------------------------
   ------------------
  | NAIVE APPROACH-> |
   -------------------
  
  int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

T.C=O(n*n*r) ~ O(n3)
S.C=O(1)

---------------------
| OPTIMAL APPROACH-> |
 -------------------- 
  cclass Solution {
public:
vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}


    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= numRows; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}
};

T.C=O(n2)
S.C=O(1)
