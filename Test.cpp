//
// Created by mintsdz on 5/30/23.
//
#include "sources/MagicalContainer.hpp"
#include "doctest.h"
#include<iostream>
#include<cstdlib>
#include <algorithm>
#include <time.h>

using namespace std;
using namespace ariel;
vector<int> numbers={-999,9999,0,4,13,-14,-3,3,77,7,123,-456,957,12345678,-23456781,1234,456,6,2,1,-1,871,888,15,20,-32,-144,700,123456789,333,-333,81};
//vector<int> sortedNumbers={-23456781,-999,-456,-333,-144,-32,-14,-3,-1,0,1,2,3,4,6,7,13,15,20,77,81,123,333,456,700,871,888,957,1234,9999,12345678,123456789};
void fillVector(vector<int>& vector){
    ::srand((unsigned) time(NULL));
    vector.reserve(100);
    for (int i = 0; i < 100; ++i) {
        int num=::rand();
        int sign=::rand()%2;
        while(std::count(vector.begin(), vector.end(),num)){
            //no duplication for tests
            num=::rand();
        }
        switch (sign) {
            case 0:
                vector.push_back(num);
                break;
            case 1:
                vector.push_back(num*-1);
                break;
            default:
                break;
        }
    }
}
MagicalContainer buildContainer(vector<int>& vector){
    MagicalContainer container;
    for (int num:vector) {
        container.addElement(num);
    }
    std::sort(vector.begin(), vector.end());
    return container;
}

TEST_SUITE("Container"){
    TEST_CASE("Basic operations on container"){
        MagicalContainer container;
        CHECK_EQ(container.size(),0);
        CHECK_NOTHROW(container.removeElement(std::rand()));

        int num=std::rand();
        CHECK_NOTHROW(container.addElement(num));
        CHECK_EQ(container.size(),1);
        CHECK_NOTHROW((container.removeElement(num)));
        CHECK_EQ(container.size(),0);

        for (int i = 1; i <= 50; ++i) {
            container.addElement(i);
            CHECK_EQ(container.size(),i);
        }
        int size=container.size();
        container.addElement(10);
        container.addElement(11);
        CHECK_EQ(container.size(),size);
        container.removeElement(10);
        container.removeElement(10);
        CHECK_EQ(container.size(),size-1);
        for (int i = 50; i >0 ; --i) {
            container.removeElement(i);
            CHECK_EQ(container.size(),i);
        }
        CHECK_EQ(container.size(),0);
        container.removeElement(10);
        CHECK_EQ(container.size(),0);
    }
}

TEST_CASE("Is Prime"){
    CHECK(isPrime(1));
    CHECK_FALSE(isPrime(4));
    CHECK(isPrime(2));
    CHECK_FALSE(isPrime(1000));
    CHECK(isPrime(3));
    CHECK_FALSE(isPrime(81));
    CHECK(isPrime(5));
    CHECK(isPrime(31));
    CHECK(isPrime(1993));
    CHECK(isPrime(5659));
    CHECK_FALSE(isPrime(2023));
}

TEST_SUITE("Operators and Iterating over the list"){
    TEST_CASE("AscendingIterator"){
        MagicalContainer container=buildContainer(numbers);
        MagicalContainer::AscendingIterator ascIter(container);
        auto it=ascIter.begin();
        size_t i=0;
        CHECK((ascIter.begin()==ascIter.begin()));
        CHECK((ascIter.begin()!=ascIter.end()));
        for (; it != ascIter.end(); ++it,++i)  {
            CHECK_EQ(*it,numbers[i]);
            CHECK_EQ(*it.operator->(),numbers[i]);
        }
        CHECK_EQ(it,ascIter.end());
    }
    TEST_CASE("SideCrossIterator"){
        MagicalContainer container=buildContainer(numbers);
        MagicalContainer::SideCrossIterator crossIter(container);
        auto it=crossIter.begin();
        size_t i=0,j=numbers.size();
        bool flag= true;
        CHECK((crossIter.begin()==crossIter.begin()));
        CHECK((crossIter.begin()!=crossIter.end()));
        for (; it != crossIter.end(); ++it)  {
            size_t index=(flag)?i:j;
            CHECK_EQ(*it,numbers[index]);
            CHECK_EQ(**it.operator->(),numbers[index]);
            if(flag){
                ++i;
                flag=false;
            }else{
                --j;
                flag= true;
            }
        }
        CHECK_EQ(it,crossIter.end());
    }
    TEST_CASE("PrimeIterator"){
        MagicalContainer container=buildContainer(numbers);
        MagicalContainer::PrimeIterator primeIter(container);
        auto it=primeIter.begin();
        size_t i=0;
        CHECK((primeIter.begin()==primeIter.begin()));
        CHECK((primeIter.begin()!=primeIter.end()));
        for (; it != primeIter.end();++i)  {
            if(isPrime(numbers[i])) {
                CHECK_EQ(*it, numbers[i]);
                CHECK_EQ(**it.operator->(), numbers[i]);
                ++it;
            }
        }
        CHECK_EQ(it,primeIter.end());
    }
}

TEST_SUITE("Iterators validation after Insertion/Erasure"){
    TEST_CASE("AscendingIterator"){
        vector<int> myVector;
        fillVector(myVector);
        MagicalContainer container=buildContainer(myVector);
        MagicalContainer::AscendingIterator ascIterator(container);
        int i=0,diff=0,num=0;
        auto it=ascIterator.begin();
        // Insertion
        while((it!=ascIterator.end()) && ((i+1)<myVector.size())){
            if((diff=myVector[i+1]-myVector[i])>1){
                //inserting median between two elements
                num=myVector[i+1]-diff/2;
                container.addElement(num);
            }
            if(diff>1){
                //case we inserted median
                //conatiner now holds ...myVector[i],num,myVector[i+1]
                CHECK_EQ(*it,myVector[i]);//should point to myVector[i]
                ++it; //now iterator should point to @num
                CHECK_EQ(*it,num);
                CHECK_FALSE(*it==myVector[i+1]);
                ++it;//now iterator should point to myVector[i+1]
                CHECK_EQ(*it,myVector[i+1]);//c
                ++i;
            }else{
                //was no insertion
                ++it;
                ++i;
            }
        }
        i=0;
        it=ascIterator.begin();
        // Erasure
        while((it!=ascIterator.end()) && ((i+1)<myVector.size())){
            if((diff=myVector[i+1]-myVector[i])>1){
                //we calculate inserted number to be removed
                num=myVector[i+1]-diff/2;
                container.removeElement(num);
            }
            if(diff>1){
                //case we removed ,container hold same numbers as myVector
                CHECK_EQ(*it,myVector[i]);
                ++it;
                CHECK_EQ(*it,myVector[i+1]);
                ++i;
            }else{
                ++it;
                ++i;
            }
        }
    }
    //to avoid non-simple logic in test we will use a pre-made vector
    TEST_CASE("SideCrossIterator"){
        MagicalContainer container=buildContainer(numbers);   //-23456781,-999,-456,-333,-144,-32,-14,-3,-1,
                                                                // 0,1,2,3,4,6,7,13,15,20,77,81,123,333,456,700
                                                                //,871,888,957,1234,9999,12345678,123456789
        MagicalContainer::SideCrossIterator crossIterator(container);
        auto it=crossIterator.begin();
        CHECK_EQ(*it,-23456781);
        container.addElement(123456789+1);
        ++it;
        CHECK_EQ(*it,123456789+1);
        ++it;
        CHECK_EQ(*it,-999);
        ++it;
        CHECK_EQ(*it,123456789);
        container.addElement(-555);
        ++it;
        CHECK_EQ(*it,-555);
        ++it;
        CHECK_EQ(*it,12345678);
        ++it;
        CHECK_EQ(*it,-456);
        container.removeElement(9999);
        ++it;
        CHECK_EQ(*it,1234);
        container.removeElement(-333);
        ++it;
        CHECK_EQ(*it,-144);
    }

    TEST_CASE("PrimeIterator"){
        MagicalContainer container=buildContainer(numbers);   //-23456781,-999,-456,-333,-144,-32,-14,-3,-1,
        // 0,1,2,3,4,6,7,13,15,20,77,81,123,333,456,700
        //,871,888,957,1234,9999,12345678,123456789
        MagicalContainer::PrimeIterator primeIterator(container);
        auto it=primeIterator.begin();
        while(*it!=1){
            ++it;
        }
        CHECK_EQ(*it,1);
        container.removeElement(2);
        ++it;
        CHECK_EQ(*it,3);
        container.removeElement(7);
        ++it;
        CHECK_EQ(*it,13);
        container.addElement(17);
        ++it;
        CHECK_EQ(*it,17);
        container.addElement(23);
        ++it;
        CHECK_EQ(*it,23);
    }

}
TEST_SUITE("Exceptions"){
    TEST_CASE("out of bound"){
        MagicalContainer container=buildContainer(numbers);
        MagicalContainer::AscendingIterator ascIterator(container);
        MagicalContainer::SideCrossIterator crossIterator(container);
        MagicalContainer::PrimeIterator primeIterator(container);
        auto it1=ascIterator.end();
        auto it2=crossIterator.end();
        auto it3=primeIterator.end();
        CHECK_THROWS_AS(++it1,runtime_error);
        CHECK_THROWS_AS(++it2,runtime_error);
        CHECK_THROWS_AS(++it3,runtime_error);
    }
}