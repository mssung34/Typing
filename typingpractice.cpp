#include "typingpractice.h"
#include "ui_typingpractice.h"
#include "/usr/include/mysql/mysql.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QtSql>
#include <QDebug>
#include <QSqlTableModel>
#include <QMessageBox>
#include <list>
#include <ctime>
#include <numeric>

using namespace std;

TypingPractice::TypingPractice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TypingPractice)
{
    ui->setupUi(this);

    enter_check = false;
    wrong = 0;

    QSqlDatabase db = database.GetDB();
    QSqlQuery query("select Data from 애국가");
    QSqlRecord rec = query.record();

    int col = rec.indexOf("Data"); // 1
    while(query.next())
    {
        data_list.push_back(query.value(col).toString().toStdString());
    }
    iter = data_list.begin();
}

void TypingPractice::Show_text()
{
    time(&end);
    if(end > start)
    {
        string text = *iter;
        int len = text.length();
        int diff_time = difftime(end, start);
        string user_input = ui->input_text->text().toStdString();
        if(user_input.length()>0)
        {
            for(int i = 0; i < len; i++)
            {
                if(text[i] != user_input[i])
                    wrong++;
            }
            int speed = user_input.length() * 60 / diff_time;
            speed_list.push_back(speed);
            ui->speed_label->setText("타수 : " + QString::number(speed));
            ui->wrong_label->setText("오타 : " + QString::number(wrong));
            iter++;
            if(iter == data_list.end())
                End_typing();
        }
    }
    if(enter_check)
    {
        qDebug() << QString::fromStdString(*iter);
        ui->show_label->setText(QString::fromStdString(*iter));
        ui->input_text->clear();
        time(&start);
        enter_check = false;
    }
}

void TypingPractice::on_exit_btn_clicked()
{
//    this->close();
}

void TypingPractice::on_input_text_returnPressed()
{
    enter_check = true;
    Show_text();
}

void TypingPractice::End_typing()
{
    int total = accumulate(speed_list.begin(), speed_list.end(), 0);
    int sum = total / speed_list.size();
    QMessageBox::information(this, "End", "평균 타수 : " + QString::number(sum) + "\n오타 : " + QString::number(wrong));
}

TypingPractice::~TypingPractice()
{
    delete ui;
}
