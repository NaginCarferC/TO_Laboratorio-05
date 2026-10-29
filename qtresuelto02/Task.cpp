#include "Task.h"
#include "ui_Task.h"
#include <QInputDialog>
#include <QDebug>

Task::Task(const QString& sinonimo, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task) {
    ui->setupUi(this);

    // Se asegura que el checkbox inicie desmarcado
    ui->checkbox->setChecked(false);
    ui->Mitext->setText(sinonimo);

    // Emisión de la señal al presionar Quitar
    connect(ui->removeButton, &QPushButton::clicked, [this]() {
        emit removed(this);
    });

    // Conexión del botón edit para modificar los sinónimos
    connect(ui->editButton, &QPushButton::clicked, this, &Task::on_editButton_clicked);
}

Task::~Task() {
    delete ui;
}

QString Task::getSinonimos() const {
    return ui->Mitext->text();
}

void Task::setSinonimos(const QString& texto) {
    ui->Mitext->setText(texto);
}

void Task::on_editButton_clicked() {
    bool ok;
    QString nuevoTexto = QInputDialog::getText(this, tr("Editar Sinónimos"),
                                               tr("Ingrese el nuevo par de sinónimos:"),
                                               QLineEdit::Normal,
                                               ui->Mitext->text(), &ok);
    if (ok && !nuevoTexto.trimmed().isEmpty()) {
        ui->Mitext->setText(nuevoTexto.trimmed());
    }
}
