from itertools import product
class Autohamil():
    def check(self, z0, z1):
        n = len(z0)
        conn = [[False] * n for _ in range(n)]
        for i in range(n): conn[i][i] = True
        for a,b in list(enumerate(z0)) + list(enumerate(z1)):
            conn[a][b] = True
        for k,i,j in product(*[range(n)] * 3):
            conn[i][j] = conn[i][j] or (conn[i][k] and conn[k][j])
        if not all(conn[0][i] for i in range(n)): return "Does not exist"
        for i,j in product(*[range(n)] * 2):
            if not conn[i][j] and not conn[j][i]:
                return "Doest not exist"
        return "Exists"
