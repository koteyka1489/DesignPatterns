#pragma once
#include <iostream>
#include <vector>

class UnitFactory
{
public:
    UnitFactory()          = default;
    virtual ~UnitFactory() = default;

    virtual void SpawnUnits() = 0;
};

class RedUnitFactory : public UnitFactory
{
public:
    virtual void SpawnUnits()
    {
        SpawnRedLox();
        SpawnRedPidor();
    }

private:
    void SpawnRedLox() { std::cout << "SpawnRedLox" << std::endl; }
    void SpawnRedPidor() { std::cout << "SpawnRedPidor" << std::endl; }
};

class GreenUnitFactory : public UnitFactory
{
public:
    virtual void SpawnUnits()
    {
        SpawnGreenLox();
        SpawnGreenPidor();
    }

private:
    void SpawnGreenLox() { std::cout << "SpawnGreenLox" << std::endl; }
    void SpawnGreenPidor() { std::cout << "SpawnGreenPidor" << std::endl; }
};

class SpawnFactory
{
public:
    SpawnFactory()
    {
        Factoris.emplace_back(std::make_unique<RedUnitFactory>());
        Factoris.emplace_back(std::make_unique<GreenUnitFactory>());
    }

    void SpawnUnits()
    { 
        for (auto& Factory : Factoris)
        {
            Factory->SpawnUnits();
        }
    }

private:
    std::vector<std::unique_ptr<UnitFactory>> Factoris;
};