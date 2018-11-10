#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "converter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_mat2af_clicked();

    void on_af2mat_clicked();

    void on_loadBtn_clicked();

private:
    Ui::MainWindow *ui;
    void test_af2mat(const char *filename);
    void test_mat2af(const char *filename);
    char* filename;
};

#endif // MAINWINDOW_H
