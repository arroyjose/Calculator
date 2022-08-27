#ifndef WIDGET_H
#define WIDGET_H

#include "ui_CalculatorMain.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorMain; }
QT_END_NAMESPACE

class CalculatorMain : public QWidget
{
    Q_OBJECT

public:
    CalculatorMain(QWidget *parent = nullptr);
    ~CalculatorMain();

private:
    Ui::CalculatorWidget *ui;
    double calculatedValue;
    bool operatorPressed;

    void connectUIObjects();
    void processNumberInput(const QString & number);

private slots:
    void OnOneButtonClicked();
    void OnTwoButtonClicked();
    void OnThreeButtonClicked();
    void OnFourButtonClicked();
    void OnFiveButtonClicked();
    void OnSixButtonClicked();
    void OnSevenButtonClicked();
    void OnEightButtonClicked();
    void OnNineButtonClicked();
    void OnZeroButtonClicked();
    void OnPlusMinusButtonClicked();
    void OnDecimalPointButtonClicked();
    void OnEqualsButtonClicked();
    void OnAdditionButtonClicked();
    void OnSubtractionButtonClicked();
    void OnMultiplicationButtonClicked();
    void OnDivisionButtonClicked();
    void OnClearAllButtonClicked();
    void OnAddButtonClicked();
};
#endif // WIDGET_H
