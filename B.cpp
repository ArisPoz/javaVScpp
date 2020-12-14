#include <iostream>
#include <chrono>
using namespace std;

class B2 {
    public:
        int data1;
        int data2;
        virtual void virtualFoo(){};
};

void createGarbage(int size) {
    for(int j = 0; j < size; j++) {
        B2 *b = new B2();
        b->data1 = j;
        b->data2 = j*2;
        delete b;
    }
}

void allocate(int in) {
    int size = in;
    B2 *ar[size];

    createGarbage(size);
    for(int i = 0; i < size; i++) {
        B2 *b = new B2();
        b->data1 = i;
        b->data2 = i*2;
        ar[i] = b;
    }

    createGarbage(size);
    for(int i = 0; i < size; i++) {
        if(10 % (i+1) != 2) {
            delete ar[i];
        }
    }

    for(int i = 0; i < size; i++) {
        B2 *b = new B2();
        b->data1 = i;
        b->data2 = i*2;
        ar[i] = b;
    }

    createGarbage(size);
    for (int i = 0; i < size; i++) {
        delete ar[i];
    }

    cout << "Phase completed" << endl;
}

int main(int argc, char **argv) {
    auto t_start = chrono::high_resolution_clock::now();
    allocate(atoi(argv[1]));
    auto t_end = chrono::high_resolution_clock::now();
    double dur = chrono::duration<double, std::milli>(t_end-t_start).count()/1000;
    cout << "Duration: " << dur << "s" << endl;
    return 0;
}