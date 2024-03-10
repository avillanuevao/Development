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
  std::shared_ptr<model::operation::User> user = std::make_shared<model::operation::User>(idUser, nameUser);
  mAllUsers[idUser] = user;

  model::operation::signal::UserAdded signal(idUser);
  utils::designPattern::SignalPublisher<model::operation::signal::UserAdded>::notifySubscribers(signal);
}

std::shared_ptr<model::operation::User> AllUsers::getUserById(int idUser)
{
  return mAllUsers[idUser];
}

}  // namespace operation
}  // namespace model
