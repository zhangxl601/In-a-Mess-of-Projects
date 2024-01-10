#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include "plateManager.h"
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
    void on_cb_type_currentIndexChanged(int index);

    void on_btn_sort_clicked();

    void on_btn_generate_clicked();

    void on_btn_find_clicked();

private:
    Ui::MainWindow *ui;
    plateManager* m_plateManager;

    int m_inputType = 0;
    QStringList m_list;
    QStringList m_inputlist;
    QStringList m_findlist;
    QMap<QString,QString> m_map;
};
#endif // MAINWINDOW_H
