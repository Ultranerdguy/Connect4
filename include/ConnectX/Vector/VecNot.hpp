#ifndef _CONNECT_X_VECTOR_VECNOT_HPP_
#define _CONNECT_X_VECTOR_VECNOT_HPP_

#include "VecEx.hpp"

namespace ConnectX::VectorExpression {
  // Employ CRTP to upcast at compile time
  template <typename U>
  class VecNot : public VecEx<VecNot<U>> {
  public:
    using TU = std::conditional_t<U::Leaf, U const&, U>;

    VecNot(VecEx<U> const& u)
      : m_u(static_cast<U const&>(u))
    {
    }

    static constexpr bool Leaf = false;
    static constexpr bool Cycle = U::Cycle;

    auto Size() const {
      return m_u.Size();
    }

    bool operator[](std::size_t index) const {
      return !m_u[index];
    }

    operator bool() {
      std::size_t size = Size();
      for (std::size_t i = 0; i < size; ++i) {
        if (!operator[](i)) return false;
      }
      return true;
    }

  private:
    TU m_u;
  };
}

template <typename U>
auto operator!(ConnectX::VectorExpression::VecEx<U> const& value) {
  return ConnectX::VectorExpression::VecNot<U>(value);
}
#endif // #ifndef _CONNECT_X_VECTOR_VECNOT_HPP_