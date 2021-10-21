class Logger {
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (hashMap.find(message) != hashMap.end()) {
            if (hashMap.find(message)->second > timestamp) {
                
                return false;
            } else {
                hashMap[message] = timestamp + 10;
                return true;
            }
        } else {
            hashMap[message] = timestamp + 10;
            return true;
        }
    }
    
private: 
    std::unordered_map<std::string, int> hashMap;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */