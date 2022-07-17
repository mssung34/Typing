#ifndef TYPINGPRACTICE_H
#define TYPINGPRACTICE_H
#include "database.h"

#include <QDialog>
#include <list>
#include <ctime>

namespace Ui {
class TypingPractice;
}

class TypingPractice : public QDialog
{
    Q_OBJECT

public:
    explicit TypingPractice(QWidget *parent = nullptr);
    void Show_text();
    void End_typing();
    ~TypingPractice();

private slots:
    void on_exit_btn_clicked();

    void on_input_text_returnPressed();

private:
    Ui::TypingPractice *ui;
    Database database;
    std::list<std::string> data_list;
    std::list<std::string>::iterator iter;
    std::list<int> speed_list;
    time_t start, end;
    bool enter_check;
    int wrong;
};

#endif // TYPINGPRACTICE_H
