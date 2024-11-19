s = ""

maxsubstring = ''
for j in range(len(s)):
    substring = ''
    for i in range(j, len(s)):
        if substring.find(s[i]) != -1:
            if len(substring) > len(maxsubstring):
                maxsubstring = substring
                break
            break
        else:
            if i == len(s)-1:
                substring += s[i]
                if len(substring) > len(maxsubstring):
                    maxsubstring = substring
            else:
                substring += s[i]
print(len(maxsubstring))