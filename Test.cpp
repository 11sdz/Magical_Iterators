//
// Created by mintsdz on 5/30/23.
//
#include "sources/MagicalContainer.hpp"
#include "doctest.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace ariel;
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
        for (int i = 50; i >0 ; --i) {
            container.removeElement(i);
            CHECK_EQ(container.size(),i);
        }
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

TEST_SUITE("Operators"){
    vector<int> numbers={-999,9999,0,4,13,-14,-3,3,77,7,123,-456,957,12345678,-23456781,1234,456,6,2,1,-1,871,888,15,20,-32,-144,700,123456789,333,-333,81};
    vector<int> sortedNumbers{-23456781,-999,-456,-333,-144,-32,-14,-3,-1,0,1,2,3,4,6,7,13,15,20,77,81,123,333,456,700,871,888,957,1234,9999,12345678,123456789};
    MagicalContainer buildContainer(){
        MagicalContainer container;
        for (int i:numbers) {
            container.addElement(i);
        }
        return container;
    }
    TEST_CASE("AscendingIterator"){
        MagicalContainer container=buildContainer();
        MagicalContainer::AscendingIterator ascIter(container);
        auto it=ascIter.begin();
        size_t i=0;
        CHECK((ascIter.begin()==ascIter.begin()));
        CHECK((ascIter.begin()!=ascIter.end()));
        for (; it != ascIter.end(); ++it,++i)  {
            CHECK_EQ(*it,sortedNumbers[i]);
            CHECK_EQ(*it.operator->(),sortedNumbers[i]);
        }
        CHECK_EQ(it,ascIter.end());
    }
    TEST_CASE("SideCrossIterator"){
        MagicalContainer container=buildContainer();
        MagicalContainer::SideCrossIterator crossIter(container);
        auto it=crossIter.begin();
        size_t i=0,j=sortedNumbers.size();
        bool flag= true;
        CHECK((crossIter.begin()==crossIter.begin()));
        CHECK((crossIter.begin()!=crossIter.end()));
        for (; it != crossIter.end(); ++it)  {
            size_t index=(flag)?i:j;
            CHECK_EQ(*it,sortedNumbers[index]);
            CHECK_EQ(*it.operator->(),sortedNumbers[index]);
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
        MagicalContainer container=buildContainer();
        MagicalContainer::PrimeIterator primeIter(container);
        auto it=primeIter.begin();
        size_t i=0;
        CHECK((primeIter.begin()==primeIter.begin()));
        CHECK((primeIter.begin()!=primeIter.end()));
        for (; it != primeIter.end();++i)  {
            if(isPrime(sortedNumbers[i])) {
                CHECK_EQ(**it, sortedNumbers[i]);
                CHECK_EQ(**it.operator->(), sortedNumbers[i]);
                ++it;
            }
        }
        CHECK_EQ(it,primeIter.end());
    }
}

TEST_SUITE("Errors"){

}