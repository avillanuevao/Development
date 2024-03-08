#include "RegisterUser.hpp"

namespace source
{
namespace controller
{
namespace operation
{

RegisterUser::RegisterUser(std::shared_ptr<model::operation::iAllUsers> allUsers) :
  mAllUsers(allUsers)
{
}

void RegisterUser::registerUser(int idUser, std::string nameUser)
{
  mAllUsers->registerUser(idUser, nameUser);
}

}  // namespace operation
}  // namespace controller
}  // namespace source
