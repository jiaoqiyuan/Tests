
public class UF_1 {
    private int[] id;
    private int count;

    public UF_1(int N) {
        // 初始化分量id数组
        count = N;
        id = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
    }

    public int count() {
        return count;
    }

    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    public int find(int p) {
        while (p != id[p]) {
            p = id[p];
        }
        return p;
    }

    public void union(int p, int q) {
        // 将 p 和 q 的节点统一
        int pRoot = find(p);
        int qRoot = find(q);

        // 如果 p 和 q 已经在相同的分量之中则不需要采取任何行动
        if (pID == qID) {
            return;
        }

        id[pRoot] = qRoot;
        count--;
    }

    public static void main(String[] args) {
        int N = StdIn.readInt();
        UF_1 uf = new UF_1(N);
        while (!StdIn.isEmpty()) {
            int p = StdIn.readInt();
            int q = StdIn.readInt();
            if (uf.connected(p, q)) {
                continue;
            }
            uf.union(p, q);
            StdOut.println(p + " " + q);
        }
        StdOut.println(uf.count() + "components");
    }
}