class Solution {
public:
    int porv(int num) {
        string s = to_string(num);
        int waviness = 0;

        if (s.size() < 3) return 0;

        for (int i = 1; i < s.size() - 1; i++) {
            int d = s[i] - '0';
            int left = s[i - 1] - '0';
            int right = s[i + 1] - '0';

            if ((d > left && d > right) || (d < left && d < right)) {
                waviness++;
            }
        }
        return waviness;
    }
    int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int x = num1; x <= num2; x++) {
            total += porv(x);
        }
        return total;
    }
};