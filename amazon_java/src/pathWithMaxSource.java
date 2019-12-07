public class pathWithMaxSource {
    public static int minMaxScore(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] dp = new int[n];
        dp[0] = matrix[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (j == 0 && i != 0) {
                    dp[j] = Math.min(matrix[i][j], dp[j]);
                } else if (j != 0 && i == 0) {
                    dp[j] = Math.min(matrix[i][j], dp[j - 1]);
                } else {
                    dp[j] = Math.min(Math.max(dp[j], dp[j - 1]), matrix[i][j]);
                }
            }
        }
        return dp[n - 1];
    }

    public static void main(String[] args) {
        int tc1 = minMaxScore(new int[][] { { 5, 1 }, { 4, 5 } });
        int tc2 = minMaxScore(new int[][] { {5, 1, 7}, {4, 8, 5}});
        int tc3 = minMaxScore(new int[][] { {1, 9, 9}, {9, 9, 9}, {9, 9, 9} });
        int tc4 = minMaxScore(new int[][] { {20, 20, 3}, {20, 3, 20}, {3, 20, 20} });
        System.out.println(tc1);
        System.out.println(tc2);
        System.out.println(tc3);
        System.out.println(tc4);
    }

}
