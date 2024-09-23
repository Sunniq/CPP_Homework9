#include <iostream>

class Building {

private:

    int Id;

    int CurrentAge = 0;

    int MaxAge;

    int InitialCost;

    //std::string Owner;

    static int Counter;

public:

    Building(int InMaxAge, int InInitialCost);

    //void SetOwner(std::string NewOwner);

    //std::string GetOwner() const;

    int GetID() const;

    void PrintCost() const;

    int GetCost() const;

    void ToAge(int Years);

private:

    void Destroy();

};

int Building::Counter = 0;

Building::Building(int InMaxAge, int InInitialCost) {
    Id = ++Counter;
    MaxAge = InMaxAge;
    InitialCost = InInitialCost;
}

int Building::GetID() const {
    return Id;
}

void Building::PrintCost() const {
    std::cout << "Building with ID == " << Id << " cost == " << GetCost() << std::endl;
}

int Building::GetCost() const {
    return (InitialCost * (1 - float(CurrentAge) / float(MaxAge)));
}

void Building::ToAge(int Years) {
    CurrentAge += Years;

    if (CurrentAge > MaxAge) {
        Destroy();
    }
}

void Building::Destroy() {
    std::cout << "Building with ID == " << Id << " was destroyed!\n";
}

//void Building::SetOwner(std::string NewOwner) {
//    Owner = NewOwner;
//}

//std::string Building::GetOwner() const {
//    return Owner;
//}

int main() {
    Building Building_1(20, 10);
    Building Building_2(100, 1000);

    //Building_1.SetOwner("Sasha");
    //std::cout << Building_1.GetOwner() << std::endl;
    Building_2.ToAge(50);
    Building_2.PrintCost();
    Building_2.ToAge(25);
    Building_2.PrintCost();

    Building_1.ToAge(21);
    Building_2.ToAge(101);

    return 0;
}
