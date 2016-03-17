class CliqueParty():
    def maxsize(self, a, k):
        a = list(a)
        a.sort()
        n = len(a)
        ans = 1
        for i in range(n):
            for j in range(i + 1, n):
                last = a[i]
                rlen = a[j] - a[i]
                count = 2

                for m in range(i + 1, j):
                    if (a[m] - last) * k >= rlen and (a[j] - a[m]) * k >= rlen:
                        last = a[m]
                        count += 1
                ans = max(ans, count)
        return ans
