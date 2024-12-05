#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>

void loadTextFile(const QString &filePath, QTextBrowser *textBrowser)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(nullptr, "Error", "Cannot open file");
        return;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8"); // 设置编码为 UTF-8
    QString fileContent = in.readAll();

    // 设置文件内容到 QTextBrowser 中
    textBrowser->setHtml(fileContent);  // 使用 setHtml() 解析并显示 HTML 格式的内容

    file.close();
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QFont font("Courier New", 9);
//    ui->textBrowser_Para->setFont(font);


//    ui->textBrowser_Para->setSource(QUrl());
}

Widget::~Widget()
{
    delete ui;
}
