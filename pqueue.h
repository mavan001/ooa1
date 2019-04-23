#ifndef _PQUEUE_H
#define _PQUEUE_H

using namespace std;

typedef struct pqentry{
    float priority;
    string value;
    struct pqentry *prev;
    struct pqentry *next;
}pqentry_t;

class PriorityQueue {
private:
    int _size;
    int _last;
public:
    PriorityQueue(int size = 100);
    ~PriorityQueue(void);
    void insert(string value, float priority);
    string extractMin(void);
    void decreaseKey(string value, float priority);
    void remove(string value);
    bool isEmpty(void);
    void print();
};

#endif
