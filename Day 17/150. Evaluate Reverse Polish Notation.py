# https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

from ast import List
import math
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operators = {'+', '-', '*', '/'}
        if len(tokens) == 1: return int(tokens[0])
        for token in tokens:
            if token not in operators:
                stack.append(int(token))
            else:
                sec_operand = stack.pop()
                fir_operand = stack.pop()
                tmp=0
                if token == '+':
                    tmp = fir_operand + sec_operand
                elif token == '-':
                    tmp = fir_operand - sec_operand
                elif token == '*':
                    tmp = fir_operand * sec_operand
                elif token == '/':
                    tmp = fir_operand / sec_operand
                    tmp = math.trunc(tmp)
                stack.append(tmp)
        return stack.pop()