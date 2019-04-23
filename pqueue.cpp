#include <string>
#include <iostream>
#include "pqueue.h"

using namespace std;



PriorityQueue::PriorityQueue(int size) {
    _size = size;
    _last = -1;
    _entrys = new pqentry*[size];
}

PriorityQueue::~PriorityQueue() {
    for (int i = 0; i < _last ; i++) {
        delete _entrys[i];
    }
    delete[] _entrys;
}



void PriorityQueue::changeArray(int x) {
    if (x == 1) {
        if (isFull() || isAlmostFull()) {
            pqentry **newArray = new pqentry*[_size * 2];
            for (int arraysize = 0; arraysize <= _last ; arraysize++) {
                newArray[arraysize] = _entrys[arraysize];
            }
            delete[](_entrys);
            _size *= 2;
            _entrys = newArray;
        }
      //wenn Array voll ist, neues Array mit doppelter Größe
    } else if (x == -1) {
        if ((_last+1) * 4 < _size) {
            pqentry **newArray = new pqentry*[_size / 2];
            for (int arraysize = 0; arraysize <= _last ; arraysize++) {
                newArray[arraysize] = _entrys[arraysize];
            }
            delete[](_entrys);
            _size /= 2;
            _entrys = newArray;
        }
    }
}

bool PriorityQueue::isFull() {
    return _last == (_size - 1);
}
bool PriorityQueue::isAlmostFull() {
    return _last > (_size - 2);
}
bool PriorityQueue::isEmpty() {
    if (_last == -1) { // ARRAY ist leer
    return 1;
}

void PriorityQueue::insert(string value, float priority) {
    if (isEmpty()) { // ARRAY ist leer
        _last += 1;
        _entrys[_last] = new pqentry(priority,value);
    } else {
        int i = 1;
        changeArray(1);
        if (priority < _entrys[0]->priority) { //wenn oberste Priorität
            for (int arraysize = _last; arraysize >= 0; arraysize--) {
                _entrys[arraysize + 1] = _entrys[arraysize];
            }
            _entrys[0] = new pqentry(priority, value);
            _last += 1;
        } else if (priority > _entrys[_last]->priority) { //wenn niedrigste Priorität
            _last += 1;
            _entrys[_last] = new pqentry(priority, value);
        } else {
            while (_entrys[i]->priority < priority) {
                i++;
            }
            for (int arraysize = _last; arraysize >= i; arraysize--) {
                _entrys[arraysize + 1] = _entrys[arraysize];
            }
            _entrys[i] = new pqentry(priority, value);
            _last += 1;
        }
    }
}

string PriorityQueue::extractMin() {
    string ret;
    if(_last == -1) {
        cout << "Bitte erst das Array mit Inhalt befüllen" << endl;
    }
    ret = _entrys[0]->value;
    remove(ret);
 
    return ret;
}

void PriorityQueue::remove(string value) {
    if (_last == -1) { //Queue leer?
        cout << "Bitte erst die Queue mit Inhalt befüllen" << endl;
    }
    if (_entrys[0]->value == value) { //wenn erstes Element
       delete _entrys[0];
            for (int arraysize = 0; arraysize < _last; arraysize++ ) {
                _entrys[arraysize] = _entrys[arraysize + 1];
            }
    } else if(_entrys[_last]->value == value) { //wenn letztes Element
        delete _entrys[_last];
    } else {
        int i = 0;
        while(_entrys[i]->value != value && i < _last) {
          i++;
        }
        if (_entrys[i]->value != value) {
              cout << "Das Element wurde nicht gefunden." << endl;
        }
        delete _entrys[i];
        for (int arraysize = i; arraysize < _last; arraysize++) {
                _entrys[arraysize] = _entrys[arraysize+1];
        }
    }
    _last -= 1;
    changeArray(-1);
}

void PriorityQueue::decreaseKey(string value, float priority) {
    remove(value);
    insert(value,priority);
}

void PriorityQueue::print() {
    for(int i = 0; i < _size;i++) {
        if (i <= _last) {
            cout << _entrys[i]->value << " " << _entrys[i]->priority << " " <<_entrys[i] << endl;
        } else {
            cout << _entrys[i] << endl;
        }
    }

}
