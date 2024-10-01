s = "A man, a plan, a canal: Panama"

def function(s: str):
    s = s.lower()
    for i in s:
        if not (97 <= ord(i) <= 122) and not (48 <= ord(i) <= 57):
            s = s.replace(i, '')
    t = "".join(reversed(s))
    if s == t:
        return True
    return False


print(function(s))