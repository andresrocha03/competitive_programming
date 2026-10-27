class Solution:
    def reverse(self, x: int) -> int:
        int_max = str((-1)*(-2**31 + 1))
        int_min = str(-2**31)[1:]        
        str_x = str(x)

        negative = (x<0)
        if negative:
            str_x = str_x[1:]
        
        reverse_x = str_x[::-1]

        comparison = int_max
        if negative:
            comparison = int_min

        if len(reverse_x) > len(comparison):
            return 0

        if len(reverse_x) == len(comparison) and reverse_x > comparison:
            return 0
        
        res = reverse_x

        if negative:
            res = '-' + res

        return int(res)
