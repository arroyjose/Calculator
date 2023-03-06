#include "CalculatorMain.h"
#include "./ui_CalculatorMain.h"
#include <QDebug>

CalculatorMain::CalculatorMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CalculatorWidget)
    , CalculatedValue {}
    , OperatorPressed {false}
    , CurrentOperator {}
    , LastOperator {}
    , LastOperand {}
    , DecimalPointPressed {false}
{
  ui->setupUi(this);
  connectUIObjects();
}

void CalculatorMain::connectUIObjects()
{
  connect(ui->oneButton, &QPushButton::clicked, this, &CalculatorMain::OnOneButtonClicked);
  connect(ui->twoButton, &QPushButton::clicked, this, &CalculatorMain::OnTwoButtonClicked);
  connect(ui->threeButton, &QPushButton::clicked, this, &CalculatorMain::OnThreeButtonClicked);
  connect(ui->fourButton, &QPushButton::clicked, this, &CalculatorMain::OnFourButtonClicked);
  connect(ui->fiveButton, &QPushButton::clicked, this, &CalculatorMain::OnFiveButtonClicked);
  connect(ui->sixButton, &QPushButton::clicked, this, &CalculatorMain::OnSixButtonClicked);
  connect(ui->sevenButton, &QPushButton::clicked, this, &CalculatorMain::OnSevenButtonClicked);
  connect(ui->eightButton, &QPushButton::clicked, this, &CalculatorMain::OnEightButtonClicked);
  connect(ui->nineButton, &QPushButton::clicked, this, &CalculatorMain::OnNineButtonClicked);
  connect(ui->zeroButton, &QPushButton::clicked, this, &CalculatorMain::OnZeroButtonClicked);
  connect(ui->plusMinusButton, &QPushButton::clicked, this, &CalculatorMain::OnPlusMinusButtonClicked);
  connect(ui->decimalPointButton, &QPushButton::clicked, this, &CalculatorMain::OnDecimalPointButtonClicked);
  connect(ui->equalsButton, &QPushButton::clicked, this, &CalculatorMain::OnEqualsButtonClicked);
  connect(ui->additionButton, &QPushButton::clicked, this, &CalculatorMain::OnAdditionButtonClicked);
  connect(ui->subtractionButton, &QPushButton::clicked, this, &CalculatorMain::OnSubtractionButtonClicked);
  connect(ui->multiplicationButton, &QPushButton::clicked, this, &CalculatorMain::OnMultiplicationButtonClicked);
  connect(ui->divisionButton, &QPushButton::clicked, this, &CalculatorMain::OnDivisionButtonClicked);
  connect(ui->clearAllButton, &QPushButton::clicked, this, &CalculatorMain::OnClearAllButtonClicked);
}

CalculatorMain::~CalculatorMain()
{
  delete ui;
}

void CalculatorMain::OnOneButtonClicked()
{
  processNumberInput(QString("1"));
}

void CalculatorMain::OnTwoButtonClicked()
{
  processNumberInput(QString("2"));
}

void CalculatorMain::OnThreeButtonClicked()
{
  processNumberInput(QString("3"));
}

void CalculatorMain::OnFourButtonClicked()
{
  processNumberInput(QString("4"));
}

void CalculatorMain::OnFiveButtonClicked()
{
  processNumberInput(QString("5"));
}

void CalculatorMain::OnSixButtonClicked()
{
  processNumberInput(QString("6"));
}

void CalculatorMain::OnSevenButtonClicked()
{
  processNumberInput(QString("7"));
}

void CalculatorMain::OnEightButtonClicked()
{
  processNumberInput(QString("8"));
}

void CalculatorMain::OnNineButtonClicked()
{
  processNumberInput(QString("9"));
}

void CalculatorMain::OnZeroButtonClicked()
{
  processNumberInput(QString("0"));
}

void CalculatorMain::OnPlusMinusButtonClicked()
{

}

void CalculatorMain::OnDecimalPointButtonClicked()
{
  if (!DecimalPointPressed)
  {
      processNumberInput(QString("."));
      DecimalPointPressed = true;
  }
}

void CalculatorMain::OnEqualsButtonClicked()
{
  if (LastOperator != Operator::equal)
  {
    LastOperand = ui->calculatorNumberLineEdit->text().toDouble();
    CurrentOperator = LastOperator;
  }

  switch (CurrentOperator)
  {
    case Operator::addition:
      {
        CalculatedValue = Add(LastOperand, CalculatedValue);
      }
      break;
    case Operator::subtraction:
      {
        CalculatedValue = Subtract(LastOperand, CalculatedValue);
      }
      break;
    case Operator::multiplication:
      {
        CalculatedValue = Multiply(LastOperand, CalculatedValue);
      }
      break;
    case Operator::division:
      {
        CalculatedValue = Divide(LastOperand, CalculatedValue);
      }
      break;
    case Operator::none:
    default:
      break;
  }

  ui->calculatorNumberLineEdit->setText(QString::number(CalculatedValue));
  LastOperator = Operator::equal;
}

double CalculatorMain::ConvertLineEditTextToDouble()
{
  return ui->calculatorNumberLineEdit->text().toDouble();
}

void CalculatorMain::CheckPreviousEqualsOperation()
{
  if (LastOperator == Operator::equal)
  {
    CalculatedValue = ConvertLineEditTextToDouble();
  }
}

void CalculatorMain::OnAdditionButtonClicked()
{
  CheckPreviousEqualsOperation();

  if (OperatorPressed == false)
  {
    double convertedValue = ConvertLineEditTextToDouble();
    CalculatedValue = Add(CalculatedValue, convertedValue);
    ui->calculatorNumberLineEdit->setText(QString::number(CalculatedValue));
    OperatorPressed = true;
  }

  LastOperator = Operator::addition;
}

void CalculatorMain::OnSubtractionButtonClicked()
{
  CheckPreviousEqualsOperation();

  if (OperatorPressed == false)
  {
    double convertedValue = ui->calculatorNumberLineEdit->text().toDouble();
    CalculatedValue = Subtract(CalculatedValue, convertedValue);
    ui->calculatorNumberLineEdit->setText(QString::number(CalculatedValue));
    OperatorPressed = true;
  }

  LastOperator = Operator::subtraction;
}

void CalculatorMain::OnMultiplicationButtonClicked()
{
  CheckPreviousEqualsOperation();

  if (OperatorPressed == false)
    {double convertedValue = ui->calculatorNumberLineEdit->text().toDouble();
    CalculatedValue = Multiply(CalculatedValue, convertedValue);
    ui->calculatorNumberLineEdit->setText(QString::number(CalculatedValue));
    OperatorPressed = true;
  }

  LastOperator = Operator::multiplication;
}

void CalculatorMain::OnDivisionButtonClicked()
{
  CheckPreviousEqualsOperation();

  if (OperatorPressed == false)
    {double convertedValue = ui->calculatorNumberLineEdit->text().toDouble();
    CalculatedValue = Divide(CalculatedValue, convertedValue);
    ui->calculatorNumberLineEdit->setText(QString::number(CalculatedValue));
    OperatorPressed = true;
  }

  LastOperator = Operator::division;
}

void CalculatorMain::reset()
{
  OperatorPressed = false;
  DecimalPointPressed = false;
  LastOperator = Operator::none;
}

void CalculatorMain::OnClearAllButtonClicked()
{
  ui->calculatorNumberLineEdit->clear();
  CalculatedValue = 0;
  reset();
}

double CalculatorMain::Add(double a, double b)
{
  return a + b;
}

double CalculatorMain::Subtract(double a, double b)
{
  return a - b;
}

double CalculatorMain::Multiply(double a, double b)
{
  return a * b;
}

double CalculatorMain::Divide(double a, double b)
{
  double val = 0;

  if (b != 0)
  {
      val = a / b;
  }
  else
  {
      // throw exception
  }

  return val;
}

void CalculatorMain::processNumberInput(const QString &number)
{
  if (OperatorPressed == true)
  {
    ui->calculatorNumberLineEdit->clear();
    OperatorPressed = false;
  }

  qDebug() << "Number " << number;
  ui->calculatorNumberLineEdit->setText(ui->calculatorNumberLineEdit->text() + number);
  qDebug() << "LineEditText " << ui->calculatorNumberLineEdit->text();
  //operatorPressed = false;
}



