#include <iostream>
#include <matplot/matplot.h>
#include <fstream>
#include <vector>
#include <thread> // for sleep_for
#include <chrono> // for miliseconds or seconds

int main() {
    using namespace matplot;
    using namespace std;

    constexpr size_t SIZE = 8'000'000;

    ifstream file("IQdataName.bin", ios::binary);
        if (!file) {
            cerr << "Dosya açılamadı." << endl;
            return 1;
        }

    vector<int16_t> data;
    
    data.resize(SIZE); 
    data.reserve(SIZE);
    cout << data.capacity();
    int16_t value;

        while (file.read(reinterpret_cast<char*>(data.data()), sizeof(int16_t) * SIZE)) {
        }

    vector<int16_t> x;
    vector<int16_t> y;

        for (size_t i = 0; i < data.size(); i++) {
                if (i % 2 == 0) {
                    x.push_back(data[i]);
                } else {
                    y.push_back(data[i]);
                }
        }
    
    vector<double> Lspace = linspace(0, x.size()/8, x.size()/8);

        for(size_t i = 0; i<x.size(); i++){

        vector<double> tempX(Lspace.begin(), Lspace.begin() + i);
            vector<int16_t> tempY(x.begin(), x.begin() + i);
            plot(tempX, tempY);
            this_thread::sleep_for(chrono::milliseconds(100)); // wait for 1 second

        }
            hold(true);
            show();

            
    return 0;
}
