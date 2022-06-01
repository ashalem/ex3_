//
// Created by Eden_Strugo on 29/05/2022.
//

#include "HealthPoints.h"


HealthPoints::InvalidArgument::InvalidArgument(int invalidHealth): m_invalidHealth(invalidHealth) {}

HealthPoints::HealthPoints(const int maxHp): m_maxhp(maxHp), m_hp(maxHp)
 {
     if(maxHp <= 0){
         throw InvalidArgument(maxHp);
     }
}

//######################arithmetic operators######################//


int HealthPoints::getInBounds(const int changedHealth){

    if (changedHealth >= this->m_maxhp){
        return this->m_maxhp;
    }
    
    if (changedHealth <= 0){
        return 0;
    }
    
    return changedHealth;
}
  
HealthPoints& HealthPoints::operator+=(const int addHealth){
    int addedHealth = this->m_hp + addHealth; 
    this->m_hp = this->getInBounds(addedHealth);

    return *this;
}

HealthPoints operator+(const HealthPoints& hp1, const int addHealth){
    HealthPoints result = hp1;
    result += addHealth; 
    return result;
}

HealthPoints operator+(const int addHealth, const HealthPoints& hp1){
    return hp1 + addHealth;
}

HealthPoints& HealthPoints::operator-=(const int subHealth){
    int subtractedHealth = this->m_hp - subHealth;
    this->m_hp = this->getInBounds(subtractedHealth);

    return *this;
}

HealthPoints operator-(const HealthPoints& hp1, const int subHealth){
    HealthPoints result = hp1;
    result -= subHealth; 
    return result;
}

HealthPoints operator-(const int subHealth, const HealthPoints& hp1){
    return hp1 - subHealth;
}


//######################boolian operators######################//

bool operator==(const HealthPoints& hp1, const HealthPoints& hp2){
    return hp1.m_hp == hp2.m_hp;
}

bool operator<(const HealthPoints& hp1, const HealthPoints& hp2){
    return hp1.m_hp < hp2.m_hp;
}

bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2){
    return !(hp1 == hp2);
}

bool operator>(const HealthPoints& hp1, const HealthPoints& hp2){
    return !(hp1 == hp2 || hp1 < hp2);
}

bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2){
    return hp1 == hp2 || hp1 < hp2;
}

bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2){
    return hp1 == hp2 || hp1 > hp2;
}

//######################print operators######################//

ostream& operator<<(ostream& os, const HealthPoints& hp) {
    os << hp.m_hp << '(' << hp.m_maxhp << ')';
    return os;
}

