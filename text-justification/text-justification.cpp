class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        

        /*
        
            ** Clarifying the given problem
            
            1. words - is vector of strings
            2. 1 <= words.size() <= 300
            3. 1 <= words[i].size() <= 20
            4. words[i] - English letters ans symbols
            5. 1 <= maxWidth <= 100
            6. words[i].size() <= maxWidth
            
            return a string which is justification of given string
            
        
        
            ** Initial approaches
            
            1. let's place max words in particular out[i];
            2. After each word we need to add just one space to separate the words
            3. Adding extra spaces
            
            ** Exploring extra test cases:
            
                Input: words = {"Something", "everything."}, wordWidth = 20;
                
        */
        
        std::vector<std::string> justifiedString;
        std::string currStringTemp = "";
        
        for (std::size_t i = 0; i < words.size(); i++) {
            if (maxWidth - currStringTemp.size() >= words[i].size() + 1) {
                currStringTemp += (words[i] + ' ');
            } else if (maxWidth - currStringTemp.size() >= words[i].size()) {
                currStringTemp += words[i];
            } else {
                justifiedString.push_back(currStringTemp);
                currStringTemp = "";
                i--;
            }
            if (i == words.size() - 1 && currStringTemp.size() > 0) {
                justifiedString.push_back(currStringTemp);
            }
        }
    
        for (std::size_t i = 0; i < justifiedString.size(); i++) {
            
            std::size_t wordsAmount = 1;
            std::size_t nonSpaceCharsAmount = 1;
            for (std::size_t j = 1; j < justifiedString[i].size(); j++) {
                if (justifiedString[i][j - 1] != ' ' && justifiedString[i][j] == ' ') {
                    wordsAmount++;
                }
                if (justifiedString[i][j] != ' ') {
                    nonSpaceCharsAmount++;
                }
                if (j == justifiedString[i].size() - 1) wordsAmount--;
            }
            if (justifiedString[i][justifiedString[i].size() - 1] == ' ') {
                justifiedString[i].erase(justifiedString[i].begin() + justifiedString[i].size() - 1);
            }  
            if (justifiedString[i].size() == maxWidth) {
                continue;
            }
            if (wordsAmount == 1 || i == justifiedString.size() - 1) {
                int rightConstraint = maxWidth - justifiedString[i].size();
                for (std::size_t k = 0; k < rightConstraint; k++) {
                    justifiedString[i].push_back(' ');
                }
                continue;
            }
            std::size_t remainingSpacesAmount = maxWidth - nonSpaceCharsAmount - (wordsAmount - 1);
            std::size_t remainingSpacesAmountAfterEachWord = remainingSpacesAmount / (std::max((wordsAmount - 1), std::size_t(1)));
            std::size_t remainingDoubleSpacesAmountAfterEachWord = remainingSpacesAmount % (std::max((wordsAmount - 1), std::size_t(1)));
            std::size_t localWordsAmount = 1;
            
            for (std::size_t j = 1; j < justifiedString[i].size(); j++) {
                if (i != justifiedString.size() - 1 && justifiedString[i][j - 1] != ' ' && justifiedString[i][j] == ' ') {
                    for ( std::size_t k = 0; k < remainingSpacesAmountAfterEachWord; k++) {
                        justifiedString[i].insert(justifiedString[i].begin() + j, ' ');
                    }
                    if (localWordsAmount <= remainingDoubleSpacesAmountAfterEachWord) {
                        justifiedString[i].insert(justifiedString[i].begin() + j, ' ');
                    }
                    localWordsAmount++;
                   
                } 
            }
            
            
        }
        
        
           return justifiedString;

    }
};