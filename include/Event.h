#ifndef EVENT_H
#define EVENT_H

#include <vector>

using namespace std;

template <typename T>
class Event
{
public:
    ~Event();
    void Invoke(T);
    void operator+=(void (*right)(T));
    void operator-=(void (*right)(T));

private:
    vector<void (*)(T)> observers;
};

template <typename T>
Event<T>::~Event()
{
    observers.clear();
}

template <typename T>
void Event<T>::Invoke(T t)
{
    for (void (*observer)(T) : observers)
    {
        observer(t);
    }
}

template <typename T>
void Event<T>::operator+=(void (*right)(T))
{
    observers.push_back(right);
}

template <typename T>
void Event<T>::operator-=(void (*right)(T))
{
    /*

    for (vector<void (*)(T)>::iterator i = observers.begin(); i != observers.end();)
    {
        if (*i == right)
        {
            i = observers.erase(i);
        }

        else
        {
            i++;
        }
    }

    */
}

#endif