#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <unordered_map>

// void printVec(const std::vector<int> &v)
// {
//     for (int x : v)
//     {
//         printf("%i\n", x);
//     }
// }

int calcTotalDist(const std::vector<int> &v1, const std::vector<int> &v2)
{
    std::vector<int> v1Copy = v1;
    std::vector<int> v2Copy = v2;
    std::sort(v1Copy.begin(), v1Copy.end());
    std::sort(v2Copy.begin(), v2Copy.end());

    int dist = 0;
    for (int i = 0; i < v1Copy.size(); i++)
    {
        dist += abs(v1Copy[i] - v2Copy[i]);
    }

    return dist;
}

int calcSimilarityScore(const std::vector<int> &v1, const std::vector<int> &v2)
{
    std::unordered_map<int, int> freq;
    for (int x : v2)
    {
        freq[x]++;
    }

    int score = 0;
    for (int x : v1)
    {
        if (freq.find(x) != freq.end())
        {
            score += x * freq[x];
        }
    }

    return score;
}

int main()
{
    std::ifstream infile("inputs/1.txt");

    std::vector<int> lhs;
    std::vector<int> rhs;

    if (infile.is_open())
    {
        std::string line;
        while (std::getline(infile, line))
        {
            std::istringstream iss(line);

            int a, b;
            iss >> a >> b;
            lhs.push_back(a);
            rhs.push_back(b);
        }
    }

    // printVec(lhs);
    // printVec(rhs);

    infile.close();

    /* -- PART 1 -- */
    printf("%i\n", calcTotalDist(lhs, rhs));

    /* -- PART 2 -- */
    printf("%i\n", calcSimilarityScore(lhs, rhs));

    return 0;
}