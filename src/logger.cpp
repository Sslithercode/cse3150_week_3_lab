#include "logger.h"
#include <iostream>
#include <string>

void addReading(const std::string& label, double value,
                std::string labels[], double values[],
                int& size, int capacity) {
    if (size == capacity) {
        throw std::string("Full");
    }
    labels[size] = label;
    values[size] = value;
    ++size;
}

void updateValue(double* valuePtr, double newValue) {
    *valuePtr = newValue;
}

void printReading(const std::string& label, const double& value) {
    std::cout << label << ": " << value << std::endl;
}

double average(const double values[], int size) {
    if (size == 0) throw std::string("Empty");
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += values[i];
    }
    return sum / size;
}

double minValue(const double values[], int size) {
    if (size == 0) throw std::string("Empty");
    double min = values[0];
    for (int i = 1; i < size; ++i) {
        if (values[i] < min) {
            min = values[i];
        }
    }
    return min;
}

double maxValue(const double values[], int size) {
    if (size == 0) throw std::string("Empty");
    double max = values[0];
    for (int i = 1; i < size; ++i) {
        if (values[i] > max) {
            max = values[i];
        }
    }
    return max;
}
