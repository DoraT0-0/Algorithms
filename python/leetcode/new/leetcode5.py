s = ""

maxsubstring = ''
for j in range(len(s)):
    substring = ''
    for i in range(j, len(s)):
        substring += s[i]
        if substring == substring[::-1] and len(substring) > len(maxsubstring):
            maxsubstring = substring
    
print(maxsubstring)