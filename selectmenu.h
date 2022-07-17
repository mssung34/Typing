#ifndef SELECTMENU_H
#define SELECTMENU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SelectMenu; }
QT_END_NAMESPACE

class SelectMenu : public QMainWindow
{
    Q_OBJECT

public:
    SelectMenu(QWidget *parent = nullptr);
    ~SelectMenu();

private slots:
    void on_start_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::SelectMenu *ui;
};
#endif // SELECTMENU_H
