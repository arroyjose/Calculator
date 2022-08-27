#include "CalculatorMain.h"
#include "./ui_CalculatorMain.h"

CalculatorMain::CalculatorMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CalculatorWidget)
    , calculatedValue {}
    , operatorPressed {false}
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

}

void CalculatorMain::OnEqualsButtonClicked()
{
    ui->calculatorNumberLineEdit->setText(QString::number(calculatedValue));
}

void CalculatorMain::OnAdditionButtonClicked()
{
    double convertedValue = ui->calculatorNumberLineEdit->text().toDouble();
    calculatedValue = calculatedValue + convertedValue;
    operatorPressed = true;
}

void CalculatorMain::OnSubtractionButtonClicked()
{

}

void CalculatorMain::OnMultiplicationButtonClicked()
{

}

void CalculatorMain::OnDivisionButtonClicked()
{

}

void CalculatorMain::OnClearAllButtonClicked()
{
    ui->calculatorNumberLineEdit->clear();
    calculatedValue = 0;
    operatorPressed = false;
}

void CalculatorMain::OnAddButtonClicked()
{

}

void CalculatorMain::processNumberInput(const QString &number)
{
    if (operatorPressed == true)
    {
        ui->calculatorNumberLineEdit->clear();
        operatorPressed = false;
    }

    ui->calculatorNumberLineEdit->setText(ui->calculatorNumberLineEdit->text() + number);
}



