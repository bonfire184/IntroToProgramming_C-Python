#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H
#include <iostream>


struct DataFromSave{
    int wood;
    std::string typeOfCart;
    int traps;
    int huts;
    bool tradepost;
    bool lodge;
    bool workshop;
    int day;
    int villagers;
    int maxCapacity;
};

class GameFunctions
{
    public:
        GameFunctions();
        ~GameFunctions();
        void PrintDay();
        void Village();
        void Builder();
        void Merchant();
        void Workshop();
        void Reset();
        void EndDay();
        void AddInfo(DataFromSave rand);

    protected:

    private:
        DataFromSave data;
};
#endif // GAMEFUNCTIONS_H
