/**
 * @filename OrderMGMT.cpp
 * @author   Yanjia Huang <yanjia.huang.tw@gmail.com>
 */

#include <stack>

#include "OrderMGMT.hpp"

OrderMGMT::OrderMGMT() : root(0) {}

// Function to insert a new order.
// date: Date of a order.
// id: Order ID.
void OrderMGMT::addOrder(unsigned date, unsigned id) {
    Node *p(root), *pp(0);
    while (p) {
        pp = p;
        if (date < p->date) {
            p = p->left;
        } else if (date > p->date) {
            p = p->right;
        } else {
            return;
        }
    }

    p = new Node;
    p->date = date;
    p->id = id;
    p->left = 0;
    p->leftSize = 0;
    p->right = 0;

    if (root) {
        if (date < pp->date) {
            pp->left = p;
        } else {
            pp->right = p;
        }
    } else {
        root = p;
    }
}

// Function to delete orders from a given range.
// start: Begin date.
// end: End date.
void OrderMGMT::deleteOrders(unsigned start, unsigned end) {
    while (1) {
        Node *p(root), *pp(0);
        while (p) {
            if (p->date < start) {
                pp = p;
                p = p->right;
            } else if (p->date > end) {
                pp = p;
                p = p->left;
            } else {
                break;
            }
        }

        if (p) {
            if (p->left == 0 && p->right == 0) {
                if (p == root) {
                    root = 0;
                } else if (pp->left == p) {
                    pp->left = 0;
                } else {
                    pp->right = 0;
                }
                delete p;
            } else if (p->left == 0 && p->right != 0) {
                if (p == root) {
                    root = p->right;
                } else if (pp->left == p) {
                    pp->left = p->right;
                } else {
                    pp->right = p->right;
                }
                delete p;
            } else if (p->right == 0 && p->left != 0) {
                if (p == root) {
                    root = p->left;
                } else if (pp->left == p) {
                    pp->left = p->left;
                } else {
                    pp->right = p->left;
                }
                delete p;
            } else {
                Node *mp(p->left);
                Node *mpp(p);
                while (mp->right) {
                    mpp = mp;
                    mp = mp->right;
                }
                if (mpp == p) {
                    mpp->left = mp->left;
                } else {
                    mpp->right = mp->left;
                }

                mp->left = p->left;
                mp->right = p->right;

                if (p == root) {
                    root = mp;
                    delete p;
                } else {
                    if (pp->left == p) {
                        pp->left = mp;
                        delete p;
                    } else {
                        pp->right = mp;
                        delete p;
                    }
                }
            }
        } else {
            return;
        }
    }
}

// Function to output a list of order IDs from a given range of dates.
// start Begin date.
// end End date.
// id_list Order IDs stored in the STL list.
list<unsigned> OrderMGMT::searchByDate(unsigned start, unsigned end) {
    stack<Node *> s;
    Node *currentNode(root);
    list<unsigned> target;

    while (1) {
        while (currentNode) {
            s.push(currentNode);
            currentNode = currentNode->left;
        }

        if (s.empty()) {
            return target;
        }

        currentNode = s.top();
        s.pop();

        if (currentNode->date >= start && currentNode->date <= end) {
            target.push_back(currentNode->id);
        }

        currentNode = currentNode->right;
    }
}

// Function to output a list of order IDs from a given range of sequences.
// start Begin order.
// end End order.
// id_list Order IDs stored in the STL list.
list<unsigned> OrderMGMT::searchByDateOrdering(unsigned start, unsigned end) {
    stack<Node *> s;
    Node *currentNode(root);
    list<unsigned> target;
    unsigned order(0);

    while (1) {
        while (currentNode) {
            s.push(currentNode);
            currentNode = currentNode->left;
        }

        if (s.empty()) {
            return target;
        }

        currentNode = s.top();
        s.pop();
        ++order;

        if (order >= start && order <= end) {
            target.push_back(currentNode->id);
        }

        currentNode = currentNode->right;
    }
}
