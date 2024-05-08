class Solution {
    bool is_vowel(char& c) {
        string vowels = "aeiou";
        return vowels.find(c) != string::npos;
    }
    
    bool is_vowel_substring(string s) {
        bool letters[26];
        memset(letters, false, sizeof(letters));
        for (char& c : s) {
            letters[c-'a'] = true;
            if (!is_vowel(c)) {
                return false;
            }
        }
        bool has_a = letters['a'-'a'];
        bool has_e = letters['e'-'a'];
        bool has_i = letters['i'-'a'];
        bool has_o = letters['o'-'a'];
        bool has_u = letters['u'-'a'];
        return (has_a && has_e && has_i && has_o && has_u);
    }
    
public:
    int countVowelSubstrings(string word) {
        int cnt = 0, n = word.size();
        for (int i = 0; i < n; i++) {
            string temp = string(1, word[i]);
            for (int j = i + 1; j < n; j++) {
                temp += word[j];
                cnt += is_vowel_substring(temp);
            }
        }
        return cnt;
    }
};
