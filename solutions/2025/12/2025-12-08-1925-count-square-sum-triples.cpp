class Solution {
    public:
    /**
    * Count the number of Pythagorean triples (a, b, c) where:
    * - 1 <= a, b, c <= n
    * - a^2 + b^2 = c^2
    *
    * @param n The upper bound for triple values
    * @return The count of valid Pythagorean triples
    */
    int countTriples(int n) {
        int count = 0;

        for (int a = 1; a < n; ++a) {

            for (int b = 1; b < n; ++b) {

                int sumOfSquares = a * a + b * b;

                int c = static_cast<int>(sqrt(sumOfSquares));

                if (c <= n && c * c == sumOfSquares) {
                    ++count;
                }
            }
        }

        return count;
    }
};