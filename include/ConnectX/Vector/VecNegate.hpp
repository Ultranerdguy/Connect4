#ifndef _CONNECT_X_VECTOR_VECNEGATE_HPP_
#define _CONNECT_X_VECTOR_VECNEGATE_HPP_

#include "VecEx.hpp"

namespace ConnectX::VectorExpression {
  // Employ CRTP to upcast at compile time
  template <typename U>
  class VecNegate : public VecEx<VecNegate<U>> {
  public:
    using TU = std::conditional_t<U::Leaf, U const&, U>;

    VecNegate(VecEx<U> const& u)
      : m_u(static_cast<U const&>(u))
    {
    }

    static constexpr bool Leaf = false;
    static constexpr bool Cycle = U::Cycle;

    auto Size() const {
      return m_u.Size();
    }

    auto operator[](std::size_t index) const {
      return -m_u[index];
    }

  private:
    TU m_u;
  };
}

template <typename U>
auto operator-(ConnectX::VectorExpression::VecEx<U> const& value) {
  return ConnectX::VectorExpression::VecNegate<U>(value);
}
#endif // #ifndef _CONNECT_X_VECTOR_VECNEGATE_HPP_