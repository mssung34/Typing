#include "selectmenu.h"
#include "ui_selectmenu.h"
#include "typingpractice.h"

SelectMenu::SelectMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SelectMenu)
{
    ui->setupUi(this);
    ui->menu_list->addItem("애국가");
}

SelectMenu::~SelectMenu()
{
    delete ui;
}


void SelectMenu::on_start_btn_clicked()
{
    this->hide();
    TypingPractice tp;
    tp.setModal(true);
    tp.exec();
    this->show();
}

void SelectMenu::on_exit_btn_clicked()
{
    exit(0);
}
