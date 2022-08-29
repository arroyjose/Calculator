#ifndef WIDGET_H
#define WIDGET_H

#include "ui_CalculatorMain.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorMain; }
QT_END_NAMESPACE

enum class Operator
{
  none = 0,
  addition,
  subtraction,
  multiplication,
  division
};

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
  Operator lastOperator;

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

  double Add(double a, double b);
  double Subtract(double a, double b);
  double Multiply(double a, double b);
  double Divide(double a, double b);
};
#endif // WIDGET_H
