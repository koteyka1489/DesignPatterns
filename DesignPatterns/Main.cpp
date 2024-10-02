#include "UnitFactory.h"
#include <Vector>
#include <algorithm>
#include <iostream>

int main()
{
    // SpawnFactory Factory;
    // Factory.SpawnUnits();

    class Solution
    {
    public:
        std::vector<int> arrayRankTransform(std::vector<int>& arr)
        {
            std::vector<int> SortArr = arr;
            std::sort(SortArr.begin(), SortArr.end());

            std::vector<int> Result = arr;

            int DublicateNumbers = 0;
            int PrevNumber       = -1000000000;
            bool ThisNumberDublicate = false;

            for (int i = 0; i < SortArr.size(); i++)
            {
                if (SortArr[i] == PrevNumber)
                {
                    DublicateNumbers++;
                    ThisNumberDublicate = true;
                }
                PrevNumber                     = SortArr[i]; 

                auto ItSortNumberInUnsortArray = std::find(arr.begin(), arr.end(), SortArr[i]);
                int IndexInUnsortArray         = std::distance(arr.begin(), ItSortNumberInUnsortArray);

                if (ThisNumberDublicate)
                {
                    IndexInUnsortArray += DublicateNumbers;
                }

                Result[IndexInUnsortArray] = i + 1 - DublicateNumbers;

                ThisNumberDublicate = false;
            }
     

            return Result;
        }
    };


    Solution Sol;
    std::vector<int> test{37, 12, 28, 9, 100, 56, 80, 5, 12};

    Sol.arrayRankTransform(test);

    return 0;
}
