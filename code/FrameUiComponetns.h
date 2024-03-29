#ifndef FRAMEUICOMPONETNS_H
#define FRAMEUICOMPONETNS_H

#include <QFrame>
#include <QPropertyAnimation>
#include <QQueue>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QScrollBar>

#include "Tree/Graphics/GraphicsLinkCutTree.h"
#include "Tree/Node.h"
#include "Helpers/Sequence.h"
#include "Helpers/Colors.h"

namespace Ui {
class FrameUiComponetns;
}

class FrameUiComponetns : public QFrame
{
    Q_OBJECT

public:
    Ui::FrameUiComponetns *ui;


    explicit FrameUiComponetns(GraphicsLinkCutTree &graphics_tree,
                               QQueue<Node*> &selected_nodes,
                               QGraphicsView *graphicsView,
                               QWidget *parent = nullptr);
    ~FrameUiComponetns() override;

    void disable_operations_buttons();

private slots:
    void mousePressEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

    void on_pushButtonMakeStep_clicked();
    void on_horizontalSliderAnimationSpeed_valueChanged(int value);
    void on_pushButtonReset_clicked();
    void on_pushButtonExpose_clicked();
    void on_pushButtonCut_clicked();
    void on_pushButtonLink_clicked();
    void on_pushButtonEndOperation_clicked();
    void on_pushButtonAutoStep_clicked();
    void on_pushButtonOpenPresets_clicked();

    void on_pushButtonPreset1_clicked();
    void on_pushButtonPreset2_clicked();
    void on_pushButtonPreset3_clicked();
    void on_pushButtonPreset4_clicked();
    void on_pushButtonPreset5_clicked();
    void on_pushButtonPreset6_clicked();
    void on_pushButtonPreset7_clicked();

    void on_pushButtonClearLog_clicked();
    void on_pushButtonHideLog_clicked();
    void on_pushButtonSwitchTree_clicked();

    void on_pushButtonPathSum_clicked();

    void on_pushButtonPathMin_clicked();

    void on_pushButtonPathMax_clicked();

    void on_pushButtonLCA_clicked();

private:

    QPropertyAnimation * showPresetsListAnimation;
    QPropertyAnimation * hidePresetsListAnimation;

    QPropertyAnimation * showPopUpDialogAnimation;
    QPropertyAnimation * hidePopUpDialogAnimation;

    QGraphicsView * graphics_view_ui;

    GraphicsLinkCutTree &graphics_tree;
    LinkCutTree * tree;

    QQueue<Node*> &selected_nodes;

    // Either "abstract" or "concrete"
    // Abstract tree -- the one we *imagine* when talking about Link-Cut tree
    // Concrete tree -- the way the tree is *actually* stored in the memory
    QString current_tree_view = "concrete";

    QTimer auto_step_timer;

    void reset_tree();
};

#endif // FRAMEUICOMPONETNS_H
