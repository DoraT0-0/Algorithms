

def encode(strs: list) -> str:
    s = ''
    for i in strs:
        s += str(len(i))+'#'+i
    return s
def decode(s: str) -> list:
    res = []
    i = 0
    while i < len(s):
        j = i
        while s[j] != '#':
            j += 1
        lenght = int(s[i:j])
        res.append(s[j + 1: j + 1 + lenght])
        i = j + 1 + lenght
    return res

    
arr = ["The quick brown fox","jumps over the","lazy dog","1234567890","abcdefghijklmnopqrstuvwxyz"]
arr = encode(arr)
arr = decode(arr)
print(arr)