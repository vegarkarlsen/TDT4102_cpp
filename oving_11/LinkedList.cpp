
#include <cassert>
#include "LinkedList.h"
#include "logger.hpp"



std::ostream& operator<<(std::ostream &os, const Node &node){
    os << node.value;
    return os;
}

std::ostream & operator<<(std::ostream & os, const LinkedList& list){

    Node *iterator = list.begin();
    os << "[";
    while (iterator != list.end()){
        os << iterator->getValue() << ", ";
        iterator = iterator->getNext();
    }
    os << "]";
    return os;
}


Node* LinkedList::insert(Node *pos, const std::string& value){

    assert(pos != nullptr);

    if (pos == begin()){
        head = std::make_unique<Node>(value, std::move(head), nullptr);
        pos->prev = begin();
    }
    else {
        pos->prev->next = std::make_unique<Node>(value, std::move(pos->prev->next), pos->prev);
        pos->prev = pos->prev->getNext();
    }
    return pos->prev;
}

Node* LinkedList::remove(Node* pos){
    // DEBUG("[prev<-pos->next] " << pos->prev << " <- " << pos << " -> " << pos->getNext());
    
    assert(pos != nullptr);
    assert(pos != end());

    if (pos == begin()){
        head = std::move(pos->next);
        head->prev = nullptr;
        return begin();
    } else { 
        auto nextNode = pos->getNext();
        // correct (pos +1)->prev = (pos-1), skipping pos
        nextNode->prev = pos->prev;
        // moving (pos-1)->next = (pos+1), skipping pos
        pos->prev->next = std::move(pos->next);
        // think pos deletes itself when it gets overwriten. 
        
        return nextNode;
    }
    
}

Node* LinkedList::find(const std::string &value){
    for (auto it = begin(); it!= end(); it = it->getNext()){
        if (it->getValue() == value){
            return it;
        }
    }
    return end();
}

void LinkedList::remove(const std::string& value){
    auto removeNode = find(value);
    if (removeNode != end()){
        remove(removeNode);
    }
}

