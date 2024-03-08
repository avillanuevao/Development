#ifndef MODEL_OPERATION_ALLUSERS_HPP
#define MODEL_OPERATION_ALLUSERS_HPP

#include <iostream>
#include <map>
#include <memory>

#include <operation/User.hpp>
#include <operation/iAllUsers.hpp>

namespace model
{
namespace operation
{

class AllUsers :
    public model::operation::iAllUsers
{
  public:
    AllUsers();

    void registerUser(int idUser, std::string nameUser) override;
    std::shared_ptr<model::operation::User> getUserById(int idUser) override;

  private:
    std::map<int, std::shared_ptr<model::operation::User>> mAllUsers;
};

}  // namespace operation
}  // namespace model

#endif // MODEL_OPERATION_ALLUSERS_HPP
