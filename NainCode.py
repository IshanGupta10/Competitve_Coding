class Solution:
    # @param A : tuple of integers
    # @return a strings
    def compare_num(self,A,B):
        if(int(A+B)>int(B+A)):
            return 1
        else:
            return -1
    def largestNumber(self, C):
        for element in C:
            if(element == 0):
                flag = False
            else:
                flag = True
        if flag:        
            number_string = []
            result = ""
            i = 0
            for element in C:
                number_string.append(str(element))
            number_string=sorted(number_string,cmp = self.compare_num)
            number_string = list(reversed(number_string))
            for element in number_string:
                result += element
            return result
        else:
            return '0'
