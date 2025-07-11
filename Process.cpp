//
// Created by Junyeong on 2025. 7. 11..
//

#include "Process.h"

#include <iostream>
using namespace std;

Process::Process(const string &process_name, uint64_t whole_memory) {
    this->process_name = process_name;
    this->resource = make_unique<Resource>(whole_memory);
    this->is_running = false;
    this->total_running_time = 0;
}

Process::~Process() = default;

uint64_t Process::get_total_running_time() const {
    return this->total_running_time;
}

bool Process::get_running_statement() const {
    return this->is_running;
}

string Process::get_process_name() const {
    return this->process_name;
}


void Process::start() {
    if (!is_running) {
        start_time = chrono::high_resolution_clock::now();
        is_running = true;
        cout << "Process '" << process_name << "' started." << endl;
    } else {
        cout << "Process '" << process_name << "' is already running." << endl;
    }
}

void Process::stop() {
    if (is_running) {
        chrono::high_resolution_clock::time_point end_time = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end_time - start_time;
        total_running_time += static_cast<uint64_t>(duration.count() * 1000);

        is_running = false;
        cout << "Process '" << process_name << "' stopped. Total running time: "
                  << total_running_time << " ms" << endl;
    } else {
        cout << "Process '" << process_name << "' is not running." << endl;
    }
}

void Process::pause() {
    if (is_running) {
        chrono::high_resolution_clock::time_point pause_time = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = pause_time - start_time;
        total_running_time += static_cast<uint64_t>(duration.count() * 1000);

        is_running = false;
        cout << "Process '" << process_name << "' paused. Current total running time: "
                  << total_running_time << " ms" << endl;
    } else {
        cout << "Process '" << process_name << "' is not running or already paused." << endl;
    }
}

void Process::resume() {
    this->start();
}

