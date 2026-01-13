*This activity has been created as part of the 42 curriculum by yafranco and jfoeller.*
================================================================================
PROJECT: PUSH_SWAP
================================================================================

[DESCRIPTION]
Push_swap is a 42 algorithmic project that challenges us to sort data on a
stack, with a limited set of instructions, using the lowest possible number
of actions. The goal is to manipulate various types of algorithms and choose
the most appropriate solution for optimized data sorting based on algorithmic
complexity constraints.

================================================================================
INSTRUCTIONS
================================================================================

[COMPILATION]
Use the Makefile to compile the project. It ensures no memory leaks and
strictly follows the project norms.

    > make

[EXECUTION]
Run the program with a list of integers as arguments:

    > ./push_swap 4 67 3 87 23

[STRATEGY SELECTION (FLAGS)]
Our program implements 4 specific strategies as required by the subject.
You can force a strategy using flags:

    --simple    : Forces O(n^2) algorithm (Selection/Insertion sort).
    --medium    : Forces O(n*sqrt(n)) algorithm (Chunk Sort).
    --complex   : Forces O(n log n) algorithm (Radix Sort).
    --adaptive  : (Default) Automatically selects the best strategy based
                  on the input size and disorder metric.

[BENCHMARK MODE]
We implemented a custom benchmark feature to analyze performance and disorder.
Output is sent to stderr to avoid interfering with the checker.

    > ./push_swap --bench 4 67 3 87 23

================================================================================
ALGORITHMS & TECHNICAL CHOICES
================================================================================

[DATA STRUCTURE: CIRCULAR BUFFER]
Instead of using standard linked lists, we implemented a Circular Buffer
(array-based stack).
- Why? Better cache locality (performance), simpler index management for
  rotations, and no overhead from repeated malloc/free during push/pop operations.

1. SIMPLE STRATEGY (O(n^2))
   - Technique: Selection Sort.
   - Logic: Finds the minimum element in stack A, rotates it to the top,
     and pushes to B. Repeats until A is sorted.
   - Usage: Used for very small inputs (N <= 5).

2. MEDIUM STRATEGY (O(n*sqrt(n)))
   - Technique: Optimized Chunk Sort.
   - Logic:
     1. The sorted range is divided into X chunks (determined dynamically,
        e.g., ~53 for 500 numbers).
     2. Elements belonging to the current chunk are pushed from A to B.
     3. Optimization: A "Double-Sight" check looks at both the top and
        bottom of stack A to minimize rotations (ra vs rra).
     4. Once A is empty, elements are pushed back from B to A, ensuring
        the maximum is always on top.

3. COMPLEX STRATEGY (O(n log n))
   - Technique: Radix Sort (Base 2 / Binary).
   - Logic: Sorts numbers by processing their binary representation bit by bit.
     It requires a constant number of passes relative to the number of bits
     (32 max), ensuring linear complexity O(k * n).

4. ADAPTIVE STRATEGY
   - Logic: Before sorting, the program calculates a Disorder Metric (0.0 to 1.0).
     - If the list is nearly sorted (< 10% disorder), it uses the Complex
       strategy (Radix) as it is stable.
     - For random or reverse-sorted lists, it defaults to the Medium strategy
       (Chunk Sort), which we optimized to beat the "Excellent" score thresholds.

================================================================================
CONTRIBUTORS
================================================================================
- jfoeller aka jerem aka Jeremy Foeller
- yafranco aka yanouchka aka Yann Francois

Both members contributed to the architecture, algorithm implementation, and debugging.

================================================================================
RESOURCES & AI USAGE
================================================================================

[RESOURCES]
- Introduction to Algorithms (Cormen et al.) for complexity analysis.
- Wikipedia: Radix Sort and Circular Buffers.

[AI USAGE DECLARATION]
As permitted by the subject, AI assistance was used for the following specific tasks:
- Debugging: Identifying logic errors in the sort_three function and the
  b_to_a return logic.
- Optimization: Fine-tuning the chunk_size constant (testing values 45, 50, 53)
  to achieve the target of < 5500 operations.
- Code Structure: Helping design the Circular Buffer structure to replace
  linked lists.
- Documentation: Generating the structure of this README file to ensure
  compliance with the subject requirements.

All code logic was reviewed, understood, and tested by the group members.