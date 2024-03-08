#ifndef SOURCE_CONTROLLER_OPERATION_REGISTERUSER_HPP
#define SOURCE_CONTROLLER_OPERATION_REGISTERUSER_HPP

#include <memory>
#include <string>

#include <model/source/operation/iAllUsers.hpp>

namespace source
{
namespace controller
{
namespace operation
{

class RegisterUser
{
  public:
    RegisterUser(std::shared_ptr<model::operation::iAllUsers> allUsers);

    void registerUser(int idUser, std::string nameUser);

  private:
    std::shared_ptr<model::operation::iAllUsers> mAllUsers;
};

}  // namespace operation
}  // namespace controller
}  // namespace source

#endif // SOURCE_CONTROLLER_OPERATION_REGISTERUSER_HPP
