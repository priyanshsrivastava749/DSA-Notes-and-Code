# 96. Unique Binary Search Trees — Detailed Explanation

## 🔥 Problem Statement
Tumhe ek integer **n** diya hai. Tumhe batana hai ki **1 se n** tak unique values se kitne **structurally unique BSTs (Binary Search Trees)** ban sakte hain.

### Example se samjho:

**Example 1:** `n = 3`, Output: `5`
**Example 2:** `n = 1`, Output: `1`

**Constraints:** `1 <= n <= 19`

---

## 🌳 BST ki Property (Yaad rakho!)
BST mein har node ke liye:
- **Left subtree** ke saare nodes **chhote** honge root se
- **Right subtree** ke saare nodes **bade** honge root se

---

## 🧠 Intuition — Har node ko root banao aur socho!

Maan lo humein `n = 3` ke liye solve karna hai, yani nodes: `{1, 2, 3}`

**Key Idea:** Hum ek ek karke har node ko **root** bana dete hain, phir dekhte hain ki left mein kitne nodes bache aur right mein kitne.

### Jab Root = 1:
```
     1
      \
    {2,3}  ← 2 nodes right mein → f(2) tarike se BST banega
```
Left mein **0** nodes → `f(0) = 1` (khaali tree bhi ek valid tree hai!)
Right mein **2** nodes → `f(2) = 2`
**Total BSTs = f(0) × f(2) = 1 × 2 = 2**

### Jab Root = 2:
```
     2
    / \
  {1} {3}  ← 1 node left, 1 node right
```
Left mein **1** node → `f(1) = 1`
Right mein **1** node → `f(1) = 1`
**Total BSTs = f(1) × f(1) = 1 × 1 = 1**

### Jab Root = 3:
```
     3
    /
  {1,2}  ← 2 nodes left mein → f(2) tarike se BST banega
```
Left mein **2** nodes → `f(2) = 2`
Right mein **0** nodes → `f(0) = 1`
**Total BSTs = f(2) × f(0) = 2 × 1 = 2**

### Final Answer for n = 3:
> **f(3) = 2 + 1 + 2 = 5** ✅

---

## 📐 Recurrence Relation (Formula)

Jab hum **k** ko root banate hain (jahan `1 ≤ k ≤ n`):
- Left subtree mein **(k - 1)** nodes hain
- Right subtree mein **(n - k)** nodes hain

Toh formula banta hai:

```
f(n) = Σ (k=1 to n) f(k-1) × f(n-k)
```

### Base Cases:
- `f(0) = 1` → Khaali tree bhi valid hai (1 tarika)
- `f(1) = 1` → Sirf ek node, ek hi BST banta hai
- `f(2) = 2` → Do arrangements possible hain

---

## 📊 Pura Recursion Tree for n=3 (Visualization)

```
                        f(3)
                    /    |    \
               k=1      k=2      k=3
              /    \    /   \    /    \
           f(0)  f(2) f(1) f(1) f(2)  f(0)
            1   / \    1     1  / \     1
              k=1 k=2       k=1  k=2
             / \  / \       / \   / \
           f(0) f(1) f(1) f(0) f(0) f(1) f(1) f(0)
            1    1    1    1    1    1    1    1

f(2) = f(0)×f(1) + f(1)×f(0) = 1×1 + 1×1 = 2
f(3) = f(0)×f(2) + f(1)×f(1) + f(2)×f(0) 
     = 1×2 + 1×1 + 2×1 = 5
```

---

## 🌲 All 5 BSTs for n=3 (Visual Figure)

```
  1          1         2         3        3
   \          \       / \       /        /
    2          3     1   3     1        2
     \        /               \       /
      3      2                 2     1
```

**Tree 1:** Root=1, Right=2, Right=3
**Tree 2:** Root=1, Right=3, Left=2
**Tree 3:** Root=2, Left=1, Right=3
**Tree 4:** Root=3, Left=1, Right=2
**Tree 5:** Root=3, Left=2, Left=1

---

## 🔢 Catalan Numbers — Ye formula actually famous hai!

Ye problem internally **Catalan Number** nikalta hai! Nth Catalan number:

```
C(n) = C(2n, n) / (n+1)  ya  Σ C(i-1) × C(n-i) for i=1 to n
```

| n | f(n) | Catalan Number |
|---|------|---------------|
| 0 |  1   |     C₀ = 1    |
| 1 |  1   |     C₁ = 1    |
| 2 |  2   |     C₂ = 2    |
| 3 |  5   |     C₃ = 5    |
| 4 | 14   |     C₄ = 14   |
| 5 | 42   |     C₅ = 42   |

---

## 🚀 Code Explanation (Top-Down DP with Memoization)

```cpp
class Solution {
public:
    int f(int n, vector<int>& dp) {
        // Base cases
        if (n == 0 or n == 1) return 1;  // Khaali ya 1 node → 1 BST
        if (n == 2) return 2;             // 2 nodes → 2 BSTs

        // Agar pehle se solve kiya hai toh return karo
        if (dp[n] != -1) return dp[n];

        int sum = 0;
        // Har node ko root banao (1 se n tak)
        for (int k = 1; k <= n; k++) {
            // Left subtree (k-1 nodes) × Right subtree (n-k nodes)
            sum += f(k-1, dp) * f(n-k, dp);
        }

        return dp[n] = sum;  // Memoize karke return
    }

    int numTrees(int n) {
        vector<int> dp(21, -1);  // n max 19 hai, so 21 enough
        return f(n, dp);
    }
};
```

### Step-by-Step Dry Run for n=3:

| Call | k | f(k-1) | f(n-k) | Product | Running Sum |
|------|---|--------|--------|---------|-------------|
| f(3) | 1 | f(0)=1 | f(2)=2 | 2       | 2           |
| f(3) | 2 | f(1)=1 | f(1)=1 | 1       | 3           |
| f(3) | 3 | f(2)=2 | f(0)=1 | 2       | **5**       |

---

## ⏱️ Time & Space Complexity

| Approach        | Time         | Space    |
|----------------|-------------|----------|
| Brute Recursion | O(3ⁿ)       | O(n) stack |
| Top-Down DP     | **O(n²)**   | O(n)     |
| Bottom-Up DP    | **O(n²)**   | O(n)     |
| Catalan Formula | **O(n)**    | O(1)     |

Humara code **Top-Down DP** use karta hai → `O(n²)` time mein solve hota hai. Without memoization exponential hota!

---

## 💡 Key Takeaways

1. **BST structure depends on COUNT, not VALUES** — `f(3)` same rahega chahe nodes `{1,2,3}` ho ya `{5,6,7}`
2. **Multiply left × right** kyunki har left arrangement har right arrangement ke saath combine ho sakta hai
3. **Memoization zaruri hai** — Bina DP ke same subproblems baar baar solve honge → TLE!
4. **Catalan Number** — Ye ek classic formula hai, yaad rakhna exam mein kaam aayega!

---

Agar ye notes samajh aa gaye toh BST counting type ke saare problems aasaan ho jayenge! 🤘
