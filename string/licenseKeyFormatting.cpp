//482. License Key Formatting

#include <string>
#include <algorithm>

class Solution {
public:
    std::string licenseKeyFormatting(std::string s, int k) {
        // Remove dashes and convert to uppercase
        std::string cleaned;
        for (char c : s) {
            if (c != '-') {
                cleaned += std::toupper(c);
            }
        }

        int n = cleaned.size();
        // Determine the length of the first group
        int firstGroupSize = n % k;
        if (firstGroupSize == 0 && n > 0) {
            firstGroupSize = k;
        }

        std::string result;
        int count = 0;

        // Build the result string
        for (int i = 0; i < n; ++i) {
            if (count == firstGroupSize || (count > firstGroupSize && (count - firstGroupSize) % k == 0)) {
                result += '-';
            }
            result += cleaned[i];
            ++count;
        }

        return result;
    }
};
