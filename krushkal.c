#include <stdio.h>
#define I 32767

int edges[3][9] = {
    {1, 1, 2, 2, 3, 4, 4, 5, 5},   // u
    {2, 4, 3, 5, 5, 5, 6, 6, 7},   // v
    {7, 5, 8, 7, 5, 15, 6, 8, 9}   // weight
};

int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
int included[9] = {0}, t[2][6], w[6];

void Union(int u, int v) {
    if (set[u] < set[v]) {
        set[u] += set[v];
        set[v] = u;
    } else {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u) {
    int x = u;
    while (set[x] > 0) {
        x = set[x];
    }
    return x;
}

int main() {
    int i = 0, j, k, n = 7, e = 9, min, u, v;

    while (i < n - 1) {
        min = I;
        for (j = 0; j < e; j++) {
            if ((included[j] == 0) && (edges[2][j] < min)) {
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }

        int fu = find(u);
        int fv = find(v);

        if (fu != fv) {
            t[0][i] = u;
            t[1][i] = v;
            w[i] = edges[2][k];
            Union(fu, fv);
            i++;
        }
        included[k] = 1;
    }

    int s = 0;
    for (i = 0; i < n - 1; i++) {
        int u = t[0][i];
        int v = t[1][i];
        printf("Edge: (%d,%d)  Weight = %d\n", u, v, w[i]);
        s += w[i];
    }
    printf("Minimum cost: %d\n", s);

    return 0;
}
