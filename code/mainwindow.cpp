#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_MainUI.h"
//#include "ui_

#include "Helpers/Colors.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_base(new Ui::MainWindow)
    , ui_main(new Ui::Frame)
{
    ui_base->setupUi(this);
    ui_main->setupUi(ui_base->main_ui_frame);


    // add some layouts
    QGridLayout *gl1 = new QGridLayout(this->centralWidget());
    this->centralWidget()->setLayout(gl1);
    gl1->setContentsMargins(0, 0, 0, 0);
    gl1->addWidget(ui_base->graphicsView, 0, 0);
    gl1->addWidget(ui_base->main_ui_frame, 0, 0);

    QGridLayout *gl2 = new QGridLayout(ui_main->frameTopGrid);
    ui_main->frameTopGrid->setLayout(gl2);
    gl2->setContentsMargins(0,0,0,0);
    gl2->addWidget(ui_main->framePopUpMenu, 0, 0);
    gl2->addWidget(ui_main->scrollAreaLog, 0, 0);



    // connect slots that qt does't want to connect
    connect(ui_main->pushButtonMakeStep, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonMakeStepClicked);
    connect(ui_main->pushButtonEndOperation, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonEndOperationClicked);
    connect(ui_main->pushButtonReset, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonResetClicked);
    connect(ui_main->pushButtonCut, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonCutClicked);
    connect(ui_main->pushButtonLink, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonLinkClicked);
    connect(ui_main->pushButtonExpose, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonExposeClicked);
    connect(ui_main->pushButtonOpenPresets, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonOpenPresetsClicked);
    connect(ui_main->horizontalSliderAnimationSpeed, &QAbstractSlider::valueChanged, this, &MainWindow::on_horizontalSliderAnimationSpeedValueChanged);

    connect(ui_main->pushButtonPreset1, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonPreset1Clicked);
    connect(ui_main->pushButtonPreset2, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonPreset2Clicked);
    connect(ui_main->pushButtonPreset3, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonPreset3Clicked);
    connect(ui_main->pushButtonPreset4, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonPreset4Clicked);
    connect(ui_main->pushButtonPreset5, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonPreset5Clicked);
    connect(ui_main->pushButtonPreset6, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonPreset6Clicked);
    connect(ui_main->pushButtonPreset7, &QAbstractButton::clicked, this, &MainWindow::on_pushButtonPreset7Clicked);


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

    ui_main->framePresetsList->setMaximumHeight(0);

    // animations
    showPresetsListAnimation = new QPropertyAnimation(this);
    showPresetsListAnimation->setPropertyName("maximumHeight");
    showPresetsListAnimation->setTargetObject(ui_main->framePresetsList);
    showPresetsListAnimation->setEasingCurve(QEasingCurve::OutExpo);
    showPresetsListAnimation->setDuration(300);
    showPresetsListAnimation->setEndValue(170);

    hidePresetsListAnimation = new QPropertyAnimation(this);
    hidePresetsListAnimation->setPropertyName("maximumHeight");
    hidePresetsListAnimation->setTargetObject(ui_main->framePresetsList);
    hidePresetsListAnimation->setEasingCurve(QEasingCurve::OutExpo);
    hidePresetsListAnimation->setDuration(300);
    hidePresetsListAnimation->setEndValue(0);


    // set background tiling for the graphicsview
    QPixmap tile(20, 20);
    QPainter painter(&tile);
    QPen black_pen(QColor(45,45,45));
    black_pen.setWidth(3);

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

void MainWindow::wheelEvent(QWheelEvent *e)
{
//    ui_base->graphicsView->resetTransform();
//    if (e->delta() < 0) {
//        ui_base->graphicsView->scale(0.9, 0.9);
//    } else if (e->delta() > 0) {
//        ui_base->graphicsView->scale(1.1, 1.1);
//    }
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

void MainWindow::on_pushButtonOpenPresetsClicked()
{
    if (ui_main->framePresetsList->maximumHeight() > 0) {
//        showPresetsListAnimation->setDirection(QPropertyAnimation::Direction::Backward);
//        showPresetsListAnimation->start();
        hidePresetsListAnimation->start();
    } else {
//        showPresetsListAnimation->setDirection(QPropertyAnimation::Direction::Forward);
//        showPresetsListAnimation->start();
        showPresetsListAnimation->start();
    }
}

void MainWindow::on_pushButtonPreset1Clicked()
{
    hidePresetsListAnimation->start();

    graphics_tree.init(14);

    QVector<Node*> &nodes = tree->nodes;

    tree->link(nodes[1], nodes[0]);
    tree->link(nodes[2], nodes[1]);
    tree->link(nodes[3], nodes[2]);
    tree->link(nodes[4], nodes[1]);
    tree->link(nodes[5], nodes[4]);
    tree->link(nodes[6], nodes[5]);
    tree->link(nodes[7], nodes[5]);
    tree->link(nodes[8], nodes[7]);
    tree->link(nodes[9], nodes[8]);
    tree->link(nodes[10], nodes[9]);
    tree->link(nodes[11], nodes[8]);
    tree->link(nodes[12], nodes[11]);
    tree->link(nodes[13], nodes[12]);


    graphics_tree.update_scene();
    ui_base->graphicsView->scale(0.5, 0.5);
}

void MainWindow::on_pushButtonPreset2Clicked()
{
    hidePresetsListAnimation->start();
}

void MainWindow::on_pushButtonPreset3Clicked()
{
    hidePresetsListAnimation->start();
}

void MainWindow::on_pushButtonPreset4Clicked()
{
    hidePresetsListAnimation->start();
}

void MainWindow::on_pushButtonPreset5Clicked()
{
    hidePresetsListAnimation->start();
}

void MainWindow::on_pushButtonPreset6Clicked()
{
    hidePresetsListAnimation->start();
}

void MainWindow::on_pushButtonPreset7Clicked()
{
    hidePresetsListAnimation->start();
}

void MainWindow::on_pushButtonPreset8Clicked()
{
    hidePresetsListAnimation->start();
}
