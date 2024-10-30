//question link: https://leetcode.com/problems/string-to-integer-atoi/description/?envType=problem-list-v2&envId=string
//submission link: https://leetcode.com/problems/string-to-integer-atoi/submissions/1340835195

class Solution {
    public static int myAtoi(String s) {
        long ans = 0;
        int i = 0;
        int sign = 1;

        while (i < s.length()) {
            char temp = s.charAt(i);
            if (temp != ' ') {
                if (temp == '-') {
                    sign = -1;
                    i++;
                }
                if (temp == '+') {
                    sign = 1;
                    i++;
                }
                break;
            }
            i++;
        }

        while (i < s.length()) {
            char temp = s.charAt(i);
            if (temp >= '0' && temp <= '9') {
                ans *= 10;
                ans += temp - '0';
                if (sign * ans > Integer.MAX_VALUE) {
                    return Integer.MAX_VALUE;
                }
                if (sign * ans < Integer.MIN_VALUE) {
                    return Integer.MIN_VALUE;
                }
                i++;
            } else {
                break;
            }
        }

        return (int)(sign * ans);

    }
}
