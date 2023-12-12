#include "stringComparator.h"

int stringComparator(const char *str1, const char *str2, int limite){
    int distancia = levenshteinDistance(str1, str2);
    return (distancia <= limite) ? 1 : 0;
}
int levenshteinDistance(const char *str1, const char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int dp[len1 + 1][len2 + 1];

    for (int i = 0; i <= len1; ++i) {
        for (int j = 0; j <= len2; ++j) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else
                dp[i][j] = (str1[i - 1] == str2[j - 1]) ?
                           dp[i - 1][j - 1] :
                           1 + fmin(fmin(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
        }
    }

    return dp[len1][len2];
}