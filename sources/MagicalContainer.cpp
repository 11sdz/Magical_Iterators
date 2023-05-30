//
// Created by mintsdz on 5/30/23.
//

#include "MagicalContainer.hpp"

namespace ariel {

    MagicalContainer::MagicalContainer() {

    }

    void MagicalContainer::addElement(int ele) {

    }

    void MagicalContainer::removeElement(int ele) {

    }

    int MagicalContainer::size() {
        return 0;
    }

    /*
     * =============================================================================================
     * ===================================AscendingIterator=========================================
     * =============================================================================================
     */

    MagicalContainer::AscendingIterator::AscendingIterator() {

    }

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer container) {

    }

    MagicalContainer::AscendingIterator::value_type &MagicalContainer::AscendingIterator::operator*() const {
        return *this->_ptr;
    }

    MagicalContainer::AscendingIterator::pointer MagicalContainer::AscendingIterator::operator->() {
        return nullptr;
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++(int) {
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
        return *this;
    }

    bool operator==(const MagicalContainer::AscendingIterator& rhs,const MagicalContainer::AscendingIterator& lhs){
        return false;
    }

    bool operator!=(const MagicalContainer::AscendingIterator& rhs,const MagicalContainer::AscendingIterator& lhs){
        return false;
    }

    bool operator>(const MagicalContainer::AscendingIterator& rhs,const MagicalContainer::AscendingIterator& lhs){
        return false;
    }

    bool operator<(const MagicalContainer::AscendingIterator& rhs,const MagicalContainer::AscendingIterator& lhs){
        return false;
    }

    MagicalContainer::AscendingIterator::~AscendingIterator() {

    }

    /*
     * =============================================================================================
     * ===================================SideCrossIterator=========================================
     * =============================================================================================
     */

    MagicalContainer::SideCrossIterator::SideCrossIterator() {}


    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer container) {

    }

    MagicalContainer::SideCrossIterator::value_type &MagicalContainer::SideCrossIterator::operator*() const {
        return *this->_ptr;
    }

    MagicalContainer::SideCrossIterator::pointer MagicalContainer::SideCrossIterator::operator->() {
        return nullptr;
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() {
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++(int) {
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
        return *this;
    }

    bool operator==(const MagicalContainer::SideCrossIterator& rhs,const MagicalContainer::SideCrossIterator& lhs){
        return false;
    }

    bool operator!=(const MagicalContainer::SideCrossIterator& rhs,const MagicalContainer::SideCrossIterator& lhs){
        return false;
    }

    bool operator>(const MagicalContainer::SideCrossIterator& rhs,const MagicalContainer::SideCrossIterator& lhs){
        return false;
    }

    bool operator<(const MagicalContainer::SideCrossIterator& rhs,const MagicalContainer::SideCrossIterator& lhs){
        return false;
    }

    MagicalContainer::SideCrossIterator::~SideCrossIterator() {

    }

    /*
    * =============================================================================================
    * ===================================PrimeIterator=============================================
    * =============================================================================================
    */

    MagicalContainer::PrimeIterator::PrimeIterator() {}


    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer container) {

    }

    MagicalContainer::PrimeIterator::value_type &MagicalContainer::PrimeIterator::operator*() const {
        return *this->_ptr;
    }

    MagicalContainer::PrimeIterator::pointer MagicalContainer::PrimeIterator::operator->() {
        return nullptr;
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++(int) {
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
        return *this;
    }

    bool operator==(const MagicalContainer::PrimeIterator& rhs,const MagicalContainer::PrimeIterator& lhs){
        return false;
    }

    bool operator!=(const MagicalContainer::PrimeIterator& rhs,const MagicalContainer::PrimeIterator& lhs){
        return false;
    }

    bool operator>(const MagicalContainer::PrimeIterator& rhs,const MagicalContainer::PrimeIterator& lhs){
        return false;
    }

    bool operator<(const MagicalContainer::PrimeIterator& rhs,const MagicalContainer::PrimeIterator& lhs){
        return false;
    }

    MagicalContainer::PrimeIterator::~PrimeIterator() {

    }
} // ariel