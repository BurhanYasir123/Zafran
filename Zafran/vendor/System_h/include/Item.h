#pragma once

template<typename T>
struct Item
{
    T data;
    int id;
    Item() : data(nullptr), id(-1) {}
    Item(T Data, int Id) { data = Data; id = Id; }
};
