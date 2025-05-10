template <typename T> Accumulator<T>::Accumulator() {
  _sum = 0;
  _min = std::numeric_limits<T>::max();
  _max = std::numeric_limits<T>::lowest();
  _count = 0;
}

template <typename T>
Accumulator<T>::Accumulator(T const &v)
    : _sum(v), _min(v), _max(v), _count(1) {}

template <typename T> void Accumulator<T>::setCount(size_t x) { _count = x; }

template <typename T> void Accumulator<T>::add(T const &x) {
  _sum += x;
  _min = x < _min ? x : _min;
  _max = x > _max ? x : _max;
  _count += 1;
}

template <typename T> double Accumulator<T>::getMean() {
  if (_count == 0) {
    throw std::runtime_error("Cannot calculate mean: count is zero.");
  }
  return static_cast<double>(_sum) / _count;
}

template <typename T> void Accumulator<T>::reset() { *this = Accumulator(); }

template <typename T> T Accumulator<T>::getSum() const { return _sum; }
template <typename T> T Accumulator<T>::getMin() const { return _min; }
template <typename T> T Accumulator<T>::getMax() const { return _max; }
template <typename T> size_t Accumulator<T>::getCount() const { return _count; }

template <typename T> std::string Accumulator<T>::test() {
  return "I am a private function.";
}