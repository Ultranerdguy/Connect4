#ifndef _CONNECT_X_VECTOR_VECSCALAR_HPP_
#define _CONNECT_X_VECTOR_VECSCALAR_HPP_

#include <concepts>

namespace ConnectX::VectorExpression {
  // Employ CRTP to upcast at compile time
  template <typename T>
  class VecScalar : public VecEx<VecScalar<T>> {
  public:
    VecScalar(T const& value)
      : m_value(value)
    {
    }

    static constexpr bool Leaf = false;
    static constexpr bool Cycle = true;

    std::size_t Size() const {
      return 1;
    }

    T const& operator[](std::size_t index) const {
      return m_value;
    }
  private:
    T m_value;
  };

  namespace Concept {
    template <typename T>
    concept Scalar = std::integral<T> || std::floating_point<T>;
  }
}

#endif // #ifndef _CONNECT_X_VECTOR_VECEX_HPP_