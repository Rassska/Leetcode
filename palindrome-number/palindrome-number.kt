class Solution {
    fun isPalindrome(x: Int): Boolean {
        
        var m_intToString: String = x.toString()
        var ans: Boolean = true
        
        if (m_intToString[0] == '-') return false
        
        for(i in 0..m_intToString.length - 1) {
            if (m_intToString[i] != m_intToString[m_intToString.length - 1 - i]) {
                ans = false
                break
            }
        }
        return ans
        
    }
}