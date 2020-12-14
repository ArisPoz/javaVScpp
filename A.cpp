#include <iostream>
#include <chrono>
using namespace std;

class A2 {
    public:
        int data1;
        int data2;
        virtual void virtualFoo(){};
};

void createGarbage(int size) {
    for(int j = 0; j < size; j++) {
        A2 *a = new A2();
        a->data1 = j;
        a->data2 = j*2;
        delete a;
    }
}

void allocate(int in) {
    int size = in;
    A2 *a = NULL;
    A2 *ar[size];
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        createGarbage(100);
        a = new A2();
        a->data1 = i;
        a->data2 = i*2;
        ar[i] = a;
    }

    for (int i=0; i<size; i++) {
        int pos = rand() % size;
        A2 *temp = ar[i];
        ar[i] = ar[pos];
        ar[pos] = temp;
    }

    for (int i = 0; i < size; i++) {
        sum += ar[i]->data2 + ar[i]->data1;
        delete ar[i];
    }
    
    cout << "Total: " << sum << endl;
    cout << "Phase Completion" << endl;
}

int main(int argc, char **argv) {
    auto t_start = chrono::high_resolution_clock::now();
    allocate(atoi(argv[1]));
    auto t_end = chrono::high_resolution_clock::now();
    double dur = chrono::duration<double, std::milli>(t_end-t_start).count()/1000;
    cout << "Duration: " << dur << "s" << endl;
    return 0;
}