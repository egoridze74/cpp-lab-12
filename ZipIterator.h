//
// Created by Egor on 10.03.2024.
//

#ifndef CPP_LAB_12_ZIPITERATOR_H
#define CPP_LAB_12_ZIPITERATOR_H

#include <iterator>

// ZipIterator works similar to function "zip()" in Python,
// joining together elements of two or more containers.
// We will use std::pair to store elements

template<typename IT1, typename IT2>
class zip_iterator {
private:
    template <class Iter>
    friend struct std::iterator_traits;
public:
    typedef std::pair<typename IT1::value_type, typename IT2::value_type> value_type;
    typedef value_type* pointer;
    typedef value_type& reference;

    IT1 iter1;
    IT2 iter2;

    zip_iterator():
    iter1(), iter2() {}

    zip_iterator(IT1 iter1, IT2 iter2):
    iter1(iter1), iter2(iter2) {}

    zip_iterator(const zip_iterator& other):
    iter1(other.iter1), iter2(other.iter2) {}

    zip_iterator& operator=(const zip_iterator& other) {
        if (this != other) {
            iter1 = other.iter1;
            iter2 = other.iter2;
        }
        return *this;
    }

    template<typename C1, typename C2>
    zip_iterator(C1& container1, C2& container2):
    iter1(container1.begin()), iter2(container2.begin()) {}

    reference operator*() const {
        return std::make_pair(*iter1, *iter2);
    }

    pointer operator->() {
        return new std::pair<typename IT1::value_type, typename IT2::value_type>(*iter1, *iter2);
    }

    zip_iterator operator++() {
        iter1++;
        iter2++;
        return *this;
    }

    zip_iterator operator++(int) {
        zip_iterator old(*this);
        iter1++;
        iter2++;
        return old;
    }

    bool operator==(const zip_iterator& other) const {
        return iter1 == other.iter1 && iter2 == other.iter2;
    }

    bool operator!=(const zip_iterator& other) const {
        return iter1 != other.iter1 || iter2 != other.iter2;
    }

    bool operator==(const std::pair<IT1, IT2>& other) const {
        return iter1 == other.first && iter2 == other.second;
    }

    bool operator!=(const std::pair<IT1, IT2>& other) const {
        return iter1 != other.first || iter2 != other.second;
    }

    bool any(const std::pair<IT1, IT2>& other) const {
        return iter1 == other.first || iter2 == other.second;
    }

    zip_iterator swap() {
        std::swap(iter1, iter2);
        return *this;
    }
};

#endif //CPP_LAB_12_ZIPITERATOR_H
