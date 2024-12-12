#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <string>

class Queue {
public:
    bool is_empty() const {
        return items.empty();
    }
    void enqueue(const std::string& item) {
        items.push(item);
    }
    std::string dequeue() {
        if (is_empty()) {
            throw std::runtime_error("Queue is empty, cannot dequeue.");
        }
        std::string front = items.front();
        items.pop();
        return front;
    }

private:
    std::queue<std::string> items;
};

#endif // QUEUE_H