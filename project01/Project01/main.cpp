#include <memory>
#include <iostream>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <model/source/operation/AllUsers.hpp>
#include <source/source/controller/operation/RegisterUser.hpp>
#include <source/source/view/operation/RegisterUser.hpp>

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  std::shared_ptr<model::operation::AllUsers> allUsersPtr = std::make_shared<model::operation::AllUsers>();

  std::shared_ptr<source::controller::operation::RegisterUser> controllerRegisterUser =
      std::make_shared<source::controller::operation::RegisterUser>(allUsersPtr);

  std::shared_ptr<source::view::operation::RegisterUser> viewRegisterUser =
      std::make_shared<source::view::operation::RegisterUser>(controllerRegisterUser);

  engine.rootContext()->setContextProperty("viewRegisterUser", viewRegisterUser.get());

  const QUrl url(QStringLiteral("qrc:/main.qml"));
  engine.load(url);

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return app.exec();
}
