#ifndef MODEL_OPERATION_IALLUSERS_HPP
#define MODEL_OPERATION_IALLUSERS_HPP

#include <string>
#include <memory>

#include <operation/User.hpp>

namespace model
{
namespace operation
{

class iAllUsers
{
  public:
    iAllUsers() = default;

    virtual void registerUser(int idUser, std::string nameUser) = 0;
    virtual  std::shared_ptr<model::operation::User> getUserById(int idUser) = 0;
};

}  // namespace operation
}  // namespace model

#endif // MODEL_OPERATION_IALLUSERS_HPP
