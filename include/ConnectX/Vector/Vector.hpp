#ifndef _CONNECT_X_VECTOR_VECTOR_HPP_
#define _CONNECT_X_VECTOR_VECTOR_HPP_

#include <vector>
#include <initializer_list>
#include "VecEx.hpp"
#include "VecScalar.hpp"
#include "VecSum.hpp"
#include "VecSub.hpp"
#include "VecMul.hpp"
#include "VecDiv.hpp"
#include "VecEqual.hpp"
#include "VecLess.hpp"
#include "VecLessEq.hpp"
#include "VecGreater.hpp"
#include "VecGreaterEq.hpp"
#include "VecMin.hpp"
#include "VecMax.hpp"

namespace ConnectX::VectorExpression {
  template <typename T>
  class Vector : public VecEx<Vector<T>> {
  public:
    using TStorage = std::vector<T>;
    using TIterator = typename TStorage::iterator;
    using TCIterator = typename TStorage::const_iterator;
    // Constructors
    Vector() = default;
    Vector(std::initializer_list<T> const& list)
      : m_data(list)
    {
    }

    template <typename U>
    Vector(VecEx<U> const& v) {
      std::size_t const size = v.Size();
      m_data.resize(size,T{});
      for (std::size_t i = 0; i < size; ++i) {
        m_data[i] = v[i];
      }
    }
    Vector(std::size_t const size, T const& init) 
      : m_data(size, init)
    {
    }

    // VecEx template interface
    static constexpr bool Leaf = true;

    auto Size() const {
      return m_data.size();
    }

    auto operator[](std::size_t index) const {
      return m_data[index];
    }

    auto& operator[](std::size_t index) {
      return m_data[index];
    }

    // iterator interface
    TIterator begin() {
      return m_data.begin();
    }

    TCIterator begin() const {
      return m_data.begin();
    }

    TCIterator cbegin() const {
      return m_data.cbegin();
    }

    TIterator end() {
      return m_data.end();
    }

    TCIterator end() const {
      return m_data.end();
    }
    
    TCIterator cend() const {
      return m_data.cend();
    }

    // Convenience interface
    bool IsEmpty() const {
      return m_data.empty();
    }

    void Append(T const& t) {
      m_data.push_back(t);
    }

  private:
    TStorage m_data;
  };
}

#endif // #ifndef _CONNECT_X_VECTOR_VECTOR_HPP_