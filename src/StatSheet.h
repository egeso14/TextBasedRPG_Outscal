#pragma once
#include "PlayerClasses.h"
#include "EnemySpecies.h"
#include "Stats.h"

struct StatSheet {
    // Constructor for Player Classes
    StatSheet(PlayerClasses classChoice) {
        level = 1;
        InitializeStats(classChoice);
    }

    // Constructor for Enemy Species
    StatSheet(EnemySpecies enemyType) {
        level = 1;
        InitializeStats(enemyType);
    }

    int level;

    float baseAtk;
    float baseDef;
    float baseHP;

    float currentAtk;
    float currentDef;
    float currentHP;

    float currentMaxHP;
    float currentMaxAtk;
    float currentMaxDef;

    // Function to retrieve stat values
    float GetStat(Stats stat) const {
        switch (stat) {
        case Stats::HP:
            return currentHP;
        case Stats::Attack:
            return currentAtk;
        case Stats::Defense:
            return currentDef;
        default:
            return 0;
        }
    }

    // Restores all stats to their maximum values
    void RestoreToMax() {
        currentAtk = currentMaxAtk;
        currentDef = currentMaxDef;
        currentHP = currentMaxHP;
    }

    float GetMaxStat(Stats stat) const
    {
        switch (stat) {
        case Stats::HP:
            return currentMaxHP;
        case Stats::Attack:
            return currentMaxAtk;
        case Stats::Defense:
            return currentMaxDef;
        default:
            return 0;
        }
    }

private:
    // **Helper Function to Initialize Stats for Players**
    void InitializeStats(PlayerClasses classChoice) {
        switch (classChoice) {
        case PlayerClasses::Warrior:
            SetStats(25, 10, 30);
            break;
        case PlayerClasses::Wizard:
            SetStats(15, 15, 25);
            break;
        case PlayerClasses::Archer:
            SetStats(20, 10, 25);
            break;
        case PlayerClasses::Paladin:
            SetStats(10, 25, 30);
            break;
        }
    }

    // **Helper Function to Initialize Stats for Enemies**
    void InitializeStats(EnemySpecies enemyType) {
        switch (enemyType) {
        case EnemySpecies::Slime:
            SetStats(5, 5, 25);
            break;
        case EnemySpecies::Skeleton:
            SetStats(15, 10, 15);
            break;
        case EnemySpecies::Troll:
            SetStats(10, 10, 20);
            break;
        case EnemySpecies::Vulture:
            SetStats(10, 20, 15);
            break;
        case EnemySpecies::Mercenary:
            SetStats(15, 15, 20);
            break;
        }
    }

    // **Sets All Stats to Their Initial Values**
    void SetStats(float atk, float def, float hp) {
        baseAtk = currentAtk = currentMaxAtk = atk;
        baseDef = currentDef = currentMaxDef = def;
        baseHP = currentHP = currentMaxHP = hp;
    }
};