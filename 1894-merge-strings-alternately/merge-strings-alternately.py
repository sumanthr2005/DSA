class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        result = []
        i, j = 0, min(len(word1), len(word2))
        
        # Interleave characters from both strings up to the length of the shorter string
        while i < len(word1) and i < len(word2):
            result.append(word1[i])
            result.append(word2[i])
            i += 1
            
        # Append any remaining characters from either string
        result.append(word1[i:])
        result.append(word2[i:])
        
        return "".join(result)