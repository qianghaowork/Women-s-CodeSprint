##1. Even Training

Maria loves playing soccer. Because she wants to play professionally when she grows up, she tracks her training by marking her calendar with a 1 on the days that she trained, and a 0 on the days she did not. She also loves math, and wants your help connecting her soccer training with what she's learning about even and odd numbers in school.

Given n days of Maria's calendar history, print whether or not she trained for an even number of days (either Yes or No), followed by the total number of days she trained.

Note: Code demonstrating how to read input from stdin is provided in your editor.

Input Format

The first line contains an integer, n, denoting the number of days Maria tracked in her calendar.
The next line contains n space-separated integers describing whether or not Maria trained each day. Recall that the number 1 indicates that she did train, and 0 indicates she did not.

Constraints

1<= n <= 10^5

Output Format

Your output should consist of 2 space-separated values on a single line. For the first value, you should print Yes if Maria trained for an even number of days or No if she did not. For the second value, you should print a single integer denoting the total number of days Maria trained.

Sample Input 0

4

1 1 0 0  

Sample Output 0

Yes 2

Sample Input 1

4

1 0 1 1

Sample Output 1

No 3

Explanation

Sample 0:
n=4, calendar = "1 1 0 0"
Maria trained on 2 days; because this is an even number, we print Yes 2.

Sample 1:
n=4, calendar = "1 0 1 1"
Maria trained on 3 days; because this is an odd number, we print No 3. 

##2. Consonant Reversal

Ritika gives N strings to Semona and asks her to perform a consonant reversal on each string S such that the indexed positions of its vowels (a, e, i, o, and u) are unchanged but all the consonants are reversed. This means that each vowel must be at the same exact index before and after the reversal. Because the value of N is very large, Semona wants your help accomplishing this with code!

Given N strings, reverse and print each string such that the positions of its vowels remain unchanged but all its consonants are reversed.

Input Format

The first line contains an integer, N, the number of strings.
Each of the N subsequent lines contains a string, S, to be reversed.

Constraints

    1<= N <= 1000
    1<= Si <= 2000, where 0<= i < N
    Each string contains lowercase letters.

Output Format

For each string S received as input, print the consonant reversal of S on a new line.

Sample Input

2

abcde

eabafgs

Sample Output

adcbe

easagfb

Explanation

N = 2
S0 = "abcde"
This string has 2 vowels that must stay in place: the a at index 0 and the e at index 4. We reverse only the consonants (leaving the vowels in place), and print the result (adcbe) on a new line.

S1 = "eabafgs"
This string has 3 vowels that must stay in place (at indices 0, 1, and 3). We reverse only the consonants (leaving the vowels in place), and print the result (easagfb) on a new line.

##3. Secret Message Groups

Doreen is trying to decode a message in the form of N strings, where each string is composed of numeric characters. To do so, she must take each string i (where 0<=i<n) and put it into a group such that every string in each group has the same frequency of 0-9 digits as every other string within that same group. If the message contains 2 or more instances of the same exact string, she must keep 1 instance of that string and get rid of its duplicates.

Given N messages, Doreen wants you to do 2 things:

    Find G,the number of groups that she can form and print it on a new line.
    Let M be the size of the largest possible group; print all groups having M elements in the following order:
        The strings within each group must be in descending order, printed as a single line of space-separated values.
        If there are 2 or more groups of size M, then each group must be printed in ascending order, meaning you should print them lexicographically as if they were letters. An example of lexicographically ordered numeric characters would be 1 < 11 < 111 < 2.

Note: To compare two groups G1 and G2 lexicographically, compare the elements from left to right and take the first element that doesn't match. Let the elements be e1 and e2. Now make lexicographical comparision between e1 and e2. If is lexicographically smaller than e2, then the group G1 is also smaller than G2.

Input Format

The first line contains N, the number of coded strings.
Each of N the subsequent lines contains a string, Si (where 1<i<N).

Constraints

    1<= N <= 2x10^4, 
    1<= |Si| <= 2000, where 1<=i<=N

Output Format

Print the value of G, the number of groups formed, as your first line of output.
For each subsequent line of output you must print the groups in lexicographical order, where each M-element group is a single line of space-separated elements in descending order.

Note: Each group must be printed on a new line, and the elements of each group must be a single line of space-separated values. Your groups must not contain duplicate strings.

Sample Input 0

11

133

213

312

331

313

123

133

24

56

5

331

Sample Output 0

5

312 213 123

331 313 133

Sample Input 1

4

1

3

10

33

Sample Output 1

4

1

10

3

33

Explanation

Sample 0:

There are 5 groups:
G1 = {133, 331, 313} has one 1 and two 3s.
G2 = {213, 312, 123} has one 1, one 2, and one 3.
G3 = {24} has one 2 and one 4.
G4 = {56} has one 5 and one 6.
G5 = {5} has one 5.
The maximum size, M, of these groups is 3, and we have two groups meeting that criteria ( G1 and G2). When we sort these two groups in descending order, we get G1 = {331, 313, 133} and G2 = {312, 213, 123}.
Because G2 is lexicographically smaller than G1, we print the contents of G2 on our first line, and the contents of G1 on our second line.

Sample 1:

There are 4 groups:
G1 = {1} has one 1.
G2 = {3} has one 3.
G3 = {10} has one 1 and one 0.
G4 = {33} has two 3s.
The maximum size, M, of these groups is 1, so every group will be printed in our output, and a group of 1 element is already sorted with respect to itself. The lexicographic order is G1 < G3 < G2 < G4, so we print the contents of each of those respective groups as a new line. 

##4. Annual Car Race

Naruto is participating in Hidden Leaf village's Annual Car Race. There are N connected dragstrips in the village.

Each participant would be given the IDs of the source stop, S, the destination stop, D, and a map of bidirectional (undirected) roads connecting different stops in Hidden leaf village. Generally speaking, most participants use shortest-distance paths to reach the destination; because of this, there is traffic included in these paths which slows down the participants.

Naruto won the race last year by using one of the second shortest-distance paths to reach the destination; however, he can't use the same trick again this year as 50% of the participants are also planning to use the second shortest-distance path during the race.

Naruto realizes that the only way to win the contest is to use one of the third shortest-distance paths. Help him find the total distance he must travel to reach the destination using one of the third shortest-distance paths; if no such third shortest-distance path exists, print -1.

Note:

    If a road belongs to any one of 1st the shortest paths, that road mustn't be a part of 2nd or 3rd shortest path.

    If a road belongs to any one of the 2nd shortest paths, that road also mustn't be a part of the 3rd shortest path.

Input Format

The first line contains a single integer, T, denoting the number of test cases.
The second line contains 2 space-separated integers, N (the number of stops) and M (the number of roads between stops), respectively.
The third line contains 2 space-separated integers, S (the source, or starting point) and D (the destination, or finish point), respectively. The M subsequent lines each contain 3 space-separated integers: u, v, and dist, where dist denotes the distance between stop u and stop v.

Note: All stops are connected by undirected roads.

Constraints

1<= T <= 10
5<= N <= 500
N<= M <= Nx(N-1)/2
0<= S < N
0<= D < N
1<= dist <= 50000

Output Format

Print the total distance Naruto must travel to reach the finish line if he chooses to use one of the third shortest-distance paths; if there is no third shortest-distance path, print -1.

Sample Input

1

7 9

0 6

0 1 1

0 2 1

0 3 2

0 4 3

1 5 2

2 6 4

3 6 2

4 6 4

5 6 1

Sample Output

7

##5. Veronica Mars and the Binary Search Tree

With the help of Mac, Veronica Mars just came up with a new way of numbering Binary Search Tree(BST) nodes! She assigns the number 1 to the root node, and any node indexed as i will have a left child indexed as 2i and a right child indexed as 2i+1.

           1
          / \
         /   \
        /     \
       /       \
      2         3
     / \       / \
    /   \     /   \
   4     5   6     7

   and so on...

Veronica tells this new numbering scheme to her dad, Keith, and and then inserts n distinct numbers, a0, a1, .... a(n-1), into a BST in increasing order of indices. Because he's better at hitting bad guys than hitting books, Keith promptly forgets the numbering scheme and asks for your help!

For each number ai, print the index of the node where it's located in the BST. See the Explanation section for more detail.

Input Format

The first line contains a single integer, n, denoting the number of nodes in the tree.
The second line contains n space-separated integers describing the respective integer elements, a0 through a(n-1).

Constraints
   1<= ai <= 10^9

   1<= n <= 1000 for 30% of the test cases.
   1<= n <= 3x10^5  for 100% of the test cases.

Output Format

Print a single line of n space-separated integers where the ith number denotes the node index where number ai is present in the BST. As these numbers may be large, output them modulo 10^9+7.

Sample Input 0

4

5 3 6 2

Sample Output 0

1 2 3 4

Sample Input 1

3

1 2 3

Sample Output 1

1 3 7

Explanation

Sample Case 0:

The BST formed is:

     5(1)
    / \
   /   \
  3(2)  6(3)
 /
2(4)

* The node indices are written in parentheses.

Sample Case 1:
The BST formed is

1(1)
 \
  \
   2(3)
    \
     \
      3(7)

* The node indices are written in parentheses.

##6. Smriti and the Strings

Smriti is learning about strings in school and asks her best friend, Stephanie, to give her a practice problem.

Stephanie gives Smriti a string S of length n, and a positive integer m (where m<n). Smriti must delete exactly m characters from the String such that the resultant string is lexicographically largest (last when ordered alphabetically). Solve the challenge along with Smriti so she can check her answer!

Input Format

The first line contains an integer, T, the number of test cases.
Each of the T subsequent lines of test cases contains 2 space-separated values: a string, S, followed by an integer, m.

Constraints

    
   1<= T <= 1000
   1<= N <= 10^6
   1<= Sum(ni) <= 10^7, where ni is the length of the ith string.
   1<= m < n
   All strings contain only lowercase letters.

Output Format

For each line of the T test cases (where 0<=i<T), print the lexicographically largest string that can be formed by deleting mi characters from Si on a new line.

Sample Input

2

abcde 2

dcabe 2

Sample Output

cde

dce

Explanation

Test Case 0:
S0 = "abcde", m = 2
We delete the first 2 characters to get cde, the lexicographically largest possible string.

Test Case 1:
S1 = "dcabe", m = 2 
We delete the 3rd and 4th characters to get "dce", the lexicographically largest possible string.

