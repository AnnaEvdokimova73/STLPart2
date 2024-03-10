#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void uniqueWithSort(std::vector<T>& vec)
{
    std::sort(vec.begin(), vec.end());
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
}

void uniqueWithoutSort(std::vector<int>& vec)
{
    // Изначально избавимся от дубликатов, идущих подряд 
    //auto last = std::unique(vec.begin(), vec.end());
    //vec.erase(last, vec.end());

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        auto el = *it;
        std::vector<int>::iterator indFound = it;
        while (indFound != vec.end())
        {
            indFound = find(it + 1, vec.end(), el);
            if (indFound != vec.end())
            {
                vec.erase(indFound);
            }
        }
    }
}

int main()
{
    std::vector<int> vec{ 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "[IN]:\t";
    for (const auto& el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;

    //uniqueWithoutSort(vec);
    uniqueWithSort(vec);

    std::cout << "[OUT]:\t";
    for (const auto& el : vec)
    {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}
