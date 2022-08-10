#include "randgen.h"
#include "./ui_randgen.h"
#include <random>

RandGen::RandGen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RandGen)
    , m_generateAction(new QAction("Generate", this))
    , m_exitAction(new QAction("Exit", this))
{
    ui->setupUi(this);
    m_fileMenu = menuBar()->addMenu("File");
    m_fileMenu->addAction(m_generateAction);
    m_fileMenu->addAction(m_exitAction);

    ui->numberDisplay->setDigitCount(10);

    m_generateAction->setShortcut(tr("Ctrl+r"));
    connect(m_generateAction, &QAction::triggered, this, [this]() {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> dist(ui->lowerBound->value(), ui->higherBound->value());

        ui->numberDisplay->display(dist(rng));
    });

    m_exitAction->setShortcut(tr("Ctrl+q"));
    connect(m_exitAction, &QAction::triggered, this, [this]() { QApplication::quit(); });

    connect(ui->generateButton, &QPushButton::clicked, this, [this]() { m_generateAction->trigger(); });
}

RandGen::~RandGen()
{
    delete ui;
}
