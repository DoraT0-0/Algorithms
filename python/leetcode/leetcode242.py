s = 'anagram'
t = 'nagaram'

def function(s: str, t:str):
    if len(s) != len(t):
        return False
    s = sorted(s)
    t = sorted(t)
    if s == t:
        return True
    
print(function(s,t))