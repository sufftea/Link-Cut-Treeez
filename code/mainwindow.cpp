#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_MainUI.h"

#include "Helpers/Colors.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_base(new Ui::MainWindow)
    , ui_main(new Ui::Frame)
{
    ui_base->setupUi(this);
    ui_main->setupUi(ui_base->main_ui_frame);


    // connect slots that qt does't want to
    connect(ui_main->pushButtonMakeStep, SIGNAL(clicked()), this, SLOT(on_pushButtonMakeStepClicked()));
    connect(ui_main->pushButtonReset, SIGNAL(clicked()), this, SLOT(on_pushButtonResetClicked()));
    connect(ui_main->horizontalSliderAnimationSpeed, SIGNAL(valueChanged(int)),
            this, SLOT(on_horizontalSliderAnimationSpeedValueChanged(int)));


    // create a layout
    QGridLayout *gl = new QGridLayout(this->centralWidget());

    this->centralWidget()->setLayout(gl);
    gl->setContentsMargins(0, 0, 0, 0);

    gl->addWidget(ui_base->graphicsView, 0, 0);
    gl->addWidget(ui_base->main_ui_frame, 0, 0);


    // set other stuff
    graphics_tree.set_animation_easing_curve(Animation::ease_out_cubic);
    tree = & graphics_tree.tree;

    ui_base->graphicsView->setScene(graphics_tree.scene);
    ui_base->graphicsView->setRenderHints(QPainter::RenderHint::Antialiasing);
    ui_main->horizontalSliderAnimationSpeed->setValue(50);


    // set background tiling for the graphicsview
    QPixmap tile(20, 20);
    QPainter painter(&tile);
    QPen black_pen(QColor(45,45,45));
    black_pen.setWidth(2);

    painter.setPen(black_pen);
    painter.fillRect(tile.rect(), MyColors::black);
    painter.drawPoint(10, 10);

    ui_base->graphicsView->setBackgroundBrush(tile);


    init();
}

MainWindow::~MainWindow()
{
    delete ui_base;
}

void MainWindow::showEvent(QShowEvent *)
{

}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QGraphicsView * gw = ui_base->graphicsView;
    QPoint pos = gw->mapToScene(gw->mapFromParent(e->pos())).toPoint();

    GraphicsSolidNodeItem * node_g = graphics_tree.solid_node_at(pos);
    // TODO
}

void MainWindow::on_pushButtonMakeStepClicked()
{
    tree->make_step();
    ui_main->labelSequence->setText(SequanceLog::get_text());
    graphics_tree.update_scene();
}

void MainWindow::on_horizontalSliderAnimationSpeedValueChanged(int value)
{
    graphics_tree.set_animation_speed(qreal(value) / 100.0);
}

void MainWindow::on_pushButtonResetClicked()
{
    init();
}

void MainWindow::init()
{
    graphics_tree.init(8);
    auto & nodes = tree->nodes;

    tree->link(nodes[0], nodes[2]);
    tree->link(nodes[2], nodes[1]);
    tree->link(nodes[3], nodes[2]);
    tree->link(nodes[4], nodes[3]);
    tree->link(nodes[5], nodes[4]);
    tree->link(nodes[6], nodes[5]);
    tree->link(nodes[7], nodes[4]);

    tree->start_expose(nodes[6]);
    tree->finish_operation();
    tree->start_expose(nodes[3]);
    tree->finish_operation();

    graphics_tree.update_scene();

    SequanceLog::clear();
    tree->start_expose(nodes[7]);
    ui_main->labelSequence->setText(SequanceLog::get_text());
}
