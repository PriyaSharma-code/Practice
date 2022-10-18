#/*1108. Defanging an IP Address

class Solution:
    def defangIPaddr(self, address: str) -> str:
        split = address.split('.')
        new = '[.]'.join(split)
                
        return new
        