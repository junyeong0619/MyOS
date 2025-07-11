//
// Created by Junyeong on 2025. 7. 11..
//

#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include "Resource.h"
using namespace std;



class Process {
    unique_ptr<Resource> resource;
    bool is_running;
    uint64_t total_running_time;
    string process_name;
    chrono::high_resolution_clock::time_point start_time;

    public:
    explicit Process(const string &process_name, uint64_t whole_memory);
    ~Process();

    [[nodiscard]] uint64_t get_total_running_time() const;
    [[nodiscard]] bool get_running_statement() const;
    [[nodiscard]] string get_process_name() const;


    void start();
    void stop();
    void pause();
    void resume();

};



#endif //PROCESS_H
