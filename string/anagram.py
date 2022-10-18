# Making Anagrams hackerrank
 
def makeAnagram(a, b):
    # Write your code here
    count = 0
    for letter in a:
        if letter in b:
            b = b.replace(letter,'',1)
            continue
        count +=1
    return count+(len(b))