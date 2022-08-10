#include "randgen.h"
#include "./ui_randgen.h"
#include <random>

RandGen::RandGen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RandGen)
    , m_closeAction(new QAction("Closes the application", this))
{
    ui->setupUi(this);
    ui->numberDisplay->setDigitCount(10);

    connect(ui->generateButton, &QPushButton::clicked, this, [this]() {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> dist(ui->lowerBound->value(), ui->higherBound->value());

        ui->numberDisplay->display(dist(rng));
    });

    m_closeAction->setShortcut(tr("Ctrl+q"));
    connect(m_closeAction, &QAction::triggered, this, []() {
        QApplication::quit();
    });

    ui->generateButton->setShortcut(tr("Ctrl+r"));
}

RandGen::~RandGen()
{
    delete ui;
}
