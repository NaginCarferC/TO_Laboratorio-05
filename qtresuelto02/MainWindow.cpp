#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    mListaSinonimos() {
    ui->setupUi(this);

    // Cambio del texto del botón y etiqueta principal según requerimiento
    ui->addTaskButton->setText("Agregar sinónimos");
    ui->statusLabel->setText("Gestor de Sinónimos");

    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::agregarSinonimos);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::agregarSinonimos() {
    Task* nuevaFila = new Task("Subir - Ascender", this);

    // Conexión para eliminación reactiva
    connect(nuevaFila, &Task::removed, this, &MainWindow::removerFila);

    mListaSinonimos.append(nuevaFila);
    ui->tasksLayout->addWidget(nuevaFila);
}

void MainWindow::removerFila(Task* task) {
    mListaSinonimos.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->deleteLater();
}
