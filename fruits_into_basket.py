# LC 904: https://leetcode.com/problems/fruit-into-baskets/
# tutorial: https://youtu.be/hClCsJDcpSU
class Solution(object):
    def totalFruit(self, fruits):
        start = 0
        end = 0
        max_len = 0
        dict = {}

        while end < len(fruits):
            dict[fruits[end]] = end
            if len(dict) >= 3:
                min_val = min(dict.values())
                del dict[fruits[min_val]]
                start = min_val + 1
            max_len = max(max_len, end-start+1)
            end += 1

        return max_len
    
# TC : O(n) have to traverse all the valeus in the fruits
# SC : O(1) as the total space will be highest for the 3 value in the map/dictionary
