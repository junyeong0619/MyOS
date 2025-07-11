//
// Created by Junyeong on 2025. 7. 11..
//

#ifndef RESOURCE_H
#define RESOURCE_H
#include <cstdint>


class Resource {
    uint64_t  whole_memory;
    uint64_t  used_memory;
    uint64_t process_number;
    bool resource_available;

    public:
    explicit Resource(uint64_t whole_memory);
    ~Resource();

    [[nodiscard]] uint64_t getProcessNumber() const;
    [[nodiscard]] uint64_t getUsedMemory() const;
    [[nodiscard]] uint64_t getAvailableMemory() const;
    [[nodiscard]] bool getResourceAvailable() const;

    void setProcessNumber(uint64_t process_number);
    void setUsedMemory(uint64_t used_memory);
    void setResourceAvailable(bool resource_available);
    void setAvailableMemory(uint64_t available_memory);
};



#endif //RESOURCE_H
