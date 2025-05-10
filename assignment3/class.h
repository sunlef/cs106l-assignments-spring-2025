#ifndef CLASS_H
#define CLASS_H

/**
 * @brief
 一个通用的累加器类，用于统计任意类型数值的总和、最小值、最大值、平均值和样本数量。
 *
 * 此模板类支持对任意支持加法、比较和除法操作的类型 T 进行基本统计计算。
 * 提供了插入数据、获取统计信息和重置状态的接口。

 * @tparam T 用于统计的数值类型，例如 int、float、double 等。
 */
#include <cstddef>
#include <limits>
#include <stdexcept>

template <typename T> class Accumulator {
public:
  Accumulator();
  Accumulator(T const &);

  T getSum() const;
  T getMin() const;
  T getMax() const;
  size_t getCount() const;

  void setCount(size_t x);

  void add(T const &);
  double getMean();
  void reset();

private:
  T _sum;
  T _min, _max;
  size_t _count;

  std::string test();
};

#include "class.cpp"

#endif