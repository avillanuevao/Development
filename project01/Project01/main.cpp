#include <memory>
#include <iostream>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <model/source/operation/AllUsers.hpp>
#include <model/source/operation/AllExpensesTrackers.hpp>
#include <source/source/controller/operation/RegisterUser.hpp>
#include <source/source/view/operation/RegisterUser.hpp>
#include <source/source/controller/operation/RegisterExpenseTracker.hpp>
#include <source/source/view/operation/RegisterExpenseTracker.hpp>

#include <source/source/includeView/visualization/VisualizeRegisterExpenseTracker.hpp>
#include <source/source/controller/visualization/VisualizeRegisterExpenseTracker.hpp>
#include <source/source/view/visualization/VisualizeRegisterExpenseTracker.hpp>



int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);
  QQmlApplicationEngine engine;

  std::shared_ptr<model::operation::AllUsers> allUsersPtr = std::make_shared<model::operation::AllUsers>();
  std::shared_ptr<model::operation::AllExpensesTrackers> allExpensesTrackersPtr = std::make_shared<model::operation::AllExpensesTrackers>();

  std::shared_ptr<source::view::visualization::VisualizeRegisterExpenseTracker> viewVisualizeRegisterExpenseTracker =
      std::make_shared<source::view::visualization::VisualizeRegisterExpenseTracker>(engine);

  std::shared_ptr<source::controller::operation::RegisterUser> controllerRegisterUser =
      std::make_shared<source::controller::operation::RegisterUser>(allUsersPtr);
  std::shared_ptr<source::controller::operation::RegisterExpenseTracker> controllerRegisterExpenseTracker =
      std::make_shared<source::controller::operation::RegisterExpenseTracker>(allExpensesTrackersPtr);
  std::shared_ptr<source::controller::visualization::VisualizeRegisterExpenseTracker> controllerVisualizeRegisterExpenseTracker =
      std::make_shared<source::controller::visualization::VisualizeRegisterExpenseTracker>(viewVisualizeRegisterExpenseTracker);

  std::shared_ptr<source::view::operation::RegisterUser> viewRegisterUser =
      std::make_shared<source::view::operation::RegisterUser>(controllerRegisterUser);
  std::shared_ptr<source::view::operation::RegisterExpenseTracker> viewRegisterExpenseTracker =
      std::make_shared<source::view::operation::RegisterExpenseTracker>(controllerRegisterExpenseTracker);
  std::shared_ptr<source::includeView::visualization::VisualizeRegisterExpenseTracker> includeViewVisualizeRegisterExpenseTracker =
      std::make_shared<source::includeView::visualization::VisualizeRegisterExpenseTracker>(controllerVisualizeRegisterExpenseTracker);

  allExpensesTrackersPtr->
      utils::designPattern::SignalPublisher<model::operation::signal::AddExpenseTracker>::addSubscriber(
        includeViewVisualizeRegisterExpenseTracker);

  engine.rootContext()->setContextProperty("viewRegisterUser", viewRegisterUser.get());
  engine.rootContext()->setContextProperty("viewRegisterExpenseTracker", viewRegisterExpenseTracker.get());

  const QUrl url(QStringLiteral("qrc:/main.qml"));
  engine.load(url);

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return app.exec();
}
