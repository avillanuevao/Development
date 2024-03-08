#ifndef MODEL_OPERATION_IUSER_HPP
#define MODEL_OPERATION_IUSER_HPP

#include <iostream>
#include <map>

namespace model
{
namespace operation
{

class iUser
{
  public:
    iUser() = default;

    virtual int getId() const = 0;
    virtual const std::string& getName() const = 0;
};

}  // namespace operation
}  // namespace model

#endif // MODEL_OPERATION_IUSER_HPP
