class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        skill.sort ()
        t = len (skill)
        q = skill [0] + skill [t - 1] # Referência
        total = 0
        for i in range (t // 2):
            if (skill [i] + skill [t - i - 1]) != q:
                return -1
            # else
            total += skill [i] * skill [t - i - 1]
        return total
    
