class Solution
{
public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b) {

        map<char, int> hash;
        for (auto it : a) hash[it]++;
        for (auto it : b) hash[it]--;
        for (auto it : hash) {
            if (it.second != 0) return false;
        }
        return true;

    }

};