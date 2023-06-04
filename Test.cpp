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
vector<int> numVec={-999,9999,0,4,13,-14,-3,3,77,7,123,-456,957,12345678,-23456781,1234,456,6,2,1,-1,871,888,15,20,-32,-144,700,123456789,333,-333,81};
//sortedNumVec={-23456781,-999,-456,-333,-144,-32,-14,-3,-1,0,1,2,3,4,6,7,13,15,20,77,81,123,333,456,700,871,888,957,1234,9999,12345678,123456789};
void fillVector(vector<int>* vector){
    ::srand((unsigned) time(NULL));
    vector->reserve(100);
    for (int i = 0; i < 100; ++i) {
        int num=::rand();
        int sign=::rand()%2;
        while(std::count(vector->begin(), vector->end(),num)){
            //no duplication for tests
            num=::rand();
        }
        switch (sign) {
            case 0:
                vector->push_back(num);
                break;
            case 1:
                vector->push_back(num*-1);
                break;
            default:
                break;
        }
    }
}
void buildContainer(MagicalContainer *container ,vector<int>* vector) {
    std::sort(vector->begin(), vector->end());
    for (int num: *vector) {
        container->addElement(num);
    }
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
        MagicalContainer container;
        buildContainer(&container,&numVec);
        MagicalContainer::AscendingIterator ascIter(container);
        auto it=ascIter.begin();
        size_t i=0;
        CHECK((ascIter.begin()==ascIter.begin()));
        CHECK((ascIter.begin()!=ascIter.end()));
        for (; it != ascIter.end(); ++it,++i)  {
            CHECK_EQ(*it,numVec[i]);
            CHECK_EQ(*it.operator->(),numVec[i]);
        }
        CHECK_EQ(it,ascIter.end());
    }
    TEST_CASE("SideCrossIterator"){
        MagicalContainer container;
        buildContainer(&container,&numVec);
        MagicalContainer::SideCrossIterator crossIter(container);
        auto it=crossIter.begin();
        size_t i=0,j=numVec.size();
        bool flag= true;
        CHECK((crossIter.begin()==crossIter.begin()));
        CHECK((crossIter.begin()!=crossIter.end()));
        for (; it != crossIter.end(); ++it)  {
            size_t index=(flag)?i:j;
            CHECK_EQ(*it,numVec[index]);
            CHECK_EQ(**it.operator->(),numVec[index]);
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
        MagicalContainer container;
        buildContainer(&container,&numVec);
        MagicalContainer::PrimeIterator primeIter(container);
        auto it=primeIter.begin();
        size_t i=0;
        CHECK((primeIter.begin()==primeIter.begin()));
        CHECK((primeIter.begin()!=primeIter.end()));
        for (; it != primeIter.end();++i)  {
            if(isPrime(numVec[i])) {
                CHECK_EQ(*it, numVec[i]);
                CHECK_EQ(**it.operator->(), numVec[i]);
                ++it;
            }
        }
        CHECK_EQ(it,primeIter.end());
    }
}


TEST_SUITE("Iterators validation after Insertion/Erasure , Relational Operators"){

    TEST_CASE("AscendingIterator"){
        MagicalContainer container;
        buildContainer(&container,&numVec);   //-23456781,-999,-456,-333,-144,-32,-14,-3,-1,
        // 0,1,2,3,4,6,7,13,15,20,77,81,123,333,456,700
        //,871,888,957,1234,9999,12345678,123456789
        MagicalContainer::AscendingIterator ascIterator(container);
        auto it=ascIterator.begin();

        CHECK_EQ(*it,-23456781);
        ++it;
        container.addElement(-111111);
        CHECK_EQ(*it,-999);
        container.addElement(-555);
        ++it;
        CHECK_EQ(*it,-555);
        container.removeElement(-456);
        ++it;
        CHECK_EQ(*it,-333);
        container.removeElement(-999);
        CHECK_EQ(*it,-333);
    }
    //to avoid non-simple logic in test we will use a pre-made vector
    TEST_CASE("SideCrossIterator"){
        MagicalContainer container;
        buildContainer(&container,&numVec);   //-23456781,-999,-456,-333,-144,-32,-14,-3,-1,
        // 0,1,2,3,4,6,7,13,15,20,77,81,123,333,456,700
        //,871,888,957,1234,9999,12345678,123456789
        MagicalContainer::SideCrossIterator crossIterator(container);
        auto it=crossIterator.begin();

        CHECK_EQ(*it,-23456781);
        ++it;
        container.addElement(123456790);
        CHECK_EQ(*it,123456790);
        container.addElement(-1000);
        ++it;
        CHECK_EQ(*it,-1000);
        container.removeElement(123456789);
        ++it;
        CHECK_EQ(*it,12345678);
        container.removeElement(-999);
        CHECK_EQ(*it,-333);
    }

    TEST_CASE("PrimeIterator"){
        MagicalContainer container;
        buildContainer(&container,&numVec);   //-23456781,-999,-456,-333,-144,-32,-14,-3,-1,
        // 0,1,2,3,4,6,7,13,15,20,77,81,123,333,456,700
        //,871,888,957,1234,9999,12345678,123456789
        MagicalContainer::PrimeIterator primeIterator(container);
        auto it=primeIterator.begin();
        CHECK_EQ(*it,1);
        container.removeElement(2);
        ++it;
        CHECK_EQ(*it,3);
        container.addElement(5);
        ++it;
        CHECK_EQ(*it,5);
        container.removeElement(7);
        ++it;
        CHECK_EQ(*it,13);
        container.removeElement(3);
        CHECK_EQ(*it,13);

    }

    TEST_CASE("Relational operators"){
        MagicalContainer container;
        buildContainer(&container,&numVec);   //-23456781,-999,-456,-333,-144,-32,-14,-3,-1,
        // 0,1,2,3,4,6,7,13,15,20,77,81,123,333,456,700
        //,871,888,957,1234,9999,12345678,123456789
        MagicalContainer::AscendingIterator ascIterator(container);
        MagicalContainer::SideCrossIterator crossIterator(container);
        MagicalContainer::PrimeIterator primeIterator(container);

        auto it1=ascIterator.begin();
        auto it2=ascIterator.begin();
        auto it3=crossIterator.begin();
        auto it4=crossIterator.begin();
        auto it5=primeIterator.begin();
        auto it6=primeIterator.begin();

        CHECK_EQ(it1,it2);
        CHECK_EQ(it3,it4);
        CHECK_EQ(it5,it6);
        ++it2;
        ++it4;
        ++it6;
        CHECK_GT(it2,it1);
        CHECK_GT(it4,it3);
        CHECK_GT(it6,it5);
        ++it2;
        ++it4;
        ++it6;
        CHECK_LT(it1,it2);
        CHECK_LT(it3,it4);
        CHECK_LT(it6,it5);

        CHECK_FALSE((it1==it2));
        CHECK_FALSE((it3==it4));
        CHECK_FALSE((it5==it6));
    }

}


TEST_SUITE("Exceptions"){
    TEST_CASE("out of bound"){
        MagicalContainer container;
        buildContainer(&container,&numVec);
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