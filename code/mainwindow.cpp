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
    connect(ui_main->pushButtonEndOperation, SIGNAL(clicked()), this, SLOT(on_pushButtonEndOperationClicked()));
    connect(ui_main->pushButtonReset, SIGNAL(clicked()), this, SLOT(on_pushButtonResetClicked()));

    connect(ui_main->horizontalSliderAnimationSpeed, SIGNAL(valueChanged(int)),
            this, SLOT(on_horizontalSliderAnimationSpeedValueChanged(int)));

    connect(ui_main->pushButtonCut, SIGNAL(clicked()), this, SLOT(on_pushButtonCutClicked()));
    connect(ui_main->pushButtonLink, SIGNAL(clicked()), this, SLOT(on_pushButtonLinkClicked()));
    connect(ui_main->pushButtonExpose, SIGNAL(clicked()), this, SLOT(on_pushButtonExposeClicked()));


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

    selected_nodes.reserve(3);

    ui_main->pushButtonCut->setEnabled(false);
    ui_main->pushButtonLink->setEnabled(false);
    ui_main->pushButtonExpose->setEnabled(false);


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

    GraphicsSolidNodeItem * graphics_node = graphics_tree.solid_node_at(pos);

    if (graphics_node != nullptr) {
        if (graphics_node->get_selection_type() == GraphicsSolidNodeItem::SelectionType::no_selection) {
            graphics_node->set_selection_type(GraphicsSolidNodeItem::SelectionType::user_selected);
            selected_nodes << graphics_node;
        } else if (graphics_node->get_selection_type() == GraphicsSolidNodeItem::SelectionType::user_selected) {
            graphics_node->set_selection_type(GraphicsSolidNodeItem::SelectionType::no_selection);
            selected_nodes.removeOne(graphics_node);
        }

        if (selected_nodes.size() == 0) {
            ui_main->pushButtonCut->setEnabled(false);
            ui_main->pushButtonLink->setEnabled(false);
            ui_main->pushButtonExpose->setEnabled(false);
        } else if (selected_nodes.size() == 1) {
            ui_main->pushButtonCut->setEnabled(true);
            ui_main->pushButtonLink->setEnabled(false);
            ui_main->pushButtonExpose->setEnabled(true);
        } else if (selected_nodes.size() == 2) {
            ui_main->pushButtonCut->setEnabled(false);
            ui_main->pushButtonLink->setEnabled(true);
            ui_main->pushButtonExpose->setEnabled(false);
        } else if (selected_nodes.size() == 3) {
            selected_nodes.first()->set_selection_type(GraphicsSolidNodeItem::SelectionType::no_selection);
            selected_nodes.pop_front();
        }
    }
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
    graphics_tree.update_scene();

    SequanceLog::clear();
    ui_main->labelSequence->setText(SequanceLog::get_text());

    selected_nodes.clear();
}

void MainWindow::on_pushButtonExposeClicked()
{
    if (selected_nodes.size() == 1) {
        SequanceLog::clear();

        tree->start_expose(selected_nodes[0]->my_node);

        ui_main->labelSequence->setText(SequanceLog::get_text());

        for (GraphicsSolidNodeItem * node : selected_nodes) {
            node->set_selection_type(GraphicsSolidNodeItem::SelectionType::no_selection);
        }
        selected_nodes.clear();

        ui_main->pushButtonCut->setEnabled(false);
        ui_main->pushButtonLink->setEnabled(false);
        ui_main->pushButtonExpose->setEnabled(false);
    }
}

void MainWindow::on_pushButtonCutClicked()
{

}

void MainWindow::on_pushButtonLinkClicked()
{
    if (selected_nodes.size() == 2) {
        SequanceLog::clear();

        tree->start_link(selected_nodes[0]->my_node, selected_nodes[1]->my_node);

        ui_main->labelSequence->setText(SequanceLog::get_text());

        for (GraphicsSolidNodeItem * node : selected_nodes) {
            node->set_selection_type(GraphicsSolidNodeItem::SelectionType::no_selection);
        }
        selected_nodes.clear();

        ui_main->pushButtonCut->setEnabled(false);
        ui_main->pushButtonLink->setEnabled(false);
        ui_main->pushButtonExpose->setEnabled(false);
    }
}

void MainWindow::on_pushButtonEndOperationClicked()
{
    tree->finish_operation();
    graphics_tree.update_scene();
}
