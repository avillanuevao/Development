#ifndef SOURCE_CONTROLLER_VISUALIZATION_REGISTERUSER_HPP
#define SOURCE_CONTROLLER_VISUALIZATION_REGISTERUSER_HPP

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include <QString>

#include <memory>

#include <source/source/controller/operation/RegisterUser.hpp>

namespace source
{
namespace view
{
namespace operation
{

class RegisterUser :
    public QObject
{
    Q_OBJECT
  public:
    RegisterUser(std::shared_ptr<source::controller::operation::RegisterUser> controller);

  public slots:
    void registerUser(QString nameUser);

  private:
    std::shared_ptr<source::controller::operation::RegisterUser> mController;
    int mLastIdUser = 0;
};

}  // namespace operation
}  // namespace view
}  // namespace source

#endif // SOURCE_CONTROLLER_VISUALIZATION_REGISTERUSER_HPP
