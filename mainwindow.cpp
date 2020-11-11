#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphics_tree = new GraphicsLinkCutTree(5);
    tree = & graphics_tree->tree;

    ui->graphicsView->setScene(graphics_tree->scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{

}


void MainWindow::on_pushButton_clicked()
{
    graphics_tree->update_scene();

    Node * a = tree->nodes[0];
    Node * b = tree->nodes[1];
    Node * c = tree->nodes[2];
    Node * d = tree->nodes[3];
    Node * e = tree->nodes[4];

//    tree->start_link(a, b);
//    tree->finish_operation();
    tree->link(a, b);
    tree->link(c, b);



//    tree->link()


    ui->labelSequence->setText(Sequence::get_text());
    Sequence::clear();

    tree->start_expose(c);
}

void MainWindow::on_pushButton_2_clicked()
{
    tree->make_step();
    graphics_tree->update_scene();
    ui->labelSequence->setText(Sequence::get_text());
}
