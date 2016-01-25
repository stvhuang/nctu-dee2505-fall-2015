/**
 * @filename OrderMGMT.hpp
 * @author   Yanjia Huang <yanjia.huang.tw@gmail.com>
 */


#ifndef _ORDERMGMT_HPP_
#define _ORDERMGMT_HPP_

#include <list>

using namespace std;

// Data structure consisting of Order ID and date.
struct Node {
    unsigned id;
    unsigned date;
    unsigned leftSize;
    Node *left, *right;
};

// Order Management System consolidating key operational processes.
class OrderMGMT {
private:
    Node * root;

public:
    OrderMGMT();
    void addOrder(unsigned date, unsigned id);
    void deleteOrders(unsigned start, unsigned end);
    list<unsigned> searchByDate(unsigned start, unsigned end);
    list<unsigned> searchByDateOrdering(unsigned start, unsigned end);
};

#endif
