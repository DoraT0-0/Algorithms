strs = ["eat","tea","tan","ate","nat","bat"]

import collections
def function(strs: list):
    res = collections.defaultdict(list)
    for s in strs:
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1
        res[tuple(count)].append(s)

    return res.values()

print(function(strs))