class DivFreed2():
    def count(self, n, k):
        mod = 1000000007

        ans = [1] * (k + 1)
        ans[0] = 0
        for i in range(n - 1):
            next = [0] * (k + 1)
            s = sum(ans)
            for j in range(1, k + 1):
                next[j] = s
                for m in range(j + j, k + 1, j):
                    next[j] -= ans[m]
                next[j] %= mod
            ans = next
        return sum(ans) % mod
