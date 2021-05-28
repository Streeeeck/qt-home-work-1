#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItem>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QJsonValue>
#include <QString>
#include <QFileDialog>
#include <QFile>

#include <QDebug>

#include <QDialogButtonBox>
#include <QFormLayout>

#include "storage.h"
#include "dialogadd.h"
#include "myqlinklist.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QTableView *view;
    MyQLinkList *linklist;
    QStandardItemModel *model;
    QStandardItem * item;
    QString filename;
    DialogAdd* dlg;
};
#endif // MAINWINDOW_H
