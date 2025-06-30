https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383

---------------------------------
  APPROACH 1-> RECURSION (TLE)
---------------------------------
string f(int i, int j, string &s1, string &s2) {
    if (i < 0 || j < 0) return "";

    if (s1[i] == s2[j]) {
        return f(i-1, j-1, s1, s2) + s1[i];
    } else {
        string left = f(i-1, j, s1, s2);
        string right = f(i, j-1, s1, s2);
        return (left.size() > right.size()) ? left : right;
    }
}

string findLCS(int n, int m,string &s1, string &s2){
	return f(n-1,m-1,s1,s2);	
}


TC=O(2^n)	
SC=O(n + m) (stack)
  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ------------------------------------
    APPROACH 2->MEMOIZATION
  ------------------------------------
string f(int i, int j, string &s1, string &s2,vector<vector<string>>& dp) {
    if (i < 0 || j < 0) return "";

    //memoization
    if (dp[i][j] != "#") return dp[i][j];


    if (s1[i] == s2[j]) {
        return dp[i][j]=f(i-1, j-1, s1, s2,dp) + s1[i];
    } else {
        string left = f(i-1, j, s1, s2,dp);
        string right = f(i, j-1, s1, s2,dp);
        return dp[i][j]=(left.size() > right.size()) ? left : right;
    }
}

string findLCS(int n, int m,string &s1, string &s2){
    vector<vector<string>> dp(n, vector<string>(m, "#"));
	return f(n-1,m-1,s1,s2,dp);	
}

TC=O(n × m × k)	
SC=O(n × m × k) (stores strings)
  -----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  ----------------------------------
    APPROACH 3-> TABULATION
  ----------------------------------



✏️ Step 1: Initialize DP Table
    ---------------------------
-> Create a DP table dp[n+1][m+1] of size (length of s1 + 1) x (length of s2 + 1).
-> Each dp[i][j] will store the length of LCS for s1[0..i-1] and s2[0..j-1].

Why n+1 and m+1?
* The 0th row and 0th column represent the case where one of the strings is empty, so the LCS length is 0.


  ✏️ Step 2: Fill the DP Table
---------------------------------
Loop through i and j:
-> If the characters match (s1[i-1] == s2[j-1]):
         - You can extend the LCS by 1.
         - dp[i][j] = 1 + dp[i-1][j-1]

-> Else:
     - You skip a character from either s1 or s2 to find the longer subsequence.
     - dp[i][j] = max(dp[i-1][j], dp[i][j-1])


  ✏️ Step 3: Initialize LCS String
----------------------------------------
-> Once the table is filled, dp[n][m] contains the length of the LCS.
-> Create a dummy string of that length, e.g., "$$$$$".


  ✏️ Step 4: Backtrack to Build the LCS
---------------------------------------------
Now, trace back to find which characters made up the LCS:
-> Start from (i = n, j = m) and move towards (0, 0).
-> If s1[i-1] == s2[j-1]:
    - That character is part of the LCS → put it at str[index].
    - Move diagonally: i--, j--.

-> Else:
    - Check which direction gives the longer LCS:
    - If dp[i-1][j] > dp[i][j-1] → move up (i--).
    - Else → move left (j--).

✏️ Step 5: Return the Final LCS
  ------------------------------
  return str;




string findLCS(int n, int m, string &s1, string &s2) {
  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  // Fill DP table
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  // Build LCS from DP table
  int len = dp[n][m];
  int i = n, j = m;
  int index = len - 1;

  string str(len, '$'); // initialize with dummy

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      str[index] = s1[i - 1];
      index--;
      i--;
      j--;
    } else if (dp[i-1][j] > dp[i][j-1]) {
      i--;
    } else {
      j--;
    }
  }

  return str;
}

TC=O(n × m)	
  SC=O(n × m)



  

 
