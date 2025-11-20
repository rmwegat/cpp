// How It Works (Simple Version)
// Think of it like organizing a deck of cards in the most efficient way:

// Step 1: Pair Up Elements
// Take your unsorted list and pair up adjacent elements
// Compare each pair and put the smaller one first
// Example: [5, 2, 8, 1, 9, 3] becomes pairs [(2,5), (1,8), (3,9)]
// Step 2: Sort the Winners
// Take the larger element from each pair (the "winners": 5, 8, 9)
// Sort these winners recursively using the same algorithm
// This gives you: [5, 8, 9]
// Step 3: Insert the Losers Strategically
// Now you have the "losers" to insert: [2, 1, 3]
// Insert them one by one using binary search to find the best position
// The key insight: you already know some relationships, so you don't need to compare everything
// Real-World Analogy
// Imagine you're a teacher organizing students by height:

// Pair students: Have them stand in pairs, shorter in front
// Sort the tall ones: Line up all the taller students from shortest to tallest
// Smart insertion: Now insert each shorter student, 
// but you already know they're shorter than their original partner, so you don't need to check everyone

// Why It's "Optimal"
// For small lists (up to about 20-30 elements), Ford-Johnson uses the theoretical minimum number of comparisons.
// It's mathematically proven to be optimal for small inputs.

// ✅ Pros: Minimum comparisons, optimal for small lists
// ❌ Cons: Complex to implement, slower overall due to overhead, not great for large lists