#ifndef SOURCE_VIEW_VISUALIZATION_VISUALIZEUSEROFEXPENSETRACKER_HPP
#define SOURCE_VIEW_VISUALIZATION_VISUALIZEUSEROFEXPENSETRACKER_HPP

#include <memory>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include <QAbstractItemModel>
#include <QStandardItem>

#include <model/source/operation/iAllExpensesTrackers.hpp>
#include <model/source/operation/iAllUsers.hpp>

namespace source
{
namespace view
{
namespace visualization
{

class VisualizeUserOfExpenseTracker :
    public QObject
{
    Q_OBJECT
  public:
    VisualizeUserOfExpenseTracker(QQmlApplicationEngine& engine, QObject* parent);

    void showUserOfExpenseTracker(int idExpenseTracker);

  private:
    std::shared_ptr<model::operation::iAllExpensesTrackers> mAllExpensesTrackers;
    std::shared_ptr<model::operation::iAllUsers> mAllUsers;
    QQmlApplicationEngine& mEngine;
    QObject* mParent;
};

}  // namespace visualization
}  // namespace view
}  // namespace source

#endif // SOURCE_VIEW_VISUALIZATION_VISUALIZEUSEROFEXPENSETRACKER_HPP
