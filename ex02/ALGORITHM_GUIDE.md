# Ford-Johnson Algorithm Step-by-Step Guide

## Example: Sorting [5, 2, 8, 1, 9, 3, 7]

---

## **STEP 1: Input Processing**
• **Function:** `validateInput()` → `parseInput()`
• **Action:** Check input is valid positive integers
• **Result:** [5, 2, 8, 1, 9, 3, 7]

---

## **STEP 2: Handle Odd Elements**
• **Function:** `fordJohnsonSort()` (beginning)
• **Action:** If odd number of elements, remove last one temporarily
• **Example:** Remove 7 → Working with [5, 2, 8, 1, 9, 3]
• **Store:** oddElement = 7, hasOddElement = true

---

## **STEP 3: Create Pairs**
• **Function:** `fordJohnsonSort()` (pair creation section)
• **Action:** Group adjacent elements into pairs, smaller first
• **Example:** 
  - (5,2) → (2,5)
  - (8,1) → (1,8) 
  - (9,3) → (3,9)
• **Result:** pairs = [(2,5), (1,8), (3,9)]

---

## **STEP 4: Extract Larger Elements**
• **Function:** `fordJohnsonSort()` (recursive section)
• **Action:** Take larger element from each pair
• **Example:** [5, 8, 9]
• **Next:** Sort these recursively using same algorithm

---

## **STEP 5: Recursive Sort**
• **Function:** `fordJohnsonSort()` (called recursively)
• **Action:** Sort the larger elements [5, 8, 9]
• **Sub-steps:** 
  - Pair: (5,8), odd: 9
  - Larger elements: [8]
  - Main chain: [5, 8]
  - Insert: 9 → [5, 8, 9]
• **Result:** [5, 8, 9]

---

## **STEP 6: Reorder Original Pairs**
• **Function:** `fordJohnsonSort()` (pair reordering)
• **Action:** Match original pairs to sorted larger elements
• **Example:** 
  - 5 matches (2,5)
  - 8 matches (1,8)
  - 9 matches (3,9)
• **Result:** pairs = [(2,5), (1,8), (3,9)]

---

## **STEP 7: Build Main Chain**
• **Function:** `fordJohnsonSort()` (main chain creation)
• **Action:** Create initial sorted sequence
• **Steps:**
  - Add first complete pair: [2, 5]
  - Add remaining larger elements: [2, 5, 8, 9]
  - Collect smaller elements: pending = [1, 3]

---

## **STEP 8: Generate Jacobsthal Sequence**
• **Function:** `jacobsthal()`
• **Action:** Calculate optimal insertion order
• **Formula:** J(0)=0, J(1)=1, J(n)=J(n-1)+2×J(n-2)
• **Sequence:** 0, 1, 1, 3, 5, 11, 21, ...
• **Example:** For 2 pending elements → insert order: [1, 0] (indices)

---

## **STEP 9: Insert Pending Elements**
• **Function:** `std::upper_bound()` + `container.insert()`
• **Action:** Insert each pending element using binary search
• **Example:**
  - Insert pending[1] = 3: [2, 5, 8, 9] → [2, 3, 5, 8, 9]
  - Insert pending[0] = 1: [2, 3, 5, 8, 9] → [1, 2, 3, 5, 8, 9]

---

## **STEP 10: Insert Odd Element**
• **Function:** `std::upper_bound()` + `container.insert()`
• **Action:** Insert the temporarily removed odd element
• **Example:** Insert 7: [1, 2, 3, 5, 8, 9] → [1, 2, 3, 5, 7, 8, 9]

---

## **STEP 11: Timing and Output**
• **Functions:** `printBefore()`, `printAfter()`, `printTimings()`
• **Action:** Display results and performance metrics

---

## **Key Functions Summary:**

### **Main Algorithm:**
- `fordJohnsonSort<Container>()` - Core recursive algorithm
- `jacobsthal(int n)` - Generate optimal insertion sequence

### **Input Processing:**
- `validateInput()` - Check input validity
- `parseInput()` - Convert string to numbers

### **Container Operations:**
- `sortList()` - Sort using std::list
- `sortDeque()` - Sort using std::deque

### **Output/Utility:**
- `printBefore()` - Show original sequence
- `printAfter()` - Show sorted sequence  
- `printTimings()` - Show performance metrics
- `compareSorts()` - Verify both containers match

---

## **Why This Works:**
• **Optimal Comparisons:** Jacobsthal sequence minimizes total comparisons
• **Divide & Conquer:** Recursively sort larger elements first
• **Strategic Insertion:** Binary search for efficient placement
• **Mathematical Foundation:** Proven optimal for small datasets (≤30 elements)