#ifndef MODEL_OPERATION_USER_HPP
#define MODEL_OPERATION_USER_HPP

#include <iostream>
#include <map>

#include <operation/iUser.hpp>

namespace model
{
namespace operation
{

class User :
    public model::operation::iUser
{
  public:
    User(int id, std::string name);

    int getId() const override;
    const std::string& getName() const override;

  private:
    int mId;
    std::string mName;
};

}  // namespace operation
}  // namespace model



#endif // MODEL_OPERATION_USER_HPP
