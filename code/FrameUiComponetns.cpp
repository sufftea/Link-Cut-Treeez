#include "FrameUiComponetns.h"
#include "ui_FrameUiComponetns.h"

FrameUiComponetns::FrameUiComponetns(GraphicsLinkCutTree &graphics_tree,
                                     QQueue<GraphicsSolidNodeItem *> &selected_nodes,
                                     QGraphicsView * graphicsView,
                                     QWidget *parent) :
    QFrame(parent),
    ui(new Ui::FrameUiComponetns),
    graphics_tree(graphics_tree),
    selected_nodes(selected_nodes)
{
    ui->setupUi(this);


    // initialize stuff
    this->tree = & graphics_tree.tree;
    this->graphics_view_ui = graphicsView;

    // layouts
    ui->gridLayoutPopUpMenu->setParent(nullptr);
    ui->gridLayoutTopPart->addLayout(ui->gridLayoutPopUpMenu, 0, 0);
    ui->gridLayoutPopUpMenu->setParent(ui->gridLayoutTopPart);

    ui->scrollAreaLog->stackUnder(ui->framePresetsList);


    // other
    ui->horizontalSliderAnimationSpeed->setValue(50);
    ui->pushButtonCut->setEnabled(false);
    ui->pushButtonLink->setEnabled(false);
    ui->pushButtonExpose->setEnabled(false);
    ui->framePresetsList->setMaximumHeight(0);

//    ui->scrollAreaLog->setAttribute(Qt::WA_TransparentForMouseEvents);
    ui->labelSequence->setAttribute(Qt::WA_TransparentForMouseEvents);

    ui->pushButtonShowDelta->setStyleSheet(ButtonStyles::switch_button_off);


    // animations
    showPresetsListAnimation = new QPropertyAnimation(this);
    showPresetsListAnimation->setPropertyName("maximumHeight");
    showPresetsListAnimation->setTargetObject(ui->framePresetsList);
    showPresetsListAnimation->setEasingCurve(QEasingCurve::OutExpo);
    showPresetsListAnimation->setDuration(300);
    showPresetsListAnimation->setEndValue(170);

    hidePresetsListAnimation = new QPropertyAnimation(this);
    hidePresetsListAnimation->setPropertyName("maximumHeight");
    hidePresetsListAnimation->setTargetObject(ui->framePresetsList);
    hidePresetsListAnimation->setEasingCurve(QEasingCurve::OutExpo);
    hidePresetsListAnimation->setDuration(300);
    hidePresetsListAnimation->setEndValue(0);
}

FrameUiComponetns::~FrameUiComponetns()
{
    delete ui;
}

void FrameUiComponetns::mousePressEvent(QMouseEvent *e)
{
    e->ignore();
}

void FrameUiComponetns::mouseMoveEvent(QMouseEvent *e)
{
    e->ignore();
}

void FrameUiComponetns::mouseReleaseEvent(QMouseEvent *e)
{
    e->ignore();
}

void FrameUiComponetns::on_pushButtonMakeStep_clicked()
{
    tree->make_step();
    ui->labelSequence->setText(SequanceLog::get_text());
    graphics_tree.update_scene();

    ui->scrollAreaLog->verticalScrollBar()->setSliderPosition(ui->scrollAreaLog->height());
}

void FrameUiComponetns::on_horizontalSliderAnimationSpeed_valueChanged(int value)
{
    graphics_tree.set_animation_speed(qreal(value) / 100.0);
}

void FrameUiComponetns::on_pushButtonReset_clicked()
{
    reset_tree();
}

void FrameUiComponetns::reset_tree()
{
    graphics_tree.init(8);
    graphics_tree.update_scene();

    SequanceLog::clear();
    ui->labelSequence->setText(SequanceLog::get_text());

    selected_nodes.clear();
}

void FrameUiComponetns::on_pushButtonExpose_clicked()
{
    if (selected_nodes.size() == 1) {
        SequanceLog::clear();

        tree->start_expose(selected_nodes[0]->my_node);

        ui->labelSequence->setText(SequanceLog::get_text());

        for (GraphicsSolidNodeItem * node : selected_nodes) {
            node->set_selection_type(GraphicsSolidNodeItem::SelectionType::no_selection);
        }
        selected_nodes.clear();

        ui->pushButtonCut->setEnabled(false);
        ui->pushButtonLink->setEnabled(false);
        ui->pushButtonExpose->setEnabled(false);

        graphics_tree.update_scene();
    }
}

void FrameUiComponetns::on_pushButtonCut_clicked()
{

}

void FrameUiComponetns::on_pushButtonLink_clicked()
{
    if (selected_nodes.size() == 2) {
        SequanceLog::clear();

        tree->start_link(selected_nodes[0]->my_node, selected_nodes[1]->my_node);

        ui->labelSequence->setText(SequanceLog::get_text());

        for (GraphicsSolidNodeItem * node : selected_nodes) {
            node->set_selection_type(GraphicsSolidNodeItem::SelectionType::no_selection);
        }
        selected_nodes.clear();

        ui->pushButtonCut->setEnabled(false);
        ui->pushButtonLink->setEnabled(false);
        ui->pushButtonExpose->setEnabled(false);
    }
}

void FrameUiComponetns::on_pushButtonEndOperation_clicked()
{
    tree->finish_operation();
    graphics_tree.update_scene();
    ui->labelSequence->setText(SequanceLog::get_text());

    ui->scrollAreaLog->verticalScrollBar()->setSliderPosition(ui->scrollAreaLog->height());
}

void FrameUiComponetns::on_pushButtonOpenPresets_clicked()
{
    if (ui->framePresetsList->maximumHeight() > 0) {
        hidePresetsListAnimation->start();
    } else {
        showPresetsListAnimation->start();
    }
}

void FrameUiComponetns::on_pushButtonPreset1_clicked()
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
}

void FrameUiComponetns::on_pushButtonPreset2_clicked()
{
    hidePresetsListAnimation->start();
}

void FrameUiComponetns::on_pushButtonPreset3_clicked()
{
    hidePresetsListAnimation->start();
}

void FrameUiComponetns::on_pushButtonPreset4_clicked()
{
    hidePresetsListAnimation->start();
}

void FrameUiComponetns::on_pushButtonPreset5_clicked()
{
    hidePresetsListAnimation->start();
}

void FrameUiComponetns::on_pushButtonPreset6_clicked()
{
    hidePresetsListAnimation->start();
}

void FrameUiComponetns::on_pushButtonPreset7_clicked()
{
    hidePresetsListAnimation->start();
}


void FrameUiComponetns::on_pushButtonClearLog_clicked()
{
    ui->labelSequence->clear();
    SequanceLog::clear();
}

void FrameUiComponetns::on_pushButtonHideLog_clicked()
{
    if (ui->labelSequence->isHidden()) {
        ui->labelSequence->show();
        ui->pushButtonClearLog->show();
        ui->pushButtonHideLog->setText("Hide Log");
    } else {
        ui->labelSequence->hide();
        ui->pushButtonClearLog->hide();
        ui->pushButtonHideLog->setText("Show Log");
    }
}

void FrameUiComponetns::on_pushButtonShowDelta_clicked()
{
    if (graphics_tree.is_show_delta()) {
        ui->pushButtonShowDelta->setStyleSheet(ButtonStyles::switch_button_off);
        graphics_tree.set_show_delta(false);
    } else {
        ui->pushButtonShowDelta->setStyleSheet(ButtonStyles::switch_button_on);
        graphics_tree.set_show_delta(true);
    }
}
