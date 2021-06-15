# Minecraft

Oneman233 is crazy about Minecraft, he even has his own server! However, his server's password $123456$ has been broken by a hacker after only $3$ seconds. He hopelessly find that every house in his world has been destroyed and he can only use sand to rebuild these houses.

Minecraft's houses can be regarded as a 3-dimensional cube with length $n$, width $m$, and height $h$. In order to rebuild houses, oneman233 uses upper case letters $A-Z$ to mark every point in this 3-dimensional cube, he can choose one letter a time and put sand on ALL THE POINTS marked with the same letter. When every point in the cube is filled up with sand, then we say that oneman233 successfully rebuild the house.

sand has an interesting property: It falls when there's no sand under it and it's not on the ground. Formally, sand in point $(x,y,z)$ falls if and only if there's no sand in $(x,y,z-1)$ and $z\neq 1$. Oneman233 hates the sound when sand falls, so he wonder if he can rebuild the house without any sand falls. 

The first line of the input gives the number of test cases $t(t\leq 10)$. And the first line of every test case gives the house's length $n(n\leq 30)$, width $m(m\leq 30)$, and height $h(h\leq 30)$. Then we give you $h$ matrix of size $n*m$, they consist of only upper case letters, showing the house from high to low. The lowest matrix is on the ground. We do not guarantee all points with same letter are connected. 

If you can rebuild the house, you should output how to rebuild the house in every step, and the answer should have the MAX lexicographic order. Otherwise you should only output $-1$.

# Input

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

# Output

```
AB
-1
DCBA
```

# explanation

* for test case 1, there only one posiible answer: 'AB'. Sand will fall if you choose 'B' firstly.
* for test case 2, sand will fall no matter what letter you choose first
* for test case 3, `DBCA` is another possible answer, but it has a smaller lexicographic order than `DCBA`