#include "LinkedList.h"

// using namespace LinkedList;

std::ostream& operator<<(std::ostream &os, const LinkedList::Node &node){
    os << node.getValue();
    return os;
}

// FIXME: bug when inserting end()
LinkedList::Node* LinkedList::LinkedList::insert(Node *pos, const std::string& value){
    
    // first element in list    
    if (pos == head.get()){
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value,
            std::move(head), 
            nullptr);
        // pos points to same adress as head
        pos->prev = newNode.get();

        head = std::move(newNode);
        return newNode.get();

    }
    else{ // not first element
        // newNode->next point to pos, and newNode->prev point to pos->prev 
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value, 
            std::move(pos->prev->next), 
            pos->prev);
        
        // update prev->next to point to newNode
        pos->prev->next = std::move(newNode);
        
        // pos->prev points to newNode
        pos->prev = newNode.get();
        return newNode.get();
    }
}

LinkedList::Node* LinkedList::LinkedList::remove(Node* pos){
    
    // first element in list
    if (pos == head.get()){
        // temprary store head
        auto currentNode = std::move(head);
        // (pos +1) prev pointer = nullptr
        currentNode->next->prev = nullptr;
        // head = (pos + 1) next pointer
        head = std::move(currentNode->next);
        // delete currentNode (pos)
        currentNode.reset();
        return head->next.get();

    }else{ // not first element
        // temperary store uniqe pointer of pos
        auto currentNode = std::move(pos->prev->next);
        // update (pos - 1) next pointer
        currentNode->prev->next = std::move(currentNode->next);
        //update (pos + 1) prev pointer
        currentNode->prev->next->prev = currentNode->prev;

        // pointer to (pos + 1)
        Node *returnNode = currentNode->prev->next.get();

        // delete current node (pos);
        currentNode.reset();
        return returnNode;
    }
    


}