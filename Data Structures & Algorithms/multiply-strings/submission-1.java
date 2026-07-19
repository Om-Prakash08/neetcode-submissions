class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0"))
            return "0";
        int n = num1.length();
        int m = num2.length();
        int[] res = new int[n + m];
        for (int k = 0; k < n + m; k++) {
            res[k] = 0;
        }
        for (int i = n-1; i >=0; i--)
            for (int j = m-1; j >=0; j--) {
                int mul = (num1.charAt(i) - '0') * (num2.charAt(j) - '0');

                int sum = mul + res[i + j + 1];

                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        StringBuilder ans = new StringBuilder();

        int i = 0;
        while (i < res.length && res[i] == 0) i++;

        while (i < res.length) ans.append(res[i++]);
        return ans.toString();
    }
}
