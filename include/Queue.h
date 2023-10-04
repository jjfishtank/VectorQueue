// Queue.h
//
#ifndef Queue_h
#define Queue_h

#include <vector>
#include <sstream>
#include <iostream>

template <typename T>
class Queue {
private:
  std::vector<T> data_;
  size_t head_, tail_;
  static T sentinel_;
public:
  static const int MAX_DISP_ELEMS = 100;
  Queue(size_t size);
  static void setSentinel(const T& elem) { sentinel_ = elem; }
  static T getSentinel() { return sentinel_; }
  bool empty() const;
  size_t size() const { return tail_; }
  void resize(size_t size);
  const T& peek() const;
  bool dequeue();
  bool enqueue(const T& elem);
  std::string toString(size_t limit = MAX_DISP_ELEMS) const {
    std::ostringstream oss;
    oss << "# Queue - size = " << size() << "\ndata :";
    for (auto i = head_; i != tail_; ++i) {
      oss << ' ' << data_[i];
    }
    oss << '\n';
    return oss.str();
  }

  Queue<T>& operator= (const Queue<T>& that);
  friend class Tests; // Don't remove this line
};

template <typename T>
T Queue<T>::sentinel_ = T();

template <typename T>
Queue<T>::Queue(size_t size) {
  data_.resize(size + 1);
  head_ = 0;
  tail_ = head_;
}

template <typename T>
bool Queue<T>::enqueue(const T& elem) {
  if (head_ != (tail_ + 1) % data_.size()) {
    data_[tail_] = elem;
    tail_++;
    return true;
  }
  return false;
}

template <typename T>
bool Queue<T>::dequeue() {
  if (head_ != tail_) {
    data_.erase(data_.begin());
    tail_--;
    return true;
  }
  return false;
}

template <typename T>
const T& Queue<T>::peek() const {
  if (head_ != tail_) {
    return data_[head_];
  }
  return sentinel_;
}

template <typename T>
bool Queue<T>::empty() const {
  if (head_ == tail_) {
    return true;
  }
  return false;
}

template <typename T>
void Queue<T>::resize(size_t size) {
  Queue<T> next(size);

  while (head_ != tail_) {
    next.enqueue(data_[head_]);
    dequeue();
  }
  *this = next;
}

template <typename T>
void popalot(Queue<T>& q) {
  while (!q.empty()) {
    q.dequeue();
  }
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& that) {
  data_ = that.data_;
  head_ = that.head_;
  tail_ = that.tail_;
  return *this;
}
#endif // !Queue_h
