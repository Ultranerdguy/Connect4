#ifndef _CONNECT_X_DENSE_BOARD_HPP_
#define _CONNECT_X_DENSE_BOARD_HPP_

#include "IBoard.hpp"

namespace ConnectX {
  class DenseBoard : public IBoard {
  public:
    explicit DenseBoard(Vector const& start, Vector const& end);

    virtual Vector GetStart() const override;
    virtual Vector GetEnd() const override;
    virtual Token GetAt(Vector const& position) const override;
    virtual void SetAt(Vector const& position, Token const token) override;
    virtual TokenBuffer GetRange(Vector const& start, Vector const& end) const override;
    
  private:
    TokenBuffer m_grid;
    Vector m_start;
    Vector m_end;
  };
}

#endif // #ifndef _CONNECT_X_DENSE_BOARD_HPP_
