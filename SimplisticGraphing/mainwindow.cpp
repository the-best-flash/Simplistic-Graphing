#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->view->setScene(&scene);

    //If anti-ailising
    ui->view->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
