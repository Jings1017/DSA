#include <iostream>
#include <string>

using namespace std;

int main(){
    // text1="ECABCADBE" text2="ABADDCECBA"
    string text1, text2;
    int result;
    cout << "input two string :\n";
    cin >> text1 >> text2;
    int n = text1.size();
    int m = text2.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n;i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m;j++)
        dp[0][j] = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            if(text1[i-1]==text2[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }   
            else
                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            result = dp[i][j];
         }
    }
    cout << "the length of LCS = " << result << endl ;
    cout << "    ";
    for (int i = 0; i < text2.length();i++){
        cout << text2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {   
        if(i!=0){
            cout << text1[i-1] << " ";
        }
        else{
            cout << "  ";
        }
        
        for (int j = 0; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}