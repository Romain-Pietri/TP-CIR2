#include "Vector.hpp"
#include <iostream>

using namespace std;

My_vector::My_vector() {
    size = 0;
    tab = new my_type[size];
}
My_vector::My_vector(const size_t&size) {
    if(size < 0){
        this->size = 0;
        tab = new my_type[0];
    }
    else if(size>=1073741824){
        this->size = 1073741823;
        tab = new my_type[size];
    }
    else{
        this->size = size;
        tab = new my_type[size];
    }
}

My_vector::~My_vector() {
    delete[] tab;
}
My_vector::My_vector(const My_vector&v) {
    size = v.size;
    tab = new my_type[size];
    for (int i = 0; i < size; i++) {
        tab[i] = v.tab[i];
    }
}
const size_t&My_vector::get_size()const {
    return size;
}
void My_vector::set_an_element(const size_t&index,const my_type&val) {
    if (index < size) {
        tab[index] = val;
    }
}
const my_type&My_vector::get_an_element(const size_t&index)const {
    if (index < size) {
        return tab[index];
    }
    return tab[size];
}

void My_vector::push(const my_type&val) {
    my_type *temp = new my_type[size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = tab[i];
    }
    temp[size] = val;
    delete[] tab;
    tab = temp;
    size++;
}

int main(){
    My_vector v(10);
    v.set_an_element(0, 1);
    v.set_an_element(1, 2);
    v.set_an_element(2, 3);
    v.set_an_element(3, 4);
    v.set_an_element(4, 5);
    v.set_an_element(5, 6);
    v.set_an_element(6, 7);
    v.set_an_element(7, 8);
    v.set_an_element(8, 9);
    v.set_an_element(9, 10);
    v.push(11);
    for (int i = 0; i < v.get_size(); i++) {
        cout << v.get_an_element(i) << endl;
    }
    return 0;
}
