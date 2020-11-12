#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphics_tree = new GraphicsLinkCutTree(6);
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
    Node * f = tree->nodes[5];


    tree->link(b, a);
    tree->link(c, b);
    tree->link(d, e);
    tree->link(f, e);
    tree->link(e, b);

    tree->start_expose(c);
    tree->finish_operation();
    Sequence::clear();
    graphics_tree->update_scene();

    tree->start_expose(f);
}

void MainWindow::on_pushButton_2_clicked()
{
    tree->make_step();
    graphics_tree->update_scene();
    ui->labelSequence->setText(Sequence::get_text());
}
