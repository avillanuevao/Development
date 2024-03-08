#include "User.hpp"

namespace model
{
namespace operation
{

User::User(int id, std::string name) :
  mId(id), mName(name)
{

}

int User::getId() const
{
  return mId;
}

const std::string& User::getName() const
{
  return mName;
}

}  // namespace operation
}  // namespace model


