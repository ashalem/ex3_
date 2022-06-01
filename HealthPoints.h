//
// Created by Eden_Strugo on 29/05/2022.
//

#ifndef EX3_HealthPoints_H
#define EX3_HealthPoints_H
#include <iostream>
#include <stdbool.h>
using std::ostream;
using std::endl;


#define DEFAULT_MAX_HP (100)

class HealthPoints {
public:

    /*
     * C'tor of HealthPoints (HP):
     *
     * @param maxHealth - The max hp of player.
     * @param currentHealth - The current hp of player.
     * @result
     *      An instance of HealthPoints
    */
    HealthPoints(const int maxHealth = DEFAULT_MAX_HP);

    /*
     *  plusEqual (+=) operator for adding an integer to the current HealthPoints object.
     * Gets an integer to add on.
     *
     *  @return
     *          The current HealthPoints object.
     */   
    HealthPoints& operator+=(const int addHealth);

    /*
     * minusEqual (-=) operator for suntracting an integer from current HealthPoints object.
     * Gets an integer to substract from.
     *
     *  @return
     *          The current HealthPoints object.
     */
    HealthPoints& operator-=(const int subHealth);

    /*
     *  isEqual(==) operator for comepring two HealthPoints objects.
     *
     *  @return
     *          True if the object are alike and False otherwise.
     */
    friend bool operator==(const HealthPoints& hp1, const HealthPoints& hp2);

    /*
     * isSmaller (<) operator for comepring two HealthPoints objects.
     *
     *  @return
     *          True if the right object is bigger than the left and False otherwise.
     */
    friend bool operator<(const HealthPoints& hp1, const HealthPoints& hp2);

    /*
     *  outputStream (<<) operator printing instances of HealthPoints objects.
     *
     *  @return
     *          ostream object and prints the HealthPoints object in the right format.
     */
    friend ostream& operator<<(ostream& os, const HealthPoints& hp);     

    ~HealthPoints() = default;
    HealthPoints(const HealthPoints& other) = default;
    HealthPoints& operator=(const HealthPoints& other) = default;


    //Inside class for exceptions related to the number of HealthPoints passed by the Player.
     /*
      *  Gets the Invalid health points argument that was passed by the player (0 or negative number).:
      *
      *  @return
      *          An instance of InvalidArgument
      */
     class InvalidArgument{
     public:
         int m_invalidHealth;
         InvalidArgument(int invalidHealth);
     };
     

private:

    int getInBounds(const int changedHealth);
    
    int m_maxhp;
    int m_hp;
};


    /*
     *  addHealth (HealthPoints + int) operator for adding Healthpoints to HealthPoints object.
     * Gets an integer and an HealthPoints Object.
     *
     *  @return
     *          An isnstance of the added number.
     */
    HealthPoints operator+(const HealthPoints& hp1, const int addHealth);

    /*
     *  addHealth (int + HealthPoints) operator for adding Healthpoints to HealthPoints object.
     * Gets an integer and an HealthPoints Object.
     *
     *  @return
     *          An isnstance of the added number.
     */
    HealthPoints operator+(const int addHealth, const HealthPoints& hp1);
    
    /*
     * subractHealth (HealthPoints - int) operator for subtracting an integer from HealthPoints object.
     * Gets an integer and an HealthPoints Object.
     *
     *  @return
     *          An isnstance of the subtracted number.
     */
    HealthPoints operator-(const HealthPoints& hp1, const int subHealth);

    /*
     * subractHealth (HealthPoints - int) for subtracting HealthPoints object from an integer.
     * Gets an integers to add on.
     *
     *  @return
     *          An isnstance of the subtracted number.
     */
    HealthPoints operator-(const int subHealth, const HealthPoints& hp1); 

    /*
     * isNotEqual (!=) operator for comepring two HealthPoints objects.
     *
     *  @return
     *          True if the right object different from the left and False otherwise.
     */
     bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2);

/*
     *  isEqualOrSmaller (<=) operator for comepring two HealthPoints objects.
     *
     *  @return
     *          True if the left object is equal or smaller from the right object and False otherwise.
     */
     bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2);

    /*
     * isBigger (>) operator for comepring two HealthPoints objects.
     *
     *  @return
     *          True if the left object is bigger than the right object and False otherwise.
     */
     bool operator>(const HealthPoints& hp1, const HealthPoints& hp2);

    /*
     *  isEqualOrSmaller (>=) operator for comepring two HealthPoints objects.
     *
     *  @return
     *          True if the left object is equal or bigger than the right object and False otherwise.
     */
     bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2);


#endif //EX3_HealthPoints_H
