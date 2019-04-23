#ifndef _PQUEUE_H
#define _PQUEUE_H

using namespace std;

class MyException {
};

template <typename T>
struct pqentry{
    float priority;
    T value;
    pqentry(float getPriority, T getValue);
}

template <typename T>
class PriorityQueue {
private:
    int _size;
    int _last;
    pqentry<T> **_entrys; //Array aus pqentry<T> Pointern
    bool isFull(void);
    bool isAlmostFull(void);
    void changeArray(int x);
public:
    PriorityQueue(int size = 100);
    ~PriorityQueue(void);
    void insert(T value, float priority);
    T extractMin(void);
    void decreaseKey(T value, float priority);
    void remove(T value);
    bool isEmpty(void);
    void print();
};

template <typename T>
pqentry<T>::pqentry(float getPriority, T getValue) {
    priority = getPriority;
    value = getValue;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(int size) {
    _size = size;
    _last = -1;
    _entrys = new pqentry<T>*[size];
}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    for (int i = 0; i < _last ; i++) {
        delete _entrys[i];
    }
    delete[] _entrys;
}


template <typename T>
void PriorityQueue<T>::changeArray(int x) {
    if (x == 1) {
        if (isFull() || isAlmostFull()) {
            pqentry<T> **newArray = new pqentry<T>*[_size * 2];
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
            pqentry<T> **newArray = new pqentry<T>*[_size / 2];
            for (int arraysize = 0; arraysize <= _last ; arraysize++) {
                newArray[arraysize] = _entrys[arraysize];
            }
            delete[](_entrys);
            _size /= 2;
            _entrys = newArray;
        }
    }
}

template <typename T>
bool PriorityQueue<T>::isFull() {
    return _last == (_size - 1);
}

template <typename T>
bool PriorityQueue<T>::isAlmostFull() {
    return _last > (_size - 2);
}

template <typename T>
bool PriorityQueue<T>::isEmpty() {
    if (_last == -1) { // ARRAY ist leer
    return 1;
}

template <typename T>
void PriorityQueue<T>::insert(T value, float priority) {
    if (isEmpty()) { // ARRAY ist leer
        _last += 1;
        _entrys[_last] = new pqentry<T>(priority,value);
    } else {
        int i = 1;
        changeArray(1);
        if (priority < _entrys[0]->priority) { //wenn oberste Priorität
            for (int arraysize = _last; arraysize >= 0; arraysize--) {
                _entrys[arraysize + 1] = _entrys[arraysize];
            }
            _entrys[0] = new pqentry<T>(priority, value);
            _last += 1;
        } else if (priority > _entrys[_last]->priority) { //wenn niedrigste Priorität
            _last += 1;
            _entrys[_last] = new pqentry<T>(priority, value);
        } else {
            while (_entrys[i]->priority < priority) {
                i++;
            }
            for (int arraysize = _last; arraysize >= i; arraysize--) {
                _entrys[arraysize + 1] = _entrys[arraysize];
            }
            _entrys[i] = new pqentry<T>(priority, value);
            _last += 1;
        }
    }
}

template <typename T>
T PriorityQueue<T>::extractMin() {
    T ret;
    if(_last == -1) {
        cout << "Bitte erst das Array mit Inhalt befüllen" << endl;
    }
    ret = _entrys[0]->value;
    remove(ret);
 
    return ret;
}

template <typename T>
void PriorityQueue<T>::remove(T value) {
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

template <typename T>
void PriorityQueue<T>::decreaseKey(T value, float priority) {
    remove(value);
    insert(value,priority);
}

template <typename T>
void PriorityQueue<T>::print() {
    for(int i = 0; i < _size;i++) {
        if (i <= _last) {
            cout << _entrys[i]->value << " " << _entrys[i]->priority << " " <<_entrys[i] << endl;
        } else {
            cout << _entrys[i] << endl;
        }
    }

}

#endif
