//
// Created by Junyeong on 2025. 7. 11..
//

#include "Resource.h"

#define EMPTY 0

Resource::Resource(uint64_t whole_memory) {
    this->whole_memory = whole_memory;
    this->process_number = EMPTY;
    this->used_memory = EMPTY;
    this->resource_available = true;
}

Resource::~Resource() = default;


uint64_t Resource::getProcessNumber() const {
    return this->process_number;
}

uint64_t Resource::getUsedMemory() const {
    return this->used_memory;
}

uint64_t Resource::getAvailableMemory() const {
    return this->whole_memory - this->used_memory;
}

bool Resource::getResourceAvailable() const {
    return this->resource_available;
}

void Resource::setProcessNumber(const uint64_t process_number) {
    this->process_number = process_number;
}

void Resource::setUsedMemory(const uint64_t used_memory) {
    this->used_memory = used_memory;
}

void Resource::setResourceAvailable(const bool resource_available) {
    this->resource_available = resource_available;
}

void Resource::setAvailableMemory(const uint64_t available_memory) {
    this->used_memory = available_memory;
}
