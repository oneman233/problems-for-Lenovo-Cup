oneman233非常喜欢Minecraft，他甚至开设了自己的服务器！但是他没想到的是，使用 $123456$ 作为登录口令的服务器在上线 $3$ 秒后就被攻破了，他无奈地发现自己建造的所有建筑都被夷为了平地，并且世界里只剩下了一堆沙子供他重建家园。

Minecraft的世界可以被理解成一个长为 $n$ ，宽为 $m$ ，高为 $h$ 的三维世界。为了重建被破坏的建筑，oneman233凭着记忆用大写字母 $A-Z$ 给三维世界中的每个点都做了标记，他每次可以**选择一个大写字母并把标记为这个字母的点都用沙子填上**，同时**数据不保证标记相同的点都是互相连通的**。

沙子有这样一个特性：**当它的正下方不是地面或者没有其他沙子时，它将会下落**，oneman233非常讨厌沙子下落时的音效，他现在想知道有没有一种方案能够在没有任何一个沙子下落的情况下填满所有标记。

输入的第一行给出了数据组数 $t(t\leq 10)$ ，每组数据的第一行给出了三维世界的长 $n(n\leq 30)$ ，宽 $m(m\leq 30)$ 和高 $h(h\leq 30)$ ，接下来给出了 $h$ 个大小为 $n*m$ 仅由大写字母组成的矩阵，按照**从高到低的顺序**给出了三维世界中不同高度的标记情况，其中**高度为 $1$ 的矩阵紧贴地面。**

如果能够填满所有标记，你需要输出**字典序最大**的填满标记的顺序，否则输出 $-1$ 即可

样例输入：

```
3
2 2 2
BA
BB
AA
BA
1 2 4
AA
BB
CB
BB
1 2 2
AB
CD
```

样例输出：

```
AB
-1
DCBA
```

样例说明：

* 对于第一组数据，只有`AB`一种答案，先放`B`标记的话会导致沙子下落
* 对于第二组数据，无论先放哪种标记都会导致沙子下落
* 对于第三组数据，`DBCA`也是一种可能的顺序，但是它的字典序小于`DCBA`