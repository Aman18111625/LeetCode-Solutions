class Solution {
public:
    unordered_map<string, string> map1, map2;
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    string getCode() {
        string code = "";
        for (int i = 0; i < 6; i++) code += chars[rand() % 62];
        return code;
    }
    
    string encode(string longUrl) {
        if (map2.find(longUrl) != map2.end()) return map2[longUrl];
        string code = getCode();
        while (map1.find(code) != map1.end()) code = getCode();
        map1[code] = longUrl;
        map2[longUrl] = code;
        return code;
    }

    string decode(string shortUrl) {
        return map1[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));