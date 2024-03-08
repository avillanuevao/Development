#ifndef SOURCE_VIEW_OPERATION_SELECTEXPENSETRACKER_HPP
#define SOURCE_VIEW_OPERATION_SELECTEXPENSETRACKER_HPP

#include <memory>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>

#include <source/source/controller/operation/SelectExpenseTracker.hpp>

namespace source
{
namespace view
{
namespace operation
{

class SelectExpenseTracker :
    public QObject
{
    Q_OBJECT
  public:
    SelectExpenseTracker(std::shared_ptr<source::controller::operation::SelectExpenseTracker> controller);

  public slots:
    void selectExpenseTracker(int idExpenseTracker);

  private:
    std::shared_ptr<source::controller::operation::SelectExpenseTracker> mController;
};

}  // namespace operation
}  // namespace view
}  // namespace source


#endif // SOURCE_VIEW_OPERATION_SELECTEXPENSETRACKER_HPP
