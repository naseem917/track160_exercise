#pragma once

#include <mutex>
#include <queue>
#include <condition_variable>

// Empty class to signal that we want to stop executing.
class Stop {};

template<typename T>
class TaskQueue {
public:
    // Adds task to the queue. TaskQueue owns this task.
    void PushTask(T&& task);
    // Returns a task from the queue. Blocks if no tasks are available.
    // User owns the returned task.
    T GetTask();

private:
    std::queue<T> m_queue; // Israeli Queue might be better to allow the STOP tasks to jump the line.
    // Lock every time we modify the queue.
    std::mutex m_lock;
    // Wake up threads waiting for new tasks.
    std::condition_variable m_condition;
};


// Implementation

template<typename T>
void TaskQueue<T>::PushTask(T&& t)
{
    {
        std::scoped_lock l{ m_lock };
        m_queue.push(std::move(t));
    }
    m_condition.notify_one();
}

template<typename T>
T TaskQueue<T>::GetTask()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(m_lock);
        // Lock is released while waiting, and reacquired after.
        m_condition.wait(lock, [&m_queue = this->m_queue]()
        { return !m_queue.empty(); });
        // Just in case someone else grabbed our task, we will double check.
        // Worst case we will wait for the next one.
        if (!m_queue.empty()) {
            auto ret = m_queue.front();
            m_queue.pop();
            return ret;
        }
    }
}