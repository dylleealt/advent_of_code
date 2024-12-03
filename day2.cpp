#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

bool invalidDiff(int d, bool decr)
{
    return abs(d) < 1 || abs(d) > 3 || (decr && d > 0) || (!decr && d < 0);
}

int validateReport(std::vector<int> &report)
{
    if (report.size() == 1)
    {
        return true;
    }

    bool valid = true;
    bool decr = (report[1] - report[0]) < 0;
    for (int i = 1; i < report.size(); i++)
    {
        if (invalidDiff(report[i] - report[i - 1], decr))
        {
            valid = false;
            break;
        }
    }

    return valid;
}

int main()
{
    std::ifstream infile("inputs/2.txt");

    int count = 0;
    if (infile.is_open())
    {
        std::string line;
        while (std::getline(infile, line))
        {
            std::istringstream iss(line);
            std::string token;
            std::vector<int> report;
            while (iss >> token)
            {
                report.push_back(stoi(token));
            }
            bool valid = validateReport(report);
            if (valid)
            {
                count++;
            }
            else
            {
                for (int i = 0; i < report.size(); i++)
                {
                    std::vector<int> copy = report;
                    copy.erase(copy.begin() + i);
                    if (validateReport(copy))
                    {
                        count++;
                        break;
                    }
                }
            }
        }
    }
    infile.close();
    printf("%i\n", count);
    return 0;
}