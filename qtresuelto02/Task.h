#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui {
class Task;
}

class Task : public QWidget {
    Q_OBJECT

public:
    explicit Task(const QString& sinonimo = "Subir - Ascender", QWidget *parent = nullptr);
    ~Task();

    QString getSinonimos() const;
    void setSinonimos(const QString& texto);

signals:
    void removed(Task* task);

private slots:
    void on_editButton_clicked();

private:
    Ui::Task *ui;
};

#endif // TASK_H
