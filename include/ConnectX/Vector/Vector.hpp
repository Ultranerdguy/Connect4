#ifndef _CONNECT_X_VECTOR_VECTOR_HPP_
#define _CONNECT_X_VECTOR_VECTOR_HPP_

#include <vector>
#include <initializer_list>
#include "VecEx.hpp"
#include "VecSum.hpp"
#include "VecEqual.hpp"
#include "VecMul.hpp"
#include "VecDiv.hpp"
#include "VecScalar.hpp"

namespace ConnectX::VectorExpression {
  template <typename T>
  class Vector : public VecEx<Vector<T>> {
  public:
    // Constructors
    template <typename U>
    Vector(std::initializer_list<U> const& list)
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
    auto begin() {
      return m_data.begin();
    }

    auto end() {
      return m_data.end();
    }

  private:
    std::vector<T> m_data;
  };
}

#endif // #ifndef _CONNECT_X_VECTOR_VECTOR_HPP_