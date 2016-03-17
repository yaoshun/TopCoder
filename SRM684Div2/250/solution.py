from collections import Counter
class Istr():
    def count(self, s, k):
        c = Counter(s)
        for _ in range(k): c[c.most_common(1)[0][0]] -= 1
        return sum(mapx(lambda x: x*x, c.values()))
