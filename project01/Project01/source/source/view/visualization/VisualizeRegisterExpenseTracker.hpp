#ifndef SOURCE_VIEW_VISUALIZATION_VISUALIZEREGISTEREXPENSETRACKER_HPP
#define SOURCE_VIEW_VISUALIZATION_VISUALIZEREGISTEREXPENSETRACKER_HPP

#include <iostream>

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQuickWindow>
#include <QAbstractItemModel>
#include <QStandardItem>

namespace source
{
namespace view
{
namespace visualization
{

class VisualizeRegisterExpenseTracker :
    public QObject
{
    Q_OBJECT
  public:
    VisualizeRegisterExpenseTracker(QQmlApplicationEngine& engine, QObject* parent = nullptr);

    void expenseTrackerRegistered(int idExpenseTracker, std::string nameExpenseTracker);

  public slots:
    void addItemsToComboBox(const QString& item);

  private:
    QQmlApplicationEngine& mEngine;
    QObject* mParent;

};

}  // namespace visualization
}  // namespace view
}  // namespace source

#endif // SOURCE_VIEW_VISUALIZATION_VISUALIZEREGISTEREXPENSETRACKER_HPP
