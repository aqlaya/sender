#pragma once


#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <queue>
#include <memory>

template <typename T>
class threadsafe_queue 
{
    public:

        threadsafe_queue() = default;
        ~threadsafe_queue() = default;

        threadsafe_queue(const threadsafe_queue&) = delete;

        threadsafe_queue& operator=(const threadsafe_queue&) = delete;

        void push(T&& new_value)
        {

            std::lock_guard<std::mutex> lk(mut);
            data_queue.push(std::forward<T>(new_value));
            data_cond.notify_one(); 
        }

        bool try_pop(T& value)
        {
            std::lock_guard<std::mutex> lk(mut);
            if (!data_queue.empty())
            {
                value = data_queue.back();
                data_queue.pop();
                return true;
            }
            return false;
        }

        std::shared_ptr<T> try_pop()
        {

            std::lock_guard<std::mutex> lk(mut);
            if (!data_queue.empty()) {
                std::shared_ptr<T> ptr_value = std::make_shared<T>(std::move(data_queue.back()));
                data_queue.pop();
                return ptr_value;
            }
            return std::shared_ptr<T>();
        }

        void wait_and_pop(T& value)
        {
            std::unique_lock<std::mutex> lk(mut);
            data_cond.wait(lk, [this](){ return data_queue.empty();});
            value = data_queue.back();
            data_queue.pop();
        }

        std::shared_ptr<T> wait_and_pop()
        {
            std::unique_lock<std::mutex> lk(mut);
            data_cond.wait(lk, [this](){ return data_queue.empty(); });
            std::shared_ptr<T> ptr_value = std::make_shared(data_queue.back());
            data_queue.pop();
        }


        bool empty() const {
            return data_queue.empty();
        }

    private:
            mutable std::mutex mut;
            std::queue<T> data_queue;
            std::condition_variable data_cond;
};


