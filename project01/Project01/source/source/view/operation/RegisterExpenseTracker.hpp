#ifndef SOURCE_VIEW_OPERATION_REGISTEREXPENSETRACKER_HPP
#define SOURCE_VIEW_OPERATION_REGISTEREXPENSETRACKER_HPP

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>

#include <source/controller/operation/RegisterExpenseTracker.hpp>

namespace source
{
namespace view
{
namespace operation
{

class RegisterExpenseTracker :
    public QObject
{
    Q_OBJECT
  public:
    RegisterExpenseTracker(std::shared_ptr<source::controller::operation::RegisterExpenseTracker> controller);

  public slots:
    void registerExpenseTracker(QString nameExpense);

  private:
    std::shared_ptr<source::controller::operation::RegisterExpenseTracker> mController;
    int mLastIdExpenseTracker = 0;
};

}  // namespace operation
}  // namespace view
}  // namespace source

#endif // SOURCE_VIEW_OPERATION_REGISTEREXPENSETRACKER_HPP
