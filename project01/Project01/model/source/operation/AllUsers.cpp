#include "AllUsers.hpp"

namespace model
{
namespace operation
{

AllUsers::AllUsers()
{

}

void AllUsers::registerUser(int idUser, std::string nameUser)
{
  mAllUsers[idUser] = std::make_shared<model::operation::User>(idUser, nameUser);
}

std::shared_ptr<model::operation::User> AllUsers::getUserById(int idUser)
{
  return mAllUsers[idUser];
}

}  // namespace operation
}  // namespace model
