//
//  Sequence.cpp
//  CS-32-Homework-1
//
//  Created by Edward Chu on 18/1/2017.
//  Copyright © 2017 Puffins. All rights reserved.
//

#include "Sequence.h"
#include <iostream>


Sequence::Sequence(const Sequence& s){

    m_numItems = s.m_numItems;
    
    for(int i = 0; i < m_numItems; i++){
        m_items[i] = s.m_items[i];
    }
}

bool Sequence::insert(int pos, const ItemType& value) {
    
    //Outside valid location
    if (pos < 0 || pos > m_numItems)
        return false;
    
    //Full!
    if(m_numItems == DEFAULT_MAX_ITEMS)
        return false;
    
    
    for(int i = m_numItems-1; i >= pos; i--){
        m_items[i+1] = m_items[i];
    }
    
    m_items[pos] = value;
    m_numItems++;
    return true;
}


int Sequence::insert(const ItemType& value){
    
    //Full!
    if(m_numItems == DEFAULT_MAX_ITEMS)
        return false;
    
    for(int i = 0; i < m_numItems; i++){
        if(value <= m_items[i]){
            insert(i, value);
            return i;
        }
    }
    
    //Larger than all values or only value
    insert(m_numItems, value);
    return m_numItems;
}


bool Sequence::erase(int pos){
    
    //Outside array
    if(pos < 0 || pos >= m_numItems)
        return false;
    
    for(int i = pos; i < m_numItems-1; i++)
        m_items[i] = m_items[i+1];
    
    m_numItems--;
    return true;
}


int Sequence::remove(const ItemType& value){
    
    int count = 0;
    
    for(int i = 0; i < m_numItems; i++){
        if(m_items[i] == value){
            erase(i);
            i--;
            count++;
        }
    }
    return count; //items removed
}

bool Sequence::get(int pos, ItemType& value) const {
    
    //Outside array
    if(pos < 0 || pos >= m_numItems)
        return false;
    
    value = m_items[pos];
    return true;
}

bool Sequence::set(int pos, const ItemType& value) {
    
    //Outside array
    if(pos < 0 || pos >= m_numItems)
        return false;
    
    m_items[pos] = value;
    return true;
}

int Sequence::find(const ItemType& value) const {
    
    for(int i = 0; i < m_numItems; i++){
        if(m_items[i] == value)
            return i;
    }
    return -1;
}

void Sequence::swap(Sequence& other) {
    
    //Swap items
    for(int i = 0; i < other.size() && i < this->size(); i++) {
        ItemType temp = this->m_items[i];
        this->m_items[i] = other.m_items[i];
        other.m_items[i] = temp;
    }
    
    if(this->size() > other.size()){
        for(int i = other.size(); i < this->size(); i++)
            other.m_items[i] = this->m_items[i];
    } else {
        for(int i = this->size(); i < other.size(); i++)
            this->m_items[i] = other.m_items[i];
    }
    
    //Swap size
    int temp;
    temp = this->size();
    this->m_numItems = other.size();
    other.m_numItems = temp;
}




void Sequence::dump() const {
    for(int i = 0; i < m_numItems; i++)
        std::cerr << m_items[i] << " ";
    std::cerr << std::endl;
}

