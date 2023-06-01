//
// Created by mintsdz on 5/30/23.
//

#ifndef MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
#define MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
#include <vector>
#include <iterator>
#include <cstddef>
#include <list>
using namespace std;
namespace ariel {

    class MagicalContainer {
        //vectors are contiguous
    private:
        list<int> _numbers;
        list<int*> _sideCross;
        list<int*> _primes;
        int _size;
        int _sizePrimes;
    public:
        MagicalContainer();
        void addElement(int ele);
        void removeElement(int ele);
        int size();

        struct AscendingIterator{
            using iterator_catagory = forward_iterator_tag; //TOBE DECIDED
            using difference_type = ptrdiff_t;
            using value_type= int;
            using pointer = value_type*;
            using reference = value_type&;

            AscendingIterator();
            AscendingIterator(AscendingIterator& ascendingIterator);
            AscendingIterator(MagicalContainer container);
            AscendingIterator& operator=(const AscendingIterator& ascendingIterator);


            reference operator*()const;
            pointer operator->();

            //prefix
            AscendingIterator& operator++();
            //postfix
            AscendingIterator operator++(int);

            friend bool operator==(const AscendingIterator& rhs,const AscendingIterator& lhs);
            friend bool operator!=(const AscendingIterator& rhs,const AscendingIterator& lhs);
            friend bool operator>(const AscendingIterator& rhs,const AscendingIterator& lhs);
            friend bool operator<(const AscendingIterator& rhs,const AscendingIterator& lhs);

            AscendingIterator begin();
            AscendingIterator end();

            virtual ~AscendingIterator();

        private:
            pointer _ptr;
        };

        struct SideCrossIterator{
            using iterator_catagory = forward_iterator_tag; //TOBE DECIDED
            using difference_type = ptrdiff_t;
            using value_type= int*;
            using pointer = value_type*;
            using reference = int&;

            SideCrossIterator();
            SideCrossIterator(SideCrossIterator& crossIterator);
            SideCrossIterator(MagicalContainer container);
            SideCrossIterator& operator=(const SideCrossIterator& crossIterator);

            reference operator*()const;
            pointer operator->();

            //prefix
            SideCrossIterator& operator++();
            //postfix
            SideCrossIterator operator++(int);

            friend bool operator==(const SideCrossIterator& rhs,const SideCrossIterator& lhs);
            friend bool operator!=(const SideCrossIterator& rhs,const SideCrossIterator& lhs);
            friend bool operator>(const SideCrossIterator& rhs,const SideCrossIterator& lhs);
            friend bool operator<(const SideCrossIterator& rhs,const SideCrossIterator& lhs);

            SideCrossIterator begin();
            SideCrossIterator end();

            virtual ~SideCrossIterator();

        private:
            pointer _ptr;
        };

        struct PrimeIterator{
            using iterator_catagory = forward_iterator_tag; //TOBE DECIDED
            using difference_type = ptrdiff_t;
            using value_type= int*;
            using pointer = value_type*;
            using reference = int&;

            PrimeIterator();
            PrimeIterator(PrimeIterator& primeIterator);
            PrimeIterator(MagicalContainer container);
            PrimeIterator& operator=(const PrimeIterator& primeIterator);

            reference operator*()const;
            pointer operator->();

            //prefix
            PrimeIterator& operator++();
            //postfix
            PrimeIterator operator++(int);

            friend bool operator==(const PrimeIterator& rhs,const PrimeIterator& lhs);
            friend bool operator!=(const PrimeIterator& rhs,const PrimeIterator& lhs);
            friend bool operator>(const PrimeIterator& rhs,const PrimeIterator& lhs);
            friend bool operator<(const PrimeIterator& rhs,const PrimeIterator& lhs);

            PrimeIterator begin();
            PrimeIterator end();

            virtual ~PrimeIterator();

        private:
            pointer _ptr;
        };

    };

    bool isPrime(int num);

} // ariel

#endif //MAGICAL_ITERATORS_MAGICALCONTAINER_HPP
