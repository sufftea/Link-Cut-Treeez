#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphics_tree.set_movement_easing_curve(Animation::ease_out_cubic);
    tree = & graphics_tree.tree;

    ui->graphicsView->setScene(graphics_tree.scene);
    ui->graphicsView->setRenderHints(QPainter::RenderHint::Antialiasing);
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
    graphics_tree.init(6);

    auto & nodes = tree->nodes;

    tree->link(nodes[0], nodes[1]);
    tree->link(nodes[2], nodes[1]);
    tree->link(nodes[3], nodes[2]);
    tree->link(nodes[4], nodes[3]);

    tree->start_expose(nodes[4]);
    tree->finish_operation();

    tree->link(nodes[5], nodes[3]);

    graphics_tree.update_scene();

    Sequence::clear();
    tree->start_expose(nodes[5]);
    ui->labelSequence->setText(Sequence::get_text());

}

void MainWindow::on_pushButton_2_clicked()
{
    tree->make_step();
    graphics_tree.update_scene();
    ui->labelSequence->setText(Sequence::get_text());
}
