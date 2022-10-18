#/*2011. Final Value of Variable After Performing Operations

class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        return len(operations) - str(operations).count('-')